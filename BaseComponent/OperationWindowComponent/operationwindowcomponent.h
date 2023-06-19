#ifndef OPERATIONWINDOWCOMPONENT_H
#define OPERATIONWINDOWCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "operationview.h"
#include "Service/operationwindowservice.h"


class OperationWindowComponent : public BaseComponent, public OperationWindowService
{
public:
    OperationWindowComponent();

private:
    void registerService(ServiceManager *serviceManager);
    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();
    QWidget *componentWidget();

    void switchOperationWindow(QWidget *widget);

    void setCurrentView(QWidget *widget);

    OperationView *view;
    QWidget *currentView;
};

#endif // OPERATIONWINDOWCOMPONENT_H
