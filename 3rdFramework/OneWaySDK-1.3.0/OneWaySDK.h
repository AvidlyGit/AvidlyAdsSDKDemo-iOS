#import <UIKit/UIKit.h>

#import "OWUserMetaData.h"

/**
 *  An enumerate that describes the state of `OneWaySDK` placements. 
 *  @note All placement states, other than `kOneWaySDKPlacementStateReady`, indicate that the placement is not currently ready to show ads.
 */
typedef NS_ENUM(NSInteger, OneWaySDKPlacementState) {
    /**
     *  A state that indicates that the placement is ready to show an ad. The `show:` selector can be called.
     */
    kOneWaySDKPlacementStateReady,
    /**
     *  A state that indicates that no state is information is available.
     *  @warning This state can that OneWaySDK is not initialized or that the placement is not correctly configured in the oneway ads admin tool.
     */
    kOneWaySDKPlacementStateNotAvailable,
    /**
     *  A state that indicates that the placement is currently disabled. The placement can be enabled in the oneway ads admin tools.
     */
    kOneWaySDKPlacementStateDisabled,
    /**
     *  A state that indicates that the placement is not currently ready, but will be in the future.
     *  @note This state most likely indicates that the ad content is currently caching.
     */
    kOneWaySDKPlacementStateWaiting,
    /**
     *  A state that indicates that the placement is properly configured, but there are currently no ads available for the placement.
     */
    kOneWaySDKPlacementStateNoFill
};


/**
 *  An enumeration for the completion state of an ad.
 */
typedef NS_ENUM(NSInteger, OneWaySDKFinishState) {
    /**
     *  A state that indicates that the ad did not successfully display.
     */
    kOneWaySDKFinishStateError,
    /**
     *  A state that indicates that the user skipped the ad.
     */
    kOneWaySDKFinishStateSkipped,
    /**
     *  A state that indicates that the ad was played entirely.
     */
    kOneWaySDKFinishStateCompleted
};

/**
 *  An enumeration for the various errors that can be emitted through the `OneWaySDKDelegate` `OneWaySDKDidError:withMessage:` method.
 */
typedef NS_ENUM(NSInteger, OneWaySDKError) {
    /**
     *  An error that indicates failure due to `OneWaySDK` currently being uninitialized.
     */
    kOneWaySDKErrorNotInitialized = 0,
    /**
     *  An error that indicates failure due to a failure in the initialization process.
     */
    kOneWaySDKErrorInitializedFailed,
    /**
     *  An error that indicates failure due to attempting to initialize `OneWaySDK` with invalid parameters.
     */
    kOneWaySDKErrorInvalidArgument,
    /**
     *  An error that indicates failure of the video player.
     */
    kOneWaySDKErrorVideoPlayerError,
    /**
     *  An error that indicates failure due to having attempted to initialize the `OneWaySDK` class in an invalid environment.
     */
    kOneWaySDKErrorInitSanityCheckFail,
    /**
     *  An error that indicates failure due to the presence of an ad blocker.
     */
    kOneWaySDKErrorAdBlockerDetected,
    /**
     *  An error that indicates failure due to inability to read or write a file.
     */
    kOneWaySDKErrorFileIoError,
    /**
     *  An error that indicates failure due to a bad device identifier.
     */
    kOneWaySDKErrorDeviceIdError,
    /**
     *  An error that indicates a failure when attempting to show an ad.
     */
    kOneWaySDKErrorShowError,
    /**
     *  An error that indicates an internal failure in `OneWaySDK`.
     */
    kOneWaySDKErrorInternalError,
    /**
     *  A state that indicates that the SDK is properly configured, but there are currently no ads available.
     */
    kOneWaySDKCampaignNoFill,

};

/**
 *  The `OneWaySDKDelegate` protocol defines the required methods for receiving messages from OneWaySDK.
 *  Must be implemented by the hosting app.
 *  The OneWaySDKReady: method is called when it's possible to show an ad.
 *  All other methods are used to provide notifications of events of the ad lifecycle.
 *  @note On initialization, there are ready (or error) callbacks for each placement attached to the publish identifier.
 */
NS_ASSUME_NONNULL_BEGIN
@protocol OneWaySDKDelegate <NSObject>
/**
 *  Called when `OneWaySDK` is ready to show an ad. After this callback you can call the `OneWaySDK` `show:` method for this placement.
 *  Note that sometimes placement might no longer be ready due to exceptional reasons. These situations will give no new callbacks.
 *
 *  @warning To avoid error situations, it is always best to check `isReady` method status before calling show.
 *  @param placementId The ID of the placement that is ready to show, as defined in oneway ads admin tools.
 */
- (void)oneWaySDKReady:(NSString *)placementId;
/**
 *  Called when `OneWaySDK` encounters an error. All errors will be logged but this method can be used as an additional debugging aid. This callback can also be used for collecting statistics from different error scenarios.
 *
 *  @param error   A `OneWaySDKError` error enum value indicating the type of error encountered.
 *  @param message A human readable string indicating the type of error encountered.
 */
- (void)oneWaySDKDidError:(OneWaySDKError)error withMessage:(NSString *)message;
/**
 *  Called on a successful start of advertisement after calling the `OneWaySDK` `show:` method.
 *  
 * @warning If there are errors in starting the advertisement, this method may never be called. oneway ads will directly call `oneWaySDKDidFinish:withFinishState:` with error status.
 *
 *  @param placementId The ID of the placement that has started, as defined in oneway ads admin tools.
 */
- (void)oneWaySDKDidStart:(NSString *)placementId;
/**
 *  Called after the ad has closed.
 *
 *  @param placementId The ID of the placement that has finished, as defined in oneway ads admin tools.
 *  @param state       An enum value indicating the finish state of the ad. Possible values are `Completed`, `Skipped`, and `Error`.
 */
- (void)oneWaySDKDidFinish:(NSString *)placementId
          withFinishState:(OneWaySDKFinishState)state;
@end

/**
 * `oneWaySDK` is a static class with methods for preparing and showing ads.
 *
 * @warning In order to ensure expected behaviour, the delegate must always be set.
 */

@interface OneWaySDK : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)initialize NS_UNAVAILABLE;

/**
 *  Initializes oneWaySDK. oneWaySDK should be initialized when app starts.
 *
 *  @param publishId   Unique identifier for a game, given by oneway ads admin tools or OneWay editor.
 *  @param delegate delegate for OneWaySDKDelegate callbacks
 */
+ (void)initialize:(NSString *)publishId
          delegate:(nullable id<OneWaySDKDelegate>)delegate;
/**
 *  Initializes oneWaySDK. oneWaySDK should be initialized when app starts.
 *
 *  @param publishId   Unique identifier for a game, given by oneway ads admin tools or OneWay editor.
 *  @param delegate delegate for OneWaySDKDelegate callbacks
 *  @param testMode Set this flag to `YES` to indicate test mode and show only test ads.
 */
+ (void)initialize:(NSString *)publishId
          delegate:(nullable id<OneWaySDKDelegate>)delegate
          testMode:(BOOL)testMode;
/**
 *  Show an ad using the defaul placement.
 *
 *  @param viewController The `UIViewController` that is to present the ad view controller.
 */
+ (void)show:(UIViewController *)viewController;
/**
 *  Show an ad using the provided placement ID.
 *
 *  @param viewController The `UIViewController` that is to present the ad view controller.
 *  @param placementId    The placement ID, as defined in oneway ads admin tools.
 */
+ (void)show:(UIViewController *)viewController placementId:(NSString *)placementId;
/**
 *  Provides the currently assigned `OneWaySDKDelegate`.
 *
 *  @return The current `OneWaySDKDelegate`.
 */
+ (id<OneWaySDKDelegate>)getDelegate;
/**
 *  Allows the delegate to be reassigned after oneWaySDK has already been initialized.
 *
 *  @param delegate The new `OneWaySDKDelegate' for OneWaySDK to send callbacks to.
 */
+ (void)setDelegate:(id<OneWaySDKDelegate>)delegate;
/**
 *  Get the current debug status of `oneWaySDK`.
 *
 *  @return If `YES`, `oneWaySDK` will provide verbose logs.
 */
+ (BOOL)getDebugMode;
/**
 *  Set the logging verbosity of `oneWaySDK`. Debug mode indicates verbose logging.
 *  @warning Does not relate to test mode for ad content.
 *  @param enableDebugMode `YES` for verbose logging.
 */
+ (void)setDebugMode:(BOOL)enableDebugMode;
/**
 *  Check to see if the current device supports using oneway ads.
 *
 *  @return If `NO`, the current device cannot initialize `oneWaySDK` or show ads.
 */
+ (BOOL)isSupported;
/**
 *  Check if the default placement is ready to show an ad.
 *
 *  @return If `YES`, the default placement is ready to show an ad.
 */
+ (BOOL)isReady;
/**
 *  Check if a particular placement is ready to show an ad.
 *
 *  @param placementId The placement ID being checked.
 *
 *  @return If `YES`, the placement is ready to show an ad.
 */
+ (BOOL)isReady:(NSString *)placementId;
/**
 *  Check the current state of the default placement.
 *
 *  @return If this is `kOneWaySDKPlacementStateReady`, the placement is ready to show ads. Other states represent errors.
 */
+ (OneWaySDKPlacementState)getPlacementState;
/**
 *  Check the current state of a placement.
 *
 *  @param placementId The placement ID, as defined in oneway ads admin tools.
 *
 *  @return If this is `kOneWaySDKPlacementStateReady`, the placement is ready to show ads. Other states represent errors.
 */
+ (OneWaySDKPlacementState)getPlacementState:(NSString *)placementId;
/**
 *  Check the version of this `oneWaySDK` SDK
 *
 *  @return String representing the current version name.
 */
+ (NSString *)getVersion;
/**
 *  Check that `oneWaySDK` has been initialized. This might be useful for debugging initialization problems.
 *
 *  @return If `YES`, oneway ads has been successfully initialized.
 */
+ (BOOL)isInitialized;

@end
NS_ASSUME_NONNULL_END
