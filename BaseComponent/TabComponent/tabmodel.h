#ifndef TABMODEL_H
#define TABMODEL_H

#include <QObject>

class TabModel : public QObject
{
    Q_OBJECT
public:
    explicit TabModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TABMODEL_H