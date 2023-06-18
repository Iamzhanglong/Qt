#ifndef LOGVIEW_H
#define LOGVIEW_H

#include <QWidget>

class LogView : public QWidget
{
    Q_OBJECT
public:
    explicit LogView(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // LOGVIEW_H
