#ifndef MCTRACEVIEW_H
#define MCTRACEVIEW_H

#include <QWidget>
#include <QtCharts>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>

class MCTraceView : public QWidget
{
    Q_OBJECT
public:
    explicit MCTraceView(QWidget *parent = nullptr);
    void addPoint(qreal x, qreal y);

private:
    QChart *chart;
    QChartView *chartView;

    QValueAxis *xAxis;
    QValueAxis *yAxis;
    QSplineSeries *series;

signals:

public slots:
    void updateCoordinate(qreal x, qreal y);
};

#endif // MCTRACEVIEW_H
