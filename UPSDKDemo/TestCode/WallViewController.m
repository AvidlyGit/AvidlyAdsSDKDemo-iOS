//
//  WallViewController.m
//  UPSDKDemo
//
//  Created by steve on 2017/7/3.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "WallViewController.h"
#import <UPSDK/UPSDK.h>

@interface WallViewController ()
{
    AvidlyAdsWallWrapper *_recWallerWrapper;
}
@end

@implementation WallViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button2.backgroundColor = [UIColor orangeColor];
    button2.frame = CGRectMake(70, 100, 250, 40);
    [button2 setTitle:@"加载H5推荐墙广告" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(recwallerClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
}

- (void)recwallerClick
{
    if (!_recWallerWrapper) {
        _recWallerWrapper = [[AvidlyAdsWallWrapper alloc] init];
    }
    
    [_recWallerWrapper show:self];
}

@end
