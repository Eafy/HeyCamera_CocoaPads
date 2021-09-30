//
//  HHFrameInfo.h
//  HeyCamera
//
//  Created by eafy on 2020/11/7.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HHFrameInfo : NSObject

/// 视频宽度
@property (nonatomic, assign) NSUInteger videoWidth;
/// 视频高度
@property (nonatomic, assign) NSUInteger videoHeight;

/// 时间戳
@property (nonatomic, assign) NSUInteger timestamp;

/// 视频质量， 0:1080p 1:720p 2:360p
@property (nonatomic, assign) NSUInteger videoQuality;

/// 视频动态帧率
@property (nonatomic, assign) NSUInteger videoFPS;

/// 音视频动态码率（b/s）
@property (nonatomic, assign) NSUInteger bps;

/// 在线人数
@property (nonatomic, assign) NSUInteger onlineNm;

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
