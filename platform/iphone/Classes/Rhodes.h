/*
 *  Rhodes.h
 *  rhorunner
 *
 *  Created by Dmitry Moskalchuk on 07.03.10.
 *  Copyright 2010 Rhomobile Inc. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "AppManager.h"
#import "RhoMainView.h"

#import "LogOptionsController.h"
#import "LogViewController.h"
#import "DateTimePickerDelegate.h"
#import "PickImageDelegate.h"

@protocol RhoRunnable

- (void)run;

@end

@interface Rhodes : NSObject <UIApplicationDelegate, UIWebViewDelegate, UITabBarControllerDelegate, AVAudioPlayerDelegate>
{
    AppManager *appManager;
    UIApplication *application;
    UIWindow *window;
    AVAudioPlayer *player;
    // Controllers
    LogOptionsController* logOptionsController;
    LogViewController* logViewController;
    DateTimePickerDelegate* dateTimePickerDelegate;
    PickImageDelegate* pickImageDelegate;
@public
    id<RhoMainView,NSObject> mainView;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) AVAudioPlayer *player;
@property (nonatomic, retain) id<RhoMainView,NSObject> mainView;

+ (Rhodes*)sharedInstance;

+ (UIApplication*)application;

+ (void)performOnUiThread:(id<RhoRunnable>)runnable wait:(BOOL)wait;

- (UIWindow*)rootWindow;
- (void)fixFrame;

- (void)playStart:(NSString*)fileName mediaType:(NSString*)type;
- (void)playStop;

@end