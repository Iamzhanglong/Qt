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
    this->logService->printfLog("Start server");
}

void STModel::stopServer()
{
    this->server->close();
    this->server->deleteLater();
    this->logService->printfLog("Stop server");
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
        this->logService->printfLog("Client already connect");
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

void STModel::sendData(unsigned char *data, qint32 len)
{
    socket->write((char *)data, len);
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
        this->sendInterLockErrorState();
        break;
    case 0x07:
        this->sendWaterLeakErrorState();
        break;
    case 0x0A:
        this->sendSmokeErrorState();
        break;
    case 0x0D:
        this->sendFanErrorState();
        break;
    case 0x10:
        this->sendTempErrorState();
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

    QString str = QString("Receive Set Signal Tower Command:[%1 %2 %3 %4 %5 %6 %7 %8]")
            .arg(buf[0], 2, 16, QLatin1Char('0'))
            .arg(buf[1], 2, 16, QLatin1Char('0'))
            .arg(buf[2], 2, 16, QLatin1Char('0'))
            .arg(buf[3], 2, 16, QLatin1Char('0'))
            .arg(buf[4], 2, 16, QLatin1Char('0'))
            .arg(buf[5], 2, 16, QLatin1Char('0'))
            .arg(buf[6], 2, 16, QLatin1Char('0'))
            .arg(buf[7], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
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

    //interlock
    data[4] |= this->getInterLockErrorState() == ST::STState_error ? 0x02 : 0x00;

    //waterLeak
      data[4] |= this->getWaterLeakErrorState() == ST::STState_error ? 0x04 : 0x00;

    //smoke
    data[4] |= this->getSmokeErrorState() == ST::STState_error ? 0x08 : 0x00;

    //fan
    data[4] |= this->getFanErrorState() == ST::STState_error ? 0x10 : 0x00;

    //temp
    data[4] |= this->getTempErrorState() == ST::STState_error ? 0x20 : 0x00;

    data[5] = 0x19;
    data[6] = 0x18;
    this->sendData(data, 7);
    QString str = QString("Send First Level Error:[%1 %2 %3 %4 %5 %6 %7]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}

ST::STState STModel::getInterLockErrorState()
{
    for (int errorId = ST::STError_InterLock1; errorId <= ST::STError_InterLock6; errorId ++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                return ST::STState_error;
            }
        }
    }
    return ST::STState_normal;
}

ST::STState STModel::getWaterLeakErrorState()
{
    for (int errorId = ST::STError_WaterLeak1; errorId <= ST::STError_WaterLeak8; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                return ST::STState_error;
            }
        }
    }
    return ST::STState_normal;
}

ST::STState STModel::getSmokeErrorState()
{
    for (int errorId = ST::STError_Smoke1; errorId <= ST::STError_Smoke3; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                return ST::STState_error;
            }
        }
    }
    return ST::STState_normal;
}

ST::STState STModel::getFanErrorState()
{
    for (int errorId = ST::STError_PWCRFan; errorId <= ST::STError_WSPR2Fan; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                return ST::STState_error;
            }
        }
    }
    return ST::STState_normal;
}

ST::STState STModel::getTempErrorState()
{
    for (int errorId = ST::STError_ECABTemp; errorId <= ST::STError_WHCRTemp; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                return ST::STState_error;
            }
        }
    }
    return ST::STState_normal;
}

void STModel::sendInterLockErrorState()
{
    unsigned char data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x06;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    unsigned char bit = 0x01;
    for (int errorId = ST::STError_InterLock1; errorId <= ST::STError_InterLock6; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                data[8] |= bit;
            }
        }
        bit = bit << 1;
    }

    data[9] = 0xDF;
    data[10] = 0x74;
    this->sendData(data, 11);
    QString str = QString("Send Interlock Error:[%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'))
            .arg(data[7], 2, 16, QLatin1Char('0'))
            .arg(data[8], 2, 16, QLatin1Char('0'))
            .arg(data[9], 2, 16, QLatin1Char('0'))
            .arg(data[10], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}

void STModel::sendWaterLeakErrorState()
{
    unsigned char data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x06;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    unsigned char bit = 0x01;
    for (int errorId = ST::STError_WaterLeak1; errorId <= ST::STError_WaterLeak8; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                data[8] |= bit;
            }
        }
        bit = bit << 1;
    }

    data[9] = 0xDF;
    data[10] = 0x74;
    this->sendData(data, 11);
    QString str = QString("Send Water Leak Error:[%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'))
            .arg(data[7], 2, 16, QLatin1Char('0'))
            .arg(data[8], 2, 16, QLatin1Char('0'))
            .arg(data[9], 2, 16, QLatin1Char('0'))
            .arg(data[10], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}

void STModel::sendSmokeErrorState()
{
    unsigned char data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x06;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    unsigned char bit = 0x01;
    for (int errorId = ST::STError_Smoke1; errorId <= ST::STError_Smoke3; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                data[8] |= bit;
            }
        }
        bit = bit << 1;
    }

    data[9] = 0xDF;
    data[10] = 0x74;
    this->sendData(data, 11);
    QString str = QString("Send Smoke Error:[%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'))
            .arg(data[7], 2, 16, QLatin1Char('0'))
            .arg(data[8], 2, 16, QLatin1Char('0'))
            .arg(data[9], 2, 16, QLatin1Char('0'))
            .arg(data[10], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}

void STModel::sendFanErrorState()
{
    unsigned char data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x06;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    unsigned char bit = 0x01;
    for (int errorId = ST::STError_PWCRFan; errorId <= ST::STError_WSPR2Fan; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                data[8] |= bit;
            }
        }
        bit = bit << 1;
    }

    data[9] = 0xDF;
    data[10] = 0xDF;
    this->sendData(data, 11);
    QString str = QString("Send Fan Error:[%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'))
            .arg(data[7], 2, 16, QLatin1Char('0'))
            .arg(data[8], 2, 16, QLatin1Char('0'))
            .arg(data[9], 2, 16, QLatin1Char('0'))
            .arg(data[10], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}

void STModel::sendTempErrorState()
{
    unsigned char data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    data[0] = 0x29;
    data[1] = 0x03;
    data[2] = 0x06;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    unsigned char bit = 0x01;
    for (int errorId = ST::STError_ECABTemp; errorId <= ST::STError_WHCRTemp; errorId++)
    {
        ST::STErrorId error = (ST::STErrorId)errorId;
        if (this->errorStates->contains(error))
        {
            ST::STState state = this->errorStates->value(error);
            if (state == ST::STState_error)
            {
                data[8] |= bit;
            }
        }
        bit = bit << 1;
    }

    data[9] = 0xDF;
    data[10] = 0x74;
    this->sendData(data, 11);

    QString str = QString("Send Temp Error:[%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11]")
            .arg(data[0], 2, 16, QLatin1Char('0'))
            .arg(data[1], 2, 16, QLatin1Char('0'))
            .arg(data[2], 2, 16, QLatin1Char('0'))
            .arg(data[3], 2, 16, QLatin1Char('0'))
            .arg(data[4], 2, 16, QLatin1Char('0'))
            .arg(data[5], 2, 16, QLatin1Char('0'))
            .arg(data[6], 2, 16, QLatin1Char('0'))
            .arg(data[7], 2, 16, QLatin1Char('0'))
            .arg(data[8], 2, 16, QLatin1Char('0'))
            .arg(data[9], 2, 16, QLatin1Char('0'))
            .arg(data[10], 2, 16, QLatin1Char('0'));
    this->logService->printfLog(str);
}
