#include "stmodel.h"


STModel::STModel(QObject *parent) : QObject(parent)
{
    this->errorStates = new QMap<ST::STErrorId, ST::STState>();
}

/*=======================Slots===================*/
void STModel::updateErrorState(ST::STErrorId stErrorId, ST::STState state)
{
    if (this->errorStates->contains(stErrorId))
    {
        this->errorStates->insert(stErrorId, state);
    }
    qDebug("sterror:%d, state:%d\n", stErrorId, state);
}


void STModel::startServer(quint16 port)
{
    this->server = new QTcpServer(this);
   //客户机连接信号槽
    connect(this->server, SIGNAL(QTcpServer::newConnection), this, SLOT(ClientConnect));
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
        connect(this->socket, SIGNAL(QTcpSocket::readyRead), this, SLOT(receiveData));
    }
}

//获取客户端向服务器发送的信息
void STModel::receiveData()
{
    QByteArray buf = this->socket->readAll();//readAll最多接收65532的数据
    ST::STCommand command;
    qint16 value;
    this->parseCommand(buf, &command, &value);
    this->distributeCommand(command, value);
}

ST::STCommand STModel::parseCommand(QByteArray &buf, ST::STCommand *command, qint16 *value)
{

}

void STModel::distributeCommand(ST::STCommand command, qint16 value)
{
    emit receiveCommand(command, value);
}

//服务器向客户端发送信息
//void STModel::on_btn_server_clicked()
//{
//  if(ui.comboBox->count()== 0)return;
//  //QTcpSocket* skt=  (QTcpSocket*)ui.comboBox->itemData(ui.comboBox->currentIndex()).value<int>();
//  socket->write(ui.lineEdit1->text().toUtf8());
//}
