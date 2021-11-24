#ifndef TRIP_H
#define TRIP_H

#include <QDialog>

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

private:
    Ui::trip *ui;
};

#endif // TRIP_H
