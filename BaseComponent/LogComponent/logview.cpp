#include "logview.h"
#include <QPainter>
#include <QPaintEvent>
#include <QObject>
#include <QStyleOption>

LogView::LogView(QWidget *parent) : QWidget(parent)
{

}

void LogView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
