//
//  PlayableAdsTools.h
//  
//
//  Created by dgaf on 2017/8/25.
//  Copyright © 2017年 dgaf. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PlayableAdsTools : NSObject

/*
 * 清除所有缓存
 */
+ (BOOL)clearAllCachedData;

/*
 * 控制台是否输出Log
 * 1 输出
 * 9 开启线上查看log服务
 * 0 不输出
 */
+ (void)setDebugLog:(NSInteger)debug;

/*
 * 获取版本号
 */
+ (NSString *_Nullable)getVersion;

@end
