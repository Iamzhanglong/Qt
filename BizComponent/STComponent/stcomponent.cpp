#include "stcomponent.h"

STComponent::STComponent()
{
    this->view = new STView();
}

void STComponent::injectService(ServiceManager *serviceManager)
{
    this->tabService = (TabService *)serviceManager->getService(tabServiceId);
}

void STComponent::componentDidLoad()
{
    this->tabService->insertTab(stTabId, "ST", this->view);
}
