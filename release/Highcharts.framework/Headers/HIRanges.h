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
Options for specific range. One range consists of bubble, label and connector.

**Try it**

* [Manually defined ranges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/ranges/)
* [Auto calculated ranges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/autoranges/)
*/
@interface HIRanges: HIChartsJSONSerializable

/**
The color of the border for individual range.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The color of the bubble for individual range.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
The color of the connector for individual range.
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
/**
Range size value, similar to bubble Z data.
*/
@property(nonatomic, readwrite) NSNumber *value;

-(NSDictionary *)getParams;

@end
