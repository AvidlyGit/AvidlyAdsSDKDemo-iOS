//
//  UPBannerBaseWrapper.h
//  UPSDK
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol UPBannerWrapperProtocol;

@interface UPBannerBaseWrapper : NSObject

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc bannerType:(NSInteger) type;

- (instancetype)initWithPlacement:(NSString *)avidPlacement controller:(UIViewController*)vc size:(CGSize)size bannerType:(NSInteger)type;

- (void)onlineDebugReportIfNeed:(NSString *)msg placeId:(NSString *)placeid type:(NSInteger)type;

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
@property (nonatomic, weak) id<UPBannerWrapperProtocol> delegate;

@end

@protocol UPBannerWrapperProtocol <NSObject>

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
