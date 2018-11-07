//
//  UPIconWrapper.h
//  UPSDK
//
//  Created by steve on 2018/10/17.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol UPIconDelegate;

@interface UPIconWrapper : NSObject

@property (nonatomic,weak) id<UPIconDelegate> delegate;
@property (nonatomic,copy) NSString *placementId;

- (instancetype)initWithFrame:(CGRect)frame rotationAngle:(int)rotationAngle;

//加载广告
- (void)loadAd;
//在传入的视图上展示广告
- (BOOL)showAd:(UIView *)superView;
//移除广告
- (BOOL)removeAd;

@end

@protocol UPIconDelegate <NSObject>
@optional
//Icon广告加载完成
- (void)iconAdDidLoad:(id)iconWrapper;

//Icon广告加载失败
- (void)iconAd:(id)iconWrapper didLoadFail:(NSError *)error;

//Icon广告点击
- (void)iconAdDidClick:(id)iconWrapper;

//Icon广告展示完成
- (void)iconAdDidShow:(id)iconWrapper;

@end
