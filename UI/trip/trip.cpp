#include "trip.h"
#include "ui_trip.h"
#include "../purchase_souvenirs/purchase_souvenirs.h"
#include "../login/login.h"
#include <iostream>
#include <string>

trip::trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
    myTeams.initialize();

    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    qry->prepare("SELECT DISTINCT BeginningTeamName FROM Distances");
    qry->exec();

    while (qry->next())
    {
        ui->dfs_comboBox->addItem(qry->value(0).toString());
        ui->bfs_comboBox->addItem(qry->value(0).toString());
    }

    connect(ui->dfs_pushButton, SIGNAL(clicked()), this, SLOT(on_dfs_pushButton_clicked()), Qt::UniqueConnection);
    connect(ui->bfs_pushButton, SIGNAL(clicked()), this, SLOT(on_bfs_pushButton_clicked()), Qt::UniqueConnection);

}

trip::~trip()
{
    delete ui;
}

void trip::on_pushButton_clicked()
{
    purchase_souvenirs souvenir;
    souvenir.setModal(true);
    souvenir.exec();
}

void trip::on_dfs_pushButton_clicked()
{
    double distance;
    distance = myTeams.depth_first_search(static_cast<manage_teams::Teams>(ui->dfs_comboBox->currentIndex()));
    ui->dfs_distance->setText(QString::number(distance));

    std::cout << "total distance: " << distance << std::endl;
}


void trip::on_bfs_pushButton_clicked()
{
    double distance;
    distance = myTeams.breadth_first_search(static_cast<manage_teams::Teams>(ui->bfs_comboBox->currentIndex()));
    ui->bfs_distance->setText(QString::number(distance));
    std::cout << "total distance: " << distance << std::endl;
}


void trip::on_mst_button_clicked()
{
    double distance;
    distance = myTeams.minimum_spanning_tree();
    ui->mst_distance->setText(QString::number(distance));

}

