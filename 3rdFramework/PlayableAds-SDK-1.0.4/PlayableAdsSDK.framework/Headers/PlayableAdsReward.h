//
//  PlayableAdsReward.h
//  
//
//  Created by dgaf on 2017/8/24.
//  Copyright © 2017年 dgaf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayableAdsGlobalZone.h"

@protocol PlayableAdsRewardDelegate <NSObject>

@optional
/**
 *加载成功
 */
- (void)playableAdsRewardLoadSuccessWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *加载失败
 */
- (void)playableAdsRewardLoadFailed:(NSDictionary *_Nullable)dic withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告打开
 */
- (void)playableAdsRewardDidOpenWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告点击
 */
- (void)playableAdsRewardDidClick:(NSString *_Nullable)placeString withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;
/**
 *广告播放完成
 */
- (void)playableAdsRewardDidPlayCompleteWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *广告关闭
 */
- (void)playableAdsRewardDidCloseWithKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *准备发放奖励
 */
- (void)playableAdsRewardDidRewardUserWithReward:(NSDictionary *_Nullable)reward withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;

/**
 *不符合发放奖励
 */
- (void)playableAdsRewardDontReward:(NSError *_Nullable)error withKey:(NSString *_Nonnull)key placeId:(NSString *_Nullable)placeId;


@end

@interface PlayableAdsReward : NSObject

/**
 * 设置激励互动广告回调
 *
 */
@property (nonatomic, weak, nullable)id <PlayableAdsRewardDelegate> delegate;

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
 */
+ (PlayableAdsReward *_Nonnull)sharedInstance;

/*
 * 加载激励互动广告
 * key APPKEY
 */
- (void)loadRewardAdsResourcesWithKey:(NSString *_Nonnull)key;

/*
 * 判断预加载的内容是否可显示(校验使用)
 */
- (BOOL)isReady;

/**
 * 展示激励互动广告
 * viewController  展示广告的控制器(controller)
 */
- (void)showRewardAdsWithController:(UIViewController *_Nonnull)viewController;


/**
 * 返回待播放的激励互动广告Info
 * @{@"icon":@""}
 */
- (NSDictionary *_Nullable)getOfferInfo;




@end
