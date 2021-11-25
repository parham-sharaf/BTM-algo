#ifndef TRIP_H
#define TRIP_H

#include <QDialog>
#include "../../manage_teams/manage_teams.h"

namespace Ui {
    class trip;
}

class trip : public QDialog
{
Q_OBJECT

public:
    explicit trip(QWidget *parent = nullptr);
    ~trip();

private slots:
    void on_pushButton_clicked();

    void on_dfs_pushButton_clicked();
    void on_bfs_pushButton_clicked();
    void on_mst_button_clicked();

private:
    Ui::trip *ui;
    manage_teams myTeams;
};

#endif // TRIP_H