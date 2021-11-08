#include "display_team.h"
#include "ui_display_team.h"
#include <QtSql>
#include <QDebug>

#include <QMessageBox>
#include <QFileInfo>
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "login.h"
#include <QSqlQueryModel>


display_team::display_team(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display_team)
{
    ui->setupUi(this);

    login conn;

    auto * modal = new QSqlQueryModel();

        conn.connOpen();
        auto* qry=new QSqlQuery(conn.mydb);
        qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata");
        qry->exec();

        ui->tableView->verticalHeader()->setHidden(true);
        modal->setQuery(*qry);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setModel(modal);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       // conn.connClose();
}

display_team::~display_team()
{
    delete ui;
}

void display_team::on_reload_button_clicked()
{
    login conn;
        auto * modal=new QSqlQueryModel();

        conn.connOpen();
        auto* qry=new QSqlQuery(conn.mydb);

        qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        qDebug() << (modal->rowCount());

}

void display_team::on_combo_sort_activated(const QString &arg1)
{
    login conn;
    auto * modal=new QSqlQueryModel();

    conn.connOpen();
    auto* qry=new QSqlQuery(conn.mydb);

    // QMessageBox::information(this, "Title", ui->combo_sort->currentText());
    if(ui->combo_sort->currentText() == "Team Name")
    {
        qry->prepare("select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata order by TeamName");
    }
    else if (ui->combo_sort->currentText() == "Arena")
    {
        qry->prepare("select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata order by ArenaName");
    }

    else if (ui->combo_sort->currentText() == "Capacity")
    {
        qry->prepare("select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata order by StadiumCapacity");
    }
    else if (ui->combo_sort->currentText() == "Year Joined")
    {
        qry->prepare("select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata order by JoinedLeague");
    }
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}
