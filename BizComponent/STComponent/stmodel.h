#ifndef STMODEL_H
#define STMODEL_H

#include <QObject>
#include <QMap>
#include "BizComponent/STComponent/stcomponentconst.h"
#include <QTcpSocket>
#include <QTcpServer>

class STModel : public QObject
{
    Q_OBJECT
public:
    explicit STModel(QObject *parent = nullptr);
    void startServer();

private:
    QMap<ST::STErrorId, ST::STState> *errorStates;
    QTcpServer* server;
    QTcpSocket* socket;

    void ClientConnect();
    void receiveData();
    ST::STCommand parseCommand(QByteArray &buf, ST::STCommand *command, qint16 *value);
    void distributeCommand(ST::STCommand command, qint16 value);

public slots:
    void updateErrorState(ST::STErrorId stErrorId, ST::STState state);
    void startServer(quint16 port);
    void stopServer();
signals:
    void receiveCommand(ST::STCommand command, qint16 value);
};

#endif // STMODEL_H
