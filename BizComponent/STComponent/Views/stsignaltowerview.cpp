#include "stsignaltowerview.h"
#include <QVBoxLayout>

STSignalTowerView::STSignalTowerView(QWidget *parent) : QWidget(parent)
{
    this->redLamp = new QWidget();
    this->redLamp->setParent(this);
    this->redLamp->setStyleSheet("background-color:rgba(255, 0, 0, 0.6);");

    this->yellowLamp = new QWidget();
    this->yellowLamp->setParent(this);
    this->yellowLamp->setStyleSheet("background-color:yellow;");
    this->yellowLamp->setStyleSheet("background-color:rgba(255, 255, 0, 0.6);");

    this->blueLamp = new QWidget();
    this->blueLamp->setParent(this);
    this->blueLamp->setStyleSheet("background-color:rgba(0, 0, 255, 0.6);");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->addWidget(this->redLamp);
    layout->addWidget(this->yellowLamp);
    layout->addWidget(this->blueLamp);
    this->setLayout(layout);
}


/*=========================Slots=========================*/
void STSignalTowerView::handleCommand(ST::STCommand command, qint16 value)
{
    qDebug("receive data\n");
}
