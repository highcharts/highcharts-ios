/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIResponsiveRulesCondition.h"


/**
* description: A set of rules for responsive settings. The rules are executed from the top down.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : Axis changes
*/
@interface HIResponsiveRules: HIChartsJSONSerializable

/**
* description: Under which conditions the rule applies.
*/
@property(nonatomic, readwrite) HIResponsiveRulesCondition *condition;
/**
* description: A full set of chart options to apply as overrides to the general chart options. The chart options are applied when the given rule is active.
A special case is configuration objects that take arrays, for example xAxis, yAxis or series. For these collections, an id option is used to map the new option set to an existing object. If an existing object of the same id is not found, the first item is updated. So for example, setting chartOptions with a series item without an id, will cause the existing chart's first series to be updated.
* demo: Chart options overrides for http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : axis, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/ : legend and http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/ : class name.
*/
@property(nonatomic, readwrite) id chartOptions;

-(NSDictionary *)getParams;

@end
