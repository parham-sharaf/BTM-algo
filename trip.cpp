#include "trip.h"
#include "ui_trip.h"

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
