#include "tabview.h"
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QObject>

#define BUTTON_WIDTH 60
#define BUTTON_HIGHT 20

#define TAB_HIGHT 30

TabView::TabView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(10,2,10,2);
    this->setMinimumHeight(TAB_HIGHT);
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

void TabView::addTab(QString tabId, QString btnTitle)
{
    QPushButton *button = new QPushButton();
    button->setFixedWidth(BUTTON_WIDTH);
    button->setFixedHeight(BUTTON_HIGHT);
    button->setStyleSheet("background-color:#ced4da;border:1px solid gray;border-radius:5px;");
    button->setText(btnTitle);

    QObject::connect(button, &QPushButton::clicked, [=]() {
            qDebug("Button was %s", qPrintable(button->text()));
            emit buttonDidCliked(tabId);
        });

    QHBoxLayout *hLayout = (QHBoxLayout *)this->layout();

    QLayoutItem *item = hLayout->itemAt(hLayout->count() - 1);
    hLayout->removeItem(item);

    (button)->setParent(this);
    this->layout()->addWidget(button);

    hLayout->addStretch();

    this->buttonArray.append(button);
}
