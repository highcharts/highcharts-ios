/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISummary.h"
#import "HIPoint.h"
#import "HIStates.h"
#import "HITooltip.h"
#import "HIMarker.h"
#import "HILabel.h"
#import "HIAnimation.h"
#import "HIEvents.h"
#import "HIZones.h"
#import "HIDataLabels.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
 General options for all series types.
 */
@interface HISeries: HIChartsJSONSerializable

/**
 An array of data points for the series. The points can be given in three ways:
 </br></br>1. An array of numerical values. In this case, the numerical values will
 be interpreted as `y` values, and `x` values will be automatically calculated,
 either starting at 0 and incrementing by 1, or from `pointStart`
 and `pointInterval` given in the plotOptions. If the axis is
 has categories, these will be used. This option is not available for range series. Example:
 <pre>
 data: [0, 5, 3, 5]
 </pre>
 </br>2. An array of arrays with two values. In this case, the first value is the
 `x` value and the second is the `y` value. If the first value is a string, it is
 applied as the name of the point, and the `x` value is incremented following
 the above rules. For range series, the arrays will be interpreted as `[x, low, high]`. In this cases, the `X` value can be skipped altogether to make use of `pointStart` and `pointRange`.
 Example:
 <pre>
 data: [
     [0, 9],
     [1, 2],
     [2, 8]
 ]
 </pre>
 </br>3. An array of objects with named values. In this case the objects are
 point configuration objects as seen below. Range series values are given by low and high.
 Example:
 <pre>
 data: [{
     x: 1,
     y: 9,
     name: "Point2",
     color: "#00FF00"
 }, {
     x: 1,
     y: 0,
     name: "Point1",
     color: "#FF00FF"
 }]
 </pre>Note that line series and derived types like spline and area, require data to be sorted by X because it interpolates mouse coordinates for the tooltip. Column and scatter series, where each point has its own mouse event, does not require sorting.
 
 ####Try it
 * [Numerical values](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/)
 * [Arrays of numeric x and y](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays/)
 * [Arrays of datetime x and y](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays-datetime/)
 * [Arrays of point.name and y](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-name-value/)
 * [Config objects](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/)
 */
@property(nonatomic, readwrite) NSArray /* <Data, NSNumber, NSArray> */ *data;
/**
An id for the series. This can be used after render time to get a pointer to the series object through chart.get().

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-id/" target="_blank">Get series by id</a>*/
@property(nonatomic, readwrite) NSString *id;
/**
The index of the series in the chart, affecting the internal index in the chart.series array, the visible Z index as well as the order in the legend.
*/
@property(nonatomic, readwrite) NSNumber *index;
/**
The sequential index of the series in the legend. Try it: 	Legend in opposite order .
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
The name of the series as shown in the legend, tooltip etc.

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/name/" target="_blank">Series name</a>*/
@property(nonatomic, readwrite) NSString *name;
/**
This option allows grouping series in a stacked chart. The stack option can be a string or a number or anything else, as long as the grouped series' stack options match each other.

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/stack/" target="_blank">Stacked and grouped columns</a>*/
@property(nonatomic, readwrite) NSString *stack;
/**
The type of series. Can be one of area, areaspline,
 bar, column, line, pie,
 scatter or spline. From version 2.3, arearange, areasplinerange and columnrange are supported with the highcharts-more.js component.

**Accepted values:** `[null, "line", "spline", "column", "area", "areaspline", "pie", "arearange", "areasplinerange", "boxplot", "bubble", "columnrange", "errorbar", "funnel", "gauge", "scatter", "waterfall"]`.

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/type/" target="_blank">Line and column in the same chart</a>*/
@property(nonatomic, readwrite) NSString *type;
/**
When using dual or multiple x axes, this number defines which xAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the xAxis array, with 0 being the first.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ xAxis;
/**
When using dual or multiple y axes, this number defines which yAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the yAxis array, with 0 being the first.

**Defaults to** `0`.

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/yaxis/" target="_blank">Apply the column series to the secondary Y axis</a>*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ yAxis;
/**
Define the visual z index of the series.

**Try it**

<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex-default/" target="_blank">With no z index, the series defined last are on top</a>,
			<a href="http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex/" target="_blank">with a z index, the series with the highest z index is on top</a>.*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
yAxis description for series if there are multiple yAxes in the chart.
*/
@property(nonatomic, readwrite) NSString *yAxisDescription;
/**
xAxis description for series if there are multiple xAxes in the chart.
*/
@property(nonatomic, readwrite) NSString *xAxisDescription;
/**
User supplied description text. This is added after the main summary if present.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Lang configuration for the series main summary. Each series type has two modes:   1. This series type is the only series type used in the    chart  2. This is a combination chart with multiple series types If a definition does not exist for the specific series type and mode, the 'default' lang definitions are used.
*/
@property(nonatomic, readwrite) HISummary *summary;
/**
Properties for each single point.
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
Whether to select the series initially. If `showCheckbox` is true, the checkbox next to the series name in the legend will be checked for a selected series.

**Defaults to** `false`.

**Try it**

* [One out of two series selected](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-selected/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
Styled mode only. A specific color index to use for the series, so its graphic representations are given the class name `highcharts-color-{n}`.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
Disable this option to allow series rendering in the whole plotting area. **Note:** Clipping should be always enabled when `chart.zoomType` is set

**Defaults to** `true`.

**Try it**

* [Disabled clipping](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-clip/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *clip;
/**
The color for the parts of the graph or points that are below the `threshold`.

**Try it**

* [Spline, area and column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-negative-color/)
* [Arearange](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-negativecolor/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-negative-color/)
*/
@property(nonatomic, readwrite) HIColor *negativeColor;
/**
The main color of the series. In line type series it applies to the line and the point markers unless otherwise specified. In bar type series it applies to the bars unless a color is specified per point. The default value is pulled from the `options.colors` array. In styled mode, the color can be defined by the `colorIndex` option. Also, the series color can be set with the `.highcharts-series`, `.highcharts-color-{n}`, `.highcharts-{type}-series` or `.highcharts-series-{n}` class, or individual classes given by the `className` option.

**Try it**

* [General plot option](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-general/)
* [One specific series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-specific/)
* [Area color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-color-area/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
If no x values are given for the points in a series, `pointInterval` defines the interval of the x values. For example, if a series contains one value every decade starting from year 0, set `pointInterval` to `10`. In true `datetime` axes, the `pointInterval` is set in milliseconds. It can be also be combined with `pointIntervalUnit` to draw irregular time intervals. Please note that this options applies to the _series data_, not the interval of the axis ticks, which is independent.

**Defaults to** `1`.

**Try it**

* [Datetime X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/)
*/
@property(nonatomic, readwrite) NSNumber *pointInterval;
/**
When the series contains less points than the crop threshold, all points are drawn, even if the points fall outside the visible plot area at the current zoom. The advantage of drawing all points (including markers and columns), is that animation is performed on updates. On the other hand, when the series contains more points than the crop threshold, the series data is cropped to only contain points that fall within the plot area. The advantage of cropping away invisible points is to increase performance on large series.

**Defaults to** `300`.
*/
@property(nonatomic, readwrite) NSNumber *cropThreshold;
/**
A wrapper object for all the series options in specific states.
*/
@property(nonatomic, readwrite) HIStates *states;
/**
The threshold, also called zero level or base level. For line type series this is only used in conjunction with `negativeColor`.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *threshold;
/**
When this is true, the series will not cause the Y axis to cross the zero plane (or `threshold` option) unless the data actually crosses the plane. For example, if `softThreshold` is `false`, a series of 0, 1, 2, 3 will make the Y axis show negative values according to the `minPadding` option. If `softThreshold` is `true`, the Y axis starts at 0.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softThreshold;
/**
A configuration object for the tooltip rendering of each single series. Properties are inherited from `tooltip`, but only the following properties can be defined on a series level.
*/
@property(nonatomic, readwrite) HITooltip *tooltip;
/**
Options for the point markers of line-like series. Properties like `fillColor`, `lineColor` and `lineWidth` define the visual appearance of the markers. Other series types, like column series, don't have markers, but have visual options on the series level instead. In styled mode, the markers can be styled with the `.highcharts-point`, `.highcharts-point-hover` and `.highcharts-point-select` class names.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
Same as `accessibility.pointDescriptionFormatter`, but for an individual series. Overrides the chart wide configuration.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
The border color of the map areas. In styled mode, the border stroke is given in the `.highcharts-point` class.

**Defaults to** `#cccccc`.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
An additional class name to apply to the series' graphical elements. This option does not replace default class names of the graphical element.
*/
@property(nonatomic, readwrite) NSString *className;
/**
A name for the dash style to use for the graph, or for some series types the outline of each shape. The value for the `dashStyle` include: `"Dash"`, `"DashDot"`, `"Dot"`, `"LongDash"`, `"LongDashDot"`, `"LongDashDotDot"`, `"ShortDash"`, `"ShortDashDot"`, `"ShortDashDotDot"`, `"ShortDot"`, and `"Solid"`. In styled mode, the [stroke dash-array](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-dashstyle/) can be set with the same classes as listed under `series.color`.

**Defaults to** `Solid`.

**Try it**

* [Possible values demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/)
* [Chart suitable for printing in black and white](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
Possible values: `"on"`, `"between"`, `number`. In a column chart, when pointPlacement is `"on"`, the point will not create any padding of the X axis. In a polar column chart this means that the first column points directly north. If the pointPlacement is `"between"`, the columns will be laid out between ticks. This is useful for example for visualising an amount between two points in time or in a certain sector of a polar chart. Since Highcharts 3.0.2, the point placement can also be numeric, where 0 is on the axis value, -0.5 is between this value and the previous, and 0.5 is between this value and the next. Unlike the textual options, numeric point placement options won't affect axis padding. Note that pointPlacement needs a `pointRange` to work. For column series this is computed, but for line-type series it needs to be set. Defaults to `undefined` in cartesian charts, `"between"` in polar charts.

**Try it**

* [Between in a column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-between/)
* [Numeric placement for custom layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-numeric/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ pointPlacement;
/**
Whether to connect a graph line across null points, or render a gap between the two points on either side of the null.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-connectnulls-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectNulls;
/**
Enable or disable the mouse tracking for a specific series. This includes point tooltips and click events on graphs and points. For large datasets it improves performance.

**Defaults to** `true`.

**Try it**

* [No mouse tracking](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-enablemousetracking-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableMouseTracking;
/**
Series labels are placed as close to the series as possible in a natural way, seeking to avoid other series. The goal of this feature is to make the chart more easily readable, like if a human designer placed the labels in the optimal position. The series labels currently work with series types having a `graph` or an `area`. Requires the `series-label.js` module.

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/line-chart)
* [Stream graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph)
* [Stock chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/stock-chart)
*/
@property(nonatomic, readwrite) HILabel *label;
/**
Whether to stack the values of each series on top of each other. Possible values are `undefined` to disable, `"normal"` to stack by value or `"percent"`. When stacking is enabled, data must be sorted in ascending X order. A special stacking option is with the streamgraph series type, where the stacking option is set to `"stream"`.

**Accepted values:** `["normal", "percent"]`.

**Try it**

* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-line/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-column/)
* [Bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-bar/)
* [Area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-area/)
* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-line/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-column/)
* [Bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-bar/)
* [Area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-area/)
*/
@property(nonatomic, readwrite) NSString *stacking;
/**
Enable or disable the initial animation when a series is displayed. The animation can also be set as a configuration object. Please note that this option only applies to the initial animation of the series itself. For other animations, see `chart.animation` and the animation parameter under the API methods. The following properties are supported:  duration The duration of the animation in milliseconds. easing Can be a string reference to an easing function set on the `Math` object or a function. See the _Custom easing function_ demo below.  Due to poor performance, animation is disabled in old IE browsers for several chart types.

**Defaults to** `true`.

**Try it**

* [Animation disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-disabled/)
* [Slower animation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-slower/)
* [Custom easing function](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/)
*/
@property(nonatomic, readwrite) HIAnimation *animation;
/**
Determines whether the series should look for the nearest point in both dimensions or just the x-dimension when hovering the series. Defaults to `'xy'` for scatter series and `'x'` for most other series. If the data has duplicate x-values, it is recommended to set this to `'xy'` to allow hovering over all points. Applies only to series types using nearest neighbor search (not direct hover) for tooltip.

**Accepted values:** `["x", "xy"]`.

**Try it**

* [Different hover behaviors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/findnearestpointby/)
*/
@property(nonatomic, readwrite) NSString *findNearestPointBy;
@property(nonatomic, readwrite) NSNumber /* Bool */ *showCheckbox;
/**
General event handlers for the series items. These event hooks can also be attached to the series at run time using the `Highcharts.addEvent` function.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
For some series, there is a limit that shuts down initial animation by default when the total number of points in the chart is too high. For example, for a column chart and its derivatives, animation doesn't run if there is more than 250 points totally. To disable this cap, set `animationLimit` to `Infinity`.
*/
@property(nonatomic, readwrite) NSNumber *animationLimit;
/**
An array specifying which option maps to which key in the data point array. This makes it convenient to work with unstructured data arrays from different sources.

**Try it**

* [An extended data array with keys](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-keys/)
* [Nested keys used to access object properties](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-nested-keys/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *keys;
/**
When a series contains a data array that is longer than this, only one dimensional arrays of numbers, or two dimensional arrays with x and y values are allowed. Also, only the first point is tested, and the rest are assumed to be the same format. This saves expensive data checking and indexing in long series. Set it to `0` disable.

**Defaults to** `1000`.
*/
@property(nonatomic, readwrite) NSNumber *turboThreshold;
/**
If set to `True`, the accessibility module will skip past the points in this series for keyboard navigation.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipKeyboardNavigation;
/**
If true, a checkbox is displayed next to the legend item to allow selecting the series. The state of the checkbox is determined by the `selected` option.

**Defaults to** `false`.

**Try it**

* [Show select box](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showcheckbox-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;
/**
Whether to apply steps to the line. Possible values are `left`, `center` and `right`.

**Accepted values:** `["left", "center", "right"]`.

**Try it**

* [Different step line options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-step/)
* [Stepped, stacked area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-step/)
*/
@property(nonatomic, readwrite) NSString *step;
/**
Whether to use the Y extremes of the total chart width or only the zoomed area when zooming in on parts of the X axis. By default, the Y axis adjusts to the min and max of the visible data. Cartesian series only.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *getExtremesFromAll;
/**
By default, series are exposed to screen readers as regions. By enabling this option, the series element itself will be exposed in the same way as the data points. This is useful if the series is not used as a grouping entity in the chart, but you still want to attach a description to the series. Requires the Accessibility module.

**Try it**

* [Accessible data visualization](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/art-grants/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *exposeElementToA11y;
/**
Whether to apply a drop shadow to the graph line. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Shadow enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-shadow/)
*/
@property(nonatomic, readwrite) id shadow;
/**
Defines the Axis on which the zones are applied.

**Defaults to** `y`.

**Try it**

* [Zones on the X-Axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-zoneaxis-x/)
*/
@property(nonatomic, readwrite) NSString *zoneAxis;
/**
An array defining zones within a series. Zones can be applied to the X axis, Y axis or Z axis for bubbles, according to the `zoneAxis` option. The zone definitions have to be in ascending order regarding to the value. In styled mode, the color zones are styled with the `.highcharts-zone-{n}` class, or custom classed from the `className` option ([view live demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/color-zones/)).

**Try it**

* [Color zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-simple/)
*/
@property(nonatomic, readwrite) NSArray <HIZones *> *zones;
/**
On datetime series, this allows for setting the `pointInterval` to irregular time units, `day`, `month` and `year`. A day is usually the same as 24 hours, but `pointIntervalUnit` also takes the DST crossover into consideration when dealing with local time. Combine this option with `pointInterval` to draw weeks, quarters, 6 months, 10 years etc. Please note that this options applies to the _series data_, not the interval of the axis ticks, which is independent.

**Accepted values:** `["day", "month", "year"]`.

**Try it**

* [One point a month](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointintervalunit/)
*/
@property(nonatomic, readwrite) NSString *pointIntervalUnit;
/**
Pixel width of the graph line.

**Defaults to** `2`.

**Try it**

* [On all series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-general/)
* [On one single series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-linewidth-specific/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
Set the initial visibility of the series.

**Defaults to** `true`.

**Try it**

* [Two series, one hidden and one visible](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-visible/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
The `id` of another series to link to. Additionally, the value can be ":previous" to link to the previous series. When two series are linked, only the first one appears in the legend. Toggling the visibility of this also toggles the linked series.

**Try it**

* [Linked series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange-line/)
*/
@property(nonatomic, readwrite) NSString *linkedTo;
/**
Sticky tracking of mouse events. When true, the `mouseOut` event on a series isn't triggered until the mouse moves over another series, or out of the plot area. When false, the `mouseOut` event on a series is triggered when the mouse leaves the area around the series' graph or markers. This also implies the tooltip when not shared. When `stickyTracking` is false and `tooltip.shared` is false, the tooltip will be hidden when moving the mouse between series. Defaults to true for line and area type series, but to false for columns, pies etc.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *stickyTracking;
/**
Options for the series data labels, appearing next to each data point. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names ([see example](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels)).
*/
@property(nonatomic, readwrite) HIDataLabels *dataLabels;
/**
You can set the cursor to "pointer" if you have click events attached to the series, to signal to the user that the points and lines can be clicked. Possible values are: `"default"`, `"help"`, `"none"`, `"pointer"`, and `"crosshair"`. In styled mode, the series cursor can be set with the same classes as listed under `series.color`.

**Try it**

* [On line graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-line/)
* [On columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-column/)
* [On scatter markers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-scatter/)
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
If no x values are given for the points in a series, pointStart defines on what value to start. For example, if a series contains one yearly value starting from 1945, set pointStart to 1945.

**Defaults to** `0`.

**Try it**

* [Linear](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-linear/)
* [Datetime](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/)
*/
@property(nonatomic, readwrite) NSNumber *pointStart;
/**
The border width of each map area. In styled mode, the border stroke width is given in the `.highcharts-point` class.
*/
@property(nonatomic, readwrite) id borderWidth;
/**
The line cap used for line ends and line joins on the graph.

**Accepted values:** `["round", "square"]`.
*/
@property(nonatomic, readwrite) NSString *linecap;
/**
Polar charts only. Whether to connect the ends of a line series plot across the extremes.

**Try it**

* [Do not connect](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-connectends-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectEnds;
/**
Set the point threshold for when a series should enter boost mode. Setting it to e.g. 2000 will cause the series to enter boost mode when there are 2000 or more points in the series. To disable boosting on the series, set the `boostThreshold` to 0. Setting it to 1 will force boosting. Requires `modules/boost.js`.

**Defaults to** `5000`.
*/
@property(nonatomic, readwrite) NSNumber *boostThreshold;
/**
Whether to display this particular series or series type in the legend. The default value is `true` for standalone series, `false` for linked series.

**Defaults to** `true`.

**Try it**

* [One series in the legend, one hidden](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showinlegend/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;

-(NSDictionary *)getParams;

@end
