/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIRules.h"


/**
Allows setting a set of rules to apply for different screen or chart sizes. Each rule specifies additional chart options.

**Try it**

* [Axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
* [Legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/)
* [Class name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/)
*/
@interface HIResponsive: HIChartsJSONSerializable

/**
A set of rules for responsive settings. The rules are executed from the top down.

**Try it**

* [Axis changes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
*/
@property(nonatomic, readwrite) NSArray <HIRules *> *rules;

-(NSDictionary *)getParams;

@end
