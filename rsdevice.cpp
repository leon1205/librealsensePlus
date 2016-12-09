#include "rsdevice.h"


rsdevice::rsdevice()
{
   streamEnable = false;
}

void rsdevice::initRsDevice()
{
 devCount = ctx.get_device_count();

 dev = ctx.get_device(0);
 devName = QString(QLatin1String(dev->get_name()));
 devSerial = QString(QLatin1String(dev->get_serial()));
 devFwVersion = QString(QLatin1String(dev->get_firmware_version()));
 devCamType = QString(QLatin1String(dev->get_info(rs::camera_info::camera_type)));
 devIspFwVersion = QString(QLatin1String(dev->get_info(rs::camera_info::isp_fw_version)));

}

void rsdevice::printfRsDevice(QPlainTextEdit* edit){

    QString printfStr = "\nUsing device 0,name: " +devName;
    edit->appendPlainText(printfStr);
    printfStr.clear();
    printfStr = "    Serial number: " + devSerial;
    edit->appendPlainText(printfStr);
    printfStr.clear();
    printfStr = "    Firmware version: " + devFwVersion;
    edit->appendPlainText(printfStr);
    printfStr.clear();

}

void rsdevice::enableStream(){
    streamEnable = true;
    dev->enable_stream(rs::stream::color, 640, 480, rs::format::rgb8, 60);
    dev->start();
}

uchar * rsdevice::getFrameDate(){
    dev->wait_for_frames();
    return (uchar *) dev->get_frame_data(rs::stream::color);
 //   Mat rgb_show;
 //   Mat rgb(480, 640, CV_8UC3, (uchar *) dev->get_frame_data(rs::stream::color));
 //   cvtColor(rgb, rgb_show, CV_BGR2RGB);
 //   return rgb_show;
}

bool rsdevice::isSteamEnable(){
    return streamEnable;
}
