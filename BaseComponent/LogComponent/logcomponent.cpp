#include "logcomponent.h"

LogComponent::LogComponent()
{

}

void LogComponent::componentDidLoad()
{
    BaseComponent::componentDidLoad();
    qDebug("LogComponent Did Load\n");
    this->view = new LogView();
}

void LogComponent::registerService(ServiceManager *serviceManager)
{
    serviceManager->registerService(logServiceId, this);
}

QWidget *LogComponent::componentWidget()
{
    return this->view;
}

/*=====================LogService=====================*/
void LogComponent::printfLog(QString &logStr)
{
    this->view->addText(logStr);
}
