/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

@import UIKit;
#import "HIChartsJSONSerializable.h"

/**
 *  This class provides color management in the chart.
 */
@interface HIColor : HIChartsJSONSerializable

/** 
 * Standard hex color value, for example FFFFFF for black and 000000 for white
 */
-(instancetype)initWithHexValue:(NSString *)string;

/**
 * Values of red, green and blue color in RGB standard: values 0-255
 */
-(instancetype)initWithRGB:(int)red green:(int)green blue:(int)blue;

/**
 * Values of red, green and blue color in RGBa standard. Values for colors: 0-255, alpha: 0-1
 */
-(instancetype)initWithRGBA:(int)red green:(int)green blue:(int)blue alpha:(double)alpha;

/**
 * Standard color names: red, green, black etc.
 */
-(instancetype)initWithName:(NSString *)name;

/**
 * CSS-style linear gradient
 */
-(instancetype)initWithLinearGradient:(NSDictionary *)gradient stops:(NSArray *)stops;

/**
 * CSS-style radial gradient
 */
-(instancetype)initWithRadialGradient:(NSDictionary *)gradient stops:(NSArray *)stops;

/**
 * Init with UIKit's UIColor
 */
- (instancetype)initWithUIColor: (UIColor *) color;

-(id)getData;

@end
