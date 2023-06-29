#include "stsignaltowerview.h"
#include <QVBoxLayout>

#define LAMP_SIZE      50
#define BLINK_TIMER_MS 300

STSignalTowerView::STSignalTowerView(QWidget *parent) : QWidget(parent)
{
    this->redLamp = new QWidget();
    this->redLamp->setFixedSize(LAMP_SIZE, LAMP_SIZE);
    this->redLamp->setParent(this);
    this->setRedLampOn(false);

    this->yellowLamp = new QWidget();
    this->yellowLamp->setFixedSize(LAMP_SIZE, LAMP_SIZE);
    this->yellowLamp->setParent(this);
    this->setYellowLampOn(false);

    this->blueLamp = new QWidget();
    this->blueLamp->setFixedSize(LAMP_SIZE, LAMP_SIZE);
    this->blueLamp->setParent(this);
    this->setBlueLampOn(false);

    this->greenLamp = new QWidget();
    this->greenLamp->setFixedSize(LAMP_SIZE, LAMP_SIZE);
    this->greenLamp->setParent(this);
    this->setGreenLampOn(false);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(10);
    layout->addWidget(this->redLamp);
    layout->addWidget(this->yellowLamp);
    layout->addWidget(this->blueLamp);
    layout->addWidget(this->greenLamp);
    layout->addStretch();
    this->setLayout(layout);
}


/*=========================Slots=========================*/
void STSignalTowerView::handleCommand(ST::STCommand command, ST::STSignalTowerStatus status)
{
    switch (command)
    {
    case ST::STCommand_setRed:
        this->setRedLampStatus(status);
        break;
    case ST::STCommand_setYellow:
        this->setYellowLampStatus(status);
        break;
    case ST::STCommand_setBlue:
        this->setBlueLampStatus(status);
        break;
    case ST::STCommand_setGreen:
        this->setGreenLampStatus(status);
        break;
    default:
        break;
    }
}

void STSignalTowerView::clearStatus()
{
    this->setRedLampStatus(ST::STStatus_off);
    this->setYellowLampStatus(ST::STStatus_off);
    this->setBlueLampStatus(ST::STStatus_off);
    this->setGreenLampStatus(ST::STStatus_off);
}

/*=========================Private=========================*/
void STSignalTowerView::setRedLampOn(bool on)
{
    if (on)
    {
        this->redLamp->setStyleSheet("background-color:#e03131;border:1px solid #dee2e6;border-radius:25px;");
    }
    else
    {
        this->redLamp->setStyleSheet("background-color:#ffe3e3;border:1px solid #dee2e6;border-radius:25px;");
    }
}

void STSignalTowerView::setYellowLampOn(bool on)
{
    if (on)
    {
        this->yellowLamp->setStyleSheet("background-color:#f08c00;border:1px solid #dee2e6;border-radius:25px;");
    }
    else
    {
        this->yellowLamp->setStyleSheet("background-color:#fff3bf;border:1px solid #dee2e6;border-radius:25px;");
    }
}

void STSignalTowerView::setBlueLampOn(bool on)
{
    if (on)
    {
        this->blueLamp->setStyleSheet("background-color:#1971c2;border:1px solid #dee2e6;border-radius:25px;");
    }
    else
    {
        this->blueLamp->setStyleSheet("background-color:#dbe4ff;border:1px solid #dee2e6;border-radius:25px;");
    }
}

void STSignalTowerView::setGreenLampOn(bool on)
{
    if (on)
    {
        this->greenLamp->setStyleSheet("background-color:#2f9e44;border:1px solid #dee2e6;border-radius:25px;");
    }
    else
    {
        this->greenLamp->setStyleSheet("background-color:#d3f9d8;border:1px solid #dee2e6;border-radius:25px;");
    }
}

void STSignalTowerView::setRedLampStatus(ST::STSignalTowerStatus status)
{
    switch (status) {
    case ST::STStatus_on:
        this->killTimer(this->redTimer);
        this->redTimer = 0;
        this->setRedLampOn(true);
        break;
    case ST::STStatus_off:
        this->killTimer(this->redTimer);
        this->redTimer = 0;
        this->setRedLampOn(false);
        break;
    case ST::STStatus_blink:
        this->killTimer(this->redTimer);
        this->redTimer = 0;
        this->redTimer = this->startTimer(BLINK_TIMER_MS);
        break;
    default:
        break;
    }
}

void STSignalTowerView::setYellowLampStatus(ST::STSignalTowerStatus status)
{
    switch (status) {
    case ST::STStatus_on:
        this->killTimer(this->yellowTimer);
        this->yellowTimer = 0;
        this->setYellowLampOn(true);
        break;
    case ST::STStatus_off:
        this->killTimer(this->yellowTimer);
        this->yellowTimer = 0;
        this->setYellowLampOn(false);
        break;
    case ST::STStatus_blink:
        this->killTimer(this->yellowTimer);
        this->yellowTimer = 0;
        this->yellowTimer = this->startTimer(BLINK_TIMER_MS);
        break;
    default:
        break;
    }
}

void STSignalTowerView::setBlueLampStatus(ST::STSignalTowerStatus status)
{
    switch (status) {
    case ST::STStatus_on:
        this->killTimer(this->blueTimer);
        this->blueTimer = 0;
        this->setBlueLampOn(true);
        break;
    case ST::STStatus_off:
        this->killTimer(this->blueTimer);
        this->blueTimer = 0;
        this->setBlueLampOn(false);
        break;
    case ST::STStatus_blink:
        this->killTimer(this->blueTimer);
        this->blueTimer = 0;
        this->blueTimer = this->startTimer(BLINK_TIMER_MS);
        break;
    default:
        break;
    }
}

void STSignalTowerView::setGreenLampStatus(ST::STSignalTowerStatus status)
{
    switch (status) {
    case ST::STStatus_on:
        this->killTimer(this->greenTimer);
        this->greenTimer = 0;
        this->setGreenLampOn(true);
        break;
    case ST::STStatus_off:
        this->killTimer(this->greenTimer);
        this->greenTimer = 0;
        this->setGreenLampOn(false);
        break;
    case ST::STStatus_blink:
        this->killTimer(this->greenTimer);
        this->greenTimer = 0;
        this->greenTimer = this->startTimer(BLINK_TIMER_MS);
        break;
    default:
        break;
    }
}

void STSignalTowerView::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->redTimer)
    {
        if (this->isRedOn)
        {
            this->isRedOn = false;
            this->setRedLampOn(false);
        }
        else
        {
            this->isRedOn = true;
            this->setRedLampOn(true);
        }
        return;
    }

    if (event->timerId() == this->yellowTimer)
    {
        if (this->isYellowOn)
        {
            this->isYellowOn = false;
            this->setYellowLampOn(false);
        }
        else
        {
            this->isYellowOn = true;
            this->setYellowLampOn(true);
        }
        return;
    }

    if (event->timerId() == this->blueTimer)
    {
        if (this->isBlueOn)
        {
            this->isBlueOn = false;
            this->setBlueLampOn(false);
        }
        else
        {
            this->isBlueOn = true;
            this->setBlueLampOn(true);
        }
        return;
    }

    if (event->timerId() == this->greenTimer)
    {
        if (this->isGreenOn)
        {
            this->isGreenOn = false;
            this->setGreenLampOn(false);
        }
        else
        {
            this->isGreenOn = true;
            this->setGreenLampOn(true);
        }
        return;
    }
}
