#ifndef LAYOUTMANAGER_H
#define LAYOUTMANAGER_H

#include <QObject>
#include <QMap>
#include <QString>
#include "BaseComponent/BaseComponent/basecomponent.h"

#define TAB_COMPONENT                   "TAB_COMPONENT"
#define OPERATION_COMPONENT             "OPERATION_COMPONENT"
#define LOG_COMPONENT                   "LOG_COMPONENT"

class LayoutManager : public QObject
{
    Q_OBJECT
public:
    QWidget *mainWindow;

    explicit LayoutManager(QObject *parent = nullptr);
    void layoutBaseComponents(QMap<QString, BaseComponent *> *components);
private:


signals:

public slots:
};

#endif // LAYOUTMANAGER_H
