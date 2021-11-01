/********************************************************************************
** Form generated from reading UI file 'trip.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIP_H
#define UI_TRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_trip
{
public:

    void setupUi(QDialog *trip)
    {
        if (trip->objectName().isEmpty())
            trip->setObjectName(QString::fromUtf8("trip"));
        trip->resize(400, 300);

        retranslateUi(trip);

        QMetaObject::connectSlotsByName(trip);
    } // setupUi

    void retranslateUi(QDialog *trip)
    {
        trip->setWindowTitle(QCoreApplication::translate("trip", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trip: public Ui_trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H
