//
//  STDebugManager.h
//  HolaStatistical
//
//  Created by steve on 16/7/26.
//  Copyright © 2016年 steve. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface STDebugManager : NSObject

@property (nonatomic,assign) BOOL isDebug;

/**
 *  单例
 *
 *  @return instancetype
 */
+ (instancetype)shareDebugManager;

/**
 *  记录Debug日志
 *
 *  @param str 日志内容
 */
+ (void)log:(NSString *)str;

+ (void)logNofile:(NSString *)str;
@end
