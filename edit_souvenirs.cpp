#include "edit_souvenirs.h"
#include "ui_edit_souvenirs.h"
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "login.h"

edit_souvenirs::edit_souvenirs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_souvenirs)
{
    ui->setupUi(this);

    login conn;

        QSqlQueryModel * modal=new QSqlQueryModel();

        conn.connOpen();
        QSqlQuery* qry=new QSqlQuery(conn.mydb);
        qry->prepare("Select * from souvenirs");
        qry->exec();

        ui->tableView->verticalHeader()->setHidden(true);
        modal->setQuery(*qry);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setModel(modal);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        QVector<QString> string;
        QString tempString;

        qry->prepare("Select distinct TeamName from souvenirs");
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
            qry.prepare("INSERT INTO souvenirs(TeamName, SouvernirName,Price) values ('"+team+"','"+souv+"','"+cost+"')");
            if(qry.exec())
            {
                QMessageBox::critical(this,tr("Save"), tr("Saved"));
                qry.prepare("select * from souvenirs");
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
             qry.prepare("UPDATE souvenirs SET Price = :Price WHERE TraditionalFoodItem = :SouvernirName");
             qry.bindValue(":Price",ui->edit_cost->text());
             qry.bindValue(":Souvernir",ui->edit_souv->text());
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
    qry.prepare("Delete from souvenirs where SouvernirName = '"+deleteSouv+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
        qry.prepare("select TeamName, SouvernirName, Price from souvenirs");
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
       QSqlQuery* qry=new QSqlQuery(conn.mydb);
       qry->prepare("select * from souvenirs");
       qry->exec();

       modal->setQuery(*qry);
       ui->tableView->setModel(modal);
       //conn.connClose();
}

void edit_souvenirs::on_team_box1_activated(const QString &arg1)
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    // QMessageBox::information(this, "Title", ui->combo_sort->currentText());
    if(ui->team_box1->currentText() == "Boston Celtics")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Boston Celtics'");
    }
    else if(ui->team_box1->currentText() == "Brooklyn Nets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Brooklyn Nets'");
    }
    else if(ui->team_box1->currentText() == "New York Knicks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'New York Knicks'");
    }
    else if(ui->team_box1->currentText() == "Philadelphia 76ers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Philadelphia 76ers'");
    }
    else if(ui->team_box1->currentText() == "Toronto Raptors")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Toronto Raptors'");
    }
    else if(ui->team_box1->currentText() == "Chicago Bulls")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Chicago Bulls'");
    }
    else if(ui->team_box1->currentText() == "Cleveland Cavaliers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Cleveland Cavaliers'");
    }
    else if(ui->team_box1->currentText() == "Detroit Pistons")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Detroit Pistons'");
    }
    else if(ui->team_box1->currentText() == "Indiana Pacers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Indiana Pacers'");
    }
    else if(ui->team_box1->currentText() == "Milwaukee Bucks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Milwaukee Bucks'");
    }
    else if(ui->team_box1->currentText() == "Atlanta Hawks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Atlanta Hawks'");
    }
    else if(ui->team_box1->currentText() == "Charlotte Hornets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Charlotte Hornets'");
    }
    else if(ui->team_box1->currentText() == "Miami Heat")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Miami Heat'");
    }
    else if(ui->team_box1->currentText() == "Orlando Magic")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Orlando Magic'");
    }
    else if(ui->team_box1->currentText() == "Washington Wizards")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Washington Wizards'");
    }
    else if(ui->team_box1->currentText() == "Denver Nuggets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Denver Nuggets'");
    }
    else if(ui->team_box1->currentText() == "Denver Nuggets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Denver Nuggets'");
    }
    else if(ui->team_box1->currentText() == "Minnesota Timberwolves")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Minnesota Timberwolves'");
    }
    else if(ui->team_box1->currentText() == "Oklahoma City Thunder")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Oklahoma City Thunder'");
    }
    else if(ui->team_box1->currentText() == "Portland Trail Blazers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Portland Trail Blazers'");
    }
    else if(ui->team_box1->currentText() == "Utah Jazz")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Utah Jazz'");
    }
    else if(ui->team_box1->currentText() == "Golden State Warriors")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Golden State Warriors'");
    }
    else if(ui->team_box1->currentText() == "Los Angeles Clippers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Los Angeles Clippers'");
    }
    else if(ui->team_box1->currentText() == "Los Angeles Lakers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Los Angeles Lakers'");
    }
    else if(ui->team_box1->currentText() == "Phoenix Suns")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Phoenix Suns'");
    }
    else if(ui->team_box1->currentText() == "Sacramento Kings")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Sacramento Kings'");
    }
    else if(ui->team_box1->currentText() == "Dallas Mavericks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Dallas Mavericks'");
    }
    else if(ui->team_box1->currentText() == "Houston Rockets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Houston Rockets'");
    }
    else if(ui->team_box1->currentText() == "Memphis Grizzlies")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Memphis Grizzlies'");
    }
    else if(ui->team_box1->currentText() == "New Orleans Pelicans")
    {
        qry->prepare("select * from souvenirs where TeamName == 'New Orleans Pelicans'");
    }
    else if(ui->team_box1->currentText() == "San Antonio Spurs")
    {
        qry->prepare("select * from souvenirs where TeamName == 'San Antonio Spurs'");
    }
    else
    {
         qry->prepare("select * from souvenirs where TeamName == 'Seattle Supersonics'");
    }

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());
}


void edit_souvenirs::on_team_box2_activated(const QString &arg1)
{

    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    // QMessageBox::information(this, "Title", ui->combo_sort->currentText());
    if(ui->team_box1->currentText() == "Boston Celtics")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Boston Celtics'");
    }
    else if(ui->team_box1->currentText() == "Brooklyn Nets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Brooklyn Nets'");
    }
    else if(ui->team_box1->currentText() == "New York Knicks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'New York Knicks'");
    }
    else if(ui->team_box1->currentText() == "Philadelphia 76ers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Philadelphia 76ers'");
    }
    else if(ui->team_box1->currentText() == "Toronto Raptors")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Toronto Raptors'");
    }
    else if(ui->team_box1->currentText() == "Chicago Bulls")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Chicago Bulls'");
    }
    else if(ui->team_box1->currentText() == "Cleveland Cavaliers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Cleveland Cavaliers'");
    }
    else if(ui->team_box1->currentText() == "Detroit Pistons")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Detroit Pistons'");
    }
    else if(ui->team_box1->currentText() == "Indiana Pacers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Indiana Pacers'");
    }
    else if(ui->team_box1->currentText() == "Milwaukee Bucks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Milwaukee Bucks'");
    }
    else if(ui->team_box1->currentText() == "Atlanta Hawks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Atlanta Hawks'");
    }
    else if(ui->team_box1->currentText() == "Charlotte Hornets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Charlotte Hornets'");
    }
    else if(ui->team_box1->currentText() == "Miami Heat")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Miami Heat'");
    }
    else if(ui->team_box1->currentText() == "Orlando Magic")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Orlando Magic'");
    }
    else if(ui->team_box1->currentText() == "Washington Wizards")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Washington Wizards'");
    }
    else if(ui->team_box1->currentText() == "Denver Nuggets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Denver Nuggets'");
    }
    else if(ui->team_box1->currentText() == "Denver Nuggets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Denver Nuggets'");
    }
    else if(ui->team_box1->currentText() == "Minnesota Timberwolves")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Minnesota Timberwolves'");
    }
    else if(ui->team_box1->currentText() == "Oklahoma City Thunder")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Oklahoma City Thunder'");
    }
    else if(ui->team_box1->currentText() == "Portland Trail Blazers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Portland Trail Blazers'");
    }
    else if(ui->team_box1->currentText() == "Utah Jazz")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Utah Jazz'");
    }
    else if(ui->team_box1->currentText() == "Golden State Warriors")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Golden State Warriors'");
    }
    else if(ui->team_box1->currentText() == "Los Angeles Clippers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Los Angeles Clippers'");
    }
    else if(ui->team_box1->currentText() == "Los Angeles Lakers")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Los Angeles Lakers'");
    }
    else if(ui->team_box1->currentText() == "Phoenix Suns")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Phoenix Suns'");
    }
    else if(ui->team_box1->currentText() == "Sacramento Kings")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Sacramento Kings'");
    }
    else if(ui->team_box1->currentText() == "Dallas Mavericks")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Dallas Mavericks'");
    }
    else if(ui->team_box1->currentText() == "Houston Rockets")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Houston Rockets'");
    }
    else if(ui->team_box1->currentText() == "Memphis Grizzlies")
    {
        qry->prepare("select * from souvenirs where TeamName == 'Memphis Grizzlies'");
    }
    else if(ui->team_box1->currentText() == "New Orleans Pelicans")
    {
        qry->prepare("select * from souvenirs where TeamName == 'New Orleans Pelicans'");
    }
    else if(ui->team_box1->currentText() == "San Antonio Spurs")
    {
        qry->prepare("select * from souvenirs where TeamName == 'San Antonio Spurs'");
    }
    else
    {
         qry->prepare("select * from souvenirs where TeamName == 'Seattle Supersonics'");
    }

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
             qry.prepare("UPDATE souvenirs SET Price = :Price WHERE SouvernirName = :SouvernirName");
             qry.bindValue(":Price",ui->edit_cost->text());
             qry.bindValue(":SouvernirName",ui->edit_souv->text());
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
