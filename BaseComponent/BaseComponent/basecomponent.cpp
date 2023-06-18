#include "basecomponent.h"

BaseComponent::BaseComponent(QObject *parent) : QObject(parent)
{

}

void BaseComponent::componentDidLoad()
{
    qDebug("Base Component Did Load\n");
}

QWidget *BaseComponent::componentWidget()
{
    return NULL;
}
