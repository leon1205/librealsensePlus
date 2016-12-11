#ifndef RSDEVICE_H
#define RSDEVICE_H
#include <librealsense/rs.hpp>
#include <QString>

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
    float getDistance(int x,int y);
};

#endif // RSDEVICE_H
