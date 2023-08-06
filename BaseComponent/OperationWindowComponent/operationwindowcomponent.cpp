#include "operationwindowcomponent.h"
#include <QVBoxLayout>

OperationWindowComponent::OperationWindowComponent()
{
    this->view = new OperationView();
    this->currentView = nullptr;

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
    if (widget == this->currentView)
    {
        return;
    }
    QVBoxLayout *layout = (QVBoxLayout *)this->view->layout();
    layout->addWidget(widget);
    if (this->currentView)
    {
        layout->removeWidget(this->currentView);
        this->currentView->setParent(nullptr);
    }
    this->currentView = widget;
}

/*==========================OperationService==========================*/
void OperationWindowComponent::switchOperationWindow(QWidget *widget)
{
    this->setCurrentView(widget);
    qDebug("switch window\n");
}

