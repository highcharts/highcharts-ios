/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIBackground.h"


/**
* description: The pane serves as a container for axes and backgrounds for circular 
gauges and polar charts.
*/
@interface HIPane: HIChartsJSONSerializable

/**
* description: An array of background items for the pane.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/ : Speedometer gauge with multiple backgrounds
*/
@property(nonatomic, readwrite) NSArray <HIBackground *> *background;
/**
* description: The size of the pane, either as a number defining pixels, or a
percentage defining a percentage of the plot are.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : Smaller size
* default: 85%
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ size;
/**
* description: The end angle of the polar X axis or gauge value axis, given in degrees
where 0 is north. Defaults to startAngle + 360.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : VU-meter with custom start and end angle
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
* description: The center of a polar chart or angular gauge, given as an array
of [x, y] positions. Positions can be given as integers that transform
to pixels, or as percentages of the plot area size.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : Two gauges with different center
* default: ["50%", "50%"]
*/
@property(nonatomic, readwrite) NSArray /* <NSString, NSNumber> */ *center;
/**
* description: The start angle of the polar X axis or gauge axis, given in degrees
where 0 is north. Defaults to 0.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/ : VU-meter with custom start and end angle
*/
@property(nonatomic, readwrite) NSNumber *startAngle;

-(NSDictionary *)getParams;

@end
