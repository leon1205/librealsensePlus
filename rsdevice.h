#ifndef RSDEVICE_H
#define RSDEVICE_H
#include <librealsense/rs.hpp>
#include <QPlainTextEdit>
#include <opencv2/opencv.hpp>
using namespace cv;

class rsdevice
{
public:
    rs::context ctx;
    rs::device * dev;
    int devCount;
    QString devName;
    QString devSerial;
    QString devFwVersion;
    QString devCamType;
    QString devIspFwVersion;
    QPlainTextEdit *plainTextEdit;
    bool streamEnable;

public:
    rsdevice();
    void printfRsDevice(QPlainTextEdit* edit);
    void initRsDevice();
    void enableStream();
    Mat getFrameDate();
    bool isSteamEnable();
};

#endif // RSDEVICE_H
