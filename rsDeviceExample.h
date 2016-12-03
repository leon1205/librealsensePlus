#ifndef RSEXAMPLE_H
#define RSEXAMPLE_H
#include <librealsense/rs.hpp>

class RsExample
{
public:
    rs::context ctx;

    printf("There are %d connected RealSense devices.\n", ctx.get_device_count());
    if(ctx.get_device_count() == 0) return EXIT_FAILURE;

    // This tutorial will access only a single device, but it is trivial to extend to multiple devices
    rs::device * dev = ctx.get_device(0);
    printf("\nUsing device 0, an %s\n", dev->get_name());
    printf("    Serial number: %s\n", dev->get_serial());
    printf("    Firmware version: %s\n", dev->get_firmware_version());
    printf("    RS Camera device name: %s\n ",dev->get_info(rs::camera_info::device_name));

    printf("    RS Camera device serial number: %s\n ",dev->get_info(rs::camera_info::serial_number));
    printf("    RS Camera device fw version: %s\n ",dev->get_info(rs::camera_info::camera_firmware_version));
 //   printf("    RS Camera device adapter board fw : %s\n ",dev->get_info(rs::camera_info::adapter_board_firmware_version));
 //   printf("    RS Camera device motion fw: %s\n ",dev->get_info(rs::camera_info::motion_module_firmware_version));
    printf("    RS Camera device camera type: %s\n ",dev->get_info(rs::camera_info::camera_type));
    printf("    RS Camera device ODM ID: %s\n ",dev->get_info(rs::camera_info::oem_id));
    printf("    RS Camera device ISP fw: %s\n ",dev->get_info(rs::camera_info::isp_fw_version));
    printf("    RS Camera device content fw: %s\n ",dev->get_info(rs::camera_info::content_version));
    printf("    RS Camera device module fw: %s\n ",dev->get_info(rs::camera_info::module_version));
    printf("    RS Camera device image module number: %s\n ",dev->get_info(rs::camera_info::imager_model_number));
//    printf("    RS Camera device built date: %s\n ",dev->get_info(rs::camera_info::build_date));
public:
    RsExample();
};

#endif // RSEXAMPLE_H
