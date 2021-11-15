#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "edit_souvenirs.h"
#include "edit_teams.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_Edit_Teams_Button_clicked();

    void on_Edit_Souvenirs_Button_clicked();

private:
    Ui::admin *ui;
    edit_souvenirs *souv;
    edit_teams *team;
};

#endif // ADMIN_H
