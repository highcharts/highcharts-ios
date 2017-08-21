/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Under which conditions the rule applies.
*/
@interface HIResponsiveRulesCondition: HIChartsJSONSerializable

/**
* description: The responsive rule applies if the chart width is less than this.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/ : Max width is 500
*/
@property(nonatomic, readwrite) NSNumber *maxWidth;
/**
* description: A callback function to gain complete control on when the responsive rule applies. Return true if it applies. This opens for checking against other metrics than the chart size, or example the document size or other elements.
*/
@property(nonatomic, readwrite) NSString /* Function */ *callback;
/**
* description: The responsive rule applies if the chart height is greater than this.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *minHeight;
/**
* description: The responsive rule applies if the chart width is greater than this.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *minWidth;
/**
* description: The responsive rule applies if the chart height is less than this.
*/
@property(nonatomic, readwrite) NSNumber *maxHeight;

-(NSDictionary *)getParams;

@end
