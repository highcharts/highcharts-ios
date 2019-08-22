/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILinearGradientColorObject.h"
#import "HIRadialGradientColorObject.h"


/**
Gradient options instead of a solid color.
*/
@interface HIGradientColorObject: HIChartsJSONSerializable

/**
Holds an object that defines the start position and the end position relative to the shape.
*/
@property(nonatomic, readwrite) HILinearGradientColorObject *linearGradient;
/**
Holds an object that defines the center position and the radius.
*/
@property(nonatomic, readwrite) HIRadialGradientColorObject *radialGradient;
/**
The first item in each tuple is the position in the gradient, where 0 is the start of the gradient and 1 is the end of the gradient. Multiple stops can be applied. The second item is the color for each stop. This color can also be given in the rgba format.
*/
@property(nonatomic, readwrite) NSArray *stops;

-(NSDictionary *)getParams;

@end
