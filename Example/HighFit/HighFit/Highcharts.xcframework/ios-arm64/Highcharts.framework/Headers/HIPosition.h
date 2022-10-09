/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options allowing to set a position and an offset of the series in the _Series on point_ feature.
*/
@interface HIPosition: HIChartsJSONSerializable

/**
Y position of the series center. By default, the series is displayed on the point that it is connected to.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
X position of the series center. By default, the series is displayed on the point that it is connected to.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Series center offset from the original x position. If defined, the connector line is drawn connecting original position with new position.
*/
@property(nonatomic, readwrite) NSNumber *offsetX;
/**
Series center offset from the original y position. If defined, the connector line is drawn from original position to a new position.
*/
@property(nonatomic, readwrite) NSNumber *offsetY;
/**
The horizontal alignment of the button.
*/
@property(nonatomic, readwrite) NSString *align;
/**
The vertical alignment of the button.

**Defaults to** `top`.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
