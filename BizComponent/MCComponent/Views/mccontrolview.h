#ifndef MCCONTROLVIEW_H
#define MCCONTROLVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MCControlView : public QWidget
{
    Q_OBJECT
public:
    explicit MCControlView(QWidget *parent = nullptr);
private:
    QLabel *ipName;
    QLineEdit *mcIp;
    QLabel *portName;
    QLineEdit *mcPort;
    QPushButton *connectButton;
signals:
    void switchConnectState(QString ip, int port);
public slots:
    void onConnectStateChanged(bool state);
    void connectBtnClicked();
};

#endif // MCCONTROLVIEW_H
