//
//  PlayableAds.h
//  VideoGame
//
//  Created by huobanbengkui on 2017/7/4.
//  Copyright © 2017年 dgaf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol PlayableAdsDelegate <NSObject>

@optional
/**
 *加载成功
 */
- (void)loadSuccess;

/**
 *加载失败
 */
- (void)loadFailed:(NSDictionary *_Nullable)dic;

/**
 *广告打开
 */
- (void)playableAdsVideoDidOpen;

/**
 *广告点击
 */
- (void)playableAdsVideoDidClick:(NSString *_Nullable)placeString;
/**
 *广告播放完成
 */
- (void)playableAdsVideoDidPlayComplete;

/**
 *广告关闭
 */
- (void)playableAdsVideoDidClose;

/**
 *准备发放奖励
 */
- (void)playableAdsVideoDidRewardUserWithReward:(NSDictionary *_Nullable)reward;

/**
 *不符合发放奖励
 */
- (void)playableAdsVideoDontReward:(NSError *_Nullable)error;


@end

@interface PlayableAds : NSObject

+ (PlayableAds *_Nonnull)sharePlayableAds;
/**
 *初始化SDK
 *key  使用SDK需要的key，由用户注册产生
 */
- (void)initWithKey:(NSString *_Nullable)key;

/**
 *设置回调代理
 *
 */
@property (nonatomic, weak, nullable)id <PlayableAdsDelegate> delegate;

/**
 *加载广告
 *placeId  广告位ID
 *placeId  展示广告的控制器(controller)
 */
- (void)showPlayableAdsWith:(NSString *_Nullable)placeId controller:(UIViewController *_Nullable)viewController;

/*
 * 判断预加载的内容是否可显示(校验使用)
 */
- (BOOL)isReady;

/*
 * 获取版本号
 */
- (NSString *_Nullable)getVersion;

/*
 * 资源加载
 */
- (void)loadResources;

/*
 * 控制台是否输出Log
 * 1 输出
 * 9 开启线上查看log服务
 * 0 不输出
 */
- (void)setDebugLog:(NSInteger)debug;

@end

/*
 * 预加载的 isReady 刷新通知
 */
UIKIT_EXTERN NSString * _Nullable const PlayableAdsReadyStateNotification;



