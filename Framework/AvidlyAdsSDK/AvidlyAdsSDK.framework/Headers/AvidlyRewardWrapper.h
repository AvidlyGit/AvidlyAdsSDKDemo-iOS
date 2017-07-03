//
//  AvidlyRewardWrapper.h
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/22.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol AvidlyRewardDelegate;

@interface AvidlyRewardWrapper : NSObject

/*
 * 获取Wrapper的单例对象
 */
+ (instancetype)shareInstance;

/*
 * 设置回调代理（非必须）
 */
- (void)setDelegate:(id<AvidlyRewardDelegate>)delegate;

/*
 * 判断视屏内容是否可显示
 */
- (BOOL)isReady;

/**
 * 显示视频
 * @param viewController 必须正确设置，用于控制视屏跳转实现
 * @param adId cp根据自己需求，自定义视屏展示时位置标识，用于统计
 **/

- (BOOL)show:(UIViewController *)viewController placeId:(NSString*)adId;

@end

@protocol AvidlyRewardDelegate <NSObject>

/*
 * 激励视频广告打开
 */
- (void)AvidlyRewardVideoAdDidOpen;

/*
 * 激励视频广告点击
 */
- (void)AvidlyRewardVideoAdDidCilck;

/*
 * 激励视频广告关闭
 */
- (void)AvidlyRewardVideoAdDidClose;

/*
 * 准备发放奖励
 * @param reward: 奖励的有关数据内容
 */
- (void)AvidlyRewardVideoAdDidRewardUserWithReward:(NSDictionary *)reward;

/*
 * 激励条件不足，无法发放奖励
 * @param error: 条件不足的原因
 */
- (void)AvidlyRewardVideoAdDontReward:(NSError *)error;

@end
