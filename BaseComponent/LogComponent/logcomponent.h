#ifndef LOGCOMPONENT_H
#define LOGCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "logview.h"

class LogComponent : public BaseComponent
{
public:
    LogComponent();

private:
    void componentDidLoad();
    QWidget *componentWidget();

    LogView *view;
};

#endif // LOGCOMPONENT_H
