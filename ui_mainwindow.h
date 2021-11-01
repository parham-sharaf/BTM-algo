/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Display_Teams_Button;
    QPushButton *pushButton_2;
    QPushButton *Login_Button;
    QPushButton *Trip_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Display_Teams_Button = new QPushButton(centralwidget);
        Display_Teams_Button->setObjectName(QString::fromUtf8("Display_Teams_Button"));
        Display_Teams_Button->setGeometry(QRect(310, 190, 171, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 240, 171, 28));
        Login_Button = new QPushButton(centralwidget);
        Login_Button->setObjectName(QString::fromUtf8("Login_Button"));
        Login_Button->setGeometry(QRect(300, 480, 171, 28));
        Trip_Button = new QPushButton(centralwidget);
        Trip_Button->setObjectName(QString::fromUtf8("Trip_Button"));
        Trip_Button->setGeometry(QRect(310, 320, 171, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Display_Teams_Button->setText(QCoreApplication::translate("MainWindow", "Display Teams", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Display Something Else", nullptr));
        Login_Button->setText(QCoreApplication::translate("MainWindow", "Admin Login", nullptr));
        Trip_Button->setText(QCoreApplication::translate("MainWindow", "Take Yo Trip ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
