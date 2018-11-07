//
//  IconViewController.m
//  UPSDK
//
//  Created by steve on 2018/10/17.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import "IconViewController.h"
#import <UPSDK/UPSDK.h>

@interface IconViewController () <UPIconDelegate> {
    UPIconWrapper *_iconAd;
}
@end

@implementation IconViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor grayColor];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 100, 250, 40);
    [button setTitle:@"展示Icon广告" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(iconShowClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button1.backgroundColor = [UIColor orangeColor];
    button1.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, 170, 250, 40);
    [button1 setTitle:@"移除Icon广告" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(iconRemoveClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
}

- (void)iconShowClick {
    _iconAd = [[UPIconWrapper alloc] initWithFrame:CGRectMake(100, 100, 150, 150) rotationAngle:10];
    _iconAd.delegate = self;
    [_iconAd loadAd];
}

- (void)iconRemoveClick {
    [_iconAd removeAd];
}

#pragma mark - UPIconDelegate

//Icon广告加载完成
- (void)iconAdDidLoad:(id)iconWrapper {
    NSLog(@"iconAdDidLoad");
    [_iconAd showAd:self.view];
}

//Icon广告加载失败
- (void)iconAd:(id)iconWrapper didLoadFail:(NSError *)error {
    NSLog(@"iconAdDidLoadFail");
}

//Icon广告点击
- (void)iconAdDidClick:(id)iconWrapper {
    NSLog(@"iconAdDidClick");
}

//Icon广告展示完成
- (void)iconAdDidShow:(id)iconWrapper {
    NSLog(@"iconAdDidShow");
}

@end
