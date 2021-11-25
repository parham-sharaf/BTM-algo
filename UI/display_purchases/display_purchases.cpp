#include "display_purchases.h"
#include "ui_display_purchases.h"
#include "../login/login.h"

display_purchases::display_purchases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display_purchases)
{
    ui->setupUi(this);

    login conn;
    conn.connOpen();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Total Spent"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("# of souvenirs"));

    qry->prepare("Select totalTeam, totalSpent, totalSouv from Purchases");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_receipt->setModel(modal);


    ui->tableView_receipt->verticalHeader()->setHidden(true);
    ui->tableView_receipt->resizeColumnsToContents();
    ui->tableView_receipt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    conn.connClose();
}

display_purchases::~display_purchases()
{
    delete ui;
}
