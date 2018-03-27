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
A partial fill for each point, typically used to visualize how much of a task is performed. The partial fill object can be set either on series or point level.

**Try it**

* [X-range with partial fill](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range)
*/
@interface HIPartialFill: HIChartsJSONSerializable

/**
The fill color to be used for partial fills. Defaults to a darker shade of the point color.
*/
@property(nonatomic, readwrite) HIColor *fill;

-(NSDictionary *)getParams;

@end
