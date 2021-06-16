//
//  HHCameraDelegate.h
//  HeyCamera
//
//  Created by eafy on 2020/9/24.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#ifndef HHCameraDelegate_h
#define HHCameraDelegate_h

#import <Foundation/Foundation.h>
#import "HHFrameInfo.h"
#import "HHErrno.h"
#import <ZJMediaPlayer/ZJMediaStreamPlayer.h>

@class HHCamera;
@class HHDeviceConnectInfo;

/// 连接状态
typedef NS_ENUM(NSUInteger, HHConnectStatus) {
    HHConnectStatusNone = 0,
    HHConnectStatusConnecting = 1,            //正在连接
    HHConnectStatusConnected,                 //已连接
    HHConnectStatusFailed,                    //连接失败
    HHConnectStatusDisconnected,              //已连接，被断开
    HHConnectStatusHidOrPwdError,             //HID或密码错误
};

/// 对接状态
typedef NS_ENUM(NSUInteger, HHTalkStatus) {
    HHTalkStatusNone = 0,
    HHTalkStatusPreparing = 1,            //准备中
    HHTalkStatusStarting,                 //正在播放
    HHTalkStatusStop,                    //停止
    HHTalkStatusFailed,                //播放失败
    HHTalkStatusTalking,                //正在对讲，勿重复开始
};

@protocol HHCameraDelegate <NSObject>
@required

/// 设备连接状态
/// @param camera 设备
/// @param status 状态
- (void)didConnectStatusWithCamera:(HHCamera * _Nullable)camera status:(HHConnectStatus)status error:(HHErrno * _Nullable)error;

/// 对讲播放状态
/// @param camera 设备
/// @param status 状态
- (void)didAudioTalkStatusWithCamera:(HHCamera * _Nullable)camera status:(HHTalkStatus)status;

@optional

/// 接收帧信息（美妙）
/// @param camera 设备
/// @param info 帧信息
- (void)didReceiveFrameInfoWithCamera:(HHCamera * _Nullable)camera info:(HHFrameInfo * _Nullable)info;

/// 搜索局域网的设备
/// @param infoArray 设备信息
- (void)didSearchDeviceWithInfo:(NSArray<HHDeviceConnectInfo *> * _Nullable)infoArray;

/// 视频录制回调函数
/// @param status 录制状态
/// @param filePath 录制的实际路径
/// @param errCode 错误码，0表示无错误
- (void)didMediaPlayerRecord:(HHCamera *_Nonnull)camera status:(ZJ_MEDIA_RECORD_STATUS)status path:(NSString *_Nullable)filePath errCode:(NSInteger)errCode;

@end

#endif /* HHCameraDelegate_h */
