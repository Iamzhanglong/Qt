#ifndef STSETTINGVIEW_H
#define STSETTINGVIEW_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QObject>
#include "BizComponent/STComponent/stcomponentconst.h"

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
    void errorStateChanged(ST::STErrorId errorId, ST::STState state);
public slots:
    void onCheckBoxStateChanged(int state);
};

#endif // STSETTINGVIEW_H
