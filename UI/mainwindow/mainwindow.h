#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../login/login.h"
#include "../display_team/display_team.h"
#include "../trip/trip.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Display_Teams_Button_clicked();

    void on_Trip_Button_clicked();

    void on_Login_Button_clicked();

private:
    Ui::MainWindow *ui;
    display_team *team;
    login *log;
    trip *trp;

};
#endif // MAINWINDOW_H
