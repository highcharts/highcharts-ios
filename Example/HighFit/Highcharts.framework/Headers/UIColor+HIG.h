//
//  UIColor+HIG.h
//  Highcharts
//
//  License: www.highcharts.com/license
//  Copyright © 2016 Highsoft AS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (HIG)

/**
 *  Color class category. Creating HTML string representation of UIColor object.
 *
 *  @return UIColor as rgba color string egz. [UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:1.0].color to rgba(255, 255, 255, 1.0)
 */
- (NSString*)color;

@end
