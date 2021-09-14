#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1050,649);
    w.setWindowTitle("植物大战僵尸");
    w.show();
    w.setWindowIcon(QIcon(":/image/images/Logo.jpg"));

    return a.exec();
}
