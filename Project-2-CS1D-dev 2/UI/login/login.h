#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
#include "../../Admin/admin.h"

namespace Ui
{
    class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase informationDb;
    QSqlDatabase distancesDb;

      void connClose()
      {
          informationDb.close();
      }
      bool connOpen()
      {
          informationDb=QSqlDatabase::addDatabase("QSQLITE");

          // PUT IN YOUR OWN FILE PATH!
          informationDb.setDatabaseName("/Users/taliabearup/Desktop/GISdataNEW.sqlite");

          if(!informationDb.open())
          {
              qDebug() << "Failed to open the database";
                 return false;
          }
          else
          {
              qDebug() << "Connected to database";
              return true;
          }
      }

    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    /**
     * @brief on_pushButton_Login_clicked ensures correct login
     * and opens admin screen
     */
    void on_pushButton_Login_clicked();

private:
    Ui::login *ui;
    admin *ad;
};

#endif // LOGIN_H
