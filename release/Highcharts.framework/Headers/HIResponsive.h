/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIResponsiveRules.h"


/**
* description: Allows setting a set of rules to apply for different screen or chart sizes. Each rule specifies additional chart options.
* demo: Responsive http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : axis, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/ : legend and http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/ : class name.
*/
@interface HIResponsive: HIChartsJSONSerializable

/**
* description: A set of rules for responsive settings. The rules are executed from the top down.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : Axis changes
*/
@property(nonatomic, readwrite) NSArray <HIResponsiveRules *> *rules;

-(NSDictionary *)getParams;

@end
