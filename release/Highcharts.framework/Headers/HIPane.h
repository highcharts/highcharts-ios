/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIBackground.h"


/**
The pane serves as a container for axes and backgrounds for circular gauges and polar charts.
*/
@interface HIPane: HIChartsJSONSerializable

/**
The end angle of the polar X axis or gauge value axis, given in degrees where 0 is north. Defaults to `startAngle` + 360.

**Try it**

* [VU-meter with custom start and end angle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/)
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
The start angle of the polar X axis or gauge axis, given in degrees where 0 is north. Defaults to 0.

**Try it**

* [VU-meter with custom start and end angle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
The center of a polar chart or angular gauge, given as an array of [x, y] positions. Positions can be given as integers that transform to pixels, or as percentages of the plot area size.

**Defaults to** `["50%", "50%"]`.

**Try it**

* [Two gauges with different center](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/)
*/
@property(nonatomic, readwrite) NSArray /* <NSString, NSNumber> */ *center;
/**
An array of background items for the pane.

**Try it**

* [Speedometer gauge with multiple backgrounds](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/)
*/
@property(nonatomic, readwrite) NSArray <HIBackground *> *background;
/**
The size of the pane, either as a number defining pixels, or a percentage defining a percentage of the plot are.

**Try it**

* [Smaller size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-vu-meter/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ size;

-(NSDictionary *)getParams;

@end
