//
//  UPRewardWrapper.h
//  UP
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol UPRewardDelegate;
@protocol UPRewardLoadDelegate;

@interface UPRewardWrapper : NSObject

/*
 * 获取Wrapper的单例对象
 */
+ (instancetype)shareInstance;

/*
 * 设置回调代理（非必须）
 */
- (void)setDelegate:(id<UPRewardDelegate>)delegate;

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

- (void)load:(id<UPRewardLoadDelegate>)delegate;

@end

@protocol UPRewardDelegate <NSObject>

/*
 * 激励视频广告打开
 */
- (void)UPRewardVideoAdDidOpen;

/*
 * 激励视频广告点击
 */
- (void)UPRewardVideoAdDidCilck;

/*
 * 激励视频广告关闭
 */
- (void)UPRewardVideoAdDidClose;

/*
 * 准备发放奖励
 * @param reward: 奖励的有关数据内容
 */
- (void)UPRewardVideoAdDidRewardUserWithReward:(NSDictionary *)reward;

/*
 * 激励条件不足，无法发放奖励
 * @param error: 条件不足的原因
 */
- (void)UPRewardVideoAdDontReward:(NSError *)error;

@end

@protocol UPRewardLoadDelegate <NSObject>

/*
 * 激励视频广告加载完成
 */
- (void)UPRewardVideoAdDidLoad;

/*
 * 激励视频广告加载失败
 */
- (void)UPRewardVideoAdDidLoadFail;

@end
