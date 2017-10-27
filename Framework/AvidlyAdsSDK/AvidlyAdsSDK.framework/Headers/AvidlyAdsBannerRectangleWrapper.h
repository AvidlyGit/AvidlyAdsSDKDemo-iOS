//
//  AvidlyAdsBannerRectangleWrapper.h
//  AvidlyAdsSDK
//
//  Created by samliu on 2017/4/21.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "AvidlyAdsBannerBaseWrapper.h"

@interface AvidlyAdsBannerRectangleWrapper : AvidlyAdsBannerBaseWrapper

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size;

@end
