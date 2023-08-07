#include "mainwindow.h"

#include <QApplication>
#include <QProcessEnvironment>

int main(int argc, char *argv[])
{
    QProcessEnvironment::systemEnvironment().insert("NSRequiresAquaSystemAppearance", "YES");

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags()&~Qt::WindowMinMaxButtonsHint|Qt::WindowMinimizeButtonHint);
    w.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    w.showMaximized();
    return a.exec();
}
