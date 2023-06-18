#ifndef TABCOMPONENT_H
#define TABCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "tabview.h"

class TabComponent : public BaseComponent
{
public:
    TabComponent();
private:
    void componentDidLoad();
    QWidget *componentWidget();

    TabView *view;
};

#endif // TABCOMPONENT_H
