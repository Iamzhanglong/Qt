#ifndef STVIEW_H
#define STVIEW_H

#include <QWidget>
#include "BizComponent/STComponent/Views/stmenuview.h"
#include "BizComponent/STComponent/Views/stsettingview.h"
#include "BizComponent/STComponent/Views/stsignaltowerview.h"

class STView : public QWidget
{
    Q_OBJECT
public:
    explicit STView(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event);

    STMenuView *menuView;
    STSettingView *settingView;
    STSignalTowerView *signaltowerView;
signals:

public slots:
};

#endif // STVIEW_H
