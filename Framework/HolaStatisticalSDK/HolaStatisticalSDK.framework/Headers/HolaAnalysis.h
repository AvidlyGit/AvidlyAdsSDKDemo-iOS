//
//  HolaAnalysis.h
//  HolaStatistical
//
//  Created by steve on 16/4/28.
//  Copyright © 2016年 steve. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HolaAnalysis : NSObject
/**
 SDK初始化
 
 @param productId 分配的产品编号
 @param channelId 渠道编号
 @param appId     "id" + Apple ID
 */
+ (void)initWithProductId:(NSString *)productId ChannelId:(NSString *)channelId AppID:(NSString *)appId;


/**
 获取SDK版本

 @return 版本号
 */
+ (NSString *)SDKVersion;

/**
 获取统计包token

 @return 统计包token
 */
+ (NSString *)staToken;

/**
 设置扩展参数
 
 @param ext 扩展参数
 */
+ (void)setExt:(NSDictionary *)ext;


/**
 追加扩展参数

 @param addExt 需要追加的扩展参数，如与已有的扩展参数冲突，则覆盖冲突部分
 */
+ (void)addExt:(NSDictionary *)addExt;

/**
 keyValue 打点
 
 @param key   键
 @param value 值，可以是string，array，dictionary
 */
+ (void)logWithKey:(NSString *)key value:(id)value;

/**
 计数打点
 
 @param key key
 */
+ (void)countWithKey:(NSString *)key;

/**
 自定义keyValue 打点
 
 @param key   键
 @param value 值
 */
+ (void)customLogWithKey:(NSString *)key value:(NSString *)value;

/**
 GAP 打点
 */
+ (void)GAPLog;

/**
 游客登录 上报
 
 @param playerId 游戏用户ID
 */
+ (void)guestLoginWithGameId:(NSString *)playerId;

/**
 Facebook登录 上报
 
 @param playerId  游戏用户ID
 @param openId    openId
 @param openToken openToken
 */
+ (void)facebookLoginWithGameId:(NSString *)playerId
                         OpenId:(NSString *)openId
                      OpenToken:(NSString *)openToken;

/**
 twitter登录 上报

 @param playerId 游戏用户ID
 @param twitterId 推特用户id
 @param twitterUserName 推特用户Name
 @param twitterAuthToken 推特用户Token
 */
+ (void)twitterLoginWithPlayerId:(NSString *)playerId
                       twitterId:(int64_t)twitterId
                 twitterUserName:(NSString *)twitterUserName
                twitterAuthToken:(NSString *)twitterAuthToken;

/**
 平台登录 上报

 @param playerId 游戏用户ID
 @param portalId 平台Id
 */
+ (void)portalLoginWithPlayerId:(NSString *)playerId
                       portalId:(NSString *)portalId;

/**
 IAP支付 上报（已废弃，请使用 LogPaymentWithPlayerId:receiptDataString: ）

 @param playerId 分配的player编号
 @param gameId 分配的游戏编号
 @param receiptDataString IAP收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogPaymentWithPlayerId:(NSString *)playerId gameId:(NSString *)gameId receiptDataString:(NSString *)receiptDataString __deprecated_msg("Method deprecated. Use `LogPaymentWithPlayerId:receiptDataString:`");

/**
 IAP支付 上报
 
 @param playerId          游戏用户ID
 @param receiptDataString IAP收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogPaymentWithPlayerId:(NSString *)playerId receiptDataString:(NSString *)receiptDataString;

/**
 IAP支付 上报
 
 @param playerId          游戏用户ID
 @param gameAccountServer 游戏区/服ID
 @param receiptDataString IAP收据，将获取到的NSData收据转化为base64字符串
 */
+ (void)LogPaymentWithPlayerId:(NSString *)playerId gameAccountServer:(NSString *)gameAccountServer receiptDataString:(NSString *)receiptDataString;

/**
 第三方支付 上报
 
 @param playerId          游戏用户ID
 @param thirdparty        第三方支付平台名称
 @param receiptDataString 第三方支付平台单据
 */
+ (void)ThirdpartyLogPaymentWithPlayerId:(NSString *)playerId thirdparty:(NSString *)thirdparty receiptDataString:(NSString *)receiptDataString;

/**
 第三方支付 上报
 
 @param playerId          游戏用户ID
 @param gameAccountServer 游戏区/服ID
 @param thirdparty        第三方支付平台名称
 @param receiptDataString 第三方支付平台单据
 */
+ (void)ThirdpartyLogPaymentWithPlayerId:(NSString *)playerId gameAccountServer:(NSString *)gameAccountServer thirdparty:(NSString *)thirdparty receiptDataString:(NSString *)receiptDataString;

@end
