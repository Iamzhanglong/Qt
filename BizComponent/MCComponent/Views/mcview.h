#ifndef MCVIEW_H
#define MCVIEW_H

#include <QWidget>
#include "BizComponent/MCComponent/Views/mctraceview.h"
#include "BizComponent/MCComponent/Views/mccontrolview.h"

class MCView : public QWidget
{
    Q_OBJECT
public:
    explicit MCView(QWidget *parent = nullptr);

    MCTraceView *traceView;
    MCControlView *controlView;
private:

signals:

public slots:
};

#endif // MCVIEW_H
