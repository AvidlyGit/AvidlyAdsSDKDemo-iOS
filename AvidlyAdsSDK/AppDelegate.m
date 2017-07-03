//
//  AppDelegate.m
//  AvidlyAdsSDK
//
//  Created by steve on 2017/4/18.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <AvidlyAdsSDK/AvidlyAdsSDK.h>

@interface AppDelegate ()
{
    AvidlyIntersitialWrapper *_intersitialWrapper;
}
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.

    [AvidlyAdsSDK initSDK];
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    ViewController *vc = [[ViewController alloc] init];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    
    self.window.rootViewController = nav;
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
}

@end
