#ifndef LOGCOMPONENT_H
#define LOGCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "Service/logservice.h"
#include "logview.h"

class LogComponent : public BaseComponent, public LogService
{
public:
    LogComponent();

private:
    void componentDidLoad();
    void registerService(ServiceManager *serviceManager);
    QWidget *componentWidget();
    void printfLog(QString &logStr);
    void printfLog(char *logStr);
    void printfLog(std::string logStr);
    LogView *view;
};

#endif // LOGCOMPONENT_H
