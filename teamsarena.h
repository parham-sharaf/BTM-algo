#ifndef TEAMSARENA_H
#define TEAMSARENA_H

#include <QDialog>
#include <QDebug>
#include "login.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVector>

namespace Ui {
class teamsArena;
}

class teamsArena : public QDialog
{
    Q_OBJECT

public:
    explicit teamsArena(QWidget *parent = nullptr);
    ~teamsArena();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::teamsArena *ui;
    login l;
    QVector<QString> distinctTeams;
};

#endif // TEAMSARENA_H
