#-------------------------------------------------
#
# Project created by QtCreator 2023-06-15T22:11:59
#
#-------------------------------------------------

QT      += core gui
QT       += network
QT      += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo
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


SOURCES += \
    BizComponent/MCComponent/Models/sttracemodel.cpp \
        main.cpp \
        mainwindow.cpp \
    BaseComponent/TabComponent/tabcomponent.cpp \
    BaseComponent/TabComponent/tabmodel.cpp \
    BaseComponent/TabComponent/tabcontroller.cpp \
    BaseComponent/TabComponent/tabview.cpp \
    BaseComponent/BaseComponent/basecomponent.cpp \
    ComponentLoader/componentloader.cpp \
    LayoutManager/layoutmanager.cpp \
    BaseComponent/OperationWindowComponent/operationwindowcomponent.cpp \
    BaseComponent/LogComponent/logcomponent.cpp \
    BaseComponent/OperationWindowComponent/operationview.cpp \
    BaseComponent/LogComponent/logview.cpp \
    BizComponent/STComponent/Views/stview.cpp \
    BizComponent/STComponent/stcomponent.cpp \
    Service/baseservice.cpp \
    Service/servicemanager.cpp \
    BizComponent/STComponent/Views/stmenuview.cpp \
    BizComponent/STComponent/Views/stsettingview.cpp \
    BizComponent/STComponent/Views/stsignaltowerview.cpp \
    BizComponent/STComponent/stmodel.cpp \
    BizComponent/MCComponent/mccomponent.cpp \
    BizComponent/MCComponent/Views/mcview.cpp \
    BizComponent/MCComponent/mcmodel.cpp \
    BizComponent/MCComponent/Views/mccontrolview.cpp \
    BizComponent/MCComponent/Views/mctabview.cpp \
    BizComponent/MCComponent/Views/mctraceview.cpp

HEADERS += \
    BizComponent/MCComponent/Models/sttracemodel.h \
        mainwindow.h \
    BaseComponent/TabComponent/tabcomponent.h \
    BaseComponent/TabComponent/tabmodel.h \
    BaseComponent/TabComponent/tabcontroller.h \
    BaseComponent/TabComponent/tabview.h \
    BaseComponent/BaseComponent/basecomponent.h \
    ComponentLoader/componentloader.h \
    LayoutManager/layoutmanager.h \
    BaseComponent/OperationWindowComponent/operationwindowcomponent.h \
    BaseComponent/LogComponent/logcomponent.h \
    BaseComponent/OperationWindowComponent/operationview.h \
    BaseComponent/LogComponent/logview.h \
    BizComponent/STComponent/Views/stview.h \
    BizComponent/STComponent/stcomponent.h \
    Service/baseservice.h \
    Service/operationwindowservice.h \
    Service/servicemanager.h \
    Service/tabservice.h \
    BizComponent/STComponent/Views/stmenuview.h \
    BizComponent/STComponent/Views/stsettingview.h \
    BizComponent/STComponent/Views/stsignaltowerview.h \
    BizComponent/STComponent/stcomponentconst.h \
    BizComponent/STComponent/stmodel.h \
    Service/logservice.h \
    BizComponent/MCComponent/mccomponent.h \
    BizComponent/MCComponent/Views/mcview.h \
    BizComponent/MCComponent/mcmodel.h \
    BizComponent/MCComponent/Views/mccontrolview.h \
    BizComponent/MCComponent/Views/mctabview.h \
    BizComponent/MCComponent/Views/mctraceview.h

FORMS += \
        mainwindow.ui
