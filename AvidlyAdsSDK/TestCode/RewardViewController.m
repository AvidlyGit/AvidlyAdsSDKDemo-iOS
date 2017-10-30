//
//  STRewardViewController.m
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/24.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "RewardViewController.h"
#import <AvidlyAdsSDK/AvidlyAdsSDK.h>

@interface RewardViewController () <AvidlyRewardDelegate,AvidlyRewardLoadDelegate>
{
    UIButton *_loadBtn;
}
@end

@implementation RewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"激励视频";
    
    _loadBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _loadBtn.backgroundColor = [UIColor orangeColor];
    _loadBtn.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 100, 250, 40);
    [_loadBtn setTitle:@"load" forState:UIControlStateNormal];
    [_loadBtn addTarget:self action:@selector(load) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_loadBtn];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 170, 250, 40);
    [button setTitle:@"展示激励视频广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(show) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button1.backgroundColor = [UIColor orangeColor];
    button1.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 240, 250, 40);
    [button1 setTitle:@"激励视频广告测试工具" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(testViewClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    [[AvidlyRewardWrapper shareInstance] setDelegate:self];
}

- (void)load
{
    [_loadBtn setTitle:@"load" forState:UIControlStateNormal];
    [[AvidlyRewardWrapper shareInstance] load:self];
    
}

- (void)show
{
    if ([[AvidlyRewardWrapper shareInstance] isReady]) {
        
        [[AvidlyRewardWrapper shareInstance] show:self placeId:@"aaaa"];
    }
    else {
        NSLog(@"Reward no ready");
    }
}

#pragma mark AvidlyRewardDelegate

//激励视频广告打开
- (void)AvidlyRewardVideoAdDidOpen
{
//    NSLog(@"激励视频广告测试 AvidlyRewardVideoAdDidOpen 广告打开");
    //    NSLog(@"AvidlyRewardVideoAdDidOpen");
}

//激励视频广告点击
- (void)AvidlyRewardVideoAdDidCilck
{
    //    NSLog(@"AvidlyRewardVideoAdDidClick");
}

//激励视频广告关闭
- (void)AvidlyRewardVideoAdDidClose
{
//    NSLog(@"激励视频广告测试 AvidlyRewardVideoAdDidClose 广告关闭");
    //    NSLog(@"AvidlyRewardVideoAdDidClose");
}

//准备发放奖励
- (void)AvidlyRewardVideoAdDidRewardUserWithReward:(NSDictionary *)reward
{
    //    NSLog(@"AvidlyRewardVideoAdDidRewardUserWithReward");
}

//不符合发放奖励条件
- (void)AvidlyRewardVideoAdDontReward:(NSError *)error
{
    //    NSLog(@"AvidlyRewardVideoAdDontReward");
}

#pragma mark AvidlyRewardLoadDelegate

- (void)AvidlyRewardVideoAdDidLoad
{
    NSLog(@"激励视频广告测试 AvidlyRewardVideoAdDidLoad 加载成功");
    [_loadBtn setTitle:@"load Succeed" forState:UIControlStateNormal];
}

- (void)AvidlyRewardVideoAdDidLoadFail
{
    NSLog(@"激励视频广告测试 AvidlyRewardVideoAdDidLoadFail 加载失败");
    [_loadBtn setTitle:@"load Fail" forState:UIControlStateNormal];
}


#pragma mark Test

- (void)testViewClick
{
    [AvidlyRewardDebug showDebugView:[UIApplication sharedApplication].delegate.window.rootViewController];
}

@end
