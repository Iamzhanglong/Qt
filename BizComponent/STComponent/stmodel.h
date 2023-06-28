#ifndef STMODEL_H
#define STMODEL_H

#include <QObject>
#include <QMap>
#include <QTcpSocket>
#include <QTcpServer>
#include "BizComponent/STComponent/stcomponentconst.h"
#include "Service/logservice.h"


class STModel : public QObject
{
    Q_OBJECT
public:
    explicit STModel(QObject *parent = nullptr);
    void startServer();

    LogService *logService;

private:
    QMap<ST::STErrorId, ST::STState> *errorStates;
    QTcpServer* server;
    QTcpSocket* socket;

    void paseQueryCommand(QByteArray &buf);
    void paseSetCommand(QByteArray &buf);
    void parseCommand(QByteArray &buf);
    void distributeCommand(ST::STCommand command, ST::STSignalTowerStatus statuse);
    void sendData(char *data, qint32 len);
    void sendData(unsigned char *data, qint32 len);
    void sendFirstLevelErrorState();
    ST::STState getInterLockErrorState();
    ST::STState getWaterLeakErrorState();
    ST::STState getSmokeErrorState();
    ST::STState getFanErrorState();
    ST::STState getTempErrorState();
    void sendInterLockErrorState();
    void sendWaterLeakErrorState();
    void sendSmokeErrorState();
    void sendFanErrorState();
    void sendTempErrorState();

public slots:
    void ClientConnect();
    void receiveData();
    void updateErrorState(ST::STErrorId stErrorId, ST::STState state);
    void startServer(quint16 port);
    void stopServer();
signals:
    void receiveCommand(ST::STCommand command, ST::STSignalTowerStatus statuse);
};

#endif // STMODEL_H
