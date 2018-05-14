//
//  UPBannerRectangleWrapper.h
//  UPSDK
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UPBannerBaseWrapper.h"

@interface UPBannerRectangleWrapper : UPBannerBaseWrapper

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size;

@end
