#include "stsettingview.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QVariant>
#include "BizComponent/STComponent/stcomponentconst.h"

#define VERTICAL_SPACING      20
#define HORIZONTAL_SPACING    100
#define COLUMN                 2

STSettingView::STSettingView(QWidget *parent) : QWidget(parent)
{
    QVector<QCheckBox *> *checkBoxs = new QVector<QCheckBox *>();

    this->waterLeakCheck = new QCheckBox();
    this->waterLeakCheck->setText("WaterLeak");
    //QVariant var = QVariant::fromValue(STError::STError_WarterLeak);
    this->waterLeakCheck->setProperty("id", STError::STError_WarterLeak);
    checkBoxs->append(this->waterLeakCheck);

    this->airLeakCheck = new QCheckBox();
    this->airLeakCheck->setText("AirLeak");
    this->airLeakCheck->setProperty("id", STError::STError_AirLeak);
    checkBoxs->append(this->airLeakCheck);

    this->overrideLeakCheck = new QCheckBox();
    this->overrideLeakCheck->setText("OverRide");
    this->overrideLeakCheck->setProperty("id", STError::STError_Override);
    checkBoxs->append(this->overrideLeakCheck);


    QGridLayout *layout = new QGridLayout();
    layout->setHorizontalSpacing(HORIZONTAL_SPACING);
    layout->setVerticalSpacing(VERTICAL_SPACING);

    int row = 0;
    int column = 0;
    for (int i = 0; i < checkBoxs->count(); i++)
    {
        row = i / COLUMN;
        column = i % COLUMN;
        QCheckBox *checkBox = checkBoxs->at(i);
        layout->addWidget(checkBox, row , column, Qt::AlignLeft);
    }

    layout->setRowStretch(row + 1, 5);
    layout->setColumnStretch(COLUMN + 1, 5);

    this->setLayout(layout);

    delete checkBoxs;

    connectAction();
}

void STSettingView::connectAction()
{
    connect(this->waterLeakCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(this->airLeakCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(this->overrideLeakCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
}

void STSettingView::onCheckBoxStateChanged(int state)
{
    QObject *object = QObject::sender();
    if (object == nullptr)
    {
        return;
    }
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(object);
    qDebug("%d\n", checkBox->property("id").value<STError::STErrorId>());
}
