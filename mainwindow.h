#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QString>

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
    QImage mat2QImage(Mat& image);
    void paintEvent(QPaintEvent *event);
    void printfRsDevice();

private:
    Ui::MainWindow *ui;
    QPlainTextEdit* pTextEdit;
    rsdevice* dev;
    QString picName;
    QLabel* picLabel;
    QLabel* disInfoLabel;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MAINWINDOW_H
