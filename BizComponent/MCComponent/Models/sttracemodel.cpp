#include "sttracemodel.h"

STTraceModel::STTraceModel(QObject *parent) : QObject(parent)
{
    this->timer = new QTimer();
    connect(this->timer, &QTimer::timeout, this, &STTraceModel::Timeout_handler);
    this->timer->setInterval(100);
    this->timer->start();
}

void STTraceModel::Timeout_handler()
{
    emit traceDataUpdata(this->x, this->x);
    this->x++;
}
