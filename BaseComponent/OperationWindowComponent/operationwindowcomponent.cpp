#include "operationwindowcomponent.h"

OperationWindowComponent::OperationWindowComponent()
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
