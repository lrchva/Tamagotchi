QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Misc.cpp \
    animal.cpp \
    animalwindow.cpp \
    coinholder.cpp \
    inventory.cpp \
    main.cpp \
    mainwindow.cpp \
    shopwindow.cpp

HEADERS += \
    Misc.h \
    animal.h \
    animalwindow.h \
    coinholder.h \
    inventory.h \
    mainwindow.h \
    shopwindow.h

FORMS += \
    animalwindow.ui \
    mainwindow.ui \
    shopwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    release/Resources/Animals.json \
    release/Resources/Items.json \
    release/Resources/coinHolder.json \
    release/Resources/decreasers.json
