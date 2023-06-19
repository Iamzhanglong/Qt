#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QObject>
#include <QMap>
#include <QString>
#include "Service/baseservice.h"

class ServiceManager : public QObject
{
    Q_OBJECT
public:
    explicit ServiceManager(QObject *parent = nullptr);
    void registerService(QString serviceId, BaseService *service);
    BaseService *getService(QString serviceId);
private:
    QMap<QString, BaseService *> *serviceMap;

signals:

};

#endif // SERVICEMANAGER_H
