#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <QObject>
#include <QWidget>
#include "Service/servicemanager.h"

class BaseComponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseComponent(QObject *parent = nullptr);
    virtual void registerService(ServiceManager *serviceManager);
    virtual void injectService(ServiceManager *serviceManager);
    virtual void componentDidLoad();
    virtual QWidget *componentWidget();
signals:

public slots:
};

#endif // BASECOMPONENT_H
