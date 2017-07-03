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

@end
