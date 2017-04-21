/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Options for the tooltip that appears when the user hovers over a series or point.
*/
@interface HITooltip: HIChartsJSONSerializable

/**
* description: The HTML of the tooltip header line. Variables are enclosed by curly brackets. Available variables			are point.key, series.name, series.color and other members from the point and series objects. The point.key variable contains the category name, x value or datetime string depending on the type of axis. For datetime axes, the point.key date format can be set using tooltip.xDateFormat.
Defaults to <span style="font-size: 10px">{point.key}</span><br/>
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/ : A HTML table in the tooltip
*/
@property(nonatomic, readwrite) NSString *headerFormat;
/**
* description: Enable or disable animation of the tooltip. In slow legacy IE browsers the animation is disabled by default.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *animation;
/**
* description: Whether the tooltip should follow the finger as it moves on a touch device. If this is true and chart.panning is set,followTouchMove will take over one-finger touches, so the user needs to use two fingers for zooming and panning.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followTouchMove;
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
* description: A string to append to the tooltip format.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/ : A table for value alignment
* default: false
*/
@property(nonatomic, readwrite) NSString *footerFormat;
/**
* description: The pixel width of the tooltip border.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is set in the .highcharts-tooltip-box class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/ : 2px by default.
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/borderwidth/ : No border (shadow only).		

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/tooltip-border-background/ : Tooltip in styled mode.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: How many decimals to show in each series' y value. This is overridable in each series' tooltip options object. The default is to preserve all decimals.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSNumber *valueDecimals;
/**
* description: Whether the tooltip should follow the mouse as it moves across columns, pie slices and other point types with an extent. By default it behaves this way for scatter, bubble and pie series by override in the plotOptions for those series types. 
For touch moves to behave the same way, followTouchMove must be true also.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followPointer;
/**
* description: When the tooltip is shared, the entire plot area will capture mouse movement or touch events. Tooltip texts for series types with ordered data (not pie, scatter, flags etc) will be shown in a single bubble. This is recommended for single series charts and for tablet/mobile optimized charts.
See also tooltip.split, that is better suited for charts with many series, especially line-type series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-false/ : False by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-true/ : true, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-x-crosshair/ : true with x axis crosshair, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-true-mixed-types/ : true with mixed series types.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shared;
/**
* description: The format for the date in the tooltip header if the X axis is a datetime axis. The default is a best guess based on the smallest distance between points in the chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/xdateformat/ : A different format
*/
@property(nonatomic, readwrite) NSString *xDateFormat;
/**
* description: The radius of the rounded border corners.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/ : 5px by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/borderradius-0/ : square borders
* default: 3
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: The number of milliseconds to wait until the tooltip is hidden when mouse out from a point or chart. 
* default: 500
*/
@property(nonatomic, readwrite) NSNumber *hideDelay;
/**
* description: A callback function for formatting the HTML output for a single point in the tooltip. Like the pointFormat string, but with more flexibility.
*/
@property(nonatomic, readwrite) NSString /* Function */ *pointFormatter;
/**
* description: Whether to apply a drop shadow to the tooltip.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/ : True by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shadow/ : false
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
* description: The background color or gradient for the tooltip.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is set in the .highcharts-tooltip-box class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/backgroundcolor-solid/ : Yellowish background.
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/backgroundcolor-gradient/ : Gradient.


http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/tooltip-border-background/ : Tooltip in styled mode.
* default: rgba(247,247,247,0.85)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: The name of a symbol to use for the border around the tooltip. In Highcharts 3.x and less, the shape was square. 
* default: callout
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: A string to prepend to each series' y value. Overridable in each series' tooltip options object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSString *valuePrefix;
/**
* description: Padding inside the tooltip, in pixels.
* default: 8
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: Enable or disable the tooltip.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/enabled/ : Disabled,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/ : disable tooltip and show values on chart instead.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Since 4.1, the crosshair definitions are moved to the Axis object in order for a better separation from the tooltip. See xAxis.crosshair.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/crosshairs-x/ : Enable a crosshair for the x value.
*/
@property(nonatomic, readwrite) id crosshairs;
/**
* description: A string to append to each series' y value. Overridable in each series' tooltip options object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/ : Set decimals, prefix and suffix for the value
*/
@property(nonatomic, readwrite) NSString *valueSuffix;
/**
* description: Proximity snap for graphs or single points. It defaults to 10 for mouse-powered devices and 25 for touch devices.
Note that in most cases the whole plot area captures the mouse movement, and in these cases tooltip.snap doesn't make sense. This applies when stickyTracking is true (default) and when the tooltip is shared or split.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/ : 10 px by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/snap-50/ : 50 px on graph
*/
@property(nonatomic, readwrite) NSNumber *snap;
/**
* description: Use HTML to render the contents of the tooltip instead of SVG. Using HTML allows advanced formatting like tables and images in the tooltip. It is also recommended for rtl languages as it works around rtl bugs in early Firefox.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/ : A table for value alignment. http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/fullhtml/ : Full HTML tooltip.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: A callback function to place the tooltip in a default position. The callback receives three parameters: labelWidth, labelHeight and point, where point contains values for plotX and plotY telling where the reference point is in the plot area. Add chart.plotLeft and chart.plotTop to get the full coordinates.
The return should be an object containing x and y values, for example { x: 100, y: 100 }.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/positioner/ : 
				A fixed tooltip position
*/
@property(nonatomic, readwrite) NSString /* Function */ *positioner;
/**
* description: The color of the tooltip border. When null, the border takes the color of the corresponding series or point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/ : Follow series by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-black/ : black border
* default: null
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: CSS styles for the tooltip. The tooltip can also be styled through the CSS
 class .highcharts-tooltip.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/style/ : Greater padding, bold text
* default: { "color": "#333333", "cursor": "default", "fontSize": "12px", "pointerEvents": "none", "whiteSpace": "nowrap" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: Callback function to format the text of the tooltip. Return false to disable tooltip for a specific point on series. A subset of HTML is supported. The HTML of the tooltip is parsed and converted to SVG,  therefore this isn't a complete HTML renderer. The following tags are supported:  <b>, <strong>, <i>, <em>, <br/>, <span>. Spans can be styled with a style attribute, but only text-related CSS that is  shared with SVG is handled.  Since version 2.1 the tooltip can be shared between multiple series through  the shared option. The available data in the formatter differ a bit depending on whether the tooltip is shared or not. In a shared tooltip, all  properties except x, which is common for all points, are kept in  an array, this.points. Available data are:  this.percentage (not shared) / this.points[i].percentage (shared) Stacked series and pies only. The point's percentage of the total. this.point (not shared) / this.points[i].point (shared) The point object. The point name, if defined, is available  through this.point.name. this.points In a shared tooltip, this is an array containing all other properties for each point. this.series (not shared) / this.points[i].series (shared) The series object. The series name is available  through this.series.name. this.total (not shared) / this.points[i].total (shared) Stacked series only. The total value at this point's x value. this.x The x value. This property is the same regardless of the tooltip being shared or not. this.y (not shared) / this.points[i].y (shared) The y value. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-simple/ : Simple string formatting,			
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-shared/ : formatting with shared tooltip
*/
@property(nonatomic, readwrite) NSString /* Function */ *formatter;
/**
* description: The HTML of the point's line in the tooltip. Variables are enclosed by curly brackets. Available variables are point.x, point.y, series.name and series.color and other properties on the same form. Furthermore,  point.y can be extended by the tooltip.valuePrefix and tooltip.valueSuffix variables. This can also be overridden for each series, which makes it a good hook for displaying units.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the dot is colored by a class name rather than the point color.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/pointformat/ : A different point format with value suffix
* default: <span style="color:{point.color}">\u25CF</span> {series.name}: <b>{point.y}</b><br/>
*/
@property(nonatomic, readwrite) NSString *pointFormat;
/**
* description: Split the tooltip into one label per series, with the header close to the axis. This is recommended over shared tooltips for charts with multiple line series, generally making them easier to read.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/tooltip/split/ : Split tooltip
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *split;

-(NSDictionary *)getParams;

@end
