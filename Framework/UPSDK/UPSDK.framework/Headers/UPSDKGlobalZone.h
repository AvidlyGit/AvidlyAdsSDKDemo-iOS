//
//  UPSDKAdsGlobalZone.h
//  AvidlyAdsSDK
//
//  Created by steve on 2018/4/16.
//  Copyright © 2018年 liuguojun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, UPSDKGlobalZone) {
    UPSDKGlobalZoneForeign = 0,     //海外
    UPSDKGlobalZoneDomestic = 1,    //中国大陆
    UPSDKGlobalZoneAuto = 2,        //自动根据ip判断
};
