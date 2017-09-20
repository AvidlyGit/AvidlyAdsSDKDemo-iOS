//
//  AvidlyAdsGlobalZone.h
//  AvidlyAdsSDK
//
//  Created by steve on 2017/6/2.
//  Copyright © 2017年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AvidlyAdsGlobalZone) {
    AvidlyAdsGlobalZoneForeign = 0,     //国外
    AvidlyAdsGlobalZoneDomestic = 1,    //国内
    AvidlyAdsGlobalZoneAuto = 2,        //自动根据ip判断
};
