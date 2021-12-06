#ifndef DISPLAY_PURCHASES_H
#define DISPLAY_PURCHASES_H

#include <QDialog>

namespace Ui {
class display_purchases;
}

class display_purchases : public QDialog
{
    Q_OBJECT

public:
    explicit display_purchases(QWidget *parent = nullptr);
    ~display_purchases();

private:
    Ui::display_purchases *ui;
};

#endif // DISPLAY_PURCHASES_H
