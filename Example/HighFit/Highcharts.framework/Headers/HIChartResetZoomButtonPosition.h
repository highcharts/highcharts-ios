/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The position of the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-position/ : Above the plot area
*/
@interface HIChartResetZoomButtonPosition: HIChartsJSONSerializable

/**
* description: The heatmap series type. This series type is available both in Highcharts and Highmaps.
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: The vertical offset of the button.
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The horizontal offset of the button
* default: -10
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The vertical alignment of the button.
* accepted values: ["top", "middle", "bottom"]
* default: top
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
