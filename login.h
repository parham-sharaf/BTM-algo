#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>


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
          informationDb.setDatabaseName("/home/parham/Personal/School/Saddleback/2021 Fall/CS 1D/Project-2-CS1D/DB/GISdata.sqlite");

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

private:
    Ui::login *ui;
};

#endif // LOGIN_H
