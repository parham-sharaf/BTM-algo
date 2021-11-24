#include "trip.h"
#include "ui_trip.h"
#include "../mainwindow/purchase_souvenirs.h"

trip::trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
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
