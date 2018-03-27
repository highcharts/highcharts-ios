/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"


/**
A `solidgauge` series. If the `type` option is not specified, it is inherited from `chart.type`. For options that apply to multiple series, it is recommended to add them to the `plotOptions.series` options structure. To apply to all series of this specific type, apply it to `plotOptions.solidgauge`.
*/
@interface HISolidgauge: HISeries

/**
Whether to give each point an individual color.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Allow the gauge to overshoot the end of the perimeter axis by this many degrees. Say if the gauge axis goes from 0 to 60, a value of 100, or 1000, will show 5 degrees beyond the end of the axis when this option is set to 5.

**Defaults to** `0`.

**Try it**

* [Allow 5 degrees overshoot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-overshoot/)
*/
@property(nonatomic, readwrite) NSNumber *overshoot;
/**
Wether to draw rounded edges on the gauge.

**Defaults to** `false`.

**Try it**

* [Activity Gauge](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-activity/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *rounded;

-(NSDictionary *)getParams;

@end
