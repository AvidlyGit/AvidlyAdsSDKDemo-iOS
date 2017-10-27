//
//  ZZAdBannerView.h
//  ZZAdSDK
//
//  Created by xuhuize on 2017/6/6.
//  Copyright © 2017年 xuhuize. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZZAdBannerSizeType){
    
    kZZAdBannerSizeType320x50,//宽320,高50
    kZZAdBannerSizeType300x250,//宽300,高250
    
};

@protocol ZZAdBannerViewDelegate;


/**
 banner广告视图
 */
@interface ZZAdBannerView : UIView
/**
 banner的尺寸,默认是320x250的
 */
@property (nonatomic) ZZAdBannerSizeType sizeType;

/**
 广告位ID
 */
@property (nonatomic,copy) NSString *placementID;

@property (nonatomic, weak, nullable) id<ZZAdBannerViewDelegate> delegate;

/**
 加载banner广告，appkey，placementID 不能为空
 */
- (void)loadAd;

@end

@protocol ZZAdBannerViewDelegate <NSObject>

@optional

/**
 banner被点击了
 
 @param adView 被点击的banner
 */
- (void)zzAd_bannerViewDidClick:(ZZAdBannerView *)adView;

/**
 banner 加载成功了
 
 @param adView banner
 */
- (void)zzAd_bannerViewDidLoad:(ZZAdBannerView *)adView;

/**
 banner 加载失败了
 
 @param adView 加载的banner
 @param error 失败信息
 */
- (void)zzAd_bannerView:(ZZAdBannerView *)adView didFailWithError:(NSError *)error;

/**
 banner 展示了
 
 @param adView 展示了的banner
 */
- (void)zzAd_bannerViewWillLogImpression:(ZZAdBannerView *)adView;

@end

NS_ASSUME_NONNULL_END

