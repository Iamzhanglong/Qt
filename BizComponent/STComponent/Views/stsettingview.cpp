#include "stsettingview.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QVariant>

#define VERTICAL_SPACING      20
#define HORIZONTAL_SPACING    50
#define ROW                   10

STSettingView::STSettingView(QWidget *parent) : QWidget(parent)
{
    this->checkBoxs = new QVector<QCheckBox *>();

    QCheckBox *checkBox = new QCheckBox();
    checkBox->setText("Emo");
    checkBox->setProperty("id", ST::STError_Emo);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock1");
    checkBox->setProperty("id", ST::STError_InterLock1);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock2");
    checkBox->setProperty("id", ST::STError_InterLock2);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock3");
    checkBox->setProperty("id", ST::STError_InterLock3);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock4");
    checkBox->setProperty("id", ST::STError_InterLock4);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock5");
    checkBox->setProperty("id", ST::STError_InterLock5);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("InterLock6");
    checkBox->setProperty("id", ST::STError_InterLock6);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak1");
    checkBox->setProperty("id", ST::STError_WaterLeak1);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak2");
    checkBox->setProperty("id", ST::STError_WaterLeak2);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak3");
    checkBox->setProperty("id", ST::STError_WaterLeak3);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak4");
    checkBox->setProperty("id", ST::STError_WaterLeak4);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak5");
    checkBox->setProperty("id", ST::STError_WaterLeak5);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak6");
    checkBox->setProperty("id", ST::STError_WaterLeak6);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak7");
    checkBox->setProperty("id", ST::STError_WaterLeak7);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WaterLeak8");
    checkBox->setProperty("id", ST::STError_WaterLeak8);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("Smoke1");
    checkBox->setProperty("id", ST::STError_Smoke1);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("Smoke2");
    checkBox->setProperty("id", ST::STError_Smoke2);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("Smoke3");
    checkBox->setProperty("id", ST::STError_Smoke3);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("PWCRFan");
    checkBox->setProperty("id", ST::STError_PWCRFan);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WSPR1Fan");
    checkBox->setProperty("id", ST::STError_WSPR1Fan);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WSPR2Fan");
    checkBox->setProperty("id", ST::STError_WSPR2Fan);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("ECABTemp");
    checkBox->setProperty("id", ST::STError_ECABTemp);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("PMCRTemp");
    checkBox->setProperty("id", ST::STError_PMCRTemp);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WSPR1Temp");
    checkBox->setProperty("id", ST::STError_WSPR1Temp);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WSPR2Temp");
    checkBox->setProperty("id", ST::STError_WSPR2Temp);
    checkBoxs->append(checkBox);

    checkBox = new QCheckBox();
    checkBox->setText("WHCRTemp");
    checkBox->setProperty("id", ST::STError_WHCRTemp);
    checkBoxs->append(checkBox);


    QGridLayout *layout = new QGridLayout();
    layout->setHorizontalSpacing(HORIZONTAL_SPACING);
    layout->setVerticalSpacing(VERTICAL_SPACING);

    int row = 0;
    int column = 0;
    for (int i = 0; i < checkBoxs->count(); i++)
    {
        row = i % ROW;
        column = i / ROW;
        QCheckBox *checkBox = checkBoxs->at(i);
        layout->addWidget(checkBox, row , column, Qt::AlignLeft);
    }

    layout->setRowStretch(ROW + 1, 5);
    layout->setColumnStretch(column + 1, 5);

    this->setLayout(layout);

    this->bind();
}

void STSettingView::bind()
{
    QVector<QCheckBox *>::iterator iter;
    for (iter = this->checkBoxs->begin(); iter != this->checkBoxs->end(); iter++)
    {
        connect(*iter, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    }
}

void STSettingView::onCheckBoxStateChanged(int state)
{
    QObject *object = QObject::sender();
    if (object == nullptr)
    {
        return;
    }
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(object);

    ST::STState errorState;
    switch (state)
    {
    case Qt::Checked:
        errorState = ST::STState_error;
        break;
    case Qt::Unchecked:
        errorState = ST::STState_normal;
        break;
    default:
        break;
    }
    emit errorStateChanged(checkBox->property("id").value<ST::STErrorId>(), errorState);
}
