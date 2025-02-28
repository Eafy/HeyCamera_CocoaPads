//
//  HHErrno.h
//  HeyCamera
//
//  Created by eafy on 2020/9/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, HH_ERRNO) {
    HH_ERRNO_NoErr = 0,                     //成功，无错误
    HH_ERRNO_NONE = HH_ERRNO_NoErr,
    
    HH_ERRNO_OTA_DOWNLOAD    =    100100,    //开始下载升级文件
    HH_ERRNO_OTA_VERIFY    =    100101,    //下载成功，开始校验文件（暂未用到）
    HH_ERRNO_OTA_UPGRADE    =    100102,    //校验成功，开始烧录分区（暂未用到）
    HH_ERRNO_OTA_FINISH    =    100103,    //升级完成
    HH_ERRNO_OTA_VERSION_IS_LATEST    =    100104,    //版本是最新的
    HH_ERRNO_OTA_UPGRADING    =    100105,    //正在升级中
    HH_ERRNO_OTA_START    =    100106,    //开始升级程序
    
    HH_ERRNO_CMD_PARAM_FAIL    =    -100000,    //参数无效，如参数范围不对
    HH_ERRNO_CMD_NOT_SUPPORT    =    -100001,    //不支持该指令
    HH_ERRNO_CMD_UNKNOWN_FAIL    =    -100002,    //未知错误（固件端分析）
    HH_ERRNO_CMD_SEND_FORMAT_FAIL    =    -100003,    //发送指令格式错误（如APP和设备的版本差异大导致指令不匹配）
    HH_ERRNO_CMD_RECV_FORMAT_FAIL    =    -100004,    //接收到的指令格式错误（如APP和设备的版本差异大导致指令不匹配）
    HH_ERRNO_CMD_RUN_FAIL    =    -100005,    //指令执行失败（设备端分析原因）
    HH_ERRNO_CMD_IS_RUNNING    =    -100006,    //指令正在执行
    
    HH_ERRNO_OTA_OVERTIME    =    -100100,    //下载失败，网络超时
    HH_ERRNO_OTA_FILE_NOEXIST    =    -100101,    //下载失败，文件不存在
    HH_ERRNO_OTA_VERIFY_FAIL    =    -100102,    //校验失败（暂未用到）
    HH_ERRNO_OTA_MODEL_FAIL    =    -100103,    //设备型号错误/服务器不支持升级该设备
    
    HH_ERRNO_PLAYBACK_FINISH    =    100200,    //文件回放完毕
    HH_ERRNO_PLAYBACK_FILE_NOT_EXIST    =    -100200,    //文件不存在
    HH_ERRNO_PLAYBACK_FILE_READ_FAIL    =    -100201,    //文件读取失败
    HH_ERRNO_PLAYBACK_FILE_LIST_EMPTY    =    -100202,    //文件列表为空
    HH_ERRNO_PLAYBACK_MAX_PLAYBACK_NUM    =    -100203,    //已达到最大同时回放数量
    
    HH_ERRNO_PTZ_PRESET_FULL    =    -100300,    //云台预置位满
    HH_ERRNO_PTZ_LIMIT    =    -100301,    //云台限位触发
};

NS_ASSUME_NONNULL_BEGIN

@interface HHErrno : NSObject

@property (nonatomic, assign) NSInteger errCode;        //错误码
@property (nonatomic, strong) NSString *errMsg;         //错误信息

/// 生成错误信息对象
/// @param errCode 错误码
/// @param errMsg 错误信息
+ (HHErrno *)initWithCode:(NSInteger)errCode msg:(NSString *)errMsg;

@end

NS_ASSUME_NONNULL_END
