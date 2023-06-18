#include "tabview.h"
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QObject>

TabView::TabView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout();
//    hLayout->setMargin(2);
    hLayout->setContentsMargins(10,2,10,2);
    this->setLayout(hLayout);
}

void TabView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TabView::addButton(QPushButton *button)
{
    if (button == NULL)
    {
        return;
    }

    QObject::connect(button, &QPushButton::clicked, [=]() {
            qDebug("Button was %s", qPrintable(button->text()));
        });

    QHBoxLayout *hLayout = (QHBoxLayout *)this->layout();

    QLayoutItem *item = hLayout->itemAt(hLayout->count() - 1);
    hLayout->removeItem(item);

    (button)->setParent(this);
    this->layout()->addWidget(button);

    hLayout->addStretch();

    this->buttonArray.append(button);
}
