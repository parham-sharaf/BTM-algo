#include "edit_teams.h"
#include "ui_edit_teams.h"

#include <QtSql>
#include <QDebug>

#include <QFileInfo>
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include "../login/login.h"

edit_teams::edit_teams(QWidget *parent) : QDialog(parent), ui(new Ui::edit_teams)
{
    ui->setupUi(this);

    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    qry->prepare("Select TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach from GISdata");
    //qry->prepare("Select Conference, Division, TeamName, Location, Arena, JoinedLeague, Coach from GISdata");
    qry->exec();

    ui->tableView->verticalHeader()->setHidden(true);
    modal->setQuery(*qry);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Stuff for Ui Prettification
    QPixmap bkgnd("C://Users//ericj//Downloads//bball_lady.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

edit_teams::~edit_teams()
{
    delete ui;
}

void edit_teams::on_city_clicked()
{}

//void edit_teams::on_load_table_clicked()
//{
//    login obj;
//    QSqlQueryModel * model=new QSqlQueryModel();

//    QSqlQuery * qry=new QSqlQuery(obj.mydb);
//    qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GISdata");
//    qry->exec();
//    model->setQuery(*qry);
//    ui->tableView->setModel(model);
//}

void edit_teams::on_load_teams_button_clicked()
{
    QSqlQuery qry;
    QString notify;
    qry.prepare("insert into GISdata( TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach) values (:TeamName,:ArenaName,:Conference, :Division,:Location,:StadiumCapacity,:JoinedLeague,:Coach)");
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
    }

}

void edit_teams::on_load_table_button_clicked()
{
    login obj;
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery * qry=new QSqlQuery(obj.informationDb);

    qry->prepare("Select TeamName, ArenaName, Conference, Division, Location, StadiumCapacity, JoinedLeague, Coach from GISdata");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
}

void edit_teams::on_revert_changes_button_clicked()
{
    login obj;
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Delete from GISdata WHERE JoinedLeague = 2023");
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    }
    else
    {
        QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
    }
}
