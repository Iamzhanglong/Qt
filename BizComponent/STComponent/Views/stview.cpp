#include "stview.h"
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QObject>
#include <QHBoxLayout>

STView::STView(QWidget *parent) : QWidget(parent)
{
    this->menuView = new STMenuView();
    this->menuView->setParent(this);

    this->settingView = new STSettingView();
    this->settingView->setParent(this);

    this->signaltowerView = new STSignalTowerView();
    this->signaltowerView->setParent(this);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(this->menuView, 3);
    layout->addWidget(this->settingView, 6);
    layout->addWidget(this->signaltowerView, 1);

    this->setLayout(layout);
}

void STView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
