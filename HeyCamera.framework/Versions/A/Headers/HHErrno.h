//
//  HHErrno.h
//  HeyCamera
//
//  Created by eafy on 2020/9/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HH_ERRNO_NONE 0     //成功，无错误
#define HH_ERRNO_DEVICE_DISCONNECT  -1     //设备未连接

#define HH_ERRNO_RUNNING   100     //异步操作时，返回该值代表已开始(如格式化SD 卡)
#define HH_ERRNO_FILE_READ_END 200     //文件读取完毕时返回该值
#define HH_ERRNO_NEXT_DATA 300      //请求队列中下一条数据时返回该值
#define HH_ERRNO_OTA_DOWNLOAD 1000  //正在下载升级文件
#define HH_ERRNO_OTA_VERIFY   1001  //下载成功，开始校验文件
#define HH_ERRNO_OTA_UPGRADE  1002  //校验成功，开始升级
#define HH_ERRNO_OTA_FINISH   1003  //升级成功
#define HH_ERRNO_RUN_FAIL -100      //指令执行失败
#define HH_ERRNO_PARAM_FAIL   -101  //参数无效，如参数范围不对
#define HH_ERRNO_NON_SUPPORT  -102  //不支持该指令
#define HH_ERRNO_UNINIT   -103      //功能未初始化
#define HH_ERRNO_INIT_FAIL    -104  //功能初始化失败
#define HH_ERRNO_NULL_FAIL    -105  //传入的参数为空
#define HH_ERRNO_DATA_OVER    -106  //数据超过了最大大小
#define HH_ERRNO_DATA_SIZEFAIL    -107  //数据大小与实际大小不一致
#define HH_ERRNO_MEM_FAIL -108  //系统内存不足
#define HH_ERRNO_NO_KEY   -109  //没有找到解析的字符，如传的KEY错误
#define HH_ERRNO_KEY_PARAM_FAIL   -110  //字符对应的参数不正确
#define HH_ERRNO_IS_RUNNING   -111  //调用的指令正在运行，则返回该值。
#define HH_ERRNO_FILE_OPEN_FAIL   -200  //打开失败
#define HH_ERRNO_FILE_READ_FAIL   -201  //读失败
#define HH_ERRNO_FILE_WRITE_FAIL  -202  //写失败
#define HH_ERRNO_FILE_NONEXIST    -203  //文件不存在
#define HH_ERRNO_PATH_NONEXIST    -204  //路径不存在
#define HH_ERRNO_DATA_FULL    -300  //数据已满
#define HH_ERRNO_DATA_EMPTY   -301  //数据空
#define HH_ERRNO_DATA_EXIST   -302  //数据已存在
#define HH_ERRNO_CONNECT_FAIL -400   //连接失败
#define HH_ERRNO_DISCONNECT -401    //断开连接
#define HH_ERRNO_SEND_FAIL -402     //发送失败
#define HH_ERRNO_RECV_OVERTIME    -403 //执行超时
#define HH_ERRNO_DECODE_INIT_FAIL -500 //解码初始化失败
#define HH_ERRNO_DECODE_FAIL  -501 //解码失败
#define HH_ERRNO_ENCODE_INIT_FAIL -502 //编码初始化失败
#define HH_ERRNO_ENCODE_FAIL  -503 //编码失败
#define HH_ERRNO_RECORD_INIT_FAIL -504 //采集初始化失败
#define HH_ERRNO_RECORD_FAIL  -505 //采集失败
#define HH_ERRNO_OTA_OVERTIME    -1000 //下载失败，网络超时
#define HH_ERRNO_OTA_FILE_NOEXIST    -1001 //下载失败，文件不存在
#define HH_ERRNO_OTA_VERIFY_FAIL -1002 //校验失败

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
