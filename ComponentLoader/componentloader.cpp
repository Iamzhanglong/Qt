#include "componentloader.h"

#include "BaseComponent/TabComponent/tabcomponent.h"
#include "BaseComponent/OperationWindowComponent/operationwindowcomponent.h"
#include "BaseComponent/LogComponent/logcomponent.h"
#include "BizComponent/STComponent/stcomponent.h"
#include "BizComponent/MCComponent/mccomponent.h"

ComponentLoader::ComponentLoader(QObject *parent) : QObject(parent)
{
    this->serviceManager = new ServiceManager();

    createBaseComponents();
    createBizComponents();
}

void ComponentLoader::createBaseComponents()
{
    this->baseComponents = new QMap<QString, BaseComponent *>();

    TabComponent *tabComponent = new TabComponent();
    baseComponents->insert(TAB_COMPONENT, tabComponent);

    OperationWindowComponent *operationComponent = new OperationWindowComponent();
    baseComponents->insert(OPERATION_COMPONENT, operationComponent);

    LogComponent *logComponent = new LogComponent();
    baseComponents->insert(LOG_COMPONENT, logComponent);
}

void ComponentLoader::createBizComponents()
{
    this->bizComponents = new QVector<BaseComponent *>();

    STComponent *st = new STComponent();
    bizComponents->append(st);

    MCComponent *mc = new MCComponent();
    bizComponents->append(mc);
}

void ComponentLoader::loadComponents()
{
    loadBaseComponents();
    loadBizComponents();
}

void ComponentLoader::loadBaseComponents()
{
    QMap<QString, BaseComponent *>::iterator iter;

    for (iter = this->baseComponents->begin(); iter != this->baseComponents->end(); iter++)
    {
        (*iter)->registerService(this->serviceManager);
    }

    for (iter = this->baseComponents->begin(); iter != this->baseComponents->end(); iter++)
    {
        (*iter)->injectService(this->serviceManager);
    }

    for (iter = this->baseComponents->begin(); iter != this->baseComponents->end(); iter++)
    {
        (*iter)->componentDidLoad();
    }

    this->layoutManager->layoutBaseComponents(this->baseComponents);
}

void ComponentLoader::loadBizComponents()
{
    QVector<BaseComponent *>::iterator iter;

    for (iter = this->bizComponents->begin(); iter != this->bizComponents->end(); iter++)
    {
        (*iter)->registerService(this->serviceManager);
    }

    for (iter = this->bizComponents->begin(); iter != this->bizComponents->end(); iter++)
    {
        (*iter)->injectService(this->serviceManager);
    }

    for (iter = this->bizComponents->begin(); iter != this->bizComponents->end(); iter++)
    {
        (*iter)->componentDidLoad();
    }
}
