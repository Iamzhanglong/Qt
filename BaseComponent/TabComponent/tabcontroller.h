#ifndef TABCONTROLLER_H
#define TABCONTROLLER_H

#include <QObject>

class TabController : public QObject
{
    Q_OBJECT
public:
    explicit TabController(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TABCONTROLLER_H