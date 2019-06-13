/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Defines the center position and the radius for a gradient.
*/
@interface HIRadialGradientColorObject: HIChartsJSONSerializable

/**
Center horizontal position relative to the shape. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *cx;
/**
Center vertical position relative to the shape. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *cy;
/**
Radius relative to the shape. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *r;

-(NSDictionary *)getParams;

@end
