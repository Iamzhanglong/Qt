#include "mcview.h"
#include <QVBoxLayout>

MCView::MCView(QWidget *parent) : QWidget(parent)
{
    this->traceView = new MCTraceView();

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(this->traceView);

    this->setLayout(layout);
}
