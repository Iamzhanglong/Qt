#include "mctraceview.h"
#include <QVBoxLayout>

MCTraceView::MCTraceView(QWidget *parent) : QWidget(parent)
{
    this->chart = new QChart();

    this->series = new QSplineSeries(this);


    this->xAxis = new QValueAxis();
    this->xAxis->setRange(0, 10);
    this->xAxis->setTickCount(5);
    this->chart->addAxis(this->xAxis, Qt::AlignBottom);

    this->yAxis = new QValueAxis();
    this->yAxis->setRange(0, 10);
    this->chart->addAxis(this->yAxis, Qt::AlignLeft);

    this->chart->addSeries(this->series);

    this->series->attachAxis(this->xAxis);
    this->series->attachAxis(this->yAxis);

    this->chartView = new QChartView();

    this->chartView->setChart(this->chart);

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(this->chartView);

    this->setLayout(layout);
}

void MCTraceView::addPoint(qreal x, qreal y)
{
    this->series->append(x, y);

    if(x > this->chart->plotArea().width())
    {
        qreal dx = this->chart->plotArea().width() / 10;
        this->chart->scroll(dx, 0);
    }
}

void MCTraceView::updateCoordinate(qreal x, qreal y)
{
    this->addPoint(x, y);
}

