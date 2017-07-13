/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPlotOptionsErrorbarEvents.h"
#import "HIPlotOptionsErrorbarPoint.h"
#import "HIPlotOptionsErrorbarTooltip.h"
#import "HIPlotOptionsErrorbarZones.h"
#import "HIPlotOptionsErrorbarStates.h"
#import "HIColor.h"


/**
* description: Error bars are a graphical representation of the variability of data and are used on graphs to indicate the error, or uncertainty in a reported measurement. 
*/
@interface HIPlotOptionsErrorbar: HIChartsJSONSerializable

/**
* description: The parent series of the error bar. The default value links it to the previous series. Otherwise, use the id of the parent series.
* default: :previous
*/
@property(nonatomic, readwrite) NSString *linkedTo;
/**
* description: The length of the whiskers, the horizontal lines marking low and high values. It can be a numerical pixel value, or a percentage value of the box width. Set 0 to disable whiskers.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : True by default
* default: 50%
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ whiskerLength;
/**
* description: When a series contains a data array that is longer than this, only one dimensional arrays of numbers,
 or two dimensional arrays with x and y values are allowed. Also, only the first
 point is tested, and the rest are assumed to be the same format. This saves expensive
 data checking and indexing in long series. Set it to 0 disable.
* default: 1000
*/
@property(nonatomic, readwrite) NSNumber *turboThreshold;
/**
* description: For some series, there is a limit that shuts down initial animation by default when the total number of points in the chart is too high. For example, for a column chart and its derivatives, animation doesn't run if there is more than 250 points totally. To disable this cap, set animationLimit to Infinity.
*/
@property(nonatomic, readwrite) NSNumber *animationLimit;
/**
* description: The color for the parts of the graph or points that are below the threshold.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-negative-color/ : Spline, area and column - http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-negativecolor/ : arearange.
* default: null
*/
@property(nonatomic, readwrite) HIColor *negativeColor;
@property(nonatomic, readwrite) HIPlotOptionsErrorbarEvents *events;
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
* description: The color of the stem, the vertical line extending from the box to the whiskers. If null, the series color is used.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : Box plot styling, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : error bar styling
* default: null
*/
@property(nonatomic, readwrite) HIColor *stemColor;
/**
* description: The width of the line surrounding the box. If any of stemWidth, medianWidth or whiskerWidth are null, the lineWidth also applies to these lines.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : Box plot styling, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : error bar styling
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: On datetime series, this allows for setting the pointInterval to irregular time units, day, month and year. A day is usually the same as 24 hours, but pointIntervalUnit also takes the DST crossover into consideration when dealing with local time. Combine this option with pointInterval to draw weeks, quarters, 6 months, 10 years etc.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointintervalunit/ : One point a month
* accepted values: [null, "day", "month", "year"]
*/
@property(nonatomic, readwrite) NSString *pointIntervalUnit;
/**
* description: The X axis range that each point is valid for. This determines the width of the column. On a categorized axis, the range will be 1 by default (one category unit). On linear and datetime axes, the range will be computed as the distance between the two closest data points.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointrange/ : Set the point range to one day on a data set with one week between the points
*/
@property(nonatomic, readwrite) NSNumber *pointRange;
/**
* description: Defines the Axis on which the zones are applied.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-zoneaxis-x/ : Zones on the X-Axis
* default: y
*/
@property(nonatomic, readwrite) NSString *zoneAxis;
/**
* description: Properties for each single point
*/
@property(nonatomic, readwrite) HIPlotOptionsErrorbarPoint *point;
/**
* description: A series specific or series type specific color set to apply instead of the global colors when colorByPoint is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
* description: Enable or disable the mouse tracking for a specific series. This includes point tooltips and click events on graphs and points. For large datasets it improves performance.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-enablemousetracking-false/ : No mouse tracking
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableMouseTracking;
/**
* description: Requires Accessibility module
A description of the series to add to the screen reader information about the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/stock/accessibility/accessible-stock/ : Accessible stock chart
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
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
* description: Whether to select the series initially. If showCheckbox is true, the checkbox next to the series name will be checked for a selected series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-selected/ : One out of two series selected
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
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
* description: If no x values are given for the points in a series, pointStart defines on what value to start. For example, if a series contains one yearly value starting from 1945, set pointStart to 1945.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-linear/ : Linear,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/ : datetime X axis
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *pointStart;
/**
* description: A configuration object for the tooltip rendering of each single series. Properties are inherited from tooltip, but only the following properties can be defined on a series level.
*/
@property(nonatomic, readwrite) HIPlotOptionsErrorbarTooltip *tooltip;
/**
* description: An array defining zones within a series. Zones can be applied to the X axis, Y axis or Z axis for bubbles, according to the zoneAxis option.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the color zones are styled with the .highcharts-zone-{n} class, or custom classed from the className option (http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/color-zones/ : view live demo).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-simple/ : Color zones
*/
@property(nonatomic, readwrite) NSArray <HIPlotOptionsErrorbarZones *> *zones;
/**
* description: Set the initial visibility of the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-visible/ : Two series, one hidden and one visible
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
* description: An array specifying which option maps to which key in the data point array. This makes it convenient to work with unstructured data arrays from different sources.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-keys/ : An extended data array with keys
*/
@property(nonatomic, readwrite) NSArray<NSString *> *keys;
/**
* description: Whether to use the Y extremes of the total chart width or only the zoomed area when zooming in on parts of the X axis. By default, the Y axis adjusts to the min and max of the visible data. Cartesian series only.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *getExtremesFromAll;
/**
* description: The width of the stem, the vertical line extending from the box to the whiskers. If null, the width is inherited from the lineWidth option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : Box plot styling, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : error bar styling
* default: null
*/
@property(nonatomic, readwrite) NSNumber *stemWidth;
/**
* description: 3D columns only. The width of the colored edges.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *edgeWidth;
/**
* description: You can set the cursor to "pointer" if you have click events attached to  the series, to signal to the user that the points and lines can be clicked.
* demo: Pointer cursor http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-line/ : on line graph,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-column/ : on columns,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-scatter/ : on scatter markers
* accepted values: [null, "default", "none", "help", "pointer", "crosshair"]
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
* description: The main color of the bars. This can be overridden by stemColor and whiskerColor individually. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : Error bar styling
* default: #000000
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: A pixel value specifying a fixed width for each column or bar. When null, the width is calculated from the pointPadding and groupPadding.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointwidth-20/ : 20px wide columns regardless of chart width
			or the amount of data points
*/
@property(nonatomic, readwrite) NSNumber *pointWidth;
/**
* description: The line width of the whiskers, the horizontal lines marking low and high values. When null, the general lineWidth applies.
* demo:  http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : Error bar styling
* default: null
*/
@property(nonatomic, readwrite) NSNumber *whiskerWidth;
/**
* description: A wrapper object for all the series options in specific states.
*/
@property(nonatomic, readwrite) NSArray <HIPlotOptionsErrorbarStates *> *states;
/**
* description: The color of the whiskers, the horizontal lines marking low and high values. When null, the general series color is used.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : Box plot styling
* default: null
*/
@property(nonatomic, readwrite) HIColor *whiskerColor;
/**
* description: Allow this series' points to be selected by clicking on the markers, bars or pie slices.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-line/ : Line, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-column/ : column, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-pie/ : pie
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;
/**
* description: The maximum allowed pixel width for a column, translated to the height of a bar in a bar chart. This prevents the columns from becoming too wide when there is a small number of points in the chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-maxpointwidth-20/ : Limited to 50
* default: null
*/
@property(nonatomic, readwrite) NSNumber *maxPointWidth;
/**
* description: A class name to apply to the series' graphical elements.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The spacing between columns on the Z Axis in a 3D chart. Requires highcharts-3d.js.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *groupZPadding;
/**
* description: When using automatic point colors pulled from the options.colors
 collection, this option determines whether the chart should receive 
 one color per series or one color per point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/ : False by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/ : true
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
* description: Depth of the columns in a 3D column chart. Requires highcharts-3d.js.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/column/ : Basic 3D column chart
* default: 25
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
* description: Padding between each column or bar, in x axis units.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-default/ : 0.1 by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-025/ : 0.25, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-none/ : 0 for tightly packed columns,
* default: 0.1
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
* description: 3D columns only. The color of the edges. Similar to borderColor, except it defaults to the same color as the column.
*/
@property(nonatomic, readwrite) HIColor *edgeColor;
/**
* description: The dash style of the stem, the vertical line extending from the box to the whiskers.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/ : Box plot styling, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/ : error bar styling
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *stemDashStyle;

-(NSDictionary *)getParams;

@end
