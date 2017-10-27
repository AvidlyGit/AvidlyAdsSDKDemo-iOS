

NS_ASSUME_NONNULL_BEGIN

@protocol ZZAdNativeAdDelegate;

/**
 原生广告目前仅支持ZZADImageSize_1200x627尺寸，请求开发者选取参数时注意！！！！
 */
typedef NS_ENUM(NSInteger, ZZADImageSizeType) {

    ZZADImageSize_320x200 = 0, //广告素材 320x200
    ZZADImageSize_1200x627 = 1, //广告素材 1200x627
};

/**
 The ZZAdNativeAd represents ad metadata to allow you to construct custom ad views.
 See the NativeAdSample in the sample apps section of the Audience Network framework.
 */
@interface ZZAdNativeAd : NSObject


//*****************************常用接口**********************************

/**
 * 广告标题
 */
@property (nonatomic, copy, readonly, nullable) NSString *title;

/**
 *广告按钮图标
 */
@property (nonatomic, copy, readonly, nullable) NSString *callToAction;

/**
 *广告文字描述
 */
@property (nonatomic, copy, readonly, nullable) NSString *body;

/**
 加载广告图标
 
 @param block (图标image，图标url)，如果图标image为nil的话，需要app使用图标url去下载图标资源,如果连url都没有的话,表示没有icon
 */
-(void)loadAdIconImageAsyncWithBlock:(void(^)(UIImage*_Nullable,NSURL*_Nullable))block;

/**
 加载广告内容
 
 @param block （加载结果，广告素材的url），如果加载结果为NO的话，则需要使用广告素材的url去下载素材资源
 */
-(void)loadAdMediaImageAsyncWithBlock:(void(^)(BOOL,NSURL*_Nonnull))block;


/**
 注册整个view里面的组件都是可以点击跳转广告的,注意,该api会移除view的tap手势识别
 
 @param view 广告视图
 @param viewController 不能为空,用来给SDK present viewcontroller
 */
- (void)registerViewForInteraction:(UIView *)view
                withViewController:(nonnull UIViewController *)viewController;


/**
 注册广告视图哪些组件是可以点击跳转广告的,注意,该api会移除view和clickableViews的tap手势识别
 
 @param view 广告视图
 @param viewController 不能为空,用来给SDK present viewcontroller
 @param clickableViews 哪些子控件是可以被点击的
 */
- (void)registerViewForInteraction:(UIView *)view
                withViewController:(nonnull UIViewController *)viewController
                withClickableViews:(nonnull NSArray<UIView *>*)clickableViews;


/**
 *释放点击跳转广告的视图
 */
-(void)unRegisterView;

//*********************************************************************

/**
 广告位ID
 */
@property (nonatomic, copy, readonly, nonnull) NSString *placementID;

/**
 广告素材的尺寸，@"320x200"或者@"1200x627"
 */
@property (nonatomic, copy, readonly, nonnull) NSString *mediaSize;//广告素材尺寸

/**
 *加载广告的回调
 */
@property (nonatomic, weak, nullable) id<ZZAdNativeAdDelegate> delegate;

/**
 This is a method to initialize a ZZAdNativeAd object matching the given placement id.
 
 - Parameter placementID: The id of the ad placement. You can create your placement id from Facebook developers page.
 */
- (instancetype)initWithPlacementID:(NSString *)placementID  andImageSize:(ZZADImageSizeType) imageSize NS_DESIGNATED_INITIALIZER;


/**
 加载广告
 */
- (void)loadAd;

@end

/**
 The methods declared by the ZZAdNativeAdDelegate protocol allow the adopting delegate to respond to messages
 from the ZZAdNativeAd class and thus respond to operations such as whether the native ad has been loaded.
 */
@protocol ZZAdNativeAdDelegate <NSObject>

@optional


/**
 广告加载完成
 
 @param nativeAd 广告
 */
- (void)zzAd_nativeAdDidLoad:(ZZAdNativeAd *)nativeAd;


/**
 广告将要展示
 
 @param nativeAd 广告
 */
- (void)zzAd_nativeAdWillLogImpression:(ZZAdNativeAd *)nativeAd;


/**
 广告加载失败
 
 @param nativeAd 广告
 @param error 错误信息
 */
- (void)zzAd_nativeAd:(ZZAdNativeAd *)nativeAd didFailWithError:(NSError *)error;

/**
 广告被点击了，调用registerViewForInteraction2个api中的一个才会触发该事件
 
 @param nativeAd 广告
 */
- (void)zzAd_nativeAdDidClick:(ZZAdNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
