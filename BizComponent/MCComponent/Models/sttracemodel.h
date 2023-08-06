#ifndef STTRACEMODEL_H
#define STTRACEMODEL_H

#include <QObject>
#include <QTimer>

class STTraceModel : public QObject
{
    Q_OBJECT
public:
    explicit STTraceModel(QObject *parent = nullptr);

private:
    QTimer *timer;
    qreal x;
    void Timeout_handler();

signals:
    void traceDataUpdata(qreal x, qreal y);
};

#endif // STTRACEMODEL_H
