//
//  MobileArkAgent.h
//  MobileArkPSA
//
//  Created by liqiang on 13-8-27.
//  Copyright (c) 2013年 fiberhome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum
{
    REALTIME = 0,       //RealTime Send Policy
    BATCH = 1,          //Send Data When Start
    SEND_INTERVAL,      //Send Data When interval
} ReportPolicy;


static NSString *const NOTIFICATION_GESTURE_IS_WRONG =@"notification fhlock gesture is wrong";//手势密码输入错误
static NSString *const NOTIFICATION_CHECK_GESTURE_SUCCESS =@"notification fhlock check gesture";//手势密码验证成功

@protocol MobileArkAgentDelegate <NSObject>

- (void)callbackNetworkRequestSuccessed:(NSDictionary *)rspData;
- (void)callbackNetworkRequestFailed:(NSDictionary *)error;
- (void)callbackShowUploadProgress:(float)progress;
- (void)callbackUploadMCMFileSuccess;
- (void)callbackUploadMCMFileFailed:(NSDictionary *)dic;

@end

@interface MobileArkAgent : NSObject
{
    
}

@property (nonatomic, assign) id<MobileArkAgentDelegate> delegate;

+ (MobileArkAgent *)getInstance;

//+++++++george 6.19 +++++++++++
+ (void) setUniqueappkey:(NSString *)uniqueappkey;
+ (void) setClientgprsflow:(NSString *)clientgprsflow;
+ (void) setClientwififlow:(NSString *)clientwififlow;
+ (void) upDateNewVersionWith:(NSString*)appKey ServerURL:(NSString*)serverURL;
+ (void) feedBackWith:(NSString*)appKey ServerURL:(NSString*)serverURL With:(NSString *)feedBackString;

#pragma mark - MCM
+ (void)beginMCMTest;
+ (void)setServerUrl:(NSString *)urlStr;
+ (void)setServerUrl:(NSString *)urlStr
                ecid:(NSString *)ecidStr
         secretToken:(NSString *)secretTokenStr
            userName:(NSString *)userNameStr;
+ (void)getDocumentList:(NSDictionary*)dic;
+ (void)getDocDownloadUrlOrPreviewUrl:(NSDictionary*)dic;
+ (void)login:(NSDictionary*)dic;
+ (void)uploadFileWithFilePath:(NSString *)filePath
                    folderInfo:(NSMutableDictionary *)folderInfo
                      paramDic:(NSMutableDictionary *)paramDic;

+ (void) starRatingWith:(NSString*)appKey ServerURL:(NSString*)serverURL With:(NSString *)star;
//+++++++george 6.19 +++++++++++
+ (void) setEcid:(NSString *)ecid;

+ (void) setIsLogEnabled:(BOOL)isLogEnabled;

+ (void) startWithAppkey:(NSString*)appKey serverURL:(NSString *)serverURL;

+ (void) startWithAppkey:(NSString*)appKey ServerURL:(NSString*)serverURL FHEReportPolicy:(ReportPolicy)policy;

+ (void) stopApp;

+ (void) onEvent:(NSString *)eventId;

+ (void) onEvent:(NSString *)eventId label:(NSString *)label;

+ (void) startLogPageView:(NSString*)pagename;

+ (void) endLogPageView:(NSString*)pagename;

+ (void) uploadImmediately;

+ (void)setTimeInterval:(NSTimeInterval)interval; //Call this method before statWithAppKey.

+ (void)setUploadCount:(NSInteger)uploadCount;

#pragma 切换到后台
+(void)enterBackground;
#pragma 手势密码页面是addsubview上去
#pragma 切换到前台
+(void)willBecomeActive;
#pragma 展示手势密码
+(BOOL)showGestureView;

#pragma 第三方基于nav pushview手势密码的方式
+(BOOL)showNavGestureView:(UIViewController*)view;
+(void)willNavBecomeActive:(UIViewController*)view;

#pragma 手势密码页面present上去
+(void)willPresentBecomeActive;

#pragma 获取Parameter
+(NSString*)getParam:(NSString*)key;
#pragma GETTOKEN
+(NSString*)getToken;

#pragma AppVersionCheck 看字典返回信息,后续调用appInstallForIos去安装
+(NSDictionary*)checkAppVersion:(NSString*)appID andAppVersion:(NSString*)appVersion;
#pragma appInstallForIos
+(NSDictionary*)appInstallForIOS:(NSString*)appID andAppVersion:(NSString*)appVersion;





@end
#pragma mark JSON Writing

@interface NSObject (NSObject_SBJsonWritingAgent)
- (NSString *)JSONRepresentationAgent;
@end

#pragma mark JSON Parsing

@interface NSString (NSString_SBJsonParsingAgent)
- (id)JSONValueAgent;
@end

@interface NSData (NSData_SBJsonParsingAgent)
- (id)JSONValueAgent;

@end


