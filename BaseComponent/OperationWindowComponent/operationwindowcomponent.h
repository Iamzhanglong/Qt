#ifndef OPERATIONWINDOWCOMPONENT_H
#define OPERATIONWINDOWCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "operationview.h"


class OperationWindowComponent : public BaseComponent
{
public:
    OperationWindowComponent();

private:
    void componentDidLoad();
    QWidget *componentWidget();

    OperationView *view;
};

#endif // OPERATIONWINDOWCOMPONENT_H
