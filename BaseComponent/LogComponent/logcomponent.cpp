#include "logcomponent.h"
#include <string>

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

void LogComponent::printfLog(char *logStr)
{
    std::string str = logStr;
    QString qStr = QString::fromStdString(str);

    this->printfLog(qStr);
}

void LogComponent::printfLog(std::string logStr)
{
    QString qStr = QString::fromStdString(logStr);

    this->printfLog(qStr);
}
