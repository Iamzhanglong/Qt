#ifndef COMPONENTLOADER_H
#define COMPONENTLOADER_H

#include <QObject>
#include <QVector>
#include <QMap>

#include "BaseComponent/BaseComponent/basecomponent.h"
#include "LayoutManager/layoutmanager.h"

class ComponentLoader : public QObject
{
    Q_OBJECT
public:
    LayoutManager *layoutManager;

    explicit ComponentLoader(QObject *parent = nullptr);
    void loadComponents();
private:

private:
    QMap<QString, BaseComponent *> *baseComponents;
    QVector<BaseComponent *> *bizComponents;

    void createBaseComponents();
    void createBizComponents();

    void loadBaseComponents();
    void loadBizComponents();
signals:

public slots:
};

#endif // COMPONENTLOADER_H
