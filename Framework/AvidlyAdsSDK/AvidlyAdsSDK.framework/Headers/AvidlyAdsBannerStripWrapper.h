//
//  AvidlyAdsBannerWrapper.h
//  AvidlyAdsSDK
//
//  Created by samliu on 2017/4/19.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AvidlyAdsBannerBaseWrapper.h"
@interface AvidlyAdsBannerStripWrapper : AvidlyAdsBannerBaseWrapper

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size;

@end
