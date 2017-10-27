//
//  ZZAdInterstitialAd.h
//  ZZAdSDK
//
//  Created by xuhuize on 2017/6/8.
//  Copyright © 2017年 xuhuize. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZZAdInterstitialAdDelegate;

/**
 插屏广告
 */
@interface ZZAdInterstitialAd : NSObject

@property (nonatomic, readonly, copy,nonnull) NSString *placementID;

@property (nonatomic, weak, nullable) id<ZZAdInterstitialAdDelegate> delegate;

@property (nonatomic, readonly,weak, nullable) UIButton *closeButton;//全屏网页的关闭按钮


- (instancetype)initWithPlacementID:(NSString *)placementID NS_DESIGNATED_INITIALIZER;

/**
 加载插屏广告,appkey,placementID 不能为空
 */
- (void)loadAd;

/**
 展示全屏广告
 
 @param rootViewController 用来展示全屏广告的viewController
 */
- (void)showAdFromRootViewController:(nullable UIViewController *)rootViewController;

/**
 关闭广告
 */
- (void)closeAd;

@end

@protocol ZZAdInterstitialAdDelegate <NSObject>

@optional

/**
 全屏广告被点击了
 
 @param interstitialAd 点击了的全屏广告
 */
- (void)zzAd_interstitialAdDidClick:(ZZAdInterstitialAd *)interstitialAd;

/**
 全屏广告被关闭了
 
 @param interstitialAd 关闭了的全屏广告
 */
- (void)zzAd_interstitialAdDidClose:(ZZAdInterstitialAd *)interstitialAd;

/**
 全屏广告将要被关闭
 
 @param interstitialAd 将要被关闭的全屏广告
 */
- (void)zzAd_interstitialAdWillClose:(ZZAdInterstitialAd *)interstitialAd;

/**
 全屏广告加载成功
 
 @param interstitialAd 加载成功的全屏广告
 */
- (void)zzAd_interstitialAdDidLoad:(ZZAdInterstitialAd *)interstitialAd;

/**
 全屏广告加载失败
 
 @param interstitialAd 加载失败的全屏广告
 @param error 加载失败的错误信息
 */
- (void)zzAd_interstitialAd:(ZZAdInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;

/**
 全屏广告展示了
 
 @param interstitialAd 展示了的全屏广告
 */
- (void)zzAd_interstitialAdWillLogImpression:(ZZAdInterstitialAd *)interstitialAd;

@end

NS_ASSUME_NONNULL_END

