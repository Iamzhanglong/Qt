#include "stcomponent.h"

STComponent::STComponent()
{
    this->view = new STView();
    this->stModel = new STModel();
}

void STComponent::injectService(ServiceManager *serviceManager)
{
    this->tabService = (TabService *)serviceManager->getService(tabServiceId);
}

void STComponent::componentDidLoad()
{
    this->tabService->insertTab(stTabId, "ST", this->view);

    this->bind();
}

void STComponent::bind()
{
    connect(this->view->settingView, SIGNAL(errorStateChanged(ST::STErrorId,ST::STState)), this->stModel, SLOT(updateErrorState(ST::STErrorId , ST::STState )));
    connect(this->view->menuView, SIGNAL(startServer(quint16)), this->stModel, SLOT(startServer(quint16)));
    connect(this->view->menuView, SIGNAL(stopServer()), this->stModel, SLOT(stopServer()));
    connect(this->stModel, SIGNAL(receiveCommand(ST::STCommand,qint16)), this->view->signaltowerView, SLOT(handleCommand(ST::STCommand,qint16)));
}
