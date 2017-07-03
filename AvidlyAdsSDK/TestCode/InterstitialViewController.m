//
//  STInterstitialViewController.m
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/24.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "InterstitialViewController.h"
#import <AvidlyAdsSDK/AvidlyAdsSDK.h>

@interface InterstitialViewController () <AvidlyIntersitialDelegate>
{
    AvidlyIntersitialWrapper *_object;
    AvidlyIntersitialWrapper *_wrapper;
}
@end

@implementation InterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 100, 250, 40);
    [button setTitle:@"加载插屏广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(intersitialClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)intersitialClick
{
    _wrapper = [[AvidlyIntersitialWrapper alloc] initAvidPlacement:@"inter_ccc"];
    
    if ([_wrapper isReady]) {
        [_wrapper setDelegate:self];
        [_wrapper show:self];
    }
}

#pragma mark AvidlyIntersitialDelegate

//插屏广告展示
- (void)interstitialAdDidShow:(AvidlyIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告展示:%p",interstitialAd);
}

//插屏广告显示失败
- (void)interstitialAd:(AvidlyIntersitialWrapper *)interstitialAd showFailWithError:(NSError *)error
{
    NSLog(@"插屏广告显示失败:%p",interstitialAd);
}

//插屏广告关闭
- (void)interstitialAdDidClose:(AvidlyIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告关闭:%p",interstitialAd);
}

//插屏广告点击
- (void)interstitialAdDidClick:(AvidlyIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告点击:%p",interstitialAd);
}

@end
