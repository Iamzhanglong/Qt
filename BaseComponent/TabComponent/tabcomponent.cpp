#include "tabcomponent.h"


TabComponent::TabComponent()
{
    this->tabMap = new QMap<QString, QWidget *>();
    this->view = new TabView();
    this->view->setStyleSheet("background-color:blue;");
}

void TabComponent::registerService(ServiceManager *serviceManager)
{
    qDebug("register service\n");
    serviceManager->registerService(tabServiceId, this);
}

void TabComponent::injectService(ServiceManager *serviceManager)
{
    this->operationService = (OperationWindowService *)serviceManager->getService(operationWindowServiceId);
}

void TabComponent::componentDidLoad()
{
    BaseComponent::componentDidLoad();
    qDebug("TabComponent Did Load\n");

    connect(this->view, SIGNAL(buttonDidCliked(QString)), this, SLOT(switchOperationWindow(QString)));
}

void TabComponent::switchOperationWindow(QString tabId)
{
    QWidget *widget = this->tabMap->value(tabId);
    this->operationService->switchOperationWindow(widget);
}

QWidget *TabComponent::componentWidget()
{
    return this->view;
}

/*==========================TabService==========================*/
void TabComponent::insertTab(QString tabId, QString tabTitle, QWidget *widget)
{
    this->view->addTab(tabId, tabTitle);
    this->tabMap->insert(tabId, widget);
    qDebug("insert Tab\n");
}
