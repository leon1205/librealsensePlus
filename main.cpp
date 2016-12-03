#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <cstdio>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
/*
    QString filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.jpg *.png *.bmp", 0);
    if (filename.isNull()) {
        return -1;
    }
    w.setPicName(filename);
*/
    w.show();
    return a.exec();
}
