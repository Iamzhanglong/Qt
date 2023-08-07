#include "mccontrolview.h"
#include <QHBoxLayout>
#include <QIntValidator>

MCControlView::MCControlView(QWidget *parent) : QWidget(parent)
{
    this->ipName = new QLabel("IP地址：");
    this->mcIp = new QLineEdit();
    this->mcIp->setText("172.26.50.131");
    QHBoxLayout *ipLayout = new QHBoxLayout();
    ipLayout->addWidget(this->ipName);
    ipLayout->addWidget(this->mcIp);

    this->portName = new QLabel("端口号：");
    this->mcPort = new QLineEdit();
    this->mcPort->setValidator(new QIntValidator());
    this->mcPort->setText("1525");
    QHBoxLayout *portLayout = new QHBoxLayout();
    portLayout->addWidget(this->portName);
    portLayout->addWidget(this->mcPort);

    this->connectButton = new QPushButton();
    this->connectButton->setText("连接板卡");

    connect(this->connectButton, &QPushButton::clicked, this, &MCControlView::connectBtnClicked);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addLayout(ipLayout);
    layout->addLayout(portLayout);
    layout->addWidget(this->connectButton);

    this->setLayout(layout);
}

void MCControlView::onConnectStateChanged(bool state)
{
    if (state)
    {
        this->connectButton->setText("连接板卡");
    }
    else
    {
        this->connectButton->setText("断开连接");
    }
}

void MCControlView::connectBtnClicked()
{
    int port = this->mcPort->text().toInt();
    emit switchConnectState(this->mcIp->text(), port);
}
