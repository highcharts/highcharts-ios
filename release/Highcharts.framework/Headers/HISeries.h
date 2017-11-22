/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIEvents.h"
#import "HIMarker.h"
#import "HIAnimation.h"
#import "HIStates.h"
#import "HIZones.h"
#import "HIDataLabels.h"
#import "HILabel.h"
#import "HITooltip.h"
#import "HIPoint.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: General options for all series types.
*/
@interface HISeries: HIChartsJSONSerializable

/**
* description: An id for the series. This can be used after render time to get a pointer to the series object through chart.get().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-id/ : Get series by id
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: When using dual or multiple x axes, this number defines which xAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the xAxis array, with 0 being the first.
* default: 0
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ xAxis;
/**
* description: The name of the series as shown in the legend, tooltip etc.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/name/ : Series name
*/
@property(nonatomic, readwrite) NSString *name;
/**
* description: An array of data points for the series. The points can be given in three ways:
 
An array of numerical values. In this case, the numerical values will 
 	be interpreted as y values, and x values will be automatically calculated,
 	either starting at 0 and incrementing by 1, or from pointStart 
 	and pointInterval given in the plotOptions. If the axis is
 	has categories, these will be used. This option is not available for range series. Example:
data: [0, 5, 3, 5]

An array of arrays with two values. In this case, the first value is the
 	x value and the second is the y value. If the first value is a string, it is
 	applied as the name of the point, and the x value is incremented following
 	the above rules.
For range series, the arrays will be interpreted as [x, low, high]. In this cases, the X value can be skipped altogether to make use of pointStart and pointRange.

 Example:
data: [[5, 2], [6, 3], [8, 2]]
An array of objects with named values. In this case the objects are
 	point configuration objects as seen below.
Range series values are given by low and high.

Example:
data: [{
	name: 'Point 1',
	color: '#00FF00',
	y: 0
}, {
	name: 'Point 2',
	color: '#FF00FF',
	y: 5
}]

Note that line series and derived types like spline and area, require data to be sorted by X because it interpolates mouse coordinates for the tooltip. Column and scatter series, where each point has its own mouse event, does not require sorting.
* demo: 
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : 1) Numerical values
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays/ : 2a) arrays of numeric x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays-datetime/ : 2b) arrays of datetime x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-name-value/ : 2c) arrays of point.name and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/ : 3) config objects
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-column-null-values/ : 4) 3D column with null values

*/
@property(nonatomic, readwrite) NSArray /* <Data, NSNumber, NSArray> */ *data;
/**
* description: The index of the series in the chart, affecting the internal index in the chart.series array, the visible Z index as well as the order in the legend.
*/
@property(nonatomic, readwrite) NSNumber *index;
/**
* description: When using dual or multiple y axes, this number defines which yAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the yAxis array, with 0 being the first.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/yaxis/ : Apply the column series to the secondary Y axis
* default: 0
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ yAxis;
/**
* description: The sequential index of the series in the legend.  Try it:  	http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/legendindex/ : Legend in opposite order .
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
* description: Define the visual z index of the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex-default/ : With no z index, the series defined last are on top,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex/ : with a z index, the series with the highest z index is on top.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: The type of series. Can be one of area, areaspline, bar, column, line, pie, scatter or spline. From version 2.3, arearange, areasplinerange and columnrange are supported with the highcharts-more.js component.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/type/ : Line and column in the same chart
* accepted values: [null, "line", "spline", "column", "area", "areaspline", "pie", "arearange", "areasplinerange", "boxplot", "bubble", "columnrange", "errorbar", "funnel", "gauge", "scatter", "waterfall"]
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: This option allows grouping series in a stacked chart. The stack option can be a string  or a number or anything else, as long as the grouped series' stack options match each other.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/stack/ : Stacked and grouped columns
*/
@property(nonatomic, readwrite) NSString *stack;
/**
* description: Whether to display this particular series or series type in the legend.
The default value is true for standalone series, false for linked
series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showinlegend/ : One series in the legend, one hidden
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;
/**
* description: Whether to connect a graph line across null points, or render a gap
between the two points on either side of the null.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-false/ : False by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-true/ : True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectNulls;
/**
* description: General event handlers for the series items. These event hooks can also
be attached to the series at run time using the Highcharts.addEvent
function.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
* description: Pixel with of the graph line.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-general/ : On all series
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-specific/ : On one single series
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Options for the point markers of line-like series. Properties like
fillColor, lineColor and lineWidth define the visual appearance
of the markers. Other series types, like column series, don't have
markers, but have visual options on the series level instead.
In styled mode, the markers can be styled with the .highcharts-point,
.highcharts-point-hover and .highcharts-point-select
class names.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
* description: Determines whether the series should look for the nearest point
in both dimensions or just the x-dimension when hovering the series.
Defaults to 'xy' for scatter series and 'x' for most other
series. If the data has duplicate x-values, it is recommended to
set this to 'xy' to allow hovering over all points.
Applies only to series types using nearest neighbor search (not
direct hover) for tooltip.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/findnearestpointby/ : Different hover behaviors

* accepted values: ['x', 'xy']
* default: x
*/
@property(nonatomic, readwrite) NSString *findNearestPointBy;
/**
* description: Whether to use the Y extremes of the total chart width or only the
zoomed area when zooming in on parts of the X axis. By default, the
Y axis adjusts to the min and max of the visible data. Cartesian
series only.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *getExtremesFromAll;
/**
* description: By default, series are exposed to screen readers as regions. By enabling
this option, the series element itself will be exposed in the same
way as the data points. This is useful if the series is not used
as a grouping entity in the chart, but you still want to attach a
description to the series.
Requires the Accessibility module.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/art-grants/ : Accessible data visualization
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *exposeElementToA11y;
/**
* description: Same as accessibility.pointDescriptionFormatter, but for an individual series. Overrides
the chart wide configuration.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
* description: If no x values are given for the points in a series, pointInterval
defines the interval of the x values. For example, if a series contains
one value every decade starting from year 0, set pointInterval to
10. In true datetime axes, the pointInterval is set in
milliseconds.
It can be also be combined with pointIntervalUnit to draw irregular
time intervals.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/ : Datetime X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/plotoptions/pointinterval-pointstart/ : Using pointStart and pointInterval
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *pointInterval;
/**
* description: The color for the parts of the graph or points that are below the
threshold.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-negative-color/ : Spline, area and column
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-negativecolor/ : Arearange
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-negative-color/ : Styled mode


* default: null
*/
@property(nonatomic, readwrite) HIColor *negativeColor;
/**
* description: Polar charts only. Whether to connect the ends of a line series plot
across the extremes.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-connectends-false/ : Do not connect
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectEnds;
/**
* description: Defines the Axis on which the zones are applied.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-zoneaxis-x/ : Zones on the X-Axis
* default: y
*/
@property(nonatomic, readwrite) NSString *zoneAxis;
/**
* description: For some series, there is a limit that shuts down initial animation
by default when the total number of points in the chart is too high.
For example, for a column chart and its derivatives, animation doesn't
run if there is more than 250 points totally. To disable this cap, set
animationLimit to Infinity.
*/
@property(nonatomic, readwrite) NSNumber *animationLimit;
/**
* description: Whether to stack the values of each series on top of each other.
Possible values are null to disable, "normal" to stack by value or
"percent". When stacking is enabled, data must be sorted in ascending
X order. A special stacking option is with the streamgraph series type,
where the stacking option is set to "stream".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-line/ : Line
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-column/ : Column
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-bar/ : Bar
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-area/ : Area
* accepted values: [null, "normal", "percent"]
* default: null
*/
@property(nonatomic, readwrite) NSString *stacking;
/**
* description: On datetime series, this allows for setting the
pointInterval to irregular time 
units, day, month and year. A day is usually the same as 24 hours,
but pointIntervalUnit also takes the DST crossover into consideration
when dealing with local time. Combine this option with pointInterval
to draw weeks, quarters, 6 months, 10 years etc.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointintervalunit/ : One point a month
* accepted values: [null, "day", "month", "year"]
*/
@property(nonatomic, readwrite) NSString *pointIntervalUnit;
/**
* description: Enable or disable the initial animation when a series is displayed.
The animation can also be set as a configuration object. Please
note that this option only applies to the initial animation of the
series itself. For other animations, see chart.animation and the animation parameter under the API methods. The
following properties are supported:

duration
The duration of the animation in milliseconds.
easing
A string reference to an easing function set on the Math object.
See the Custom easing function demo below.

Due to poor performance, animation is disabled in old IE browsers
for several chart types.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-disabled/ : Animation disabled
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-slower/ : Slower animation
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/ : Custom easing function
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-animation-true/ : Animation enabled on map series
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/mapbubble-animation-false/ : Disabled on mapbubble series
*/
@property(nonatomic, readwrite) HIAnimation *animation;
/**
* description: Enable or disable the mouse tracking for a specific series. This
includes point tooltips and click events on graphs and points. For
large datasets it improves performance.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-enablemousetracking-false/ : No mouse tracking
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableMouseTracking;
/**
* description: The line cap used for line ends and line joins on the graph.

* accepted values: ["round", "square"]
* default: round
*/
@property(nonatomic, readwrite) NSString *linecap;
/**
* description: A wrapper object for all the series options in specific states.
*/
@property(nonatomic, readwrite) HIStates *states;
/**
* description: When a series contains a data array that is longer than this, only
one dimensional arrays of numbers, or two dimensional arrays with
x and y values are allowed. Also, only the first point is tested,
and the rest are assumed to be the same format. This saves expensive
data checking and indexing in long series. Set it to 0 disable.
* default: 1000
*/
@property(nonatomic, readwrite) NSNumber *turboThreshold;
/**
* description: Whether to select the series initially. If showCheckbox is true,
the checkbox next to the series name in the legend will be checked for a
selected series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-selected/ : One out of two series selected
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
* description: When this is true, the series will not cause the Y axis to cross
the zero plane (or threshold option)
unless the data actually crosses the plane.
For example, if softThreshold is false, a series of 0, 1, 2,
3 will make the Y axis show negative values according to the minPadding
option. If softThreshold is true, the Y axis starts at 0.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softThreshold;
/**
* description: Requires the Accessibility module.
A description of the series to add to the screen reader information
about the series.
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: Allow this series' points to be selected by clicking on the graphic 
(columns, point markers, pie slices, map areas etc).

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-line/ : Line
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-column/ : Column
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-pie/ : Pie
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-allowpointselect/ : Map area
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/mapbubble-allowpointselect/ : Map bubble
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;
/**
* description: An array defining zones within a series. Zones can be applied to
the X axis, Y axis or Z axis for bubbles, according to the zoneAxis
option.
In styled mode, the color zones are styled with the .highcharts-
zone-{n} class, or custom classed from the className option (http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/color-
zones/ : view
live demo).

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-simple/ : Color zones
*/
@property(nonatomic, readwrite) NSArray <HIZones *> *zones;
/**
* description: Options for the series data labels, appearing next to each data
point.
In styled mode, the data labels can be styled wtih the .highcharts-data-label-box and .highcharts-data-label class names (http://jsfiddle.
net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-
datalabels : see example).
*/
@property(nonatomic, readwrite) HIDataLabels *dataLabels;
/**
* description: The threshold, also called zero level or base level. For line type
series this is only used in conjunction with
negativeColor.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *threshold;
/**
* description: Series labels are placed as close to the series as possible in a
natural way, seeking to avoid other series. The goal of this
feature is to make the chart more easily readable, like if a
human designer placed the labels in the optimal position.
The series labels currently work with series types having a
graph or an area.
Requires the series-label.js module.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/line-chart : Line chart
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph : Stream graph
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/stock-chart : Stock chart
*/
@property(nonatomic, readwrite) HILabel *label;
/**
* description: Set the point threshold for when a series should enter boost mode.
Setting it to e.g. 2000 will cause the series to enter boost mode when there
are 2000 or more points in the series.
To disable boosting on the series, set the boostThreshold to 0. Setting it
to 1 will force boosting.
Requires modules/boost.js.
* default: 5000
*/
@property(nonatomic, readwrite) NSNumber *boostThreshold;
/**
* description: You can set the cursor to "pointer" if you have click events attached
to the series, to signal to the user that the points and lines can
be clicked.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-line/ : On line graph
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-column/ : On columns
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-scatter/ : On scatter markers
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/plotoptions/cursor/ : Pointer on a line graph
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-allowpointselect/ : Map area
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/mapbubble-allowpointselect/ : Map bubble
* accepted values: [null, "default", "none", "help", "pointer", "crosshair"]
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
* description: Possible values: null, "on", "between".
In a column chart, when pointPlacement is "on", the point will
not create any padding of the X axis. In a polar column chart this
means that the first column points directly north. If the pointPlacement
is "between", the columns will be laid out between ticks. This
is useful for example for visualising an amount between two points
in time or in a certain sector of a polar chart.
Since Highcharts 3.0.2, the point placement can also be numeric,
where 0 is on the axis value, -0.5 is between this value and the
previous, and 0.5 is between this value and the next. Unlike the
textual options, numeric point placement options won't affect axis
padding.
Note that pointPlacement needs a pointRange to work. For column series this is computed, but for
line-type series it needs to be set.
Defaults to null in cartesian charts, "between" in polar charts.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-between/ : Between in a column chart
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-numeric/ : Numeric placement for custom layout
* accepted values: [null, "on", "between"]
* default: null
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ pointPlacement;
/**
* description: The border width of each map area.
In styled mode, the border stroke width is given in the .highcharts-point class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-border/ : Borders demo
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The main color of the series. In line type series it applies to the
line and the point markers unless otherwise specified. In bar type
series it applies to the bars unless a color is specified per point.
The default value is pulled from the options.colors array.
In styled mode, the color can be defined by the
colorIndex option. Also, the series
color can be set with the .highcharts-series, .highcharts-color-{n},
.highcharts-{type}-series or .highcharts-series-{n} class, or
individual classes given by the className option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-general/ : General plot option
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-specific/ : One specific series
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-area/ : Area color
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/category-map/ : Category map by multiple series
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: When the series contains less points than the crop threshold, all
points are drawn, even if the points fall outside the visible plot
area at the current zoom. The advantage of drawing all points (including
markers and columns), is that animation is performed on updates.
On the other hand, when the series contains more points than the
crop threshold, the series data is cropped to only contain points
that fall within the plot area. The advantage of cropping away invisible
points is to increase performance on large series.
* default: 300
*/
@property(nonatomic, readwrite) NSNumber *cropThreshold;
/**
* description: A configuration object for the tooltip rendering of each single series.
Properties are inherited from tooltip, but only the
following properties can be defined on a series level.
*/
@property(nonatomic, readwrite) HITooltip *tooltip;
/**
* description: An array specifying which option maps to which key in the data point
array. This makes it convenient to work with unstructured data arrays
from different sources.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-keys/ : An extended data array with keys
*/
@property(nonatomic, readwrite) NSArray<NSString *> *keys;
/**
* description: Styled mode only. A specific color index to use for the series, so its
graphic representations are given the class name highcharts-color-
{n}.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
* description: Sticky tracking of mouse events. When true, the mouseOut event
on a series isn't triggered until the mouse moves over another series,
or out of the plot area. When false, the mouseOut event on a
series is triggered when the mouse leaves the area around the series'
graph or markers. This also implies the tooltip when not shared. When
stickyTracking is false and tooltip.shared is false, the tooltip will
be hidden when moving the mouse between series. Defaults to true for line
and area type series, but to false for columns, pies etc.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-true/ : True by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-false/ : False
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *stickyTracking;
/**
* description: If no x values are given for the points in a series, pointStart defines
on what value to start. For example, if a series contains one yearly
value starting from 1945, set pointStart to 1945.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-linear/ : Linear
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/ : Datetime
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/plotoptions/pointinterval-pointstart/ : Using pointStart and pointInterval
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *pointStart;
/**
* description: Whether to apply a drop shadow to the graph line. Since 2.3 the shadow
can be an object configuration containing color, offsetX, offsetY,
 opacity and width.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-shadow/ : Shadow enabled
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, id */ shadow;
/**
* description: Set the initial visibility of the series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-visible/ : Two series, one hidden and one visible
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/plotoptions/series-visibility/ : Hidden series
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
* description: The id of another series to link to. Additionally,
the value can be ":previous" to link to the previous series. When
two series are linked, only the first one appears in the legend.
Toggling the visibility of this also toggles the linked series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange-line/ : Linked series
*/
@property(nonatomic, readwrite) NSString *linkedTo;
/**
* description: If set to True, the accessibility module will skip past the points
in this series for keyboard navigation.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipKeyboardNavigation;
/**
* description: A name for the dash style to use for the graph, or for some series types
the outline of each shape. The value for the dashStyle include:

Solid
ShortDash
ShortDot
ShortDashDot
ShortDashDotDot
Dot
Dash
LongDash
DashDot
LongDashDot
LongDashDotDot


* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/ : Possible values demonstrated
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle/ : Chart suitable for printing in black and white

https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-dashstyle/ : Dotted borders on a map
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot",
            "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot",
            "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
* description: Whether to apply steps to the line. Possible values are left, center
and right.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-step/ : Different step line options
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-step/ : Stepped, stacked area
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/plotoptions/line-step/ : Step line
* accepted values: [null, "left", "center", "right"]
*/
@property(nonatomic, readwrite) NSString *step;
/**
* description: If true, a checkbox is displayed next to the legend item to allow
selecting the series. The state of the checkbox is determined by
the selected option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showcheckbox-true/ : Show select box
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showCheckbox;
/**
* description: A class name to apply to the series' graphical elements.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Properties for each single point.
*/
@property(nonatomic, readwrite) HIPoint *point;

-(NSDictionary *)getParams;

@end
