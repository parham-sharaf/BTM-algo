#include "../login/login.h"
#include "../mainwindow/mainwindow.h"

#ifndef PURCHASE_SOUVENIRS_H
#define PURCHASE_SOUVENIRS_H
#include <QVector>
#include <QDialog>

namespace Ui {
class purchase_souvenirs;
}

class purchase_souvenirs : public QDialog
{
    Q_OBJECT

public:
    explicit purchase_souvenirs(QWidget *parent = nullptr);
    ~purchase_souvenirs();
    double grandTotal;
    double localTotal;
    int localNumSouv;

private slots:
    void on_purchase_souvenirs_2_clicked();
    void display_souvenirs();

    void on_next_team_clicked();

    void on_end_trip_clicked();
    void addToDatabase(QString teamName, QString souvenir, QString price, QString quantity);

    void on_pushButton_view_receipt_clicked();

private:
    Ui::purchase_souvenirs *ui;
    QVector<QString>teams;
};

#endif // PURCHASE_SOUVENIRS_H
