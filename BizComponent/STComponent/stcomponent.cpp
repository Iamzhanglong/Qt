#include "stcomponent.h"

STComponent::STComponent()
{
    this->view = new STView();
    this->stModel = new STModel();
}

void STComponent::injectService(ServiceManager *serviceManager)
{
    this->tabService = (TabService *)serviceManager->getService(tabServiceId);
    this->logService = (LogService *)serviceManager->getService(logServiceId);
}

void STComponent::componentDidLoad()
{
    this->tabService->insertTab(stTabId, "ST", this->view);

    this->bind();
    QString str = "6666";
    this->logService->printfLog(str);
    this->logService->printfLog(str);
    this->logService->printfLog(str);
    this->logService->printfLog(str);
}

void STComponent::bind()
{
    connect(this->view->settingView, SIGNAL(errorStateChanged(ST::STErrorId,ST::STState)), this->stModel, SLOT(updateErrorState(ST::STErrorId , ST::STState )));
    connect(this->view->menuView, SIGNAL(startServer(quint16)), this->stModel, SLOT(startServer(quint16)));
    connect(this->view->menuView, SIGNAL(stopServer()), this->stModel, SLOT(stopServer()));
    connect(this->stModel, SIGNAL(receiveCommand(ST::STCommand,ST::STSignalTowerStatus)), this->view->signaltowerView, SLOT(handleCommand(ST::STCommand,ST::STSignalTowerStatus)));
}
