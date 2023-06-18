#include "tabcomponent.h"

TabComponent::TabComponent()
{

}

void TabComponent::componentDidLoad()
{
    BaseComponent::componentDidLoad();
    qDebug("TabComponent Did Load\n");

    this->view = new TabView();

    QPushButton *button1 = new QPushButton("1", NULL);
    button1->setStyleSheet("background-color:black;");
    this->view->addButton(button1);
    QPushButton *button2 = new QPushButton("2999999999999999999", NULL);
    button2->setStyleSheet("background-color:black;");

    this->view->addButton(button2);

    this->view->setStyleSheet("background-color:blue;");
    this->view->setFixedHeight(30);
}


QWidget *TabComponent::componentWidget()
{
    return this->view;
}
