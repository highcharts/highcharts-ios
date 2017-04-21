//
//  HIGView.h
//  Highcharts
//
//  License: www.highcharts.com/license
//  Copyright © 2016 Highsoft AS. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HIOptions.h"

/**
 *  Highcharts Chart View Class. Initialize this as a normal view and set
 *  required properties.
 */
@interface HIGChartView : UIView

/**
 *  Options are main configuration entry point for chart view, for more
 *  information read API documentation.
 */
@property (strong, nonatomic) HIOptions *options;

/**
 *  Theme name to load from file system after preloading.
 */
@property (strong, nonatomic) NSString *theme;

/**
 *  Additional plugins to load into chart after preloading.
 */
@property (strong, nonatomic) NSArray *plugins;

/**
 *  This param alows to debug chart view in safari inspector. Loads unminified 
 *  JS files to ease debuging.
 */
@property (assign, nonatomic) BOOL debug;

/**
 *  This is needed to make interactions betwen chart and your aplication view.
 */
@property (weak, nonatomic) UIViewController *viewController;

/**
 *  Allows to preload needed data to file system. Required to run before
 *  initilaiznig view.
 */
+ (void)preload;

- (void)reload;

@end
