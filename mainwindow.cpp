#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>

#include "BaseComponent/TabComponent/tabview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* widget = new QWidget(this);
    this->setCentralWidget(widget);

    this->loader = new ComponentLoader();

    LayoutManager *layoutManager = new LayoutManager();
    layoutManager->mainWindow = widget;
    this->loader->layoutManager = layoutManager;

    this->loader->loadComponents();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 空函数体，不做任何操作
}

MainWindow::~MainWindow()
{
    delete ui;
}

