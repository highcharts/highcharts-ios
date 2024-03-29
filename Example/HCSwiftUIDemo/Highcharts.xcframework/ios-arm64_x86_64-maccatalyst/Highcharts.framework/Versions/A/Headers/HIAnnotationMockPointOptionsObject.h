/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Object of shape point.
*/
@interface HIAnnotationMockPointOptionsObject: HIChartsJSONSerializable

/**
The x position of the point. Units can be either in axis or chart pixel coordinates.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
This number defines which xAxis the point is connected to. It refers to either the axis id or the index of the axis in the xAxis array. If the option is not configured or the axis is not found the point's x coordinate refers to the chart pixels.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ xAxis;
/**
The y position of the point. Units can be either in axis or chart pixel coordinates.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
This number defines which yAxis the point is connected to. It refers to either the axis id or the index of the axis in the yAxis array. If the option is not configured or the axis is not found the point's y coordinate refers to the chart pixels.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ yAxis;

-(NSDictionary *)getParams;

@end
