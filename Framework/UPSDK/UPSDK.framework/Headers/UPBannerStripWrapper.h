//
//  UPBannerStripWrapper.h
//  UPSDK
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UPBannerBaseWrapper.h"

typedef NS_ENUM(NSUInteger, UPStripShowLocationType) {
    UPStripShowLocationTypeTop       = 1,        //顶部
    UPStripShowLocationTypeBottom    = 2,        //底部
};

@interface UPBannerStripWrapper : UPBannerBaseWrapper

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc showLocation:(UPStripShowLocationType)type;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size showLocation:(UPStripShowLocationType)type;

@end
