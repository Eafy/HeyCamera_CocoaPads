//
//  HHCamera.h
//  HeyCamera
//
//  Created by eafy on 2020/9/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HHMonitor.h"
#import "HHErrno.h"
#import "HHCameraDelegate.h"
#import "HHCmdSendManager.h"

NS_ASSUME_NONNULL_BEGIN

@class HHMonitor;

@interface HHCamera : NSObject

/// Camera代理
@property (nonatomic,weak) id<HHCameraDelegate> delegate;
/// 设备HID
@property (nonatomic,readonly) NSString *hid;
/// 连接状态
@property (nonatomic,readonly) HHConnectStatus connectStatus;
/// 是否启动自动连接，默认启动
@property (nonatomic,assign) BOOL isAutoConnect;
/// 直连模式
@property (nonatomic,assign) BOOL isDirectMode;

/// 指令、设置
@property (nonatomic,strong) HHCmdSendManager *send;

/// 添加显示器视图
/// @param monitor 显示器
- (void)addMonitor:(HHMonitor * _Nonnull)monitor;

/// 移除显示器视图
- (void)removeMonitor;

#pragma mark -

/// 连接摄像头
/// @param hid 设备HID
/// @param password 设备密码
/// @return false：表示hid无效
- (BOOL)connect:(NSString * _Nonnull)hid password:(NSString * _Nonnull)password;

/// 断开连接
- (void)disConnect;

/// 是否已连接
- (BOOL)isConnected;

#pragma mark - 视频相关API

/// 开始直播/切换分辨率
/// @param quality 视频质量
- (BOOL)startLive:(HH_VIDEO_QUALITY)quality;

/// 停止直播
- (void)stopLive;

/// 开始对接
- (BOOL)startTalk;

/// 停止对接
- (void)stopTalk;

/// 开启音频（默认关闭音频）
- (BOOL)startAudio;

/// 关闭音频
- (void)stopAudio;

/// 视频是否开启或有效
- (BOOL)isValidVideo;

/// 音频是否开启或有效
- (BOOL)isValidAudio;

/// 对讲是否开启或有效
- (BOOL)isValidTalk;

@end

NS_ASSUME_NONNULL_END
