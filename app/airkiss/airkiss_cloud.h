﻿/*
 * airkiss_cloud.h
 *
 *  Created on: 2016年3月31日
 *      Author: itmaktub
 */

#ifndef APP_USER_AIRKISS_CLOUD_H_
#define APP_USER_AIRKISS_CLOUD_H_

#if defined(GLOBAL_DEBUG)
#define AIRKISS_CLOUD_DEBUG(format, ...)  log_printf("AIRKISS_CLOUD: ", format,  ##__VA_ARGS__)
#else

#define AIRKISS_CLOUD_DEBUG os_printf
#endif

#define AIRKISS_HEAP_MAX    1024*4

//deviceid:gh_299f23825e4b_f844ed61ae346b99
//TODO
#define DEVICE_LICENCE  "9E6A1363995DEF7D2C34A27A73DAEC41DF37DF3F793428DD2E287001F776D4467D4B4EBA203557124CF55A09F83A4F7CBC6CB578600630D81F4686B14D944291D9059E020E9547ADC11F72E0B4D85CEB"

typedef enum airkiss_cloud_receive_msg_t
{
    AIRKISS_CLOUD_NOTIFY_MSG,
    AIRKISS_CLOUD_RESPONSE_MSG,
    AIRKISS_CLOUD_EVENT_MSG
}airkiss_cloud_receive_msg_t;

typedef enum airkiss_cloud_error_msg_t
{
    AIRKISS_CLOUD_ERROR_OK            = 0,                    //  0   厂家异步处理成功
    AIRKISS_CLOUD_ERROR_BUSY          = 11500,                //  1 150 0   系统繁忙
    AIRKISS_CLOUD_ERROR_NOT_CONNECT   = 11501,                //  1 150 1   设备没联网
    AIRKISS_CLOUD_ERROR_POWER_OFF     = 11502,                //  1 150 2   设备已经关机
    AIRKISS_CLOUD_ERROR_UNKOWN        = 11503                 //  1 150 3   设备暂时无法操作，请微信平台稍后重试
}airkiss_cloud_error_msg_t;

enum
{
    AIRKISS_CLOUD_FUNC_ABILITY        = 0x0001,              //    0x0001  微信硬件平台能力项业务FuncID
    AIRKISS_CLOUD_FUNC_FIRMWARE       = 0x0020                //    0x0020  微信硬件平台固件管理业务FuncID
};

uint8_t airkiss_cloud_start(void);

typedef int (* airiss_cloud_receive_notify_callback_t)(const uint8_t *dat, uint32_t len);
typedef void (* airiss_cloud_initdone_callback_t)(void);


#define airkiss_cloud_send_ablity_msg(dat)  airkiss_cloud_sendmessage(AIRKISS_CLOUD_FUNC_ABILITY, dat, os_strlen(dat));

//消息回调处理注册接口
void airiss_cloud_receive_notify_callback_register(airiss_cloud_receive_notify_callback_t airiss_cloud_receive_notify_callback);
//airkiss cloud 初始化成功后的回调注册接口
void airiss_cloud_initdone_callback_register(airiss_cloud_initdone_callback_t airiss_cloud_initdone_callback);


#endif /* APP_USER_AIRKISS_CLOUD_H_ */
