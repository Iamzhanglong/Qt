#include "stmenuview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QNetworkInterface>
#include <QIntValidator>

#define START_SERVER    "开始"
#define STOP_SERVER     "停止"
#define DEFAULT_PORT    "7"

STMenuView::STMenuView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *ipLayout = new QHBoxLayout();
    this->serverIpName = new QLabel();
    this->serverIpName->setText("IP:");
    ipLayout->addWidget(this->serverIpName);

    this->serverIp = new QLineEdit();
    this->serverIp->setText(this->getLocalIp());
    this->serverIp->setEnabled(false);
    ipLayout->addWidget(this->serverIp);


    QHBoxLayout *portLayout = new QHBoxLayout();
    this->serverportName = new QLabel();
    this->serverportName->setText("端口号:");
    portLayout->addWidget(this->serverportName);

    this->serverport = new QLineEdit();
    this->serverport->setValidator(new QIntValidator());
    this->serverport->setText(DEFAULT_PORT);
    portLayout->addWidget(this->serverport);

    this->startButton = new QPushButton();
    this->startButton->setText(START_SERVER);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(ipLayout);
    layout->addLayout(portLayout);
    layout->addWidget(startButton);
    layout->addStretch();

    this->setLayout(layout);

    this->bind();
}

QString STMenuView::getLocalIp()
{
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    QString ipAddress;
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        qDebug()<<ipAddressesList.at(i);
        if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    return ipAddress;
}

void STMenuView::bind()
{
    connect(this->startButton, SIGNAL(clicked(bool)), this, SLOT(startButtonClicked()));
}

/*==========================Slots==========================*/
void STMenuView::startButtonClicked()
{
    if (this->startButton->text() == START_SERVER)
    {
        if (this->serverport->text() == "")
        {
            this->serverport->setText(DEFAULT_PORT);
        }
        emit startServer(this->serverport->text().toInt());
        this->startButton->setText(STOP_SERVER);
        this->serverport->setEnabled(false);
    }
    else
    {
        emit stopServer();
        this->startButton->setText(START_SERVER);
        this->serverport->setEnabled(true);
    }
}
