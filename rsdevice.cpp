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

void rsdevice::enableStream(){
    streamEnable = true;
    dev->enable_stream(rs::stream::color, 640, 480, rs::format::rgb8, 60);
    dev->enable_stream(rs::stream::depth,640,480, rs::format::z16, 60);
    dev->start();
}

uchar * rsdevice::getFrameData(){
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

float rsdevice::getDistance(int x, int y){
    uint16_t *depthImage = (uint16_t *) dev->get_frame_data(rs::stream::depth);
    float scale = dev->get_depth_scale();
    rs::intrinsics depthIntrin = dev->get_stream_intrinsics(rs::stream::depth);
    uint16_t depthValue = depthImage[y * depthIntrin.width + x];
    float depthInMeters = depthValue * scale;
    return depthInMeters;
}
