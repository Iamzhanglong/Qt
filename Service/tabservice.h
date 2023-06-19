#ifndef TABSERVICE_H
#define TABSERVICE_H

#include "baseservice.h"
#include <QString>

#define tabServiceId "tabServiceId"

class TabService : public BaseService
{
public:
    virtual void insertTab(QString title) = 0;
};

#endif // TABSERVICE_H
