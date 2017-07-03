//
//  AvidlyIntersitialWrapper.h
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/18.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol AvidlyIntersitialDelegate;

@interface AvidlyIntersitialWrapper : NSObject

- (instancetype)initAvidPlacement:(NSString *)avidPlacement;

- (void)setDelegate:(id<AvidlyIntersitialDelegate>)delegate;

- (BOOL)isReady;

- (BOOL)show:(UIViewController *)viewController;

////用于视频展示多次才失效，目前无逻辑
//- (void)markShown;

@end

@protocol AvidlyIntersitialDelegate <NSObject>

/**
 插屏广告展示
 
 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidShow:(AvidlyIntersitialWrapper *)interstitialAd;

/**
 插屏广告显示失败
 
 @param interstitialAd 插屏广告
 @param error          插屏广告显示失败error
 */
//- (void)interstitialAd:(AvidlyIntersitialWrapper *)interstitialAd showFailWithError:(NSError *)error;

/**
 插屏广告关闭
 
 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidClose:(AvidlyIntersitialWrapper *)interstitialAd;

/**
 插屏广告点击
 
 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidClick:(AvidlyIntersitialWrapper *)interstitialAd;

@end
