#ifndef STMODEL_H
#define STMODEL_H

#include <QObject>

class STModel : public QObject
{
    Q_OBJECT
public:
    explicit STModel(QObject *parent = nullptr);

signals:

};

#endif // STMODEL_H
