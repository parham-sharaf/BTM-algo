/********************************************************************************
** Form generated from reading UI file 'display_team.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_TEAM_H
#define UI_DISPLAY_TEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_display_team
{
public:
    QPushButton *push_souvenirs;
    QLabel *label_sort;
    QLabel *label_dbstatus;
    QComboBox *combo_team;
    QPushButton *Ami_League_Button;
    QComboBox *combo_sort;
    QPushButton *reload_button;
    QLabel *label_logo;
    QFrame *line;
    QPushButton *Nat_Leagu_Button;
    QPushButton *push_plan;
    QComboBox *combo_sort_2;
    QLabel *label_sort_2;
    QTableView *tableView;

    void setupUi(QDialog *display_team)
    {
        if (display_team->objectName().isEmpty())
            display_team->setObjectName(QString::fromUtf8("display_team"));
        display_team->resize(1223, 664);
        push_souvenirs = new QPushButton(display_team);
        push_souvenirs->setObjectName(QString::fromUtf8("push_souvenirs"));
        push_souvenirs->setGeometry(QRect(120, 550, 91, 31));
        QFont font;
        font.setPointSize(12);
        push_souvenirs->setFont(font);
        label_sort = new QLabel(display_team);
        label_sort->setObjectName(QString::fromUtf8("label_sort"));
        label_sort->setGeometry(QRect(20, 220, 71, 20));
        QFont font1;
        font1.setPointSize(10);
        label_sort->setFont(font1);
        label_dbstatus = new QLabel(display_team);
        label_dbstatus->setObjectName(QString::fromUtf8("label_dbstatus"));
        label_dbstatus->setGeometry(QRect(20, 460, 191, 20));
        combo_team = new QComboBox(display_team);
        combo_team->addItem(QString());
        combo_team->setObjectName(QString::fromUtf8("combo_team"));
        combo_team->setGeometry(QRect(20, 500, 191, 41));
        Ami_League_Button = new QPushButton(display_team);
        Ami_League_Button->setObjectName(QString::fromUtf8("Ami_League_Button"));
        Ami_League_Button->setGeometry(QRect(20, 350, 131, 28));
        combo_sort = new QComboBox(display_team);
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->setObjectName(QString::fromUtf8("combo_sort"));
        combo_sort->setGeometry(QRect(20, 240, 191, 31));
        reload_button = new QPushButton(display_team);
        reload_button->setObjectName(QString::fromUtf8("reload_button"));
        reload_button->setGeometry(QRect(1020, 590, 93, 28));
        label_logo = new QLabel(display_team);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(20, 30, 191, 191));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/resources/logo.png")));
        label_logo->setScaledContents(true);
        line = new QFrame(display_team);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 470, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Nat_Leagu_Button = new QPushButton(display_team);
        Nat_Leagu_Button->setObjectName(QString::fromUtf8("Nat_Leagu_Button"));
        Nat_Leagu_Button->setGeometry(QRect(20, 380, 131, 28));
        push_plan = new QPushButton(display_team);
        push_plan->setObjectName(QString::fromUtf8("push_plan"));
        push_plan->setGeometry(QRect(20, 550, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        push_plan->setFont(font2);
        combo_sort_2 = new QComboBox(display_team);
        combo_sort_2->addItem(QString());
        combo_sort_2->addItem(QString());
        combo_sort_2->addItem(QString());
        combo_sort_2->addItem(QString());
        combo_sort_2->addItem(QString());
        combo_sort_2->addItem(QString());
        combo_sort_2->setObjectName(QString::fromUtf8("combo_sort_2"));
        combo_sort_2->setGeometry(QRect(20, 320, 191, 31));
        label_sort_2 = new QLabel(display_team);
        label_sort_2->setObjectName(QString::fromUtf8("label_sort_2"));
        label_sort_2->setGeometry(QRect(20, 300, 81, 20));
        label_sort_2->setFont(font1);
        tableView = new QTableView(display_team);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(290, 60, 831, 511));

        retranslateUi(display_team);

        QMetaObject::connectSlotsByName(display_team);
    } // setupUi

    void retranslateUi(QDialog *display_team)
    {
        display_team->setWindowTitle(QCoreApplication::translate("display_team", "Dialog", nullptr));
        push_souvenirs->setText(QCoreApplication::translate("display_team", "Souvenirs", nullptr));
        label_sort->setText(QCoreApplication::translate("display_team", "Sort By:", nullptr));
        label_dbstatus->setText(QCoreApplication::translate("display_team", "status :)", nullptr));
        combo_team->setItemText(0, QCoreApplication::translate("display_team", "Select Team", nullptr));

        Ami_League_Button->setText(QCoreApplication::translate("display_team", "Eastern Conference", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("display_team", "Team Name", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("display_team", "Arena Name", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("display_team", "Capacity", nullptr));
        combo_sort->setItemText(3, QCoreApplication::translate("display_team", "Year Joined", nullptr));

        reload_button->setText(QCoreApplication::translate("display_team", "Reload Table", nullptr));
        label_logo->setText(QString());
        Nat_Leagu_Button->setText(QCoreApplication::translate("display_team", "Western Conference ", nullptr));
        push_plan->setText(QCoreApplication::translate("display_team", "Trip", nullptr));
        combo_sort_2->setItemText(0, QCoreApplication::translate("display_team", "Atlantic", nullptr));
        combo_sort_2->setItemText(1, QCoreApplication::translate("display_team", "Central", nullptr));
        combo_sort_2->setItemText(2, QCoreApplication::translate("display_team", "Southeast", nullptr));
        combo_sort_2->setItemText(3, QCoreApplication::translate("display_team", "Northwest", nullptr));
        combo_sort_2->setItemText(4, QCoreApplication::translate("display_team", "Pacific", nullptr));
        combo_sort_2->setItemText(5, QCoreApplication::translate("display_team", "Southwest", nullptr));

        label_sort_2->setText(QCoreApplication::translate("display_team", "Filter By:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class display_team: public Ui_display_team {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_TEAM_H
