/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPaneBackground.h"


/**
* description: Applies only to polar charts and angular gauges. This configuration object holds general options for the combined X and Y axes set. Each xAxis or yAxis can reference the pane by index.
*/
@interface HIPane: HIChartsJSONSerializable

/**
* description: The size of the pane, either as a number defining pixels, or a percentage defining a percentage of the plot are.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : Smaller size
* default: 85%
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ size;
/**
* description: An object, or array of objects, for backgrounds.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/ : Multiple backgrounds on a gauge.
*/
@property(nonatomic, readwrite) NSArray <HIPaneBackground *> *background;
/**
* description: The end angle of the polar X axis or gauge value axis, given in degrees where 0 is north. Defaults to startAngle + 360.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : VU-meter with custom start and end angle.
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
* description: The center of a polar chart or angular gauge, given as an array of [x, y] positions. Positions can be given as integers that transform to pixels, or as percentages of the plot area size.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : Two gauges with different center
* default: ["50%", "50%"]
*/
@property(nonatomic, readwrite) NSArray<id> /* <NSString, NSNumber> */ *center;
/**
* description: The start angle of the polar X axis or gauge axis, given in degrees where 0 is north. Defaults to 0.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : VU-meter with custom start and end angle.
*/
@property(nonatomic, readwrite) NSNumber *startAngle;

-(NSDictionary *)getParams;

@end
