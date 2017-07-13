//
//  AvidlyAdsSDK.h
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/20.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AvidlyAdsBannerBaseWrapper.h"
#import "AvidlyAdsBannerStripWrapper.h"
#import "AvidlyAdsBannerRectangleWrapper.h"
#import "AvidlyIntersitialWrapper.h"
#import "AvidlyRewardWrapper.h"
#import "AvidlyAdsSDKVersion.h"
#import "AvidlyAdsWallWrapper.h"
#import "AvidlyRewardDebug.h"
#import "AvidlyAdsGlobalZone.h"

@interface AvidlyAdsSDK : NSObject

/**
 初始化SDK
 */
+ (void)initSDK;

/**
 初始化SDK（根据发行区域）

 @param zone 发行区域
 */
+ (void)initSDK:(AvidlyAdsGlobalZone)zone;

/**
 CP初始化广告配置
 
 @param gameAccountId 用户在游戏中的帐号id
 @param completeTask 是否完成了游戏中的新手任务，可选0或者1
 @param isPaid 付费 - 0 未付费；>1 付费金额
 @param promotionChannelName 推广渠道
 @param gender 性别   "M", "F"，未知可以传""
 @param age 年龄
 @param tags 标签
 */
+ (void)initAdConfigWithGameAccountId:(NSString *)gameAccountId completeTask:(BOOL)completeTask isPaid:(int)isPaid promotionChannelName:(NSString *)promotionChannelName gender:(NSString *)gender age:(int)age tags:(NSArray<NSString *> *)tags;

/**
 CP根据广告位获取广告配置
 
 @param placementID 广告位 (不能为nil和@"")
 @return 广告配置
 */
+ (NSDictionary *)getAdConfigWithPlacementID:(NSString *)placementID;
@end
