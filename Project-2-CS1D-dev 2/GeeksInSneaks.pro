QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UI/mainwindow/display_purchases.cpp \
    UI/mainwindow/purchase_souvenirs.cpp \
    db.cpp \
    UI/display_team/display_team.cpp \
    UI/edit_souvenirs/edit_souvenirs.cpp \
    UI/edit_teams/edit_teams.cpp \
    UI/login/login.cpp \
    main.cpp \
    UI/mainwindow/mainwindow.cpp \
    UI/trip/trip.cpp \
    Admin/admin.cpp
    #manage_teams/manage_teams.cpp


HEADERS += \
    UI/mainwindow/display_purchases.h \
    UI/mainwindow/purchase_souvenirs.h \
    db.h \
    UI/display_team/display_team.h \
    UI/login/login.h \
    UI/mainwindow/mainwindow.h \
    UI/trip/trip.h \
    UI/edit_souvenirs/edit_souvenirs.h \
    UI/edit_teams/edit_teams.h \
    #manage_teams/manage_teams.h \
    Admin/admin.h

FORMS += \
    UI/display_team/display_team.ui \
    UI/mainwindow/display_purchases.ui \
    UI/mainwindow/mainwindow.ui \
    UI/mainwindow/purchase_souvenirs.ui \
    UI/trip/trip.ui \
    UI/login/login.ui \
    UI/edit_souvenirs/edit_souvenirs.ui \
    UI/display_team/display_team.ui \
    UI/edit_teams/edit_teams.ui \
    Admin/admin.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
