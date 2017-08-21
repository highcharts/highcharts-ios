/**
 * (c) 2009-2017 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import <UIKit/UIKit.h>

@interface UIColor (HIG)

/**
 *  Color class category. Creating HTML string representation of UIColor object.
 *
 *  @return UIColor as rgba color string egz. [UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:1.0].color to rgba(255, 255, 255, 1.0)
 */
- (NSString*)color;

@end
