/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Global options that don't apply to each chart. These options, like the lang
		options, must be set using the Highcharts.setOptions method.
Highcharts.setOptions({
	global: {
		useUTC: false
	}
});
*/
@interface HIGlobal: HIChartsJSONSerializable

/**
* description: Requires http://momentjs.com/ : moment.js. If the timezone option is specified, it creates a default getTimezoneOffset function that looks up the specified timezone in moment.js. If moment.js is not included, this throws a Highcharts error in the console, but does not crash the chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.0.0/highslide-software/highcharts.com/tree/master/samples/highcharts/global/timezone/ : Europe/Oslo
* default: undefined
*/
@property(nonatomic, readwrite) NSString *timezone;
/**
* description: A custom Date class for advanced date handling. For example, https://github.com/tahajahangir/jdate : JDate can be hooked in to handle Jalali dates.
*/
@property(nonatomic, readwrite) id Date;
/**
* description: Whether to use UTC time for axis scaling, tickmark placement and time display in  Highcharts.dateFormat. Advantages of using UTC is that the time displays equally regardless of the user agent's time zone settings. Local time can be used when the data is loaded in real time or when correct Daylight Saving Time transitions are required.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/global/useutc-true/ : True by default - the starting point which is 
			at 00:00 UTC, is displayed as 00:00 in the axis labels and in the tooltip. 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/global/useutc-false/ : False - the starting point which is 
			at 00:00 UTC, is displayed as your local browser time in the axis labels and in 
			the tooltip.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useUTC;
/**
* description: Path to the pattern image required by VML browsers in order to draw radial gradients.
* default: http://code.highcharts.com/{version}/gfx/vml-radial-gradient.png
*/
@property(nonatomic, readwrite) NSString *VMLRadialGradientURL;
/**
* description: A callback to return the time zone offset for a given datetime. It takes the timestamp in terms of milliseconds since January 1 1970, and returns the timezone offset in minutes. This provides a hook for drawing time based charts in specific time zones using their local DST crossover dates, with the help of external libraries. 
* demo:  http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/global/gettimezoneoffset/ : Use moment.js to draw Oslo time regardless of browser locale
*/
@property(nonatomic, readwrite) NSString /* Function */ *getTimezoneOffset;
/**
* description: Canvg rendering for Android 2.x is removed as of Highcharts 5.0. Use the libURL option to configure exporting.
The URL to the additional file to lazy load for Android 2.x devices. These devices don't 
 support SVG, so we download a helper file that contains http://code.google.com/p/canvg/ : canvg,
 its dependency rbcolor, and our own CanVG Renderer class. To avoid hotlinking to our site,
 you can install canvas-tools.js on your own server and change this option accordingly.
* default: http://code.highcharts.com/{version}/modules/canvas-tools.js
*/
@property(nonatomic, readwrite) NSString *canvasToolsURL;
/**
* description: The timezone offset in minutes. Positive values are west, negative values are east of UTC, as in the ECMAScript https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date/getTimezoneOffset : getTimezoneOffset method. Use this to display UTC based data in a predefined time zone. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/global/timezoneoffset/ : Timezone offset
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *timezoneOffset;

-(NSDictionary *)getParams;

@end
