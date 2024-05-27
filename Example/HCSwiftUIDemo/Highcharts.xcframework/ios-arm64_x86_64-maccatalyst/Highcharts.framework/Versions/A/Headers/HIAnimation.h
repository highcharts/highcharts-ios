/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Enable or disable animation of the tooltip.
*/
@interface HIAnimation: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *duration;
/**
The animation delay time in milliseconds. Set to `0` renders annotation immediately. As `undefined` inherits defer time from the `series.animation.defer`.
*/
@property(nonatomic, readwrite) NSNumber *defer;

-(NSDictionary *)getParams;

@end
