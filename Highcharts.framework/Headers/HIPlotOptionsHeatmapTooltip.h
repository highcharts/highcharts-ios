/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A configuration object for the tooltip rendering of each single series. Properties are inherited from tooltip, but only the following properties can be defined on a series level.
*/
@interface HIPlotOptionsHeatmapTooltip: HIChartsJSONSerializable

/**
* description: The HTML of the point's line in the tooltip. Variables are enclosed by curly brackets. Available variables are point.x, point.y, series.name and series.color and other properties on the same form. Furthermore,  point.y can be extended by the tooltip.valuePrefix and tooltip.valueSuffix variables. This can also be overridden for each series, which makes it a good hook for displaying units.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the dot is colored by a class name rather than the point color.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/pointformat/ : A different point format with value suffix
* default: <span style="color:{point.color}">\u25CF</span> {series.name}: <b>{point.y}</b><br/>
*/
@property(nonatomic, readwrite) NSString *pointFormat;
/**
* description: The format for the date in the tooltip header if the X axis is a datetime axis. The default is a best guess based on the smallest distance between points in the chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/xdateformat/ : A different format
*/
@property(nonatomic, readwrite) NSString *xDateFormat;
/**
* description: How many decimals to show in each series' y value. This is overridable in each series' tooltip options object. The default is to preserve all decimals.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSNumber *valueDecimals;
/**
* description: A string to prepend to each series' y value. Overridable in each series' tooltip options object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSString *valuePrefix;
/**
* description: Whether the tooltip should follow the mouse as it moves across columns, pie slices and other point types with an extent. By default it behaves this way for scatter, bubble and pie series by override in the plotOptions for those series types. 
For touch moves to behave the same way, followTouchMove must be true also.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followPointer;
/**
* description: Split the tooltip into one label per series, with the header close to the axis. This is recommended over shared tooltips for charts with multiple line series, generally making them easier to read.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/split/ : Split tooltip
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *split;
/**
* description: The HTML of the tooltip header line. Variables are enclosed by curly brackets. Available variables			are point.key, series.name, series.color and other members from the point and series objects. The point.key variable contains the category name, x value or datetime string depending on the type of axis. For datetime axes, the point.key date format can be set using tooltip.xDateFormat.
Defaults to <span style="font-size: 10px">{point.key}</span><br/>
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/ : A HTML table in the tooltip
*/
@property(nonatomic, readwrite) NSString *headerFormat;
/**
* description: The number of milliseconds to wait until the tooltip is hidden when mouse out from a point or chart. 
* default: 500
*/
@property(nonatomic, readwrite) NSNumber *hideDelay;
/**
* description: Padding inside the tooltip, in pixels.
* default: 8
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: A string to append to the tooltip format.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/ : A table for value alignment
* default: false
*/
@property(nonatomic, readwrite) NSString *footerFormat;
/**
* description: Whether the tooltip should follow the finger as it moves on a touch device. If this is true and chart.panning is set,followTouchMove will take over one-finger touches, so the user needs to use two fingers for zooming and panning.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followTouchMove;
/**
* description: A callback function for formatting the HTML output for a single point in the tooltip. Like the pointFormat string, but with more flexibility.
*/
@property(nonatomic, readwrite) NSString /* Function */ *pointFormatter;
/**
* description: For series on a datetime axes, the date format in the tooltip's header will by default be guessed based on the closest data points. This member gives the default string representations used for each unit. For an overview of the replacement codes, see dateFormat.
Defaults to:
{
    millisecond:"%A, %b %e, %H:%M:%S.%L",
    second:"%A, %b %e, %H:%M:%S",
    minute:"%A, %b %e, %H:%M",
    hour:"%A, %b %e, %H:%M",
    day:"%A, %b %e, %Y",
    week:"Week from %A, %b %e, %Y",
    month:"%B %Y",
    year:"%Y"
}

*/
@property(nonatomic, readwrite) id dateTimeLabelFormats;
/**
* description: A string to append to each series' y value. Overridable in each series' tooltip options object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSString *valueSuffix;

-(NSDictionary *)getParams;

@end
