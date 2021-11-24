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
    std::cout << myTeams.depth_first_search(static_cast<manage_teams::Teams>(24)) << std::endl;
    std::cout << myTeams.breadth_first_search(static_cast<manage_teams::Teams>(24)) << std::endl;
    myTeams.shortest_path(24, 15);
    myTeams.minimum_spanning_tree();

}
