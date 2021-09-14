#-------------------------------------------------
#
# Project created by QtCreator 2021-08-19T22:35:42
#
#-------------------------------------------------

QT       += core gui multimedia

CONFIG += resources_big


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = only_zoombie
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    zombie.cpp \
    zombie_basic.cpp \
    plant.cpp \
    plant_pea.cpp \
    weapon.cpp \
    weapon_pea.cpp \
    weapon_peasnow.cpp \
    messy.cpp \
    whacker.cpp \
    plant_chomper.cpp \
    plant_shield.cpp \
    box.cpp \
    lawn.cpp \
    box_chomper.cpp \
    box_peashooter.cpp \
    plant_groundattack.cpp \
    box_grounattack.cpp \
    box_sunflower.cpp \
    box_shield.cpp \
    box_cherrybomb.cpp \
    box_snowpea.cpp \
    sun_num.cpp \
    plant_peasnow.cpp \
    energy.cpp \
    sunner.cpp \
    plant_cherrybomb.cpp \
    zombie_bucket.cpp \
    zombie_block.cpp \
    zombie_jump.cpp

HEADERS += \
        mainwindow.h \
    zombie.h \
    zombie_basic.h \
    plant.h \
    plant_pea.h \
    weapon.h \
    weapon_pea.h \
    weapon_peasnow.h \
    messy.h \
    whacker.h \
    plant_chomper.h \
    plant_shield.h \
    box.h \
    lawn.h \
    box_chomper.h \
    box_peashooter.h \
    plant_groundattack.h \
    box_grounattack.h \
    box_sunflower.h \
    box_shield.h \
    box_cherrybomb.h \
    box_snowpea.h \
    sun_num.h \
    plant_peasnow.h \
    energy.h \
    sunner.h \
    plant_cherrybomb.h \
    zombie_bucket.h \
    zombie_block.h \
    zombie_jump.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
