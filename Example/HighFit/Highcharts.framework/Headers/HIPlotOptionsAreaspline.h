/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPlotOptionsAreasplineMarker.h"
#import "HIPlotOptionsAreasplinePoint.h"
#import "HIPlotOptionsAreasplineEvents.h"
#import "HIPlotOptionsAreasplineTooltip.h"
#import "HIPlotOptionsAreasplineStates.h"
#import "HIPlotOptionsAreasplineZones.h"
#import "HIPlotOptionsAreasplineDataLabels.h"
#import "HIColor.h"


@interface HIPlotOptionsAreaspline: HIChartsJSONSerializable

/**
* description: Fill opacity for the area. Note that when you set an explicit fillColor, the fillOpacity is not applied. Instead, you should define the opacity in the fillColor with an rgba color definition.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillopacity/ : Automatic fill color and fill opacity of 0.1
* default: 0.75
*/
@property(nonatomic, readwrite) NSNumber *fillOpacity;
/**
* description: Whether to connect a graph line across null points.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-false/ : False by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-true/ : true
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectNulls;
/**
* description: Sticky tracking of mouse events. When true, the mouseOut event
 on a series isn't triggered until the mouse moves over another series, or out
 of the plot area. When false, the mouseOut event on a series is
 triggered when the mouse leaves the area around the series' graph or markers.
 This also implies the tooltip. When stickyTracking is false and tooltip.shared is false, the 
 tooltip will be hidden when moving the mouse between series. Defaults to true for line and area type series, but to false for columns, pies etc.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-true/ : True by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-false/ : false
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *stickyTracking;
/**
* description: Whether to display this particular series or series type in the legend. The default value is true for standalone series, false for linked series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showinlegend/ : One series in the legend, one hidden
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;
/**
* description: The color for the parts of the graph or points that are below the threshold.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-negative-color/ : Spline, area and column - http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-negativecolor/ : arearange.
* default: null
*/
@property(nonatomic, readwrite) HIColor *negativeColor;
/**
* description: Fill color or gradient for the area. When null, the series' color  is  used with the series' fillOpacity.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-default/ : Null by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-gradient/ : gradient
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
* description: An array specifying which option maps to which key in the data point array. This makes it convenient to work with unstructured data arrays from different sources.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-keys/ : An extended data array with keys
*/
@property(nonatomic, readwrite) NSArray<NSString *> *keys;
/**
* description: Defines the Axis on which the zones are applied.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-zoneaxis-x/ : Zones on the X-Axis
* default: y
*/
@property(nonatomic, readwrite) NSString *zoneAxis;
/**
* description: Set the initial visibility of the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-visible/ : Two series, one hidden and one visible
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
* description: Polar charts only. Whether to connect the ends of a line series plot across the extremes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-connectends-false/ : Do not connect
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectEnds;
/**
* description: On datetime series, this allows for setting the pointInterval to irregular time units, day, month and year. A day is usually the same as 24 hours, but pointIntervalUnit also takes the DST crossover into consideration when dealing with local time. Combine this option with pointInterval to draw weeks, quarters, 6 months, 10 years etc.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointintervalunit/ : One point a month
* accepted values: [null, "day", "month", "year"]
*/
@property(nonatomic, readwrite) NSString *pointIntervalUnit;
/**
* description: Options for the point markers of line-like series. Properties like fillColor, lineColor and lineWidth define the visual appearance of the markers. Other series types, like column series, don't have markers, but have visual options on the series level instead.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the markers can be styled with the .highcharts-point, .highcharts-point-hover and .highcharts-point-select class names.
*/
@property(nonatomic, readwrite) HIPlotOptionsAreasplineMarker *marker;
/**
* description: If true, a checkbox is displayed next to the legend item to allow selecting the series. The state of the checkbox is determined by the selected option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showcheckbox-true/ : Show select box
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showCheckbox;
/**
* description: Properties for each single point
*/
@property(nonatomic, readwrite) HIPlotOptionsAreasplinePoint *point;
/**
* description: If no x values are given for the points in a series, pointInterval defines
 the interval of the x values. For example, if a series contains one value
 every decade starting from year 0, set pointInterval to 10.
Since Highcharts 4.1, it can be combined with pointIntervalUnit to draw irregular intervals.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/ : Datetime X axis
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *pointInterval;
/**
* description: A name for the dash style to use for the graph. Applies only to series type having a graph, like line, spline, area and scatter in  case it has a lineWidth. The value for the dashStyle include:
		    
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

* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/ : Possible values demonstrated,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle/ : chart suitable for printing in black and white
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
* description: Enable or disable the mouse tracking for a specific series. This includes point tooltips and click events on graphs and points. For large datasets it improves performance.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-enablemousetracking-false/ : No mouse tracking
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableMouseTracking;
/**
* description: The id of another series to link to. Additionally, the value can be ":previous" to link to the previous series. When two series are linked, only the first one appears in the legend. Toggling the visibility of this also toggles the linked series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange-line/ : Linked series
*/
@property(nonatomic, readwrite) NSString *linkedTo;
@property(nonatomic, readwrite) HIPlotOptionsAreasplineEvents *events;
/**
* description: For some series, there is a limit that shuts down initial animation by default when the total number of points in the chart is too high. For example, for a column chart and its derivatives, animation doesn't run if there is more than 250 points totally. To disable this cap, set animationLimit to Infinity.
*/
@property(nonatomic, readwrite) NSNumber *animationLimit;
/**
* description: A separate color for the graph line. By default the line takes the color of the series, but the lineColor setting allows setting a separate color for the line without altering the fillColor.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-linecolor/ : Dark gray line
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: Possible values: null, "on", "between".
In a column chart, when pointPlacement is "on", the point will not create any padding of the X axis. In a polar column chart this means that the first column points directly north. If the pointPlacement is "between", the columns will be laid out between ticks. This is useful for example for visualising an amount between two points in time or in a certain sector of a polar chart.
Since Highcharts 3.0.2, the point placement can also be numeric, where 0 is on the axis value, -0.5 is between this value and the previous, and 0.5 is between this value and the next. Unlike the textual options, numeric point placement options won't affect axis padding.
Note that pointPlacement needs a pointRange to work. For column series this is computed, but for line-type series it needs to be set.
Defaults to null in cartesian charts, "between" in polar charts.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-between/ : Between in a column chart, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-numeric/ : numeric placement for custom layout.
* accepted values: [null, "on", "between"]
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ pointPlacement;
/**
* description: Whether to select the series initially. If showCheckbox is true, the checkbox next to the series name will be checked for a selected series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-selected/ : One out of two series selected
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
* description: A class name to apply to the series' graphical elements.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: You can set the cursor to "pointer" if you have click events attached to  the series, to signal to the user that the points and lines can be clicked.
* demo: Pointer cursor http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-line/ : on line graph,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-column/ : on columns,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-scatter/ : on scatter markers
* accepted values: [null, "default", "none", "help", "pointer", "crosshair"]
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
* description: A configuration object for the tooltip rendering of each single series. Properties are inherited from tooltip, but only the following properties can be defined on a series level.
*/
@property(nonatomic, readwrite) HIPlotOptionsAreasplineTooltip *tooltip;
/**
* description: The line cap used for line ends and line joins on the graph.
* accepted values: ["round", "square"]
* default: round
*/
@property(nonatomic, readwrite) NSString *linecap;
/**
* description: A wrapper object for all the series options in specific states.
*/
@property(nonatomic, readwrite) NSArray <HIPlotOptionsAreasplineStates *> *states;
/**
* description: Whether to use the Y extremes of the total chart width or only the zoomed area when zooming in on parts of the X axis. By default, the Y axis adjusts to the min and max of the visible data. Cartesian series only.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *getExtremesFromAll;
/**
* description: Whether the whole area or just the line should respond to mouseover tooltips and other mouse or touch events.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-trackbyarea/ : Display the tooltip when the
				area is hovered
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *trackByArea;
/**
* description: When a series contains a data array that is longer than this, only one dimensional arrays of numbers,
 or two dimensional arrays with x and y values are allowed. Also, only the first
 point is tested, and the rest are assumed to be the same format. This saves expensive
 data checking and indexing in long series. Set it to 0 disable.
* default: 1000
*/
@property(nonatomic, readwrite) NSNumber *turboThreshold;
/**
* description: An array defining zones within a series. Zones can be applied to the X axis, Y axis or Z axis for bubbles, according to the zoneAxis option.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the color zones are styled with the .highcharts-zone-{n} class, or custom classed from the className option (http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/color-zones/ : view live demo).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-simple/ : Color zones
*/
@property(nonatomic, readwrite) NSArray <HIPlotOptionsAreasplineZones *> *zones;
/**
* description: Pixel with of the graph line.
* demo: 5px http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-general/ : on all series,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-specific/ : on one single series
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Options for the series data labels, appearing next to each data point.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the data labels can be styled wtih the .highcharts-data-label-box and .highcharts-data-label class names (see example).
*/
@property(nonatomic, readwrite) HIPlotOptionsAreasplineDataLabels *dataLabels;
/**
* description: Enable or disable the initial animation when a series is displayed. The animation can also be set as a configuration object. Please note that this option only applies to the initial animation of the series itself. For other animations, see chart.animation and the animation parameter under the API methods.		The following properties are supported:

duration
The duration of the animation in milliseconds.
easing
A string reference to an easing function set on the Math object. See http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/ : the easing demo.


Due to poor performance, animation is disabled in old IE browsers for column charts and polar charts.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-disabled/ : Animation disabled,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-slower/ : slower animation,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/ : custom easing function.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *animation;
/**
* description: Whether to apply a drop shadow to the graph line. Since 2.3 the shadow can be an object configuration containing color, offsetX, offsetY, opacity and width.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-shadow/ : Shadow enabled
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, Object */ shadow;
/**
* description: When this is true, the series will not cause the Y axis to cross the zero plane (or threshold option) unless the data actually crosses the plane.
For example, if softThreshold is false, a series of 0, 1, 2, 3 will make the Y axis show negative values according to the minPadding option. If softThreshold is true, the Y axis starts at 0.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softThreshold;
/**
* description: When the series contains less points than the crop threshold, all points are drawn,  even if the points fall outside the visible plot area at the current zoom. The advantage of drawing all points (including markers and columns), is that animation is performed on updates. On the other hand, when the series contains more points than the crop threshold, the series data is cropped to only contain points that fall within the plot area. The advantage of cropping away invisible points is to increase performance on large series.
* default: 300
*/
@property(nonatomic, readwrite) NSNumber *cropThreshold;
/**
* description: Whether to stack the values of each series on top of each other. Possible values are null to disable, "normal" to stack by value or "percent". When stacking is enabled, data must be sorted in ascending X order.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-line/ : Line,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-column/ : column,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-bar/ : bar,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-area/ : area with "normal" stacking. 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-line/ : Line,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-column/ : column,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-bar/ : bar,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-area/ : area with "percent" stacking.
* accepted values: [null, "normal", "percent"]
*/
@property(nonatomic, readwrite) NSString *stacking;
/**
* description: The main color or the series. In line type series it applies to the line and the point markers unless otherwise specified. In bar type series it applies to the bars unless a color is specified per point. The default value is pulled from the  options.colors array.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the series color can be set with the .highcharts-series, .highcharts-color-{n}, .highcharts-{type}-series or .highcharts-series-{n} class, or individual classes given by the className option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-general/ : General plot option, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-specific/ : one specific series,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-area/ : area color
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: A separate color for the negative part of the area.
*/
@property(nonatomic, readwrite) HIColor *negativeFillColor;
/**
* description: Allow this series' points to be selected by clicking on the markers, bars or pie slices.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-line/ : Line, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-column/ : column, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-pie/ : pie
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;
/**
* description: Requires Accessibility module
A description of the series to add to the screen reader information about the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/stock/accessibility/accessible-stock/ : Accessible stock chart
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: The Y axis value to serve as the base for the area, for distinguishing between values above and below a threshold. If null, the area behaves
 like a line series with fill between the graph and the Y axis minimum.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-threshold/ : A threshold of 100
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *threshold;
/**
* description: If no x values are given for the points in a series, pointStart defines on what value to start. For example, if a series contains one yearly value starting from 1945, set pointStart to 1945.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-linear/ : Linear,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/ : datetime X axis
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *pointStart;

-(NSDictionary *)getParams;

@end
