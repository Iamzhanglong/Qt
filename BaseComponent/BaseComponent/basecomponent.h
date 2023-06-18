#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <QObject>
#include <QWidget>

class BaseComponent : public QObject
{
    Q_OBJECT
public:
    explicit BaseComponent(QObject *parent = nullptr);
    virtual void componentDidLoad();
    virtual QWidget *componentWidget();
signals:

public slots:
};

#endif // BASECOMPONENT_H
