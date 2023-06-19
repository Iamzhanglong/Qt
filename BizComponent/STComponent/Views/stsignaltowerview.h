#ifndef STSIGNALTOWERVIEW_H
#define STSIGNALTOWERVIEW_H

#include <QWidget>

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
};

#endif // STSIGNALTOWERVIEW_H
