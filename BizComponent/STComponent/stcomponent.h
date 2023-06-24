#ifndef STCOMPONENT_H
#define STCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "Service/tabservice.h"
#include "BizComponent/STComponent/Views/stview.h"
#include "BizComponent/STComponent/stmodel.h"

class STComponent : public BaseComponent
{
public:
    STComponent();
private:
    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();

    TabService *tabService;
    STView *view;
    STModel *stModel;

    void bind();
};

#endif // STCOMPONENT_H
