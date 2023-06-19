#ifndef STCOMPONENT_H
#define STCOMPONENT_H

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "Service/tabservice.h"

class STComponent : public BaseComponent
{
public:
    STComponent();
private:
    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();

    TabService *tabService;
};

#endif // STCOMPONENT_H
