/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMarker.h"
#import "HILabels.h"
#import "HIEvents.h"
#import "HIDataClasses.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: A color axis for choropleth maps and heat maps. Visually, the color axis
will appear as a gradient or as separate items inside the legend,
depending on whether the axis is scalar or based on data classes.
For supported color formats, see the 
http://www.highcharts.com/docs/chart-design-and-style/colors : docs article about colors.
A scalar color axis is represented by a gradient. The colors either range
between the minColor and the maxColor,
or for more fine grained control the colors can be
defined in stops. Often times, the color axis needs
to be adjusted to get the right color spread for the data. In addition to
stops, consider using a logarithmic axis type, or
setting min and max to avoid the
colors being determined by outliers.
When dataClasses are used, the ranges are
subdivided into separate classes like categories based on their values.
This can be used for ranges between two values, but also for a true
category. However, when your data is categorized, it may be as convenient
to add each category to a separate series.
See the Axis object for programmatic access to the axis.
*/
@interface HIColorAxis: HIChartsJSONSerializable

/**
* description: The triangular marker on a scalar color axis that points to the
value of the hovered area. To disable the marker, set marker:
null.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/marker/ : Black marker
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
* description: Color for the minor tick marks.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickcolor/ : Black tick marks on Y axis
* default: #999999
*/
@property(nonatomic, readwrite) HIColor *minorTickColor;
/**
* description: Determines how to set each data class' color if no individual color
is set. The default value, tween, computes intermediate colors
between minColor and maxColor. The other possible value, category,
pulls colors from the global or chart specific colors
array.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/dataclasscolor/ : Category colors
* accepted values: ["tween", "category"]
* default: tween
*/
@property(nonatomic, readwrite) NSString *dataClassColor;
/**
* description: Whether to force the axis to start on a tick. Use this option with
the maxPadding option to control the axis start.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-false/ : False by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-true/ : True
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/endontick/ : False for Y axis
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *startOnTick;
/**
* description: The color to represent the minimum of the color axis. Unless dataClasses or stops are set, the gradient
starts at this value.
If dataClasses are set, the color is based on minColor and maxColor
unless a color is set for each data class, or the dataClassColor is set.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/mincolor-maxcolor/ : Min and max colors on scalar (gradient) axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/mincolor-maxcolor-dataclasses/ : On data classes
* default: #e6ebf5
*/
@property(nonatomic, readwrite) HIColor *minColor;
/**
* description: The color of the line marking the axis itself.
In styled mode, the line stroke is given in the
.highcharts-axis-line or .highcharts-xaxis-line class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/linecolor/ : A red line on Y axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis/ : Axes in styled mode
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/linecolor/ : A red line on X axis
* default: #ccd6eb
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: Enable or disable minor ticks. Unless
minorTickInterval is set, the tick interval is
calculated as a fifth of the tickInterval.
On a logarithmic axis, minor ticks are laid out based on a best guess,
attempting to enter approximately 5 minor ticks between each major tick.
Prior to v6.0.0, ticks were unabled in auto layout by setting
minorTickInterval to "auto".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorticks-true/ : Enabled on linear Y axis
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *minorTicks;
/**
* description: If tickInterval is null this option
sets the approximate pixel interval of the tick marks.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpixelinterval-50/ : 50 px on X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/tickpixelinterval/ : 200 px on X axis
* default: 72
*/
@property(nonatomic, readwrite) NSNumber *tickPixelInterval;
/**
* description: The axis labels show the number for each tick.
For more live examples on label options, see /highcharts#xAxis.labels : xAxis.labels in the
Highcharts API.
*/
@property(nonatomic, readwrite) HILabels *labels;
/**
* description: Color of the minor, secondary grid lines.
In styled mode, the stroke width is given in the
.highcharts-minor-grid-line class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinecolor/ : Bright grey lines from Y axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode
* default: #f2f2f2
*/
@property(nonatomic, readwrite) HIColor *minorGridLineColor;
/**
* description: Specific tick interval in axis units for the minor ticks. On a linear axis,
if "auto", the minor tick interval is calculated as a fifth of
the tickInterval. If null, minor ticks are not shown.
On logarithmic axes, the unit is the power of the value. For example,
setting the minorTickInterval to 1 puts one tick on each of 0.1,
1, 10, 100 etc. Setting the minorTickInterval to 0.1 produces 9
ticks between 1 and 10, 10 and 100 etc.
If user settings dictate minor ticks to become too dense, they don't
make sense, and will be ignored to prevent performance problems.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-null/ : Null by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-5/ : 5 units
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log-auto/ : "auto"
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log/ : 0.1
*/
@property(nonatomic, readwrite) NSNumber *minorTickInterval;
/**
* description: The pixel width of the major tick marks.
In styled mode, the stroke width is given in the .highcharts-tick class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickwidth/ : 10 px width
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/ticks/ : Formatted ticks on X axis
*/
@property(nonatomic, readwrite) NSNumber *tickWidth;
/**
* description: Whether to force the axis to end on a tick. Use this option with
the maxPadding option to control the axis
end.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : True by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/endontick/ : False
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *endOnTick;
/**
* description: Whether to show the last tick label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showlastlabel-true/ : Set to true on X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/showfirstlabel/ : Labels below plot lines on Y axis
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showLastLabel;
/**
* description: Whether to show the first tick label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showfirstlabel-false/ : Set to false on X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/showfirstlabel/ : Labels below plot lines on Y axis
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showFirstLabel;
/**
* description: An array defining where the ticks are laid out on the axis. This
overrides the default behaviour of tickPixelInterval
and tickInterval.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/ : Demo of tickPositions and tickPositioner
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *tickPositions;
/**
* description: A class name that opens for styling the axis by CSS, especially in
Highcharts styled mode. The class name is applied to group elements
for the grid, axis elements and labels.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis/ : Multiple axes with separate styling

*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Color for the main tick marks.
In styled mode, the stroke is given in the .highcharts-tick
class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickcolor/ : Red ticks on X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/ticks/ : Formatted ticks on X axis
* default: #ccd6eb
*/
@property(nonatomic, readwrite) HIColor *tickColor;
/**
* description: The amount of ticks to draw on the axis. This opens up for aligning
the ticks of multiple charts or panes within a chart. This option
overrides the tickPixelInterval option.
This option only has an effect on linear axes. Datetime, logarithmic
or category axes are not affected.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/tickamount/ : 8 ticks on Y axis
*/
@property(nonatomic, readwrite) NSNumber *tickAmount;
/**
* description: Padding of the min value relative to the length of the axis. A
padding of 0.05 will make a 100px axis 5px longer.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minpadding/ : Min padding of 0.2
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/minpadding-maxpadding/ : Greater min- and maxPadding
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/chart/plotbackgroundcolor-gradient/ : Add some padding
*/
@property(nonatomic, readwrite) NSNumber *minPadding;
/**
* description: Requires Accessibility module
Description of the axis to screen reader users.
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: The maximum value of the axis in terms of map point values. If null,
the max value is automatically calculated. If the endOnTick option
is true, the max value might be rounded up.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/gridlines/ : Explicit min and max to reduce the effect of outliers
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
* description: The dash or dot style of the grid lines. For possible values, see
http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-
dashstyle-all/ : this demonstration.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinedashstyle/ : Long dashes
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *gridLineDashStyle;
/**
* description: An id for the axis. This can be used after render time to get a pointer
to the axis object through chart.get().

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/id/ : Get the object
* default: null
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: Whether to display the colorAxis in the legend.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;
/**
* description: The minimum value of the axis in terms of map point values. If null,
the min value is automatically calculated. If the startOnTick
option is true, the min value might be rounded down.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/gridlines/ : Explicit min and max to reduce the effect of outliers
*/
@property(nonatomic, readwrite) NSNumber *min;
/**
* description: The color to represent the maximum of the color axis. Unless dataClasses or stops are set, the gradient
ends at this value.
If dataClasses are set, the color is based on minColor and maxColor
unless a color is set for each data class, or the dataClassColor is set.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/mincolor-maxcolor/ : Min and max colors on scalar (gradient) axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/mincolor-maxcolor-dataclasses/ : On data classes
* default: #003399
*/
@property(nonatomic, readwrite) HIColor *maxColor;
/**
* description: The highest allowed value for automatically computed axis extremes.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/ : Floor and ceiling
*/
@property(nonatomic, readwrite) NSNumber *ceiling;
/**
* description: The lowest allowed value for automatically computed axis extremes.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/ : Floor and ceiling
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/demo/lazy-loading/ : Prevent negative stock price on Y axis
* default: null
*/
@property(nonatomic, readwrite) NSNumber *floor;
/**
* description: Color of the grid lines extending from the axis across the gradient.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/gridlines/ : Grid lines demonstrated
* default: #e6e6e6
*/
@property(nonatomic, readwrite) HIColor *gridLineColor;
/**
* description: The position of the minor tick marks relative to the axis line.
 Can be one of inside and outside.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-outside/ : Outside by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-inside/ : Inside
* accepted values: ["inside", "outside"]
* default: outside
*/
@property(nonatomic, readwrite) NSString *minorTickPosition;
/**
* description: The Z index of the grid lines.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/gridzindex/ : A Z index of 4 renders the grid above the graph
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *gridZIndex;
/**
* description: Event handlers for the axis.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
* description: Whether to reverse the axis so that the highest number is closest
to the origin. Defaults to false in a horizontal legend and true
in a vertical legend, where the smallest value starts on top.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/reversed/ : Reversed Y axis
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
* description: A callback function returning array defining where the ticks are
laid out on the axis. This overrides the default behaviour of tickPixelInterval and tickInterval. The automatic
tick positions are accessible through this.tickPositions and can
be modified by the callback.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/ : Demo of tickPositions and tickPositioner
*/
@property(nonatomic, readwrite) HIFunction *tickPositioner;
/**
* description: For datetime axes, this decides where to put the tick between weeks.
 0 = Sunday, 1 = Monday.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-monday/ : Monday by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-sunday/ : Sunday
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *startOfWeek;
/**
* description: An array of data classes or ranges for the choropleth map. If none
given, the color axis is scalar and values are distributed as a gradient
between the minimum and maximum colors.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/data-class-ranges/ : Multiple ranges
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/data-class-two-ranges/ : Two ranges
*/
@property(nonatomic, readwrite) NSArray <HIDataClasses *> *dataClasses;
/**
* description: For categorized axes only. If on the tick mark is placed in the
center of the category, if between the tick mark is placed between
categories. The default is between if the tickInterval is 1,
 else on.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-between/ : "between" by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-on/ : "on"
* accepted values: [null, "on", "between"]
* default: null
*/
@property(nonatomic, readwrite) NSString *tickmarkPlacement;
/**
* description: A soft maximum for the axis. If the series data maximum is less than
this, the axis will stay at this maximum, but if the series data
maximum is higher, the axis will flex to show all data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/ : Soft min and max
*/
@property(nonatomic, readwrite) NSNumber *softMax;
/**
* description: Applies only when the axis type is category. When uniqueNames
is true, points are placed on the X axis according to their names.
If the same point name is repeated in the same or another series,
the point is placed on the same X position as other points of the
same name. When uniqueNames is false, the points are laid out in
increasing X positions regardless of their names, and the X axis
category will take the name of the last point in each position.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-true/ : True by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-false/ : False
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *uniqueNames;
/**
* description: The pixel length of the minor tick marks.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorticklength/ : 10px on Y axis
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *minorTickLength;
/**
* description: The type of interpolation to use for the color axis. Can be linear
or logarithmic.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-linear/ : Linear
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/type-log/ : Logarithmic
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/type-log-minorgrid/ : Logarithmic with minor grid lines
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/type-log-both/ : Logarithmic on two axes
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/type-log-negative/ : Logarithmic with extension to emulate negative values
* accepted values: ["linear", "logarithmic"]
* default: linear
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: The pixel length of the main tick marks on the color axis.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/ticklength/ : 20 px tick length on the X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/ticks/ : Formatted ticks on X axis
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *tickLength;
/**
* description: A soft minimum for the axis. If the series data minimum is greater
than this, the axis will stay at this minimum, but if the series
data minimum is lower, the axis will flex to show all data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/ : Soft min and max

*/
@property(nonatomic, readwrite) NSNumber *softMin;
/**
* description: Width of the minor, secondary grid lines.
In styled mode, the stroke width is given in the
.highcharts-grid-line class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinewidth/ : 2px lines from Y axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/ : Styled mode
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *minorGridLineWidth;
/**
* description: The width of the grid lines extending from the axis across the
gradient of a scalar color axis.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/gridlines/ : Grid lines demonstrated
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *gridLineWidth;
/**
* description: Padding of the max value relative to the length of the axis. A
padding of 0.05 will make a 100px axis 5px longer.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/maxpadding/ : Max padding of 0.25 on y axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/minpadding-maxpadding/ : Greater min- and maxPadding
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/chart/plotbackgroundcolor-gradient/ : Add some padding
*/
@property(nonatomic, readwrite) NSNumber *maxPadding;
/**
* description: The interval of the tick marks in axis units. When null, the tick
interval is computed to approximately follow the tickPixelInterval.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickinterval-5/ : Tick interval of 5 on a linear axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/tickinterval/ : Tick interval of 0.01 on Y axis
* default: null
*/
@property(nonatomic, readwrite) NSNumber *tickInterval;
/**
* description: Whether axis, including axis title, line, ticks and labels, should
be visible.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
* description: Datetime axis only. An array determining what time intervals the
ticks are allowed to fall on. Each array item is an array where the
first value is the time unit and the second value another array of
allowed multiples. Defaults to:
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
* description: Color stops for the gradient of a scalar color axis. Use this in
cases where a linear gradient between a minColor and maxColor
is not sufficient. The stops is an array of tuples, where the first
item is a float between 0 and 1 assigning the relative position in
the gradient, and the second item is the color.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/ : Heatmap with three color stops
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *stops;
/**
* description: The position of the major tick marks relative to the axis line.
 Can be one of inside and outside.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-outside/ : "outside" by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-inside/ : "inside"
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/ticks/ : Formatted ticks on X axis
* accepted values: ["inside", "outside"]
* default: outside
*/
@property(nonatomic, readwrite) NSString *tickPosition;
/**
* description: The dash or dot style of the minor grid lines. For possible values,
see http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-
dashstyle-all/ : this demonstration.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinedashstyle/ : Long dashes on minor grid lines
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *minorGridLineDashStyle;
/**
* description: The pixel width of the minor tick mark.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickwidth/ : 3px width
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/minorticks/ : 1px width
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *minorTickWidth;

-(NSDictionary *)getParams;

@end
