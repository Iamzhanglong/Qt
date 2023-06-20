#ifndef STSETTINGVIEW_H
#define STSETTINGVIEW_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QObject>

class STSettingView : public QWidget
{
    Q_OBJECT
public:
    explicit STSettingView(QWidget *parent = nullptr);
private:
    QCheckBox *waterLeakCheck;
    QCheckBox *airLeakCheck;
    QCheckBox *overrideLeakCheck;

    void connectAction();
signals:

public slots:
    void onCheckBoxStateChanged(int state);
};

#endif // STSETTINGVIEW_H
