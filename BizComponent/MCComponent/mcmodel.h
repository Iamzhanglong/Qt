#ifndef MCMODEL_H
#define MCMODEL_H

#include <QObject>

class MCModel : public QObject
{
    Q_OBJECT
public:
    explicit MCModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MCMODEL_H