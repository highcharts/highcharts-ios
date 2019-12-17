/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
A declarative filter to control of which data labels to display. The declarative filter is designed for use when callback functions are not available, like when the chart options require a pure JSON structure or for use with graphical editors. For programmatic control, use the `formatter` instead, and return `undefined` to disable a single data label.

**Try it**

* [Data labels filtered by percentage](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome)
*/
@interface HIFilter: HIChartsJSONSerializable

/**
The operator to compare by. Can be one of `>`, `<`, `>=`, `<=`, `==`, and `===`.

**Accepted values:** `[">", "<", ">=", "<=", "==", "==="]`.
*/
@property(nonatomic, readwrite) NSString *operator;
/**
The point property to filter by. Point options are passed directly to properties, additionally there are `y` value, `percentage` and others listed under {@link Highcharts.Point} members.
*/
@property(nonatomic, readwrite) NSString *property;
/**
The value to compare against.
*/
@property(nonatomic, readwrite) NSNumber *value;

-(NSDictionary *)getParams;

@end
