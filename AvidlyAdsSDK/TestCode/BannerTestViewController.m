//
//  BannerTestViewController.m
//  AvidlyAdsSDK
//
//  Created by samliu on 2017/4/21.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "BannerTestViewController.h"
#import <AvidlyAdsSDK/AvidlyAdsSDK.h>

@interface SortObj : NSObject

@property (nonatomic,copy) NSString *name;
@property (nonatomic) NSInteger index;
@end

@implementation SortObj

- (void) setIndex:(NSInteger)index{
    _index = index;
    _name = [NSString stringWithFormat:@"name[%ld]", index];
}

@end


@interface BannerTestViewController () <AvidlyAdsBannerWrapperProtocol>
{
    AvidlyAdsBannerRectangleWrapper *_bottomRectBanner;
    AvidlyAdsBannerStripWrapper *_topStripBanner;
    UIView *_bannerRectView;
    UIView *_bannerStripView;
}

@end

@implementation BannerTestViewController

- (void)delayLoadView
{
    _bottomRectBanner = [[AvidlyAdsBannerRectangleWrapper alloc] initWithPlacement:@"banner_bbb" controller:self];
    _bottomRectBanner.delegate = self;
    
    _topStripBanner = [[AvidlyAdsBannerStripWrapper alloc] initWithPlacement:@"banner_aaa" controller:self];
    _topStripBanner.delegate = self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [NSThread detachNewThreadSelector:@selector(delayLoadView) toTarget:self withObject:nil];
}

- (void)btnClick:(UIButton*)btn{
    if(btn.tag == 200){
        exit(0);
    }
    else{
        
        if(self.navigationController){
            [self.navigationController popViewControllerAnimated:YES];
        }
        else{
            //[self popViewControllerAnimated:YES];
        }
        //[self dismissViewControllerAnimated:YES completion:nil];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)adjustBannerLayout:(id)wrapper size:(CGSize)size{
    if(_topStripBanner == wrapper){
        CGRect frame = _bannerStripView.frame;
        frame.size = size;
        frame.origin.x = (self.view.frame.size.width - frame.size.width)/2;
        frame.origin.y = 100;
        _bannerStripView.frame = frame;
        _bannerStripView.hidden = NO;
        
    }
    else if (_bottomRectBanner == wrapper){
        CGRect frame = _bannerRectView.frame;
        frame.size = size;
        frame.origin.x = (self.view.frame.size.width - frame.size.width)/2;
        frame.origin.y = self.view.frame.size.height - frame.size.height;
        _bannerRectView.frame = frame;
        _bannerRectView.hidden = NO;
    }
}

- (void)bannerAdClick:(id)wrapper{
    
}


/**
 *  广告加载成功
 *
 *  @param wrapper 插屏广告对象
 */
- (void)bannerAdDidLoad:(id)wrapper size:(CGSize)size{
    NSLog(@"bannerAdDidLoad ....");
}

/**
 *  广告加载失败
 *
 *  @param wrapper 插屏广告对象
 *  @param error          插屏广告加载失败error
 */
- (void)bannerAdDidFail:(id)wrapper error:(NSError *)error{
    
}

/**
 *  广告展示完成
 *
 *  @param wrapper 广告对象
 */
- (void)bannerAdDidShow:(id)wrapper size:(CGSize)size{
    
    if(_topStripBanner == wrapper){
        if (!_bannerStripView) {
            _bannerStripView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
            [self.view addSubview:_bannerStripView];
            UIView *view = [_topStripBanner getView];
            [_bannerStripView addSubview:view];
            if(view.frame.size.width > 0){
                [self adjustBannerLayout:_topStripBanner size:view.frame.size];
            }
        }
    }
    
    else if (_bottomRectBanner == wrapper){
        if (!_bannerRectView) {
            _bannerRectView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
            [self.view addSubview:_bannerRectView];
            UIView *view = [_bottomRectBanner getView];
            [_bannerRectView addSubview:view];
            if(view.frame.size.width > 0){
                [self adjustBannerLayout:_bottomRectBanner size:view.frame.size];
            }
        }
    }
    
    [self adjustBannerLayout:wrapper size:size];
}

/**
 *  广告显示失败
 *
 *  @param bannerAd 广告对象
 *  @param error    广告显示失败error
 */
- (void)bannerAdDidShowFail:(id)bannerAd error:(NSError *)error{
    
}

/**
 *  广告关闭
 *
 *  @param bannerAd 广告对象
 */
- (void)bannerAdDidMisiss:(id)bannerAd{
    
}


@end
