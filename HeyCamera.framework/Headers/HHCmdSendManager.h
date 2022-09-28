//
//  HHCmdSendManager.h
//  HeyCamera
//
//  Created by eafy on 2020/10/29.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HHDeviceConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class HHCamera;

//回调结果状态类型
typedef NS_ENUM(NSUInteger, HHCmdSendResultType) {
    HHCmdSendResultTypeSuccess = 0,    //成功
    HHCmdSendResultTypeFailed,         //失败
    HHCmdSendResultTypeTimeout         //超时
};

/// 命令发送的回调
/// @param resultType 成功、失败或超时
/// @param dataDic 回调的数据，可能为nil，可转模型：HHResultInfo或继承它更复杂的模型
typedef void (^HHCmdRecvResultCB)(NSString *hid, HHCmdSendResultType resultType, NSDictionary *_Nullable dataDic);

@interface HHCmdSendManager : NSObject

/// 摄像头对象
@property (nonatomic,strong) HHCamera *_Nullable camera;

/// 连接超时时间（秒级），默认15.0
@property (nonatomic,assign) NSTimeInterval timeout;

/// 设备通知已断开
- (void)noticeDisconnect;

#pragma mark - 基本信息

/// 设备信息
/// @param completion 回调
- (BOOL)getDeviceSetting:(void (^)(NSString *hid, HHDeviceInfo *_Nullable info))completion;

/// 设备版本和存储信息
/// @param completion 回调
- (BOOL)getDeviceStatus:(void (^)(NSString *hid, HHResultStorageInfo *_Nullable info))completion;

/// 更改设备名称
/// @param name 设备名称
/// @param completion 回调
- (BOOL)setDeviceName:(NSString *)name completion:(HHCmdRecvResultCB)completion;

/// 更改设备密码
/// @param oldPwd 当前密码
/// @param newPwd 新密码
/// @param completion 回调
- (BOOL)changePassword:(NSString *)oldPwd newPwd:(NSString *)newPwd completion:(HHCmdRecvResultCB)completion;

#pragma mark - 摄像机设置

/// 是否显示时间戳等水印
/// @param bShow YES：显示
/// @param completion 回调
- (BOOL)showOSD:(BOOL)bShow completion:(HHCmdRecvResultCB)completion;

/// 画面旋转
/// @param mode 选择模式，0：无，1：旋转
/// @param completion 回调
- (BOOL)flipVideo:(int)mode completion:(HHCmdRecvResultCB)completion;

/// 夜视功能
/// @param mode 夜视模式
/// @param completion 回调
- (BOOL)setNightMode:(HH_CONFIG_NIGHT_MODE)mode completion:(HHCmdRecvResultCB)completion;

/// 设备视频录制开关
/// @param enable 是否开启录制
/// @param completion 回调
- (BOOL)setRecordEnable:(BOOL)enable completion:(HHCmdRecvResultCB)completion;

/// 设备视频录制模式
/// @param mode 录制模式
/// @param completion 回调
- (BOOL)setRecordMode:(HH_CONFIG_RECORD_MODE)mode completion:(HHCmdRecvResultCB)completion;

/// 推出SD卡
/// @param completion 回调
- (BOOL)pushSdWithCompletion:(HHCmdRecvResultCB)completion;

/// 格式化SD卡
/// @param completion 回调
- (BOOL)formatSdWithCompletion:(HHCmdRecvResultCB)completion;

/// 报警开关
/// @param enable 是否开启
/// @param completion 回调
- (BOOL)setAlarmEnable:(BOOL)enable completion:(HHCmdRecvResultCB)completion;

/// 报警模式
/// @param mode 报警模式
/// @param completion 回调
- (BOOL)setAlarmMode:(HH_CONFIG_ALARM_MODE)mode completion:(HHCmdRecvResultCB)completion;

/// 报警时段
/// @param schedule 时段参数
/// @param completion 回调
- (BOOL)setAlarmSchedule:(HHAlarmSchedule * _Nonnull)schedule completion:(HHCmdRecvResultCB)completion;

/// WIFI配置
/// @param ssid WIFI名称
/// @param pwd WIFI密码
/// @param mode 加密模式
/// @param completion 回调
- (BOOL)wifiConfig:(NSString *)ssid pwd:(NSString *)pwd mode:(NSInteger)mode completion:(HHCmdRecvResultCB)completion;

/// OTA升级
/// @param completion 回调
- (BOOL)otaUpdateWithCompletion:(HHCmdRecvResultCB)completion;

#pragma mark - 视频回放

/// 获取设备视频列表
/// @param completion 回调
- (BOOL)getPlaybackListWithCompletion:(HHCmdRecvResultCB)completion;

/// 开始/停止回放
/// @param mode 回放模式
/// @param time 回放时间
/// @param completion 回调，Json内容：”reclist“：历史视频列表，为UTC时间
- (BOOL)playback:(HH_PLAYBACK_MODE)mode time:(NSUInteger)time completion:(HHCmdRecvResultCB)completion;

#pragma mark - PTZ模式

/// PTZ方向设置
/// @param mode 方向模式
/// @param completion 回调
- (BOOL)setPtzDir:(HH_CONFIG_PTZDIR_MODE)mode completion:(HHCmdRecvResultCB)completion;

/// PTZ预设获取
/// @param completion 回调
- (BOOL)getPtzPresetWithCompletion:(HHCmdRecvResultCB)completion;

/// PTZ预设获取设置
/// @param ID 预设ID
/// @param completion 回调
- (BOOL)setPtzPresetWithID:(NSInteger)ID completion:(HHCmdRecvResultCB)completion;

/// 添加预设位置
/// @param name 预设名称
/// @param completion 回调
- (BOOL)addPtzPresetWithName:(NSString *)name completion:(HHCmdRecvResultCB)completion;

/// 删除预设位置
/// @param ID 预设ID
/// @param completion 回调
- (BOOL)delPtzPresetWithID:(NSInteger)ID completion:(HHCmdRecvResultCB)completion;

#pragma mark - 解绑

/// 解绑
/// @param completion 回调
- (BOOL)unbindWithCompletion:(HHCmdRecvResultCB)completion;

@end

NS_ASSUME_NONNULL_END
