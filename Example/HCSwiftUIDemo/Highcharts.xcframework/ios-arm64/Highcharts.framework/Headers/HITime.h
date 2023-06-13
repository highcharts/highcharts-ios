/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
Time options that can apply globally or to individual charts. These settings affect how `datetime` axes are laid out, how tooltips are formatted, how series `pointIntervalUnit` works and how the Highcharts Stock range selector handles time. The common use case is that all charts in the same Highcharts object share the same time settings, in which case the global settings are set using `setOptions`. ```js // Apply time settings globally Highcharts.setOptions({   time: {     timezone: 'Europe/London'   } }); // Apply time settings by instance let chart = Highcharts.chart('container', {   time: {     timezone: 'America/New_York'   },   series: [{     data: [1, 4, 3, 5]   }] }); // Use the Time object console.log(    'Current time in New York',    chart.time.dateFormat('%Y-%m-%d %H:%M:%S', Date.now()) ); ``` Since v6.0.5, the time options were moved from the `global` obect to the `time` object, and time options can be set on each individual chart.

**Try it**

* [Set the timezone globally](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
* [Set the timezone per chart instance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/individual/)
*/
@interface HITime: HIChartsJSONSerializable

/**
Whether to use UTC time for axis scaling, tickmark placement and time display in `Highcharts.dateFormat`. Advantages of using UTC is that the time displays equally regardless of the user agent's time zone settings. Local time can be used when the data is loaded in real time or when correct Daylight Saving Time transitions are required.

**Defaults to** `True`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/useutc-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/useutc-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useUTC;
/**
A callback to return the time zone offset for a given datetime. It takes the timestamp in terms of milliseconds since January 1 1970, and returns the timezone offset in minutes. This provides a hook for drawing time based charts in specific time zones using their local DST crossover dates, with the help of external libraries.

**Defaults to** `undefined`.

**Try it**

* [Use moment.js to draw Oslo time regardless of browser locale](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/gettimezoneoffset/)
*/
@property(nonatomic, readwrite) HIFunction *getTimezoneOffset;
/**
Allows to manually load the `moment.js` library from Highcharts options instead of the `window`. In case of loading the library from a `script` tag, this option is not needed, it will be loaded from there by default.
*/
@property(nonatomic, readwrite) HIFunction *moment;
/**
A custom `Date` class for advanced date handling. For example, [JDate](https://github.com/tahajahangir/jdate) can be hooked in to handle Jalali dates.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) id Date;
/**
Requires [moment.js](https://momentjs.com/). If the timezone option is specified, it creates a default `getTimezoneOffset` function that looks up the specified timezone in moment.js. If moment.js is not included, this throws a Highcharts error in the console, but does not crash the chart.

**Defaults to** `undefined`.

**Try it**

* [Europe/Oslo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
*/
@property(nonatomic, readwrite) NSString *timezone;
/**
The timezone offset in minutes. Positive values are west, negative values are east of UTC, as in the ECMAScript [getTimezoneOffset](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getTimezoneOffset) method. Use this to display UTC based data in a predefined time zone.

**Try it**

* [Timezone offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezoneoffset/)
*/
@property(nonatomic, readwrite) NSNumber *timezoneOffset;
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
