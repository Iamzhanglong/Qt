#include "mccomponent.h"

MCComponent::MCComponent()
{
    this->view = new MCView();
    this->mcModel = new MCModel();
    this->traceModel = new STTraceModel();
}

MCComponent::~MCComponent()
{

}


void MCComponent::injectService(ServiceManager *serviceManager)
{
    this->tabService = (TabService *)serviceManager->getService(tabServiceId);
    this->logService = (LogService *)serviceManager->getService(logServiceId);
}

void MCComponent::componentDidLoad()
{
    this->tabService->insertTab(mcTabId, "MC", this->view);

    this->bind();
}

void MCComponent::bind()
{
    connect(this->traceModel,
            &STTraceModel::traceDataUpdata,
            this->view->traceView,
            &MCTraceView::updateCoordinate);
    connect(this->view->controlView,
            &MCControlView::switchConnectState,
            this->mcModel,
            &MCModel::modifyConnectState);
    connect(this->mcModel,
            &MCModel::connectStateChanged,
            this->view->controlView,
            &MCControlView::onConnectStateChanged);

}
