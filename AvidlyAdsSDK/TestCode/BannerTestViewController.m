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
    AvidlyAdsBannerStripWrapper *_bottomStripBanner;
    
    UIView *_bannerRectView;
    UIView *_topStripView;
    UIView *_bottomStripView;
}

@end

@implementation BannerTestViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self loadTopStripBanner];
    [self loadBottomStripBanner];
    [self loadRectangleBanner];
}

- (void)loadRectangleBanner
{
    CGSize size = CGSizeMake(self.view.frame.size.width, self.view.frame.size.width);
    _bottomRectBanner = [[AvidlyAdsBannerRectangleWrapper alloc] initWithPlacement:@"banner_bbb" controller:self size:size];
    _bottomRectBanner.delegate = self;
    
    _bannerRectView = [[UIView alloc] initWithFrame:CGRectMake(0, 200, self.view.frame.size.width, self.view.frame.size.width)];
    [self.view addSubview:_bannerRectView];
    
    UIView *view = [_bottomRectBanner getView];
    [_bannerRectView addSubview:view];
//    _bannerRectView.backgroundColor = [UIColor orangeColor];
}

- (void)loadTopStripBanner
{
    _topStripBanner = [[AvidlyAdsBannerStripWrapper alloc] initWithPlacement:@"banner_aaa" controller:self];
    _topStripBanner.delegate = self;
    
    _topStripView = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.frame.size.width, 80)];
    [self.view addSubview:_topStripView];
    
    UIView *view = [_topStripBanner getView];
    [_topStripView addSubview:view];
}

- (void)loadBottomStripBanner
{
    CGFloat height = 50;
    CGSize size = CGSizeMake(self.view.frame.size.width, height);
    _bottomStripBanner = [[AvidlyAdsBannerStripWrapper alloc] initWithPlacement:@"banner_aaa" controller:self size:size];
    _bottomStripBanner.delegate = self;
    
    _bottomStripView = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height - height, self.view.frame.size.width, height)];
    [self.view addSubview:_bottomStripView];
    
    UIView *view = [_bottomStripBanner getView];
    [_bottomStripView addSubview:view];
}

- (void)btnClick:(UIButton*)btn{
    if(self.navigationController){
        [self.navigationController popViewControllerAnimated:YES];
    }
    else{
        //[self popViewControllerAnimated:YES];
    }
}

#pragma mark AvidlyAdsBannerWrapperProtocol

/**
 *  广告展示完成
 *
 *  @param wrapper 广告对象
 */
- (void)bannerAdDidShow:(id)wrapper size:(CGSize)size
{
    
}

/**
 *  广告点击
 *
 *  @param wrapper 广告对象
 */
- (void)bannerAdClick:(id)wrapper
{
    
}


@end
