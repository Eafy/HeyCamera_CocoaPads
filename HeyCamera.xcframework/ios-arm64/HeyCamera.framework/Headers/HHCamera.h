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

/// 视频是否开启
- (BOOL)isValidVideo;

/// 音频是否开启
- (BOOL)isValidAudio;

/// 对讲是否开启
- (BOOL)isValidTalk;

/// 设置播放的缓存队列时间
/// @param pursueTime 设置追赶时间，默认3秒
- (void)setMediaPursueTime:(NSInteger)pursueTime;

/// 设置降噪级别（0~3），0表示关闭
/// @param nLevel 级别，默认0
- (void)setDenoiseLevel:(NSUInteger)nLevel;

/// 设置是否音视频同步
/// @param sync 是否同步，默认NO
- (void)setMediaSyncMode:(BOOL)sync;

#pragma mark - 录制相关

/// 截屏
- (UIImage *_Nullable)snapshot;

/// 开始录制视频
/// @param filePath filePath 保存视频的沙盒路径，必须以.mp4为文件后缀
- (void)startRecord:(NSString *_Nonnull)filePath;

/// 停止视频录制(如视频中断，则会自动停止录像)
- (void)stopRecord;

/// 是否正在录制视频
- (BOOL)isRecording;

/// 获取正在录制视频的时长(毫秒)
- (long)getRecordDuration;

@end

NS_ASSUME_NONNULL_END
