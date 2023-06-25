#include "stsettingview.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QVariant>

#define VERTICAL_SPACING      20
#define HORIZONTAL_SPACING    100
#define COLUMN                 2

STSettingView::STSettingView(QWidget *parent) : QWidget(parent)
{
    QVector<QCheckBox *> *checkBoxs = new QVector<QCheckBox *>();

    this->waterLeakCheck = new QCheckBox();
    this->waterLeakCheck->setText("WaterLeak");
    this->waterLeakCheck->setProperty("id", ST::STError_WaterLeak);
    checkBoxs->append(this->waterLeakCheck);

    this->smokeCheck = new QCheckBox();
    this->smokeCheck->setText("AirLeak");
    this->smokeCheck->setProperty("id", ST::STError_Smoke);
    checkBoxs->append(this->smokeCheck);

    this->emoCheck = new QCheckBox();
    this->emoCheck->setText("Emo");
    this->emoCheck->setProperty("id", ST::STError_Emo);
    checkBoxs->append(this->emoCheck);


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

    this->bind();
}

void STSettingView::bind()
{
    connect(this->waterLeakCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(this->smokeCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
    connect(this->emoCheck, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));
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
