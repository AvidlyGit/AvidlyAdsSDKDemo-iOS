//
//  STInterstitialViewController.m
//  UPSDKDemo
//
//  Created by steve on 2017/4/24.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "InterstitialViewController.h"
#import <UPSDK/UPSDK.h>

@interface InterstitialViewController () <UPIntersitialDelegate,UPIntersitialLoadDelegate>
{
    UPIntersitialWrapper *_wrapper;
    
    UIButton *_loadBtn;
}
@end

@implementation InterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    _loadBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _loadBtn.backgroundColor = [UIColor orangeColor];
    _loadBtn.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 100, 250, 40);
    [_loadBtn setTitle:@"load" forState:UIControlStateNormal];
    [_loadBtn addTarget:self action:@selector(load) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_loadBtn];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 170, 250, 40);
    [button setTitle:@"展示插屏广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(intersitialClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button1.backgroundColor = [UIColor orangeColor];
    button1.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 240, 250, 40);
    [button1 setTitle:@"插屏调试工具" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(testViewClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    _wrapper = [[UPIntersitialWrapper alloc] initAvidPlacement:@"inter"];
    
}

- (void)load
{
    [_loadBtn setTitle:@"load" forState:UIControlStateNormal];
    
    [_wrapper load:self];
}

- (void)intersitialClick
{
    if ([_wrapper isReady]) {
        [_wrapper show:self];
    }
}

#pragma mark UPIntersitialDelegate

//插屏广告展示
- (void)interstitialAdDidShow:(UPIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告展示:%p",interstitialAd);
}

//插屏广告显示失败
- (void)interstitialAd:(UPIntersitialWrapper *)interstitialAd showFailWithError:(NSError *)error
{
    NSLog(@"插屏广告显示失败:%p",interstitialAd);
}

//插屏广告关闭
- (void)interstitialAdDidClose:(UPIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告关闭:%p",interstitialAd);
}

//插屏广告点击
- (void)interstitialAdDidClick:(UPIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告点击:%p",interstitialAd);
}

#pragma mark UPIntersitialLoadDelegate

- (void)interstitialAdDidLoad:(UPIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告加载成功 %@ 内存地址 %p",[interstitialAd getAvidPlacement],interstitialAd);
    [_loadBtn setTitle:@"load Succeed" forState:UIControlStateNormal];
}

- (void)interstitialAdDidLoadFail:(UPIntersitialWrapper *)interstitialAd
{
    NSLog(@"插屏广告加载失败 %@ 内存地址 %p",[interstitialAd getAvidPlacement],interstitialAd);
    [_loadBtn setTitle:@"load Fail" forState:UIControlStateNormal];
}

#pragma mark Test

- (void)testViewClick
{
    [UPInterstitialDebug showDebugView:self];
}

@end
