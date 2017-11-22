/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIDial.h"
#import "HIPivot.h"


/**
* description: A gauge series. If the type option is not
specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
gauge.
*/
@interface HIGauge: HISeries

/**
* description: When this option is true, the dial will wrap around the axes. For
instance, in a full-range gauge going from 0 to 360, a value of 400
will point to 40. When wrap is false, the dial stops at 360.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *wrap;
/**
* description: Allow the dial to overshoot the end of the perimeter axis by this
many degrees. Say if the gauge axis goes from 0 to 60, a value of
100, or 1000, will show 5 degrees beyond the end of the axis.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-overshoot/ : Allow 5 degrees overshoot
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *overshoot;
/**
* description: Options for the dial or arrow pointer of the gauge.
In styled mode, the dial is styled with the .highcharts-gauge-
series .highcharts-dial rule.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/gauge/ : Styled mode
*/
@property(nonatomic, readwrite) HIDial *dial;
/**
* description: Options for the pivot or the center point of the gauge.
In styled mode, the pivot is styled with the .highcharts-gauge-
series .highcharts-pivot rule.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/gauge/ : Styled mode
*/
@property(nonatomic, readwrite) HIPivot *pivot;

-(NSDictionary *)getParams;

@end
