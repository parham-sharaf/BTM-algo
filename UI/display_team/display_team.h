#ifndef DISPLAY_TEAM_H
#define DISPLAY_TEAM_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <string>
#include <vector>
#include "../login/login.h"


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

    void on_combo_sort_activated(const QString &arg1);

    void on_push_souvenirs_clicked();

    void on_eastern_conf_Button_clicked();

    void on_western_conf_Button_clicked();

    void on_division_comboBox_activated(const QString &arg1);

    void on_combo_team_activated(const QString &arg1);
    
    void on_clear_plan_clicked();

    void on_team_name_checkBox_state_changed();
    void on_arena_checkBox_state_changed();
    void on_capacity_checkBox_state_changed();
    void on_year_checkBox_state_changed();
    void on_coach_checkBox_state_changed();

private:
    Ui::display_team *ui;
    std::string sql;
    std::vector<std::string> headers;

};

#endif // DISPLAY_TEAM_H
