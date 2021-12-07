#ifndef TRIP_H
#define TRIP_H

#include <QDialog>
#include "../../manage_teams/manage_teams.h"
#include "../../map/map.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QCheckBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <deque>


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
    void itemChanged(QTreeWidgetItem*, int);

    void on_displayButton_clicked();

    void on_done_pushButton_clicked();

    void on_order_radioButton_clicked();

    void on_clear_pushButton_clicked();

private:
    Ui::trip *ui;
    manage_teams myTeams;
    QGraphicsScene *scene;
    QPixmap pix;
    std::vector<std::string> selectedTeams;
    bool isInOrder;

};

#endif // TRIP_H
