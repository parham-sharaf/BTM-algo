#include "edit_souvenirs.h"
#include "ui_edit_souvenirs.h"
#include <QtSql>
#include <QDebug>

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include "../login/login.h"
#include <iostream>

edit_souvenirs::edit_souvenirs(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::edit_souvenirs)
{
    ui->setupUi(this);

    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    qry->prepare("SELECT * from Souvenirs");
    qry->exec();

    ui->tableView->verticalHeader()->setHidden(true);
    modal->setQuery(*qry);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    QVector<QString> string;
    QString tempString;

    qry->prepare("SELECT DISTINCT TeamName FROM Souvenirs");
    qry->exec();

    while (qry->next())
    {

/*             string.append(qry->value(0).toString());

//          /*/  std::sort( string.begin(), string.end());
//            string.erase( std::unique( string.begin(), string.end() ), string.end() );
//            for(int i = 0; i < string.size(); i++ )
//            {
//                qDebug() << string[i] << endl;
//                ui->team_box2->addItem(string[i]);
//            }
        ui->team_box2->addItem(qry->value(0).toString());
        ui->team_box1->addItem(qry->value(0).toString());
    }

    connect(ui->team_box1, SIGNAL(currentTextChanged(const QString)), this, SLOT(on_team_box1_activated()));
    connect(ui->team_box2, SIGNAL(currentTextChanged(const QString)), this, SLOT(on_team_box2_activated()));
    connect(ui->delete_Button_2, SIGNAL(clicked()), this, SLOT(on_delete_Button_2_clicked()), Qt::UniqueConnection);
    connect(ui->delete_Button, SIGNAL(clicked()), this, SLOT(on_delete_Button_clicked()), Qt::UniqueConnection);
    connect(ui->add_Button, SIGNAL(clicked()), this, SLOT(on_add_Button_clicked()), Qt::UniqueConnection);

    //read from a database into a vector
    //display vector on combo box


}

edit_souvenirs::~edit_souvenirs()
{
    delete ui;
}

void edit_souvenirs::on_add_Button_clicked()
{
    login conn;

    QString team, souv, cost;
    souv =ui->add_souv_text->text();
    team =ui->add_team_txt->text();
    cost =ui->add_cost_txt->text();

    QDoubleValidator *priceVal = new QDoubleValidator(0,999,2,this);
    ui->add_cost_txt->setValidator(priceVal);
    if(cost.toDouble())
    {
        if(!conn.connOpen())
        {
            qDebug() << "Failed to Open the database";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("INSERT INTO Souvenirs(TeamName, SouvenirName,Price) values ('"+team+"','"+souv+"','"+cost+"')");
        if(qry.exec())
        {
            QMessageBox::critical(this,tr("Save"), tr("Saved"));
            qry.prepare("SELECT * from Souvenirs");
        }
        else
        {
            QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Invalid Cost Entry"), tr("Try Again"));
    }
}

void edit_souvenirs::on_edit_Button_clicked()
{
    login conn;

    QString souv, cost;

    souv =ui->edit_souv->text();
    cost =ui->edit_cost->text();

    QDoubleValidator *priceVal = new QDoubleValidator(0,999,2,this);
    ui->edit_cost->setValidator(priceVal);



    if(!conn.connOpen())
    {
        qDebug() << "Failed to Open the database";
        return;
    }
    if(cost.toDouble())
    {
        QSqlQuery qry ;
        qry.prepare("UPDATE Souvenirs SET Price = :Price WHERE TraditionalFoodItem = :SouvenirName");
        qry.bindValue(":Price",ui->edit_cost->text());
        qry.bindValue(":Souvenir",ui->edit_souv->text());
        if(qry.exec())
        {
            QMessageBox::critical(this,tr("Update"), tr("Updated"));
        }
        else
        {
            QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Invalid Cost Entry"), tr("Try Again"));
    }
}

void edit_souvenirs::on_delete_Button_clicked()
{
    login conn;
    QString deleteSouv;
    deleteSouv = ui->delete_souv->text();
    if(!conn.connOpen())
    {
        qDebug() << "Failed to Open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("DELETE FROM Souvenirs WHERE SouvenirName = '"+deleteSouv+"' AND TeamName IS '" + teamName + "'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
        qry.prepare("SELECT TeamName, SouvenirName, Price FROM Souvenirs");
    }
    else
    {
        QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
    }
}

void edit_souvenirs::on_load_Button_clicked()
{
    login conn;

    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    qry->prepare("SELECT * FROM Souvenirs");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    //conn.connClose();
}

void edit_souvenirs::on_team_box1_activated()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    teamName = ui->team_box1->currentText();
    qry->prepare("SELECT * FROM Souvenirs WHERE TeamName == '"+ teamName + "'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}


void edit_souvenirs::on_team_box2_activated()
{

    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    teamName = ui->team_box2->currentText();
    qry->prepare("SELECT * FROM Souvenirs WHERE TeamName == '"+ teamName + "'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}

void edit_souvenirs::on_delete_Button_2_clicked()
{
    login conn;

    QString souv, cost;

    souv =ui->edit_souv->text();
    cost =ui->edit_cost->text();

    QDoubleValidator *priceVal = new QDoubleValidator(0,999,2,this);
    ui->edit_cost->setValidator(priceVal);



    if(!conn.connOpen())
    {
        qDebug() << "Failed to Open the database";
        return;
    }
    if(cost.toDouble())
    {
        QSqlQuery qry ;
        qry.prepare("UPDATE Souvenirs SET Price = " + ui->edit_cost->text()
                    + " WHERE SouvenirName IS '" + ui->edit_souv->text() + "' AND TeamName IS +'"
                    + teamName + "'");

        if(qry.exec())
        {
            QMessageBox::critical(this,tr("Update"), tr("Updated"));
        }
        else
        {
            QMessageBox::critical(this,tr("Uh Oh"), tr("Error"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Invalid Cost Entry"), tr("Try Again"));
    }
}