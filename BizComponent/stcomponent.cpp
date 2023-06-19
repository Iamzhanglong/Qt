#include "stcomponent.h"

STComponent::STComponent()
{

}

void STComponent::injectService(ServiceManager *serviceManager)
{
    this->tabService = (TabService *)serviceManager->getService(tabServiceId);
}

void STComponent::componentDidLoad()
{
    QWidget *widget = new QWidget();
    this->tabService->insertTab(stTabId, "ST", widget);
}
