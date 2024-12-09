/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Time options that can apply globally or to individual charts. These settings affect how `datetime` axes are laid out, how tooltips are formatted, how series `pointIntervalUnit` works and how the Highcharts Stock range selector handles time. The common use case is that all charts in the same Highcharts object share the same time settings, in which case the global settings are set using `setOptions`. ```js // Apply time settings globally Highcharts.setOptions({   time: {     timezone: 'Europe/London'   } }); // Apply time settings by instance const chart = Highcharts.chart('container', {   time: {     timezone: 'America/New_York'   },   series: [{     data: [1, 4, 3, 5]   }] }); // Use the Time object console.log(    'Current time in New York',    chart.time.dateFormat('%Y-%m-%d %H:%M:%S', Date.now()) ); ``` Since v6.0.5, the time options were moved from the `global` object to the `time` object, and time options can be set on each individual chart.

**Try it**

* [Set the timezone globally](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
* [Set the timezone per chart instance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/individual/)
*/
@interface HITime: HIChartsJSONSerializable

/**
A custom `Date` class for advanced date handling. For example, [JDate](https://github.com/tahajahangir/jdate) can be hooked in to handle Jalali dates.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) id Date;
/**
A named time zone. Supported time zone names rely on the browser implementations, as described in the [mdn docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat/DateTimeFormat#timezone). If the given time zone is not recognized by the browser, Highcharts provides a warning and falls back to returning a 0 offset, corresponding to the UTC time zone. The time zone affects axis scaling, tickmark placement and time display in `Highcharts.dateFormat`. Setting `timezone` to `undefined` falls back to the default browser timezone setting. Until v11.2.0, this option depended on moment.js.

**Defaults to** `UTC`.

**Try it**

* [Europe/Oslo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
*/
@property(nonatomic, readwrite) NSString *timezone;
/**
How to perform the mapping.

**Try it**

* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) NSString *mapFunction;
/**
The minimum value for the audio parameter. This is the lowest value the audio parameter will be mapped to.
*/
@property(nonatomic, readwrite) NSNumber *min;
/**
The maximum value for the audio parameter. This is the highest value the audio parameter will be mapped to.
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
What data values to map the parameter within. Mapping within `"series"` will make the lowest value point in the series map to the min audio parameter value, and the highest value will map to the max audio parameter. Mapping within `"chart"` will make the lowest value point in the whole chart map to the min audio parameter value, and the highest value in the whole chart will map to the max audio parameter. You can also map within the X or Y axis of each series.

**Try it**

* [Mapping within demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-within)
*/
@property(nonatomic, readwrite) NSString *within;
/**
A fixed value to use for the prop when mapping. For example, if mapping to `y`, setting value to `4` will map as if all points had a y value of 4.

**Try it**

* [Map to fixed y value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
A point property to map the mapping parameter to. A negative sign `-` can be placed before the property name to make mapping inverted.

**Try it**

* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
*/
@property(nonatomic, readwrite) NSString *mapTo;

-(NSDictionary *)getParams;

@end
