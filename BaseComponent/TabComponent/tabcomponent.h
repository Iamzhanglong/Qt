#ifndef TABCOMPONENT_H
#define TABCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "tabview.h"
#include "Service/tabservice.h"

class TabComponent : public BaseComponent, public TabService
{
public:
    TabComponent();
private:
    void registerService(ServiceManager *serviceManager);
    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();
    QWidget *componentWidget();
    void insertTab(QString title);

    TabView *view;
};

#endif // TABCOMPONENT_H
