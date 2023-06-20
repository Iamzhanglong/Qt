#ifndef STCONTROLLER_H
#define STCONTROLLER_H

#include <QObject>

class STController : public QObject
{
    Q_OBJECT
public:
    explicit STController(QObject *parent = nullptr);

signals:

};

#endif // STCONTROLLER_H
