//
//  UPSDK.h
//  AvidlyAdsSDK
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "UPBannerBaseWrapper.h"
#import "UPBannerStripWrapper.h"
#import "UPBannerRectangleWrapper.h"
#import "UPIntersitialWrapper.h"
#import "UPInterstitialDebug.h"
#import "UPRewardWrapper.h"
#import "UPRewardDebug.h"
#import "UPSDKVersion.h"
#import "UPSDKGlobalZone.h"
#import "UPAccessPrivacyInfoStatusEnum.h"
#import "UPIconWrapper.h"

#import "AvidlyAdsSDK.h"
#import "AvidlyIntersitialWrapper.h"
#import "AvidlyRewardWrapper.h"
#import "AvidlyAdsWallWrapper.h"
#import "AvidlyAdsGlobalZone.h"
#import "AvidlyAdsSDKVersion.h"

@interface UPSDK : NSObject

/**
 初始化SDK
 */
+ (void)initSDK;

/**
 初始化SDK（根据发行区域）
 
 @param zone 发行区域
 */
+ (void)initSDK:(UPSDKGlobalZone)zone;

/**
 CP初始化ABTest配置
 
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
 CP根据广告位获取ABTest配置
 
 @param placementID 广告位 (不能为nil和@"")
 @return 广告配置
 */
+ (NSDictionary *)getAdConfigWithPlacementID:(NSString *)placementID;

/**
 CP根据广告位获取ABTest配置(json)
 
 @param placementID 广告位 (不能为nil和@"")
 @return 广告配置(json字符串)
 */
+ (NSString *)getAdConfigJsonStrWithPlacementID:(NSString *)placementID;

+ (void)loadAvidlyAdsByManual;

/**
 更新访问用户隐私信息状态
 
 @param status 访问用户隐私信息状态，不能传UPAccessPrivacyInfoStatusNone
 */
+ (void)updateAccessPrivacyInfoStatus:(UPAccessPrivacyInfoStatus)status;

/**
 使用弹窗向用户请求访问隐私信息授权
 
 @param viewController 当前视图控制器
 @param completionBlock 回调，其中isAccepted为YES表示用户同意使用隐私信息，为NO表示用户不同意使用隐私信息
 */
+ (void)requestAuthorizationWithAlert:(UIViewController *)viewController completion:(void (^)(BOOL isAccepted))completionBlock;

/**
 获取当前访问用户隐私信息状态
 
 @return 访问用户隐私信息状态
 */
+ (UPAccessPrivacyInfoStatus)getCurrentAccessPrivacyInfoStatus;

/**
 查询用户是否是欧盟用户
 
 @param completionBlock 回调 isEuropeanUnion为YES表示是欧盟用户
 */
+ (void)checkIsEuropeanUnionUser:(void (^)(BOOL isEuropeanUnion))completionBlock;

@end
