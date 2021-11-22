#include "UI/mainwindow/mainwindow.h"
#include "manage_teams/manage_teams.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    manage_teams myTeams;
    myTeams.initialize();
    myTeams.minimum_spanning_tree();
    myTeams.shortest_path(15, 24);

}
