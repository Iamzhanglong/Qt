#ifndef LOGSERVICE_H
#define LOGSERVICE_H

#include "baseservice.h"
#include <QString>

#define logServiceId "logServiceId"

class LogService : public BaseService
{
public:
    virtual void printfLog(QString &logStr) = 0;
    virtual void printfLog(char *logStr) = 0;
    virtual void printfLog(std::string logStr) = 0;
};

#endif // LOGSERVICE_H
