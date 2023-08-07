#ifndef MCMODEL_H
#define MCMODEL_H

#include <QObject>

class MCModel : public QObject
{
    Q_OBJECT
public:
    explicit MCModel(QObject *parent = nullptr);

signals:
    void connectStateChanged(bool state);
public slots:
    void modifyConnectState(QString ip, int port);
};

#endif // MCMODEL_H
