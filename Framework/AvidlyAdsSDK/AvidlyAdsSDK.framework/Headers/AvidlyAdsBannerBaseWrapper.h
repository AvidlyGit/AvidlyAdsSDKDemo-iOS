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

/**
 * 获取banner view
 */
- (UIView*)getView;

/*
 * 设置回调代理
 */
@property (nonatomic, weak) id<AvidlyAdsBannerWrapperProtocol> delegate;

@end

@protocol AvidlyAdsBannerWrapperProtocol <NSObject>

@optional


- (void)bannerAdClick:(id)wrapper;


/**
 *  广告加载成功
 *
 *  @param wrapper 广告控制对象
 */
//- (void)bannerAdDidLoad:(id)wrapper size:(CGSize)size;

/**
 *  广告加载失败
 *
 *  @param wrapper 广告控制对象
 *  @param error   广告加载失败error
 */
//- (void)bannerAdDidFail:(id)wrapper error:(NSError *)error;

/**
 *  广告展示完成
 *
 *  @param wrapper 广告控制对象
 */
- (void)bannerAdDidShow:(id)wrapper size:(CGSize)size;

/**
 *  广告显示失败
 *
 *  @param wrapper 广告控制对象
 *  @param error   广告显示失败error
 */
//- (void)bannerAdDidShowFail:(id)wrapper error:(NSError *)error;

/**
 *  广告关闭
 *
 *  @param wrapper 广告控制对象
 */
//- (void)bannerAdDidMisiss:(id)wrapper;

@end
