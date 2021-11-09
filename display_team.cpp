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
#include <string>
#include <iostream>


display_team::display_team(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::display_team)
{
    ui->setupUi(this);

    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata");
    qry->exec();

    ui->tableView->verticalHeader()->setHidden(true);
    modal->setQuery(*qry);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // conn.connClose();

    login conn1;
    QSqlQueryModel *modal1 = new QSqlQueryModel();

    conn1.connOpen();

    QSqlQuery* qry1 = new QSqlQuery(conn1.informationDb);

    qry1->exec("select TeamName FROM GISData");

    modal1->setQuery(*qry1);
    ui->combo_team->setModel(modal1);

    conn1.connClose();

    connect(ui->combo_sort, SIGNAL(currentTextChanged(QString)), this, SLOT(on_combo_sort_activated(QString)));
    connect(ui->division_comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_division_comboBox_activated(QString)));
    connect(ui->combo_team, SIGNAL(currentTextChanged(QString)), this, SLOT(on_combo_team_activated(QString)));

}

display_team::~display_team()
{
    delete ui;
}

void display_team::on_reload_button_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());

}

void display_team::on_combo_sort_activated(const QString &arg1)
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT ";
    if (ui->team_name_checkBox->checkState() == Qt::Checked) sql+= "TeamName, ";
    if (ui->arena_checkBox->checkState() == Qt::Checked) sql += "ArenaName, ";
    if (ui->capacity_checkBox->checkState() == Qt::Checked) sql += "StadiumCapacity, ";
    if (ui->year_checkBox->checkState() == Qt::Checked) sql += "JoinedLeague, ";
    if (ui->coach_checkBox->checkState() == Qt::Checked) sql += "Coach, ";
    sql = sql.substr(0, sql.length() - 2);
    sql += " FROM GISdata ORDER BY ";

    if (ui->combo_sort->currentText() == "Team Name") sql += "TeamName";
    else if (ui->combo_sort->currentText() == "Arena Name") sql += "ArenaName";
    else if (ui->combo_sort->currentText() == "Capacity") sql += "StadiumCapacity";
    else if (ui->combo_sort->currentText() == "Year Joined") sql += "JoinedLeague";

    qry->prepare(sql.c_str());
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}

void display_team::on_eastern_conf_Button_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName FROM GISdata WHERE Conference = 'Eastern'";
    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());

}

void display_team::on_western_conf_Button_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName FROM GISdata WHERE Conference = 'Western'";
    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}


void display_team::on_division_comboBox_activated(const QString &arg1)
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    std::string div = ui->division_comboBox->currentText().toStdString();

    std::string sqlAdd = " AND Division = '"+div+"'";
    qry->prepare((sql + sqlAdd).c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}


void display_team::on_combo_team_activated(const QString &arg1)
{

    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName, ArenaName, StadiumCapacity, Location, Conference, "
          "Division, JoinedLeague, Coach From GISdata WHERE TeamName = "
          "'"+ui->combo_team->currentText().toStdString()+"'";


    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

}

