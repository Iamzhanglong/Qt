#ifndef OPERATIONVIEW_H
#define OPERATIONVIEW_H

#include <QWidget>

class OperationView : public QWidget
{
    Q_OBJECT
public:
    explicit OperationView(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // OPERATIONVIEW_H
