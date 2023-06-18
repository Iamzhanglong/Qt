#include "operationview.h"
#include <QPainter>
#include <QPaintEvent>
#include <QObject>
#include <QStyleOption>

OperationView::OperationView(QWidget *parent) : QWidget(parent)
{

}

void OperationView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
