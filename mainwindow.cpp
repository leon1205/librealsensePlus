#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pTextEdit = ui->plainTextEdit;
    label = ui->label;
    dev = new rsdevice();
    dev->initRsDevice();
    printfRsDevice();

}

void MainWindow::printfRsDevice(){

    QString printfStr = "\nUsing device 0,name: " +dev->getDevName();
    pTextEdit->appendPlainText(printfStr);
    printfStr.clear();
    printfStr = "    Serial number: " + dev->getDevSerial();
    pTextEdit->appendPlainText(printfStr);
    printfStr.clear();
    printfStr = "    Firmware version: " + dev->devFwVersion;
    pTextEdit->appendPlainText(printfStr);
    printfStr.clear();
}

QImage MainWindow::mat2QImage(Mat& image)
{
    QImage img;

    if (image.channels()==3) {
        cvtColor(image, image, CV_BGR2RGB);
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_RGB888);
    } else if (image.channels()==1) {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_ARGB32);
    } else {
        img = QImage((const unsigned char *)(image.data), image.cols, image.rows,
                image.cols*image.channels(), QImage::Format_RGB888);
    }

    return img;
}

void MainWindow::setPicName(QString name){
    picName = name;
    Mat image = imread(picName.toStdString(), 1);
    QImage img = mat2QImage(image);
    label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::paintEvent(QPaintEvent *event){
   if(dev->isSteamEnable()){
      uchar* pRgb = dev->getFrameData();

      Mat rgb_show;
      Mat rgb(480, 640, CV_8UC3, pRgb);
      cvtColor(rgb, rgb_show, CV_BGR2RGB);

      QImage img = Mat2QImage(rgb_show);
      label->setPixmap(QPixmap::fromImage(img));
   }else{
       dev->enableStream();
   }


}

MainWindow::~MainWindow()
{
    delete ui;
}
