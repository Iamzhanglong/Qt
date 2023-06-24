#ifndef STMENUVIEW_H
#define STMENUVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class STMenuView : public QWidget
{
    Q_OBJECT
public:
    explicit STMenuView(QWidget *parent = nullptr);

private:
    QPushButton *startButton;
    QLabel *serverIpName;
    QLineEdit *serverIp;
    QLabel *serverportName;
    QLineEdit *serverport;

    QString getLocalIp();
    void bind();

signals:
    void startServer(quint16 port);
    void stopServer();

public slots:
    void startButtonClicked();
};

#endif // STMENUVIEW_H
