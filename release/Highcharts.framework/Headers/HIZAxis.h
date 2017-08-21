/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIZAxisCrosshair.h"
#import "HIZAxisEvents.h"
#import "HIZAxisPlotLines.h"
#import "HIZAxisLabels.h"
#import "HIZAxisPlotBands.h"
#import "HIZAxisTitle.h"
#import "HIColor.h"


/**
* description: The Z axis or depth axis for 3D plots.
See the Axis object for programmatic
	access to the axis.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-zaxis-categories/ : Z-Axis with Categories, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-zaxis-grid/ : Z-Axis with styling
*/
@interface HIZAxis: HIChartsJSONSerializable

/**
* description: Tick interval in scale units for the minor ticks. On a linear axis, if "auto", 
 the minor tick interval is calculated as a fifth of the tickInterval. If
 null, minor ticks are not shown.
On logarithmic axes, the unit is the power of the value. For example, setting
 	the minorTickInterval to 1 puts one tick on each of 0.1, 1, 10, 100 etc. Setting
 	the minorTickInterval to 0.1 produces 9 ticks between 1 and 10, 
 	10 and 100 etc. A minorTickInterval of "auto" on a log axis results in a best guess,
 	attempting to enter approximately 5 minor ticks between each major tick.
If user settings dictate minor ticks to become too dense, they don't make sense, and will be ignored to prevent performance problems.
On axes using categories, minor ticks are not supported.


* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-null/ : Null by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-auto/ : "auto" on linear Y axis, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-5/ : 5 units on linear Y axis, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log-auto/ : "auto" on logarithmic Y axis,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log/ : 0.1 on logarithmic Y axis.
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ minorTickInterval;
/**
* description: Color for the main tick marks.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke is given in the .highcharts-tick class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickcolor/ : Red ticks on X axis.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.
* default: #ccd6eb
*/
@property(nonatomic, readwrite) HIColor *tickColor;
/**
* description: A callback function returning array defining where the ticks are laid out on the axis. This overrides the default behaviour of tickPixelInterval and tickInterval. The automatic tick positions are accessible through this.tickPositions and can be modified by the callback.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/ : Demo of tickPositions and tickPositioner
*/
@property(nonatomic, readwrite) NSString /* Function */ *tickPositioner;
/**
* description: If categories are present for the xAxis, names are used instead of numbers for that axis. Since Highcharts 3.0, categories can also be extracted by giving each point a name and setting axis type to category. However, if you have multiple series, best practice remains defining the categories array.
Example:
categories: ['Apples', 'Bananas', 'Oranges']
		 Defaults to null

* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : With and
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/categories/ : without categories
*/
@property(nonatomic, readwrite) NSArray<NSString *> *categories;
/**
* description: Whether axis, including axis title, line, ticks and labels, should be visible.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/visible/ : Toggle axis visibility.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
* description: Color of the grid lines extending the ticks across the plot area.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke is given in the .highcharts-grid-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinecolor/ : Green lines.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.
* default: #e6e6e6
*/
@property(nonatomic, readwrite) HIColor *gridLineColor;
/**
* description: The lowest allowed value for automatically computed axis extremes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/ : Floor and ceiling
* default: null
*/
@property(nonatomic, readwrite) NSNumber *floor;
/**
* description: Whether to reverse the axis so that the highest number is closest to the origin. If the chart is inverted, the x axis is reversed by default.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/reversed/ : Reversed Y axis
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
* description: Configure a crosshair that follows either the mouse pointer or the hovered point.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the crosshairs are styled in the .highcharts-crosshair, .highcharts-crosshair-thin or .highcharts-xaxis-category classes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-both/ : Crosshair on both axes
* default: false
*/
@property(nonatomic, readwrite) HIZAxisCrosshair *crosshair;
/**
* description: Event handlers for the axis.
*/
@property(nonatomic, readwrite) HIZAxisEvents *events;
/**
* description: Whether to allow decimals in this axis' ticks. When counting integers, like persons or hits on a web page, decimals should be avoided in the labels.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/allowdecimals-true/ : True by default (unwanted for this
			type of data), 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/allowdecimals-false/ : false
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowDecimals;
/**
* description: The pixel width of the minor tick mark.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickwidth/ : 3px width
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *minorTickWidth;
/**
* description: An id for the axis. This can be used after render time to get a pointer to the axis object through chart.get().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/id/ : Get the object
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: The highest allowed value for automatically computed axis extremes.
* demo:  http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/ : Floor and ceiling
*/
@property(nonatomic, readwrite) NSNumber *ceiling;
/**
* description: An array of lines stretching across the plot area, marking a specific value on one of the axes.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the plot lines are styled by the .highcharts-plot-line class in addition to the className option.
*/
@property(nonatomic, readwrite) NSArray <HIZAxisPlotLines *> *plotLines;
/**
* description: The dash or dot style of the grid lines. For possible values, see http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/ : this demonstration.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinedashstyle/ : Long dashes
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *gridLineDashStyle;
/**
* description: Applies only when the axis type is category. When nameToX is true, points are placed on the X axis according to their names. If the same point name is repeated in the same or another series, the point is placed on the same X position as other points of the same name. When nameToX is false, the points are laid out in increasing X positions regardless of their names, and the X axis category will take the name of the last point in each position.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-true/ : True by default, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-false/ : false
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *nameToX;
/**
* description: The interval of the tick marks in axis units. When null, the tick interval
 is computed to approximately follow the tickPixelInterval on linear and datetime axes.
 On categorized axes, a null tickInterval will default to 1, one category. 
 Note that datetime axes are based on milliseconds, so for 
 example an interval of one day is expressed as 24 * 3600 * 1000.
On logarithmic axes, the tickInterval is based on powers, so a tickInterval of 1 means
 	one tick on each of 0.1, 1, 10, 100 etc. A tickInterval of 2 means a tick of 0.1, 10, 1000 etc.
 	A tickInterval of 0.2 puts a tick on 0.1, 0.2, 0.4, 0.6, 0.8, 1, 2, 4, 6, 8, 10, 20, 40 etc.
If the tickInterval is too dense for labels to be drawn, Highcharts may remove ticks.
If the chart has multiple axes, the alignTicks option may interfere with the tickInterval setting.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickinterval-5/ : Tick interval of 5 on a linear axis
*/
@property(nonatomic, readwrite) NSNumber *tickInterval;
/**
* description: Whether to show the axis line and title when the axis has no data.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/showempty/ : When clicking the legend to hide series, one axis preserves line and title, the other doesn't
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showEmpty;
/**
* description: Padding of the max value relative to the length of the axis. A padding of 0.05 will make a 100px axis 5px longer. This is useful when you don't want the highest data value to appear on the edge of the plot area. When the axis' max option is set or a max extreme is set using axis.setExtremes(), the maxPadding will be ignored.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/maxpadding/ : Max padding of 0.25 on y axis
* default: 0.01
*/
@property(nonatomic, readwrite) NSNumber *maxPadding;
/**
* description: Whether to show the first tick label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showfirstlabel-false/ : Set to false on X axis
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showFirstLabel;
/**
* description: The dash or dot style of the minor grid lines. For possible values, see http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/ : this demonstration.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinedashstyle/ : Long dashes on minor grid lines
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *minorGridLineDashStyle;
/**
* description: Datetime axis only. An array determining what time intervals the ticks are allowed to fall on. Each array item is an array where the first value is the time unit and the  second value another array of allowed multiples. Defaults to:
units: [[
	'millisecond', // unit name
	[1, 2, 5, 10, 20, 25, 50, 100, 200, 500] // allowed multiples
], [
	'second',
	[1, 2, 5, 10, 15, 30]
], [
	'minute',
	[1, 2, 5, 10, 15, 30]
], [
	'hour',
	[1, 2, 3, 4, 6, 8, 12]
], [
	'day',
	[1]
], [
	'week',
	[1]
], [
	'month',
	[1, 3, 6]
], [
	'year',
	null
]]
*/
@property(nonatomic, readwrite) NSArray *units;
/**
* description: For categorized axes only. If on the tick mark is placed in the center of  the category, if between the tick mark is placed between categories. The default is between if the tickInterval is 1, else on.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-between/ : "between" by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-on/ : "on"
* accepted values: [null, "on", "between"]
* default: null
*/
@property(nonatomic, readwrite) NSString *tickmarkPlacement;
/**
* description: The axis labels show the number or category for each tick.
*/
@property(nonatomic, readwrite) HIZAxisLabels *labels;
/**
* description: Whether to display the axis on the opposite side of the normal. The normal is on the left side for vertical axes and bottom for horizontal, so the opposite sides will be right and top respectively. This is typically used with dual or multiple axes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/opposite/ : Secondary Y axis opposite
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *opposite;
/**
* description: The amount of ticks to draw on the axis. This opens up for aligning the ticks of multiple charts or panes within a chart. This option overrides the tickPixelInterval option.
This option only has an effect on linear axes. Datetime, logarithmic or category axes are not affected.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/tickamount/ : 8 ticks on Y axis
*/
@property(nonatomic, readwrite) NSNumber *tickAmount;
/**
* description: The minimum range to display on this axis. The entire axis will not be allowed to span over a smaller interval than this. For example, for a datetime axis the main unit is milliseconds. If minRange is set to 3600000, you can't zoom in more than to one hour.
The default minRange for the x axis is five times the smallest interval between any of the data points.
On a logarithmic axis, the unit for the minimum range is the power. So a minRange of 	1 means that the axis can be zoomed to 10-100, 100-1000, 1000-10000 etc.
Note that the minPadding, maxPadding, startOnTick and endOnTick settings also affect how the extremes of the axis are computed.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/minrange/ : Minimum range of 5
*/
@property(nonatomic, readwrite) NSNumber *minRange;
/**
* description: An array of colored bands stretching across the plot area marking an interval on the axis.
In a gauge, a plot band on the Y axis (value axis) will stretch along the perimeter of the gauge.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the plot bands are styled by the .highcharts-plot-band class in addition to the className option.
*/
@property(nonatomic, readwrite) NSArray <HIZAxisPlotBands *> *plotBands;
/**
* description: The position of the major tick marks relative to the axis line. Can be one of inside and outside.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-outside/ : "outside" by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-inside/ : "inside" on X axis
* accepted values: ["inside", "outside"]
* default: outside
*/
@property(nonatomic, readwrite) NSString *tickPosition;
/**
* description: The pixel length of the main tick marks.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/ticklength/ : 20 px tick length on the X axis
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *tickLength;
/**
* description: For a datetime axis, the scale will automatically adjust to the appropriate unit.  This member gives the default string representations used for each unit. For intermediate values, different units may be used, for example the day unit can be used on midnight and hour unit be used for intermediate values on the same axis. For an overview of the replacement codes, see dateFormat.

Defaults to:
{
	millisecond: '%H:%M:%S.%L',
	second: '%H:%M:%S',
	minute: '%H:%M',
	hour: '%H:%M',
	day: '%e. %b',
	week: '%e. %b',
	month: '%b \'%y',
	year: '%Y'
}
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/datetimelabelformats/ : Different day format on X axis
*/
@property(nonatomic, readwrite) id dateTimeLabelFormats;
/**
* description: If tickInterval is null this option sets the approximate pixel interval of the tick marks. Not applicable to categorized axis.
The tick interval is also influenced by the minTickInterval option, that, by default prevents ticks from being denser than the data points.
Defaults to 72  for the Y axis and 100 for the X axis.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpixelinterval-50/ : 50 px on X axis
*/
@property(nonatomic, readwrite) NSNumber *tickPixelInterval;
/**
* description: The pixel length of the minor tick marks.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorticklength/ : 10px on Y axis
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *minorTickLength;
/**
* description: The distance in pixels from the plot area to the axis line. A positive offset moves the axis with it's line, labels and ticks away from the plot area. This is typically used when two or more axes are displayed on the same side of the plot. With multiple axes the offset is dynamically adjusted to avoid collision, this can be overridden by setting offset explicitly.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/offset/ : Y axis offset of 70,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/offset-centered/ : Axes positioned in the center of the plot
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *offset;
/**
* description: Whether to force the axis to end on a tick. Use this option with the maxPadding option to control the axis end.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : True by default and
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/endontick/ : false for Y axis
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *endOnTick;
/**
* description: A soft maximum for the axis. If the series data maximum is greater than this, the axis will stay at this maximum, but if the series data maximum is higher, the axis will flex to show all data.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/ : Soft min and max
*/
@property(nonatomic, readwrite) NSNumber *softMax;
/**
* description: The type of axis. Can be one of linear, logarithmic, datetime or category. In a datetime axis, the numbers are given in milliseconds, and tick marks are placed 		on appropriate values like full hours or days. In a category axis, the point names of the chart's series are used for categories, if not a categories array is defined.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-linear/ : "linear", 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-datetime/ : "datetime" with regular intervals,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-datetime-irregular/ : "datetime" with irregular intervals,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/type-log/ : "logarithmic",
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/type-log-minorgrid/ : "logarithmic" with minor grid lines,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-log-both/ : "logarithmic" on two axes.
* accepted values: ["linear", "logarithmic", "datetime", "category"]
* default: linear
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: Deprecated. Renamed to minRange as of Highcharts 2.2.
*/
@property(nonatomic, readwrite) NSNumber *maxZoom;
/**
* description: The color of the line marking the axis itself.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the line stroke is given in the .highcharts-axis-line or .highcharts-xaxis-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/linecolor/ : A red line on Y axis.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis/ : Axes in styled mode.
* default: #ccd6eb
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: The minimum tick interval allowed in axis values. For example on zooming in on an axis with daily data, this can be used to prevent the axis from showing hours. Defaults to the closest distance between two points on the axis.
*/
@property(nonatomic, readwrite) NSNumber *minTickInterval;
/**
* description: Whether to show the last tick label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showlastlabel-true/ : Set to true on X axis
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showLastLabel;
/**
* description: The minimum value of the axis. If null the min value is automatically calculated. If the startOnTick option is true, the min value might be rounded down.
* demo: Y axis min of http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/min-startontick-false/ : -50 with startOnTick to false,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/min-startontick-true/ : -50 with startOnTick true by default
*/
@property(nonatomic, readwrite) NSNumber *min;
/**
* description: The position of the minor tick marks relative to the axis line. Can be one of inside and outside.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-outside/ : Outside by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-inside/ : inside
* accepted values: ["inside", "outside"]
* default: outside
*/
@property(nonatomic, readwrite) NSString *minorTickPosition;
/**
* description: An array defining where the ticks are laid out on the axis. This overrides the default behaviour of tickPixelInterval and tickInterval.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/ : Demo of tickPositions and tickPositioner
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *tickPositions;
/**
* description: The width of the line marking the axis itself.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is given in the .highcharts-axis-line or .highcharts-xaxis-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/linecolor/ : A 1px line on Y axis.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis/ : Axes in styled mode.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Index of another axis that this axis is linked to. When an axis is linked to a master axis, it will take the same extremes as the master, but as assigned by min or max or by setExtremes. It can be used to show additional info, or to ease reading the chart by duplicating the scales.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/linkedto/ : Different string formats of the same date,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/linkedto/ : Y values on both sides
*/
@property(nonatomic, readwrite) NSNumber *linkedTo;
/**
* description: Requires Accessibility module
Description of the axis to screen reader users.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/accessibility/advanced-accessible/ : Accessible complex chart
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: Color for the minor tick marks.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickcolor/ : Black tick marks on Y axis
* default: #999999
*/
@property(nonatomic, readwrite) HIColor *minorTickColor;
/**
* description: A soft minimum for the axis. If the series data minimum is greater than this, the axis will stay at this minimum, but if the series data minimum is lower, the axis will flex to show all data.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/ : Soft min and max
*/
@property(nonatomic, readwrite) NSNumber *softMin;
/**
* description: Color of the minor, secondary grid lines.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is given in the .highcharts-minor-grid-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinecolor/ : Bright grey lines from Y axis.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.
* default: #f2f2f2
*/
@property(nonatomic, readwrite) HIColor *minorGridLineColor;
/**
* description: A class name that opens for styling the axis by CSS, especially in Highcharts http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode. The class name is applied to group elements for the grid, axis elements and labels.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis/ : Multiple axes with separate styling.

*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Padding of the min value relative to the length of the axis. A padding of 0.05 will make a 100px axis 5px longer. This is useful when you don't want the lowest data value to appear on the edge of the plot area. When the axis' min option is set or a min extreme is set using axis.setExtremes(), the minPadding will be ignored.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minpadding/ : Min padding of 0.2
* default: 0.01
*/
@property(nonatomic, readwrite) NSNumber *minPadding;
/**
* description: The maximum value of the axis. If null, the max value is automatically calculated. If the endOnTick option is true, the max value might be rounded up.
If a tickAmount is set, the axis may be extended beyond the set max in order to reach the given number of ticks. The same may happen in a chart with multiple axes, determined by  chart.alignTicks, where a tickAmount is applied internally.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/max-200/ : Y axis max of 200,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/max-logarithmic/ : Y axis max on logarithmic axis
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
* description: Width of the minor, secondary grid lines.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is given in the .highcharts-grid-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinewidth/ : 2px lines from Y axis .

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *minorGridLineWidth;
/**
* description: When using an alternate grid color, a band is painted across the plot area between every other grid line.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/alternategridcolor/ : Alternate grid color on the Y axis
*/
@property(nonatomic, readwrite) HIColor *alternateGridColor;
/**
* description: The axis title, showing next to the axis line.
*/
@property(nonatomic, readwrite) HIZAxisTitle *title;
/**
* description: For datetime axes, this decides where to put the tick between weeks. 0 = Sunday, 1 = Monday.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-monday/ : Monday by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-sunday/ : Sunday
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *startOfWeek;
/**
* description: Whether to force the axis to start on a tick. Use this option with the minPadding option to control the axis start.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-false/ : False by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-true/ : true on X axis
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *startOnTick;
/**
* description: The width of the grid lines extending the ticks across the plot area.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is given in the .highcharts-grid-line class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinewidth/ : 2px lines.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.

* default: 0
*/
@property(nonatomic, readwrite) NSNumber *gridLineWidth;
/**
* description: The Z index of the grid lines.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/gridzindex/ : A Z index of 4 renders the grid above the graph
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *gridZIndex;
/**
* description: The pixel width of the major tick marks.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the stroke width is given in the .highcharts-tick class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickwidth/ : 10 px width.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *tickWidth;

-(NSDictionary *)getParams;

@end
