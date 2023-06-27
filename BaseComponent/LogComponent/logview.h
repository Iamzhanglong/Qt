#ifndef LOGVIEW_H
#define LOGVIEW_H

#include <QWidget>
#include <QTextEdit>

class LogView : public QWidget
{
    Q_OBJECT
public:
    explicit LogView(QWidget *parent = nullptr);
    void addText(QString &str);
protected:
    void paintEvent(QPaintEvent *);
private:
    QTextEdit *logText;
signals:

public slots:
};

#endif // LOGVIEW_H
