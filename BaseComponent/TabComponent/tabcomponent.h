#ifndef TABCOMPONENT_H
#define TABCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "tabview.h"
#include "Service/tabservice.h"
#include "Service/operationwindowservice.h"

class TabComponent : public BaseComponent, public TabService
{
    Q_OBJECT
public:
    TabComponent();
private:
    void registerService(ServiceManager *serviceManager);
    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();
    QWidget *componentWidget();
    void insertTab(QString tabId, QString tabTitle, QWidget *widget);

    TabView *view;
    QMap<QString, QWidget *> *tabMap;
    OperationWindowService *operationService;

public slots:
    void switchOperationWindow(QString tabId);

};

#endif // TABCOMPONENT_H
