//
//  ZZAdSetting.h
//  ZZAdSDK
//
//  Created by xuhuize on 2017/4/16.
//  Copyright © 2017年 xuhuize. All rights reserved.
//

@class ZZAdConfig;

/**
 调试设置
 */
@interface ZZAdSettings : NSObject

/**
 设置app广告的通用配置，注意调用该接口之后才能去加载广告
 @param adConfig 广告配置
 */
+(void)setConfig:(ZZAdConfig*_Nonnull)adConfig;

+(ZZAdConfig*_Nullable)currentConfig;

+(void)closeConsole;

+(void)enableConsole;

@end
