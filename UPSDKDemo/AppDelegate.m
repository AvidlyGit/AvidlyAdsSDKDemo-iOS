//
//  AppDelegate.m
//  UPSDKDemo
//
//  Created by steve on 2017/4/18.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <UPSDK/UPSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    ViewController *vc = [[ViewController alloc] init];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    
    self.window.rootViewController = nav;
    [self.window makeKeyAndVisible];
    
    //以下模拟三种GDPR需求下的初始化方式，请根据自身情况选择其一
    //方式一 发行区域不涉及欧盟以及不涉及欧盟用户，正常的初始化逻辑
    //方式二 游戏发行在欧盟，涉及欧盟用户，且CP可以自行向用户请求授权
    //方式二 游戏发行在欧盟，涉及欧盟用户，且CP希望SDK向用户请求授权。其中使用了SDK提供的<判断欧盟用户API><向用户请求授权的API>两个API
    
    //------ 方式一 ------
    //SDK init
    [UPSDK initSDK:UPSDKGlobalZoneForeign];
    [UPSDK initAdConfigWithGameAccountId:@"123" completeTask:NO isPaid:0 promotionChannelName:@"facebook" gender:@"m" age:20 tags:nil];
    
    //------ 方式二 ------
    //设置GDPR状态
    [UPSDK updateAccessPrivacyInfoStatus:UPAccessPrivacyInfoStatusAccepted];
    //SDK init
    [UPSDK initSDK:UPSDKGlobalZoneForeign];
    [UPSDK initAdConfigWithGameAccountId:@"123" completeTask:NO isPaid:0 promotionChannelName:@"facebook" gender:@"m" age:20 tags:nil];
    
    //------ 方式三 ------
    //准备查询用户归属
    [UPSDK checkIsEuropeanUnionUser:^(BOOL isEuropeanUnion) {
        if (isEuropeanUnion) {
            //欧盟用户
            //请求授权
            [UPSDK requestAuthorizationWithAlert:vc completion:^(BOOL isAccepted) {
                if (isAccepted) {
                    //同意授权
                    [UPSDK updateAccessPrivacyInfoStatus:UPAccessPrivacyInfoStatusAccepted];
                }
                else {
                    //拒绝授权
                    [UPSDK updateAccessPrivacyInfoStatus:UPAccessPrivacyInfoStatusDenied];
                }
                //SDK init
                [UPSDK initSDK:UPSDKGlobalZoneForeign];
                [UPSDK initAdConfigWithGameAccountId:@"123" completeTask:NO isPaid:0 promotionChannelName:@"facebook" gender:@"m" age:20 tags:nil];
            }];
        }
        else {
            //非欧盟用户
            //DK init
            [UPSDK initSDK:UPSDKGlobalZoneForeign];
            [UPSDK initAdConfigWithGameAccountId:@"123" completeTask:NO isPaid:0 promotionChannelName:@"facebook" gender:@"m" age:20 tags:nil];
        }
    }];
    
    return YES;
}
    
[UPSDK requestAuthorizationWithAlert:vc completion:^(BOOL isAccepted) {
    if (isAccepted) {
        //同意授权
    }
    else {
        //拒绝授权
    }
}];

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
}

@end
