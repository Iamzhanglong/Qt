#include "operationwindowcomponent.h"

OperationWindowComponent::OperationWindowComponent()
{

}

void OperationWindowComponent::registerService(ServiceManager *serviceManager)
{
    serviceManager->registerService(operationWindowServiceId, this);
}

void OperationWindowComponent::injectService(ServiceManager *serviceManager)
{

}

void OperationWindowComponent::componentDidLoad()
{
    BaseComponent::componentDidLoad();
    qDebug("OperationWindowComponent Did Load\n");
    this->view = new OperationView();
    this->view->setStyleSheet("background-color:green;");
}


QWidget *OperationWindowComponent::componentWidget()
{
    return this->view;
}

void OperationWindowComponent::setCurrentView(QWidget *widget)
{
    this->currentView = widget;
}

/*==========================OperationService==========================*/
void OperationWindowComponent::switchOperationWindow(QWidget *widget)
{
    this->setCurrentView(widget);
    qDebug("switch window\n");
}

