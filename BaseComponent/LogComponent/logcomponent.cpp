#include "logcomponent.h"

LogComponent::LogComponent()
{

}

void LogComponent::componentDidLoad()
{
    BaseComponent::componentDidLoad();
    qDebug("LogComponent Did Load\n");
    this->view = new LogView();
    this->view->setStyleSheet("background-color:red;");
}


QWidget *LogComponent::componentWidget()
{
    return this->view;
}
