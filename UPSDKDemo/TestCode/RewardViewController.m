//
//  STRewardViewController.m
//  UPAdsSDK
//
//  Created by steve on 2017/4/24.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "RewardViewController.h"
#import <UPSDK/UPSDK.h>

@interface RewardViewController () <UPRewardDelegate,UPRewardLoadDelegate>
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
    
    [[UPRewardWrapper shareInstance] setDelegate:self];
}

- (void)load
{
    [_loadBtn setTitle:@"load" forState:UIControlStateNormal];
    [[UPRewardWrapper shareInstance] load:self];
    
}

- (void)show
{
    if ([[UPRewardWrapper shareInstance] isReady]) {
        
        [[UPRewardWrapper shareInstance] show:self placeId:@"aaaa"];
    }
    else {
        NSLog(@"Reward no ready");
    }
}

#pragma mark UPRewardDelegate

//激励视频广告打开
- (void)UPRewardVideoAdDidOpen
{
    NSLog(@"激励视频广告测试 UPRewardVideoAdDidOpen 广告打开");
}

//激励视频广告点击
- (void)UPRewardVideoAdDidCilck
{
    NSLog(@"UPRewardVideoAdDidClick");
}

//激励视频广告关闭
- (void)UPRewardVideoAdDidClose
{
    NSLog(@"UPRewardVideoAdDidClose");
}

//准备发放奖励
- (void)UPRewardVideoAdDidRewardUserWithReward:(NSDictionary *)reward
{
    NSLog(@"UPRewardVideoAdDidRewardUserWithReward");
}

//不符合发放奖励条件
- (void)UPRewardVideoAdDontReward:(NSError *)error
{
    NSLog(@"UPRewardVideoAdDontReward");
}

#pragma mark UPRewardLoadDelegate

- (void)UPRewardVideoAdDidLoad
{
    NSLog(@"激励视频广告测试 UPRewardVideoAdDidLoad 加载成功");
    [_loadBtn setTitle:@"load Succeed" forState:UIControlStateNormal];
}

- (void)UPRewardVideoAdDidLoadFail
{
    NSLog(@"激励视频广告测试 UPRewardVideoAdDidLoadFail 加载失败");
    [_loadBtn setTitle:@"load Fail" forState:UIControlStateNormal];
}


#pragma mark Test

- (void)testViewClick
{
    [UPRewardDebug showDebugView:[UIApplication sharedApplication].delegate.window.rootViewController];
}

@end
