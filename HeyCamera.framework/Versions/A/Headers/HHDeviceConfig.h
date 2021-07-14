//
//  HHDeviceConfig.h
//  HeyCamera
//
//  Created by eafy on 2020/9/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//视频清晰度
typedef NS_ENUM(NSUInteger, HH_VIDEO_QUALITY) {
    HH_VIDEO_QUALITY_HIGH = 1,     //高清
    HH_VIDEO_QUALITY_MIDDLE = 2,   //标清
    HH_VIDEO_QUALITY_LOW = 3,      //流畅(未使用)
};

//设备本地录像的模式
typedef NS_ENUM(NSUInteger, HH_CONFIG_RECORD_MODE) {
    HH_CONFIG_RECORD_MODE_ALLDAY = 0,       //全天录像
    HH_CONFIG_RECORD_MODE_MD = 1,           //移动侦测录像
};

//报警模式
typedef NS_ENUM(NSUInteger, HH_CONFIG_ALARM_MODE) {
    HH_CONFIG_ALARM_MODE_ALLDAY = 0,       //全天录像
    HH_CONFIG_ALARM_MODE_SCHEDULE = 1,     //自定义时间段报警
};

//夜视模式
typedef NS_ENUM(NSUInteger, HH_CONFIG_NIGHT_MODE) {
    HH_CONFIG_NIGHT_MODE_AUTO = 0,          //自动
    HH_CONFIG_NIGHT_MODE_ON = 1,            //开启
    HH_CONFIG_NIGHT_MODE_OFF = 2,           //关闭
};

//云台模式
typedef NS_ENUM(NSUInteger, HH_CONFIG_PTZDIR_MODE) {
    HH_CONFIG_PTZDIR_STOP = 0,              //停止转动
    HH_CONFIG_PTZDIR_LEFT = 1,              //向左转动
    HH_CONFIG_PTZDIR_RIGHT = 2,             //向右转动
    HH_CONFIG_PTZDIR_UP = 3,                //向上转动
    HH_CONFIG_PTZDIR_DOWN = 4,              //向下转动
};

/// 回放模式
typedef NS_ENUM(NSUInteger, HH_PLAYBACK_MODE) {
    HH_PLAYBACK_START = 0,              //开始
    HH_PLAYBACK_STOP = 1,              //停止
    HH_PLAYBACK_PAUSE = 2,             //暂停
};

/// 音频格式
typedef NS_ENUM(NSUInteger, HH_AUDIOFMT_TYPE) {
    HH_AUDIOFMT_TYPE_AAC = 0,
    HH_AUDIOFMT_TYPE_G711A = 1,
};

#pragma mark -

/// 通用基类回复数据模型
@interface HHResultInfo : NSObject
/// 回复指令码
@property (nonatomic,assign) NSInteger cmdCode;
/// 回复结果
@property (nonatomic,assign) NSInteger resultType;
/// 执行结果状态
@property (nonatomic,assign) NSInteger result;
@end

#pragma mark -

/// 报警时段
@interface HHAlarmSchedule : NSObject
/// 第几个
@property (nonatomic,assign) NSInteger index;
/// 开关
@property (nonatomic,assign) int en;
/// 开始时间（时）
@property (nonatomic,assign) NSInteger startHour;
/// 开始时间（分）
@property (nonatomic,assign) NSInteger startMin;
/// 结束时间（时）
@property (nonatomic,assign) NSInteger stopHour;
/// 结束时间（分）
@property (nonatomic,assign) NSInteger stopMin;

@end

#pragma mark -

/// 设备配置信息
@interface HHDeviceInfo : HHResultInfo

/// 设备名称
@property (nonatomic,copy) NSString *name;
/// 录制开关
@property (nonatomic,assign) BOOL recEn;
/// 录制模式
@property (nonatomic,assign) HH_CONFIG_RECORD_MODE recMode;
/// 报警开关
@property (nonatomic,assign) BOOL alarmEn;
/// 报警模式
@property (nonatomic,assign) HH_CONFIG_ALARM_MODE alarmMode;
/// 报警时间段
@property (nonatomic,strong) NSArray<HHAlarmSchedule *> *alarmSch;
/// 夜视模式
@property (nonatomic,assign) HH_CONFIG_NIGHT_MODE nightMode;
/// 镜像开关
@property (nonatomic,assign) int flip;
/// 时间戳开关
@property (nonatomic,assign) BOOL osd;

- (HHAlarmSchedule *)alarmSchedule:(NSUInteger)index;

@end

#pragma mark -

@interface HHResultStorageInfo : HHResultInfo
/// 总容量
@property (nonatomic,assign) NSUInteger tsd;
/// 剩余容量
@property (nonatomic,assign) NSUInteger fsd;
/// 当前版本
@property (nonatomic,assign) NSUInteger ver;
/// 最新版本
@property (nonatomic,assign) NSUInteger latestVer;
/// 当前版本（自动转字符串）
@property (nonatomic,copy) NSString *version;
/// 当前版本（自动转字符串）
@property (nonatomic,copy) NSString *latestVersion;
/// 设备WiFi名称
@property (nonatomic,copy) NSString *ssid;
/// 设备IP
@property (nonatomic,copy) NSString *ip;
/// 在线人数
@property (nonatomic,assign) NSUInteger online;
@end

#pragma mark -

/// 设备连接信息
@interface HHDeviceConnectInfo : NSObject

/// 设备Id
@property (nonatomic,strong) NSString *deviceId;

/// 设备IP
@property (nonatomic,strong) NSString *ip;

@end

NS_ASSUME_NONNULL_END
