//
//  FHSSO.h
//  FHSSO
//
//  Created by liqiang on 15-3-25.
//  Copyright (c) 2015年 fiberhome. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface FHSSO : NSObject

//单点登录新接口
+(void)startConnectSSO;

+(NSMutableDictionary *)handleLaunchedApp:(NSURL *)url;

@end
