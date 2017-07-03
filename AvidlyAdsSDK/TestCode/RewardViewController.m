//
//  STRewardViewController.m
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/24.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "RewardViewController.h"
#import <AvidlyAdsSDK/AvidlyAdsSDK.h>

@interface RewardViewController () <AvidlyRewardDelegate>

@end

@implementation RewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 100, 250, 40);
    [button setTitle:@"加载激励视频广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(rewardClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button1.backgroundColor = [UIColor orangeColor];
    button1.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 200, 250, 40);
    [button1 setTitle:@"激励视频广告测试工具" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(testViewClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    [[AvidlyRewardWrapper shareInstance] setDelegate:self];
}

- (void)rewardClick
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        if ([[AvidlyRewardWrapper shareInstance] isReady]) {
            
            dispatch_async(dispatch_get_main_queue(), ^{
                [[AvidlyRewardWrapper shareInstance] show:self placeId:@"aaaa"];
            });
        }
        else {
            NSLog(@"Reward no ready");
        }
    });
}

//激励视频广告打开
- (void)AvidlyRewardVideoAdDidOpen
{
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

- (UIStatusBarStyle)preferredStatusBarStyle
{
    return UIStatusBarStyleLightContent;
}


#pragma mark Test

- (void)testViewClick
{
    [AvidlyRewardDebug showDebugView:self];
}

@end
