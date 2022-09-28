//
//  HeyCamera.h
//  HeyCamera
//
//  Created by eafy on 2020/9/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "HHCamera.h"

#pragma mark -

NS_ASSUME_NONNULL_BEGIN

@interface HeyCamera : NSObject

/// 初始化SDK
/// @param key 授权Key
/// @param secret 授权secret
+ (BOOL)initSDKWithKey:(NSString *)key secret:(NSString *)secret;

/// 释放SDK
+ (BOOL)deinitSDK;

/// 创建绑定信息二维码(WiFi信息+语言类型)
/// @param ssid WiFi名称
/// @param password WiFi密码
/// @param language 语言类型，0：中文，1：英文
+ (UIImage * _Nullable)createBindQRCodeWithSSID:(NSString * _Nonnull)ssid password:(NSString * _Nonnull)password language:(NSInteger)language;

/// 创建绑定信息二维码(WiFi信息)
/// @param ssid WiFi名称
/// @param password WiFi密码
+ (UIImage * _Nullable)createBindQRCodeWithSSID:(NSString * _Nonnull)ssid password:(NSString * _Nonnull)password;

/// 创建更改语言类型二维码
/// @param language 语言类型，0：中文，1：英文
+ (UIImage * _Nullable)createLanguageQRCode:(NSInteger)language;

/// 开始监听绑定结果
/// @param completion 完成回调
+ (void)startListenBindResult:(void (^)(BOOL success, NSString *hid, NSString *password))completion;

+ (void)stopListenBind;

@end

NS_ASSUME_NONNULL_END
