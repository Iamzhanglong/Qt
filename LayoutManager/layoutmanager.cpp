#include "layoutmanager.h"
#include <QVBoxLayout>

LayoutManager::LayoutManager(QObject *parent) : QObject(parent)
{

}

void LayoutManager::layoutBaseComponents(QMap<QString, BaseComponent *> *components)
{
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setSpacing(2);
    layout->setContentsMargins(5, 10, 5, 10);

    if (components->contains(TAB_COMPONENT))
    {
        BaseComponent *component = components->value(TAB_COMPONENT);
        QWidget * widget = component->componentWidget();
        if (widget)
        {
            widget->setParent(this->mainWindow);
            layout->addWidget(widget, 1);
        }
    }

    if (components->contains(OPERATION_COMPONENT))
    {
        BaseComponent *component = components->value(OPERATION_COMPONENT);
        QWidget * widget = component->componentWidget();
        if (widget)
        {
            widget->setParent(this->mainWindow);
            layout->addWidget(widget, 15);
        }
    }

    if (components->contains(LOG_COMPONENT))
    {
        BaseComponent *component = components->value(LOG_COMPONENT);
        QWidget * widget = component->componentWidget();
        if (widget)
        {
            widget->setParent(this->mainWindow);
            layout->addWidget(widget, 5);
        }
    }

    this->mainWindow->setLayout(layout);
}
