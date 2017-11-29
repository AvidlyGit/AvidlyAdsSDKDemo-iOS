//
//  PlayableAdsInterstitial.h
//  
//
//  Created by dgaf on 2017/8/24.
//  Copyright © 2017年 dgaf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayableAdsGlobalZone.h"

@protocol PlayableAdsInterstitialDelegate <NSObject>

@optional
/**
 *加载成功
 */
- (void)playableAdsInterstitialLoadSuccessWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *加载失败
 */
- (void)playableAdsInterstitialLoadFailed:(NSDictionary *_Nullable)dic withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告打开
 */
- (void)playableAdsInterstitialDidOpenWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告点击
 */
- (void)playableAdsInterstitialDidClick:(NSString *_Nullable)placeString withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告关闭
 */
- (void)playableAdsInterstitialDidCloseWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;


@end

@interface PlayableAdsInterstitial : NSObject

/**
 * 设置插屏互动广告回调
 *
 */
@property (nonatomic, weak, nullable)id <PlayableAdsInterstitialDelegate> delegate;

/*
 * 广告位ID
 */
@property (nonatomic, strong) NSString *_Nullable placeId;

/*
 * 区域(区分国内国外)，请在load和show方法前设置
 */
@property (nonatomic, assign) VGGlobalZone zone;

/*
 * 初始化
 * key APPKEY
 */
- (instancetype _Nonnull)initWithKey:(NSString *_Nonnull)key;

/*
 * 加载插屏互动广告
 */
- (void)loadInterstitialAdsResources;

/*
 * 判断预加载的内容是否可显示(校验使用)
 */
- (BOOL)isReady;

/**
 * 展示插屏互动广告
 * viewController  展示广告的控制器(controller)
 */
- (void)showInterstitialAdsWithController:(UIViewController *_Nonnull)viewController;

/**
 * 返回待播放的插屏互动广告Info
 * @{@"icon":@""}
 */
- (NSDictionary *_Nullable)getOfferInfo;


@end
