//
//  ViewController.m
//  UPSDKDemo
//
//  Created by steve on 2017/4/18.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "ViewController.h"
#import "RewardViewController.h"
#import "InterstitialViewController.h"
#import "BannerTestViewController.h"
#import "WallViewController.h"
#import "IconViewController.h"
#import <UPSDK/UPSDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button1.backgroundColor = [UIColor orangeColor];
    button1.frame = CGRectMake(70, 100, 250, 40);
    [button1 setTitle:@"插屏广告测试" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(intersitialClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    [self adjustCenterH:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeSystem];
    button2.backgroundColor = [UIColor orangeColor];
    button2.frame = CGRectMake(70, 170, 250, 40);
    [button2 setTitle:@"横幅广告测试" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(bannerClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    [self adjustCenterH:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button3.backgroundColor = [UIColor orangeColor];
    button3.frame = CGRectMake(70, 240, 250, 40);
    [button3 setTitle:@"激励视频广告测试" forState:UIControlStateNormal];
    [button3 addTarget:self action:@selector(rewardClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
    [self adjustCenterH:button3];
    
    UIButton *button4 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button4.backgroundColor = [UIColor orangeColor];
    button4.frame = CGRectMake(70, 310, 250, 40);
    [button4 setTitle:@"Icon广告测试" forState:UIControlStateNormal];
    [button4 addTarget:self action:@selector(iconClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button4];
    [self adjustCenterH:button4];
}

- (void)adjustCenterH:(UIView*)v{
    CGPoint center = self.view.center;
    center.y = v.frame.origin.y + v.frame.size.height/2;
    v.center = center;
}

#pragma mark Click

- (void)bannerClick
{
    BannerTestViewController *vc = [[BannerTestViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)intersitialClick
{
    InterstitialViewController *vc = [[InterstitialViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)rewardClick
{
    RewardViewController *vc = [[RewardViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)wallClick
{
    WallViewController *vc = [[WallViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)iconClick
{
    IconViewController *vc = [[IconViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)testClick
{
    NSDictionary *adConfig = [UPSDK getAdConfigWithPlacementID:@"addStep111"];
    NSLog(@"%@",adConfig);
}

#pragma mark Orientations

- (UIInterfaceOrientationMask)supportedInterfaceOrientations{
    return UIInterfaceOrientationMaskPortrait;
}

- (BOOL)shouldAutorotate {
    return NO;
}

@end
