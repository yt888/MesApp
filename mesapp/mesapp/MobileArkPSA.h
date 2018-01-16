 //
//  MobileArkPSA.h
//  MobileArkPSA
//
//  Created by liqiang on 13-8-27.
//  Copyright (c) 2013年 fiberhome. All rights reserved.
//

#import <Foundation/Foundation.h>


//@protocol FHPushDelegate <NSObject>    
//
//-(void)pushMethod:(NSString *)method response:(NSDictionary*)data;
//
//@end

@interface MobileArkPSA : NSObject

////初始化参数
//+(void)setup;

//设置委托
+(void)setDelegate:(id)delegate;

//设置deviceToken
+(void)registerDeviceToken:(NSData *)deviceToken;

//设置push服务器url
+(void)setIp:(NSString *)ip andPort:(NSString *)port;

//设置tag
+(void)setTag:(NSString *)tag;

//获取secretToken
+(NSString *)secretToken;

//获取超时时长
+(float)tokenTimeOut;

//用户名
+(NSString *)userName;


//推送注册
+(void)pushRegister;

//推送注销
+(void)pushUnregister;

//启动MobileArk
+(void)startConnectSSO:(BOOL)refresh;

//单点登录新接口
+(void)ConnectSSO;

//对MobileArk传入的参数进行处理
+(void)handleConnectSSO:(NSURL *)url;

+(NSMutableDictionary *)handleLaunchedApp:(NSURL *)url;

//获取SDK版本号
+(NSString *)getVersion;

//获取pushToken
+(NSString *)getPushToken;

@end
