#include "operationwindowcomponent.h"
#include <QVBoxLayout>

OperationWindowComponent::OperationWindowComponent()
{
    this->view = new OperationView();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    this->view->setLayout(layout);
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
}


QWidget *OperationWindowComponent::componentWidget()
{
    return this->view;
}

void OperationWindowComponent::setCurrentView(QWidget *widget)
{
    QVBoxLayout *layout = (QVBoxLayout *)this->view->layout();
    layout->removeWidget(this->currentView);
    layout->addWidget(widget);
    this->currentView = widget;
}

/*==========================OperationService==========================*/
void OperationWindowComponent::switchOperationWindow(QWidget *widget)
{
    this->setCurrentView(widget);
    qDebug("switch window\n");
}

