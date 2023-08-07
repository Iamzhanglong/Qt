#include "mcview.h"
#include <QVBoxLayout>

MCView::MCView(QWidget *parent) : QWidget(parent)
{
    this->controlView = new MCControlView();

    this->traceView = new MCTraceView();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(this->controlView, 1);
    layout->addWidget(this->traceView, 9);

    this->setLayout(layout);
}
