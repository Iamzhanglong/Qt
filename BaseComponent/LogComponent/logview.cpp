#include "logview.h"
#include <QPainter>
#include <QPaintEvent>
#include <QObject>
#include <QStyleOption>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QFont>
#include <QDateTime>

LogView::LogView(QWidget *parent) : QWidget(parent)
{
    this->setMinimumHeight(200);
    this->logText = new QTextEdit();
    this->logText->setReadOnly(true);
    this->logText->setFont(QFont("Consloas", 11));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(this->logText);
    this->setLayout(layout);
}

void LogView::addText(QString &str)
{
    this->logText->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    //当文本数量超出一定范围就清除
//    if(this->logText->toPlainText().size()>1024*4)
//    {
//        this->logText->clear();
//    }

    QDateTime currentTime = QDateTime::currentDateTime();
    QString logStr = "[" + currentTime.toString("yy-MM-dd hh:mm:ss.zzz") + "]:" + str + "\n";

    this->logText->insertPlainText(logStr);
    //移动滚动条到底部
    QScrollBar *scrollbar = this->logText->verticalScrollBar();
    if(scrollbar)
    {
      scrollbar->setSliderPosition(scrollbar->maximum());
    }
}

void LogView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
