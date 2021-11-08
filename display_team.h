#ifndef DISPLAY_TEAM_H
#define DISPLAY_TEAM_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class display_team;
}

class display_team : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit display_team(QWidget *parent = nullptr);
    ~display_team();

private slots:
     void on_reload_button_clicked();

     void displayInfo(const QString &arg1);

private:
    Ui::display_team *ui;
};

#endif // DISPLAY_TEAM_H
