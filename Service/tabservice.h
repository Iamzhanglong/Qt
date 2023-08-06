#ifndef TABSERVICE_H
#define TABSERVICE_H

#include "baseservice.h"
#include <QString>
#include <QWidget>

#define tabServiceId "tabServiceId"

#define stTabId "stTabId"
#define mcTabId "mcTabId"

class TabService : public BaseService
{
public:
    virtual void insertTab(QString tabId, QString tabTitle, QWidget *widget) = 0;
};

#endif // TABSERVICE_H
