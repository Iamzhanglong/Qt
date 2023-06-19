#include "stmenuview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

STMenuView::STMenuView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *ipLayout = new QHBoxLayout();
    this->serverIpName = new QLabel();
    this->serverIpName->setText("IP:");
    ipLayout->addWidget(this->serverIpName);

    this->serverIp = new QLineEdit();
    this->serverIp->setText("192.168.6.158");
    this->serverIp->setEnabled(false);
    ipLayout->addWidget(this->serverIp);


    QHBoxLayout *portLayout = new QHBoxLayout();
    this->serverportName = new QLabel();
    this->serverportName->setText("端口号:");
    portLayout->addWidget(this->serverportName);

    this->serverport = new QLineEdit();
    this->serverport->setText("7");
    portLayout->addWidget(this->serverport);

    this->startButton = new QPushButton();
    this->startButton->setText("开始");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(ipLayout);
    layout->addLayout(portLayout);
    layout->addWidget(startButton);
    layout->addStretch();

    this->setLayout(layout);
}
