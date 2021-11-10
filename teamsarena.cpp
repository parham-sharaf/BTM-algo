#include "teamsarena.h"
#include "ui_teamsarena.h"

teamsArena::teamsArena(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teamsArena)
{
    ui->setupUi(this);
    distinctTeams.clear();
    l.connOpen();
    QSqlQuery qry;
    qry.exec("SELECT DISTINCT BeginningTeamName From GISdata;");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->comboBox->addItem(temp);
        distinctTeams.push_back(temp);
    }
}

teamsArena::~teamsArena()
{
    delete ui;
    l.connClose();

}

void teamsArena::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery qry;
    //get stadium
    qry.exec("SELECT DISTINCT BeginningArena From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->stadiumLabel->setText(temp);
    }

    //get capacity
    qry.exec("SELECT DISTINCT StadiumCapacity From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->capacityLabel->setText(temp);
    }

    //get location
    qry.exec("SELECT DISTINCT Location From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->locationLabel->setText(temp);
    }

    //get conference
    qry.exec("SELECT DISTINCT Conference From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->confrenceLabel->setText(temp);
    }

    //get division
    qry.exec("SELECT DISTINCT Division From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->divisionLabel->setText(temp);
    }
    //get join date
    qry.exec("SELECT DISTINCT JoinedLeague From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->joinedLabel->setText(temp);
    }
    //get coach
    qry.exec("SELECT DISTINCT Coach From GISdata where TeamName = '" + arg1 +"';");

    while(qry.next())
    {
        QString temp = qry.value(0).toString();
        ui->coachLabel->setText(temp);
    }
}

void teamsArena::on_pushButton_clicked()
{
    ui->listWidget->clear();
    for (int i = 0; i < distinctTeams.size(); i++)
    {
        QSqlQuery qry;
        qry.exec("SELECT DISTINCT BeginningArena From GISdata where TeamName = '" + distinctTeams[i]+"';");
        while(qry.next())
        {
            QString temp = qry.value(0).toString();
            ui->listWidget->addItem(distinctTeams[i] + " - " + temp);
        }
    }
}
