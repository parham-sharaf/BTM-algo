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
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->showMaximized();

    login conn;

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    qry->prepare("SELECT COUNT(*) FROM GeneralInfo");
    qry->exec();
    int teamCount;
    if (qry->next()) teamCount = qry->value(0).toInt();
    myTeams.initialize();

    if (teamCount > 30) {
        pix.load("/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/Project-2-CS1D/images/added.png");
        scene->addPixmap(pix);
        myTeams.addNewVertex();
//        QTreeWidgetItem* newTeam = new QTreeWidgetItem();
//        newTeam->setText(0, "Seattle Supersonics");
//        newTeam->setCheckState(0, Qt::Unchecked);
//        connect(ui->teamsTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)), Qt::UniqueConnection);
//        ui->teamsTreeWidget->addTopLevelItem(newTeam);
    }
    else {
        pix.load("/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/Project-2-CS1D/images/original.png");
        scene->addPixmap(pix);
    }

    QSqlQueryModel * modal = new QSqlQueryModel();

    qry = new QSqlQuery(conn.informationDb);

    qry->prepare("SELECT DISTINCT BeginningTeamName FROM Distances");
    qry->exec();

    while (qry->next())
    {
        ui->dfs_comboBox->addItem(qry->value(0).toString());
        ui->bfs_comboBox->addItem(qry->value(0).toString());
    }

    connect(ui->dfs_pushButton, SIGNAL(clicked()), this, SLOT(on_dfs_pushButton_clicked()), Qt::UniqueConnection);
    connect(ui->bfs_pushButton, SIGNAL(clicked()), this, SLOT(on_bfs_pushButton_clicked()), Qt::UniqueConnection);
    connect(ui->done_pushButton, SIGNAL(clicked()), this, SLOT(on_done_pushButton_clicked()), Qt::UniqueConnection);
    connect(ui->clear_pushButton, SIGNAL(clicked()), this, SLOT(on_clear_pushButton_clicked()), Qt::UniqueConnection);

    for (const auto& team: myTeams.getTeamNames()) {
        QTreeWidgetItem* newTeam = new QTreeWidgetItem();
        newTeam->setText(0, team.c_str());
        newTeam->setCheckState(0, Qt::Unchecked);
        connect(ui->teamsTreeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)), Qt::UniqueConnection);
        ui->teamsTreeWidget->addTopLevelItem(newTeam);
    }

    isInOrder = false;
    conn.close();
}

trip::~trip()
{
    delete ui;
}

void trip::on_pushButton_clicked()
{
    purchase_souvenirs souvenir(myTeams.getTravelPlan());
//    souvenir.setPlan(myTeams.getTravelPlan());
    souvenir.setModal(true);
    souvenir.exec();
}

void trip::on_dfs_pushButton_clicked()
{
    double distance;
    distance = myTeams.depth_first_search(static_cast<manage_teams::Teams>(ui->dfs_comboBox->currentIndex()));
    ui->total_distance_label->setText(QString::number(distance));

    std::cout << "total distance: " << distance << std::endl;
}


void trip::on_bfs_pushButton_clicked()
{
    double distance;
    distance = myTeams.breadth_first_search(static_cast<manage_teams::Teams>(ui->bfs_comboBox->currentIndex()));
    ui->total_distance_label->setText(QString::number(distance));
    std::cout << "total distance: " << distance << std::endl;
}


void trip::on_mst_button_clicked()
{
    double distance;
    distance = myTeams.minimum_spanning_tree();
    ui->total_distance_label->setText(QString::number(distance));

}

void trip::itemChanged(QTreeWidgetItem* item, int col) {
    if (item->checkState(0) == Qt::Checked){
        selectedTeams.push_back(item->text(0).toStdString());
        item->setCheckState(col, Qt::Checked);
    }
    else {
        for (int i = 0; i < selectedTeams.size(); i++) {
            if (selectedTeams[i] == item->text(0).toStdString()) {
                selectedTeams.erase(selectedTeams.begin() + i);
            }
        }
    }
}


void trip::on_displayButton_clicked()
{
    ui->teamsList->clear();
    for (const auto& item: myTeams.getTravelPlan()) {
        ui->teamsList->addItem(QString::fromStdString(item.team));
    }
}


void trip::on_done_pushButton_clicked()
{
    double distance;
    distance = myTeams.createCustomPlan(selectedTeams, isInOrder);
    ui->total_distance_label->setText(QString::number(distance));
}


void trip::on_order_radioButton_clicked()
{
    isInOrder = !isInOrder;
}


void trip::on_clear_pushButton_clicked()
{
    ui->total_distance_label->setText("0.00");
    QTreeWidgetItemIterator it(ui->teamsTreeWidget);
    while (*it) {
        (*it)->setCheckState(0, Qt::Unchecked);
        ++it;
    }

    isInOrder = false;
    ui->order_radioButton->setChecked(false);
}

