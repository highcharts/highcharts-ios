/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
The appearance of the point marker when selected. In order to allow a point to be selected, set the `series.allowPointSelect` option to true.
*/
@interface HIPointStatesSelectOptionsObject: HIChartsJSONSerializable

/**
Enable or disable visible feedback for selection.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The fill color of the point marker.
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The color of the point marker's outline. When `undefined`, the series' or point's color is used.
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
The width of the point marker's outline.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2.
*/
@property(nonatomic, readwrite) NSNumber *radius;

-(NSDictionary *)getParams;

@end
