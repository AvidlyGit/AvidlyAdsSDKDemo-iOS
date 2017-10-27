//
//  ZZAdNativeMediaView.h
//  ZZAdSDK
//
//  Created by xuhuize on 2017/4/12.
//  Copyright © 2017年 xuhuize. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@class ZZAdNativeAd;
@protocol ZZAdNativeMediaViewDelegate;
/**
 展示广告素材的容器
 */
@interface ZZAdNativeMediaView : UIView

@property(nonatomic,nullable)ZZAdNativeAd *nativeAd;

/**
 注意，设置了nativeAd之后，contentView才有值
 */
@property(nonatomic,weak,nullable)UIImageView *contentView;
@end

NS_ASSUME_NONNULL_END
