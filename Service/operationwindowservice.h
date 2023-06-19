#ifndef OPERATIONWINDOWSERVICE_H
#define OPERATIONWINDOWSERVICE_H

#include "baseservice.h"
#include <QWidget>

#define operationWindowServiceId "operationWindowServiceId"

class OperationWindowService : public BaseService
{
public:
    virtual void switchOperationWindow(QWidget *widget) = 0;
};

#endif // OPERATIONWINDOWSERVICE_H
