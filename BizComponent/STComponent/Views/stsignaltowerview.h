#ifndef STSIGNALTOWERVIEW_H
#define STSIGNALTOWERVIEW_H

#include <QWidget>
#include <QTimerEvent>
#include "BizComponent/STComponent/stcomponentconst.h"

class STSignalTowerView : public QWidget
{
    Q_OBJECT
public:
    explicit STSignalTowerView(QWidget *parent = nullptr);
private:
    QWidget *redLamp;
    QWidget *yellowLamp;
    QWidget *blueLamp;
    QWidget *greenLamp;
    int redTimer;
    int yellowTimer;
    int blueTimer;
    int greenTimer;
    bool isRedOn;
    bool isYellowOn;
    bool isBlueOn;
    bool isGreenOn;


    virtual void timerEvent(QTimerEvent *event);
    void setRedLampStatus(ST::STSignalTowerStatus status);
    void setYellowLampStatus(ST::STSignalTowerStatus status);
    void setBlueLampStatus(ST::STSignalTowerStatus status);
    void setGreenLampStatus(ST::STSignalTowerStatus status);

    void setRedLampOn(bool on);
    void setYellowLampOn(bool on);
    void setBlueLampOn(bool on);
    void setGreenLampOn(bool on);
signals:

public slots:
    void handleCommand(ST::STCommand command, ST::STSignalTowerStatus status);
    void clearStatus();
};

#endif // STSIGNALTOWERVIEW_H
