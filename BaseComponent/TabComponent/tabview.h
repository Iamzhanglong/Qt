#ifndef TABVIEW_H
#define TABVIEW_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QString>

class TabView : public QWidget
{
    Q_OBJECT
public:
    explicit TabView(QWidget *parent = nullptr);
    void addTab(QString tabId, QString btnTitle);

protected:
    void paintEvent(QPaintEvent *);

private:
    QVector<QPushButton *> buttonArray;
signals:
    void buttonDidCliked(QString tabId);
};

#endif // TABVIEW_H
