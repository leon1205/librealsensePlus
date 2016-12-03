#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QLabel>

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "rsdevice.h"

namespace Ui {
class MainWindow;
}

using namespace cv;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPicName(QString name);
    QImage Mat2QImage(Mat& image);
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QPlainTextEdit* pTextEdit;
    rsdevice* dev;
    QString picName;
    QLabel* label;


};

#endif // MAINWINDOW_H
