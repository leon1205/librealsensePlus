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
    dev->printfRsDevice(pTextEdit);

}

QImage MainWindow::Mat2QImage(Mat& image)
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
    QImage img = Mat2QImage(image);
    label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::paintEvent(QPaintEvent *event){
   if(dev->isSteamEnable()){
      Mat rgb = dev->getFrameDate();
      QImage img = Mat2QImage(rgb);
      label->setPixmap(QPixmap::fromImage(img));
   }else{
       dev->enableStream();
   }


}

MainWindow::~MainWindow()
{
    delete ui;
}
