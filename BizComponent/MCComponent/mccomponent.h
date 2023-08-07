#ifndef MCCOMPONENT_H
#define MCCOMPONENT_H

#include "BizComponent/MCComponent/Views/mcview.h"
#include "BaseComponent/BaseComponent/basecomponent.h"
#include "Service/tabservice.h"
#include "Service/logservice.h"
#include "BizComponent/MCComponent/Models/sttracemodel.h"
#include "BizComponent/MCComponent/Models/mcmodel.h"

class MCComponent : public BaseComponent
{
    Q_OBJECT
public:
    MCComponent();
    virtual ~MCComponent();

private:
    MCModel *mcModel;
    STTraceModel *traceModel;

    TabService *tabService;
    LogService *logService;
    MCView *view;

    void injectService(ServiceManager *serviceManager);
    void componentDidLoad();
    void bind();
};

#endif // MCCOMPONENT_H
