/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICondition.h"


/**
A set of rules for responsive settings. The rules are executed from the top down.

**Try it**

* [Axis changes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
*/
@interface HIRules: HIChartsJSONSerializable

/**
Under which conditions the rule applies.
*/
@property(nonatomic, readwrite) HICondition *condition;
/**
A full set of chart options to apply as overrides to the general chart options. The chart options are applied when the given rule is active. A special case is configuration objects that take arrays, for example `xAxis`, `yAxis` or `series`. For these collections, an `id` option is used to map the new option set to an existing object. If an existing object of the same id is not found, the item of the same indexupdated. So for example, setting `chartOptions` with two series items without an `id`, will cause the existing chart's two series to be updated with respective options.

**Try it**

* [Axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
* [Legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/)
* [Class name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/)
*/
@property(nonatomic, readwrite) NSDictionary *chartOptions;

-(NSDictionary *)getParams;

@end
