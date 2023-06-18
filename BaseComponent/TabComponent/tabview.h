#ifndef TABVIEW_H
#define TABVIEW_H

#include <QWidget>
#include <QVector>
#include <QPushButton>

class TabView : public QWidget
{
    Q_OBJECT
public:
    explicit TabView(QWidget *parent = nullptr);
    void addButton(QPushButton *button);

protected:
    void paintEvent(QPaintEvent *);

private:
    QVector<QPushButton *> buttonArray;
signals:

};

#endif // TABVIEW_H
