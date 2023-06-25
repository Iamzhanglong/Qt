#include "stmodel.h"


STModel::STModel(QObject *parent) : QObject(parent)
{
    this->errorStates = new QMap<ST::STErrorId, ST::STState>();
}

/*=======================Slots===================*/
void STModel::updateErrorState(ST::STErrorId stErrorId, ST::STState state)
{
    this->errorStates->insert(stErrorId, state);
}


void STModel::startServer(quint16 port)
{
    this->server = new QTcpServer(this);
   //客户机连接信号槽
    connect(this->server, SIGNAL(newConnection()), this, SLOT(ClientConnect()));
    this->server->listen(QHostAddress::Any, port);
    qDebug("start server\n");
}

void STModel::stopServer()
{
    this->server->close();
    this->server->deleteLater();
    qDebug("stop server\n");
}

void STModel::ClientConnect()
{
    //解析所有客户连接
    while (this->server->hasPendingConnections())
    {
        //连接上后通过socket获取连接信息
        this->socket = this->server->nextPendingConnection();
        //监听客户端是否有消息发送
        connect(this->socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    }
}

//获取客户端向服务器发送的信息
void STModel::receiveData()
{
    QByteArray buf = this->socket->readAll();//readAll最多接收65532的数据
    this->parseCommand(buf);
}

//服务器向客户端发送信息
void STModel::sendData(char *data, qint32 len)
{
    socket->write(data, len);
}

void STModel::distributeCommand(ST::STCommand command, ST::STSignalTowerStatus status)
{
    emit receiveCommand(command, status);
}

void STModel::paseQueryCommand(QByteArray &buf)
{
    if (buf.at(2) != 0x40)
    {
        return;
    }

    switch (buf.at(3))
    {
    case 0x00:
        this->sendFirstLevelErrorState();
        break;
    case 0x04:
        break;
    case 0x07:
        break;
    case 0x0A:
        break;
    case 0x0D:
        break;
    case 0x10:
        break;
    default:
        break;
    }
}

void STModel::paseSetCommand(QByteArray &buf)
{
    /* 红灯状态 */
    ST::STSignalTowerStatus redLampStatus = ST::STStatus_off;
    redLampStatus = buf.at(5) & 0x01 ? ST::STStatus_on : redLampStatus;
    redLampStatus = buf.at(5) & 0x10 ? ST::STStatus_blink : redLampStatus;
    this->distributeCommand(ST::STCommand_setRed, redLampStatus);

    /* 黄灯状态 */
    ST::STSignalTowerStatus yellowLampStatus = ST::STStatus_off;
    yellowLampStatus = buf.at(5) & 0x02 ? ST::STStatus_on : yellowLampStatus;
    yellowLampStatus = buf.at(5) & 0x20 ? ST::STStatus_blink : yellowLampStatus;
    this->distributeCommand(ST::STCommand_setYellow, yellowLampStatus);

    /* 绿灯状态 */
    ST::STSignalTowerStatus greenLampStatus = ST::STStatus_off;
    greenLampStatus = buf.at(5) & 0x04 ? ST::STStatus_on : greenLampStatus;
    greenLampStatus = buf.at(5) & 0x40 ? ST::STStatus_blink : greenLampStatus;
    this->distributeCommand(ST::STCommand_setGreen, greenLampStatus);

    /* 蓝灯状态 */
    ST::STSignalTowerStatus blueLampStatus = ST::STStatus_off;
    blueLampStatus = buf.at(5) & 0x08 ? ST::STStatus_on : blueLampStatus;
    blueLampStatus = buf.at(5) & 0x80 ? ST::STStatus_blink : blueLampStatus;
    this->distributeCommand(ST::STCommand_setBlue, blueLampStatus);

    /* 蜂鸣器状态 */
    ST::STSignalTowerStatus buzzerStatus = ST::STStatus_off;
    buzzerStatus = buf.at(4) & 0x01 ? ST::STStatus_on : buzzerStatus;
    this->distributeCommand(ST::STCommand_setBuzzer, buzzerStatus);

    /* 音乐状态 */
    ST::STSignalTowerStatus musicStatus = ST::STStatus_off;
    musicStatus = buf.at(4) & 0x02 ? ST::STStatus_on : musicStatus;
    this->distributeCommand(ST::STCommand_setMusic, musicStatus);
}

void STModel::parseCommand(QByteArray &buf)
{
    if (buf.at(0) != 0x29)
    {
        return;
    }

    switch(buf.at(1))
    {
    case 0x03:
        this->paseQueryCommand(buf);
        break;
    case 0x06:
        this->paseSetCommand(buf);
        break;
    }
}

void STModel::sendFirstLevelErrorState()
{
    char data[7] = {0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x02;
    data[3] = 0x00;

    //emo
    if (this->errorStates->contains(ST::STError_Emo))
    {
        ST::STState emoState = this->errorStates->value(ST::STError_Emo);
        data[4] |= emoState == ST::STState_error ? 0x01 : 0x00;
    }

    //water
    if (this->errorStates->contains(ST::STError_WaterLeak))
    {
        ST::STState wateState = this->errorStates->value(ST::STError_WaterLeak);
        data[4] |= wateState == ST::STState_error ? 0x04 : 0x00;
    }

    //smoke
    if (this->errorStates->contains(ST::STError_Smoke))
    {
        ST::STState smokeState = this->errorStates->value(ST::STError_Smoke);
        data[4] |= smokeState == ST::STState_error ? 0x08 : 0x00;
    }

    data[5] = 0x19;
    data[6] = 0x18;
    this->sendData(data, 7);
}
