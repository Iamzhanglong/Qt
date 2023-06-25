#ifndef STSIGNALTOWERVIEW_H
#define STSIGNALTOWERVIEW_H

#include <QWidget>
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
signals:

public slots:
    void handleCommand(ST::STCommand command, ST::STSignalTowerStatus status);
};

#endif // STSIGNALTOWERVIEW_H
