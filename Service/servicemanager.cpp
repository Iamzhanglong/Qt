#include "servicemanager.h"

ServiceManager::ServiceManager(QObject *parent) : QObject(parent)
{
    this->serviceMap = new QMap<QString, BaseService *>();
}

void ServiceManager::registerService(QString serviceId, BaseService *service)
{
    this->serviceMap->insert(serviceId, service);
}

BaseService *ServiceManager::getService(QString serviceId)
{
    return this->serviceMap->value(serviceId);
}
