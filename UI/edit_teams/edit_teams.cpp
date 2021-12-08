#include "edit_teams.h"
#include "ui_edit_teams.h"
#include <iostream>
#include <QDebug>

#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "../login/login.h"

edit_teams::edit_teams(QWidget *parent) : QDialog(parent), ui(new Ui::edit_teams)
{
    ui->setupUi(this);

    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    qry->prepare("SELECT TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach FROM GeneralInfo ORDER BY TeamName");
    qry->exec();

    ui->tableView->verticalHeader()->setHidden(true);
    modal->setQuery(*qry);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->teamCombo->addItem("None");

    qry->prepare("SELECT TeamName FROM GeneralInfo ORDER BY teamName ASC");
    qry->exec();
    while (qry->next()) {
        ui->teamCombo->addItem(qry->value(0).toString());
    }

    connect(ui->teamCombo, SIGNAL(currentTextChanged(const QString &)), this, SLOT(on_teamCombo_currentIndexChanged(const QString &)));
    connect(ui->changeArenaButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    QPixmap bkgnd("./images/bball_lady.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    this->showFullScreen();
}

edit_teams::~edit_teams()
{
    delete ui;
}

void edit_teams::on_city_clicked()
{}


void edit_teams::on_load_teams_button_clicked()
{
    QSqlQuery qry;
    QString notify;
    qry.prepare("INSERT into GeneralInfo( TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach) values (:TeamName,:ArenaName,:Conference, :Division,:Location,:StadiumCapacity,:JoinedLeague,:Coach)");
    qry.bindValue(":Conference", "Western");
    qry.bindValue(":Division", "Northwest");
    qry.bindValue(":TeamName", "Seattle Supersonics");
    qry.bindValue(":Location", "Seattle, Washington");
    qry.bindValue(":ArenaName","Seattle Stadium");
    qry.bindValue(":StadiumCapacity", 18919);
    qry.bindValue(":JoinedLeague", "2023");
    qry.bindValue(":Coach", "Shaquille O'Neal");

    if(qry.exec())
    {
        QMessageBox::critical(this, "Success!", "Data was successfully read!");
        isNewTeamAdded = true;
    }

    qry.prepare("INSERT INTO Distances Values('Portland Trail Blazers', 'Moda Center', 'Seattle Supersonics', 173.8)");
    qry.exec();
    qry.prepare("INSERT INTO Distances Values('Sacramento Kings', 'Golden 1 Center', 'Seattle Supersonics', 752.4)");
    qry.exec();
    qry.prepare("INSERT INTO Distances Values('Seattle Supersonics', 'Seattle Stadium', 'Portland Trail Blazers', 173.8)");
    qry.exec();
    qry.prepare("INSERT INTO Distances Values('Seattle Supersonics', 'Seattle Stadium', 'Sacramento Kings', 752.4)");
    qry.exec();

    qry.prepare("INSERT INTO Souvenirs VALUES ('Seattle Supersonics', 'Autographed Basketball', 49.99);");
    qry.exec();
    qry.prepare("INSERT INTO Souvenirs VALUES ('Seattle Supersonics', 'Team pennant', 17.99);");
    qry.exec();
    qry.prepare("INSERT INTO Souvenirs VALUES ('Seattle Supersonics', 'Team picture', 29.89);");
    qry.exec();
    qry.prepare("INSERT INTO Souvenirs VALUES ('Seattle Supersonics', 'Team jersey', 179.79);");
    qry.exec();
}

void edit_teams::on_load_table_button_clicked()
{
    login obj;
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery * qry=new QSqlQuery(obj.informationDb);

    qry->prepare("SELECT TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach FROM GeneralInfo ORDER BY TeamName");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void edit_teams::on_revert_changes_button_clicked()
{
    login obj;
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Delete FROM GeneralInfo WHERE JoinedLeague = 2023");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    }
    else
    {
        QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
    }
}

void edit_teams::on_teamCombo_currentIndexChanged(const QString &arg1)
{
    teamName = ui->teamCombo->currentText();
}


void edit_teams::on_changeArenaButton_clicked()
{
    if (teamName == "None") {
        QMessageBox::critical(this, "Error!", "Update Team Name");
        return;
    }
    if (arenaName == "None") {
        QMessageBox::critical(this, "Error!", "Update Arena Name");
        return;
    }
    login conn;
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);
    capacity = ui->capacitySpinbox->value();
    arenaName = ui->arenaLineEdit->text();
    std::cout << teamName.toStdString() << std::endl;
    qry->prepare("UPDATE GeneralInfo SET ArenaName = '" + arenaName + "', StadiumCapacity = " + QString::number(capacity) + " WHERE TeamName = '" + teamName + "';");
    qry->exec();
    if(qry->exec())
    {
        QMessageBox::critical(this, "Success!", "Updated Arena information!");
    }
}

