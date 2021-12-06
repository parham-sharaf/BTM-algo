#include "admin.h"
#include "ui_admin.h"
#include "../UI/edit_souvenirs/edit_souvenirs.h"
#include "../UI/edit_teams/edit_teams.h"

admin::admin(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::admin)
{
    ui->setupUi(this);
    // Stuff for Ui Prettification
    QPixmap bkgnd("C://Users//ericj//Downloads//bball_night.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

admin::~admin()
{
    delete ui;
}


void admin::on_Edit_Teams_Button_clicked()
{
    edit_teams team;
    team.setModal(true);
    team.exec();
}

void admin::on_Edit_Souvenirs_Button_clicked()
{
    edit_souvenirs souv;
    souv.setModal(true);
    souv.exec();
}
