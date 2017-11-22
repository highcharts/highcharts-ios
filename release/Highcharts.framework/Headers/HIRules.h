/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICondition.h"


/**
* description: A set of rules for responsive settings. The rules are executed from
the top down.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : Axis changes

*/
@interface HIRules: HIChartsJSONSerializable

/**
* description: A full set of chart options to apply as overrides to the general
chart options. The chart options are applied when the given rule
is active.
A special case is configuration objects that take arrays, for example
xAxis, yAxis or series. For these
collections, an id option is used to map the new option set to
an existing object. If an existing object of the same id is not found,
the item of the same indexupdated. So for example, setting chartOptions
with two series items without an id, will cause the existing chart's
two series to be updated with respective options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/demo/responsive/ : Stock chart
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : Axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/ : Legend
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/ : Class name
*/
@property(nonatomic, readwrite) id chartOptions;
/**
* description: Under which conditions the rule applies.
*/
@property(nonatomic, readwrite) HICondition *condition;

-(NSDictionary *)getParams;

@end
