#ifndef EDIT_SOUVENIRS_H
#define EDIT_SOUVENIRS_H

#include <QDialog>

namespace Ui {
class edit_souvenirs;
}

class edit_souvenirs : public QDialog
{
    Q_OBJECT

public:
    explicit edit_souvenirs(QWidget *parent = nullptr);
    ~edit_souvenirs();

private slots:
    void on_add_Button_clicked();

    void on_edit_Button_clicked();

    void on_delete_Button_clicked();

    void on_load_Button_clicked();

    void on_team_box1_activated(const QString &arg1);

    void on_team_box2_activated(const QString &arg1);

    void on_delete_Button_2_clicked();

private:
    Ui::edit_souvenirs *ui;
};

#endif // EDIT_SOUVENIRS_H
