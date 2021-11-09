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

    void on_combo_sort_activated(const QString &arg1);

    void on_eastern_conf_Button_clicked();

    void on_western_conf_Button_clicked();

    void on_division_comboBox_activated(const QString &arg1);

    void on_combo_team_activated(const QString &arg1);

private:
    Ui::display_team *ui;
    std::string sql;

};

#endif // DISPLAY_TEAM_H
