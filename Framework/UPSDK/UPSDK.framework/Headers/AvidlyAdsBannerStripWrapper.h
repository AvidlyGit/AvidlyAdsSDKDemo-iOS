//
//  AvidlyAdsBannerWrapper.h
//  AvidlyAdsSDK
//
//  Created by samliu on 2017/4/19.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AvidlyAdsBannerBaseWrapper.h"

typedef NS_ENUM(NSUInteger, AvidlyAdsStripShowLocationType) {
    AvidlyAdsStripShowLocationTypeTop       = 1,        //顶部
    AvidlyAdsStripShowLocationTypeBottom    = 2,        //底部
};

@interface AvidlyAdsBannerStripWrapper : AvidlyAdsBannerBaseWrapper

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc showLocation:(AvidlyAdsStripShowLocationType)type;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size showLocation:(AvidlyAdsStripShowLocationType)type;

@end
