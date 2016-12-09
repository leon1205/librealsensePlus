#ifndef RSDEVICE_H
#define RSDEVICE_H
#include <librealsense/rs.hpp>


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
    QString getDevName(){
        return devName;
    }

    QString getDevSerial(){
        return devSerial;
    }

    QString getDevFwVersion(){
        return devFwVersion;
    }

    QString getCamType(){
        return devCamType;
    }

    QString getIspFwVersion(){
        return devIspFwVersion;
    }

public:
    rsdevice();
    void initRsDevice();
    void enableStream();
    uchar * getFrameData();
    bool isSteamEnable();
};

#endif // RSDEVICE_H
