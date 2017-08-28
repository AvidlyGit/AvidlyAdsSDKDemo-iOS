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
@protocol AvidlyIntersitialLoadDelegate;

@interface AvidlyIntersitialWrapper : NSObject

- (instancetype)initAvidPlacement:(NSString *)avidPlacement;

- (NSString *)getAvidPlacement;

- (void)setDelegate:(id<AvidlyIntersitialDelegate>)delegate;

- (BOOL)isReady;

- (BOOL)show:(UIViewController *)viewController;

- (void)load:(id<AvidlyIntersitialLoadDelegate>)loadDelegate;

@end

@protocol AvidlyIntersitialDelegate <NSObject>

/**
 插屏广告展示
 
 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidShow:(AvidlyIntersitialWrapper *)interstitialAd;

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

@protocol AvidlyIntersitialLoadDelegate <NSObject>

/**
 插屏广告加载成功

 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidLoad:(AvidlyIntersitialWrapper *)interstitialAd;

/**
 插屏广告加载失败

 @param interstitialAd 插屏广告
 */
- (void)interstitialAdDidLoadFail:(AvidlyIntersitialWrapper *)interstitialAd;
@end
