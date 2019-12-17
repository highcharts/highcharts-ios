/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Time options that can apply globally or to individual charts. These settings affect how `datetime` axes are laid out, how tooltips are formatted, how series `pointIntervalUnit` works and how the Highstock range selector handles time. The common use case is that all charts in the same Highcharts object share the same time settings, in which case the global settings are set using `setOptions`. ```js // Apply time settings globally Highcharts.setOptions({   time: {     timezone: 'Europe/London'   } }); // Apply time settings by instance var chart = Highcharts.chart('container', {   time: {     timezone: 'America/New_York'   },   series: [{     data: [1, 4, 3, 5]   }] }); // Use the Time object console.log(    'Current time in New York',    chart.time.dateFormat('%Y-%m-%d %H:%M:%S', Date.now()) ); ``` Since v6.0.5, the time options were moved from the `global` obect to the `time` object, and time options can be set on each individual chart.

**Try it**

* [Set the timezone globally](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
* [Set the timezone per chart instance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/individual/)
*/
@interface HITime: HIChartsJSONSerializable

/**
A custom `Date` class for advanced date handling. For example, [JDate](https://github.com/tahajahangir/jdate) can be hooked in to handle Jalali dates.
*/
@property(nonatomic, readwrite) id Date;
/**
Requires [moment.js](http://momentjs.com/). If the timezone option is specified, it creates a default `getTimezoneOffset` function that looks up the specified timezone in moment.js. If moment.js is not included, this throws a Highcharts error in the console, but does not crash the chart.

**Try it**

* [Europe/Oslo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
*/
@property(nonatomic, readwrite) NSString *timezone;
/**
A callback to return the time zone offset for a given datetime. It takes the timestamp in terms of milliseconds since January 1 1970, and returns the timezone offset in minutes. This provides a hook for drawing time based charts in specific time zones using their local DST crossover dates, with the help of external libraries.

**Try it**

* [Use moment.js to draw Oslo time regardless of browser locale](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/gettimezoneoffset/)
*/
@property(nonatomic, readwrite) NSString *getTimezoneOffset;
/**
The timezone offset in minutes. Positive values are west, negative values are east of UTC, as in the ECMAScript [getTimezoneOffset](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getTimezoneOffset) method. Use this to display UTC based data in a predefined time zone.

**Try it**

* [Timezone offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezoneoffset/)
*/
@property(nonatomic, readwrite) NSNumber *timezoneOffset;
/**
Whether to use UTC time for axis scaling, tickmark placement and time display in `Highcharts.dateFormat`. Advantages of using UTC is that the time displays equally regardless of the user agent's time zone settings. Local time can be used when the data is loaded in real time or when correct Daylight Saving Time transitions are required.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/useutc-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/useutc-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useUTC;

-(NSDictionary *)getParams;

@end
