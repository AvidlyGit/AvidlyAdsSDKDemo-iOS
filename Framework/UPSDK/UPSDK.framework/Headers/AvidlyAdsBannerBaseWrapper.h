//
//  AvidlyAdsBannerBaseWrapper.h
//  AvidlyAdsSDK
//
//  Created by samliu on 2017/4/21.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AvidlyAdsBannerWrapperProtocol;

@interface AvidlyAdsBannerBaseWrapper : NSObject

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc bannerType:(NSInteger) type;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size bannerType:(NSInteger)type;

/**
 * 获取banner view
 */
- (UIView *)getView;

/**
 获取cp传进来的vc

 @return cp传进来的vc
 */
- (UIViewController *)getVC;

/*
 * 设置回调代理
 */
@property (nonatomic, weak) id<AvidlyAdsBannerWrapperProtocol> delegate;

@end

@protocol AvidlyAdsBannerWrapperProtocol <NSObject>

@optional

/**
 *  广告点击
 *
 *  @param wrapper 广告控制对象
 */
- (void)bannerAdClick:(id)wrapper;

/**
 *  广告展示完成
 *
 *  @param wrapper 广告控制对象
 */
- (void)bannerAdDidShow:(id)wrapper size:(CGSize)size;

@end
