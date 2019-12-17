/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISummary.h"
#import "HIStates.h"
#import "HIDragDrop.h"
#import "HIPoint.h"
#import "HIMarker.h"
#import "HITooltip.h"
#import "HILabel.h"
#import "HIEvents.h"
#import "HIAccessibility.h"
#import "HIZones.h"
#import "HIDataLabels.h"
#import "HIColor.h"
#import "HIDataSortingOptionsObject.h"
#import "HIShadowOptionsObject.h"
#import "HIFunction.h"
#import "HIData.h"
#import "HIAnimationOptionsObject.h"


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
@property(nonatomic, readwrite) NSArray /* <id, NSNumber, NSArray> */ *data;
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
The type of series. Can be one of area, areaspline, bar, column, line, pie, scatter or spline. From version 2.3, arearange, areasplinerange and columnrange are supported with the highcharts-more.js component.

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
Formatter function to use instead of the default for series descriptions. Receives one argument, `series`, referring to the series to describe. Should return a string with the description of the series for a screen reader user. If `false` is returned, the default formatter will be used for that series.
*/
@property(nonatomic, readwrite) HIFunction *descriptionFormatter;
/**
When a series contains more points than this, we no longer expose information about individual points to screen readers. Set to `false` to disable.
*/
@property(nonatomic, readwrite) NSNumber *pointDescriptionEnabledThreshold;
/**
Whether or not to add series descriptions to charts with a single series.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeSingleSeries;
/**
yAxis description for series if there are multiple yAxes in the chart.
*/
@property(nonatomic, readwrite) NSString *yAxisDescription;
/**
xAxis description for series if there are multiple xAxes in the chart.
*/
@property(nonatomic, readwrite) NSString *xAxisDescription;
/**
Description for the value of null points.
*/
@property(nonatomic, readwrite) NSString *nullPointValue;
/**
User supplied description text. This is added after the main summary if present.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Lang configuration for the series main summary. Each series type has two modes: 1. This series type is the only series type used in the  chart 2. This is a combination chart with multiple series types If a definition does not exist for the specific series type and mode, the 'default' lang definitions are used.
*/
@property(nonatomic, readwrite) HISummary *summary;
/**
When set to `false` will prevent the series data from being included in any form of data export. Since version 6.0.0 until 7.1.0 the option was existing undocumented as `includeInCSVExport`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *includeInDataExport;
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
The color for the parts of the graph or points that are below the `threshold`. Note that `zones` takes precedence over the negative color. Using `negativeColor` is equivalent to applying a zone with value of 0.

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
* [Pattern fill](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/infographic/)
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
*/
@property(nonatomic, readwrite) NSNumber *cropThreshold;
@property(nonatomic, readwrite) HIStates *states;
/**
Determines what data value should be used to calculate point color if `colorAxis` is used. Requires to set `min` and `max` if some custom point property is used or if approximation for data grouping is set to `'sum'`.

**Defaults to** `y`.

**Try it**

* [Custom color key](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/custom-color-key/)
* [Changed default color key](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/changed-default-color-key/)
*/
@property(nonatomic, readwrite) NSString *colorKey;
/**
When this is true, the series will not cause the Y axis to cross the zero plane (or `threshold` option) unless the data actually crosses the plane. For example, if `softThreshold` is `false`, a series of 0, 1, 2, 3 will make the Y axis show negative values according to the `minPadding` option. If `softThreshold` is `true`, the Y axis starts at 0.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softThreshold;
/**
The draggable-points module allows points to be moved around or modified in the chart. In addition to the options mentioned under the `dragDrop` API structure, the module fires three events, `point.dragStart`, `point.drag` and `point.drop`.

**Try it**

* [Draggable column and line series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/resize-column)
* [Draggable bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/bar-series)
* [Draggable bubbles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-bubble)
* [Draggable X range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) HIDragDrop *dragDrop;
/**
Properties for each single point.
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
Options for the series data sorting.
*/
@property(nonatomic, readwrite) HIDataSortingOptionsObject *dataSorting;
/**
Options for the point markers of line-like series. Properties like `fillColor`, `lineColor` and `lineWidth` define the visual appearance of the markers. Other series types, like column series, don't have markers, but have visual options on the series level instead. In styled mode, the markers can be styled with the `.highcharts-point`, `.highcharts-point-hover` and `.highcharts-point-select` class names.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
A configuration object for the tooltip rendering of each single series. Properties are inherited from `tooltip`, but only the following properties can be defined on a series level.
*/
@property(nonatomic, readwrite) HITooltip *tooltip;
/**
Same as `accessibility.pointDescriptionFormatter`, but for an individual series. Overrides the chart wide configuration.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
You can set the cursor to "pointer" if you have click events attached to the series, to signal to the user that the points and lines can be clicked. In styled mode, the series cursor can be set with the same classes as listed under `series.color`.

**Try it**

* [On line graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-line/)
* [On columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-column/)
* [On scatter markers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-cursor-scatter/)
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
A name for the dash style to use for the graph, or for some series types the outline of each shape. In styled mode, the [stroke dash-array](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-dashstyle/) can be set with the same classes as listed under `series.color`.

**Defaults to** `Solid`.

**Try it**

* [Possible values demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/)
* [Chart suitable for printing in black and white](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
Possible values: `"on"`, `"between"`, `number`. In a column chart, when pointPlacement is `"on"`, the point will not create any padding of the X axis. In a polar column chart this means that the first column points directly north. If the pointPlacement is `"between"`, the columns will be laid out between ticks. This is useful for example for visualising an amount between two points in time or in a certain sector of a polar chart. Since Highcharts 3.0.2, the point placement can also be numeric, where 0 is on the axis value, -0.5 is between this value and the previous, and 0.5 is between this value and the next. Unlike the textual options, numeric point placement options won't affect axis padding. Note that pointPlacement needs a `pointRange` to work. For column series this is computed, but for line-type series it needs to be set. For the `xrange` series type and gantt charts, if the Y axis is a category axis, the `pointPlacement` applies to the Y axis rather than the (typically datetime) X axis. Defaults to `undefined` in cartesian charts, `"between"` in polar charts.

**Try it**

* [Between in a column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-between/)
* [Numeric placement for custom layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointplacement-numeric/)
* [Placement in heatmap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/heatmap-pointplacement/)
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ pointPlacement;
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
Series labels are placed as close to the series as possible in a natural way, seeking to avoid other series. The goal of this feature is to make the chart more easily readable, like if a human designer placed the labels in the optimal position. The series labels currently work with series types having a `graph` or an `area`.

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/line-chart)
* [Stream graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph)
* [Stock chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/stock-chart)
*/
@property(nonatomic, readwrite) HILabel *label;
/**
Whether to stack the values of each series on top of each other. Possible values are `undefined` to disable, `"normal"` to stack by value or `"percent"`. When stacking is enabled, data must be sorted in ascending X order. A special stacking option is with the streamgraph series type, where the stacking option is set to `"stream"`. The second one is `"overlap"`, which only applies to waterfall series.

**Accepted values:** `["normal", "overlap", "percent", "stream"]`.

**Try it**

* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-line/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-column/)
* [Bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-bar/)
* [Area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-area/)
* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-line/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-column/)
* [Bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-bar/)
* [Area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stacking-percent-area/)
* [Waterfall with normal stacking](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-waterfall-with-normal-stacking)
* [Waterfall with overlap stacking](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-waterfall-with-overlap-stacking)
*/
@property(nonatomic, readwrite) NSString *stacking;
/**
Enable or disable the initial animation when a series is displayed. The animation can also be set as a configuration object. Please note that this option only applies to the initial animation of the series itself. For other animations, see `chart.animation` and the animation parameter under the API methods. The following properties are supported: - `duration`: The duration of the animation in milliseconds. - `easing`: Can be a string reference to an easing function set on  the `Math` object or a function. See the _Custom easing function_  demo below. Due to poor performance, animation is disabled in old IE browsers for several chart types.

**Defaults to** `true`.

**Try it**

* [Animation disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-disabled/)
* [Slower animation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-slower/)
* [Custom easing function](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Determines whether the series should look for the nearest point in both dimensions or just the x-dimension when hovering the series. Defaults to `'xy'` for scatter series and `'x'` for most other series. If the data has duplicate x-values, it is recommended to set this to `'xy'` to allow hovering over all points. Applies only to series types using nearest neighbor search (not direct hover) for tooltip.

**Accepted values:** `["x", "xy"]`.

**Try it**

* [Different hover behaviors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/findnearestpointby/)
*/
@property(nonatomic, readwrite) NSString *findNearestPointBy;
/**
The threshold, also called zero level or base level. For line type series this is only used in conjunction with `negativeColor`.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *threshold;
/**
If true, a checkbox is displayed next to the legend item to allow selecting the series. The state of the checkbox is determined by the `selected` option.

**Try it**

* [Show select box](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showcheckbox-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showCheckbox;
/**
Sets the color blending in the boost module.

**Accepted values:** `["add", "multiply", "darken"]`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *boostBlending;
/**
General event handlers for the series items. These event hooks can also be attached to the series at run time using the `Highcharts.addEvent` function.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
Opacity of a series parts: line, fill (e.g.area) and dataLabels.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
For some series, there is a limit that shuts down initial animation by default when the total number of points in the chart is too high. For example, for a column chart and its derivatives, animation does not run if there is more than 250 points totally. To disable this cap, set `animationLimit` to `Infinity`.
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
When a series contains a data array that is longer than this, only one dimensional arrays of numbers, or two dimensional arrays with x and y values are allowed. Also, only the first point is tested, and the rest are assumed to be the same format. This saves expensive data checking and indexing in long series. Set it to `0` disable. Note: In boost mode turbo threshold is forced. Only array of numbers or two dimensional arrays are allowed.
*/
@property(nonatomic, readwrite) NSNumber *turboThreshold;
/**
If set to `true`, the accessibility module will skip past the points in this series for keyboard navigation.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipKeyboardNavigation;
/**
Accessibility options for a series.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
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
Whether to apply a drop shadow to the graph line. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Shadow enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-shadow/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;
/**
Allow this series' points to be selected by clicking on the graphic (columns, point markers, pie slices, map areas etc). The selected points can be handled by point select and unselect events, or collectively by the `getSelectedPoints` function. And alternative way of selecting points is through dragging.

**Try it**

* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-line/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-column/)
* [Pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-allowpointselect-pie/)
* [Select a range of points through a drag selection](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;
/**
When using dual or multiple color axes, this number defines which colorAxis the particular series is connected to. It refers to either the {@link #colorAxis.id|axis id} or the index of the axis in the colorAxis array, with 0 being the first. Set this option to false to prevent a series from connecting to the default color axis. Since v7.2.0 the option can also be an axis id or an axis index instead of a boolean flag.

**Defaults to** `0`.

**Try it**

* [Color axis with pie series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/coloraxis-with-pie/)
* [Multiple color axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/multiple-coloraxis/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ colorAxis;
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
The `id` of another series to link to. Additionally, the value can be ":previous" to link to the previous series. When two series are linked, only the first one appears in the legend. Toggling the visibility of this also toggles the linked series. If master series uses data sorting and linked series does not have its own sorting definition, the linked series will be sorted in the same order as the master one.

**Try it**

* [Linked series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange-line/)
*/
@property(nonatomic, readwrite) NSString *linkedTo;
/**
Sticky tracking of mouse events. When true, the `mouseOut` event on a series isn't triggered until the mouse moves over another series, or out of the plot area. When false, the `mouseOut` event on a series is triggered when the mouse leaves the area around the series' graph or markers. This also implies the tooltip when not shared. When `stickyTracking` is false and `tooltip.shared` is false, the tooltip will be hidden when moving the mouse between series. Defaults to true for line and area type series, but to false for columns, pies etc. **Note:** The boost module will force this option because of technical limitations.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-stickytracking-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *stickyTracking;
/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names ([see example](https://www.highcharts.com/samples/highcharts/css/series-datalabels)).

**Try it**

* [Data labels enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-enabled)
* [Multiple data labels on a bar series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-multiple)
* [Style mode example](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels)
*/
@property(nonatomic, readwrite) NSArray <HIDataLabels *> *dataLabels;
/**
An additional class name to apply to the series' graphical elements. This option does not replace default class names of the graphical element.
*/
@property(nonatomic, readwrite) NSString *className;
/**
If no x values are given for the points in a series, pointStart defines on what value to start. For example, if a series contains one yearly value starting from 1945, set pointStart to 1945.

**Defaults to** `0`.

**Try it**

* [Linear](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-linear/)
* [Datetime](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-pointstart-datetime/)
*/
@property(nonatomic, readwrite) NSNumber *pointStart;
/**
The line cap used for line ends and line joins on the graph.

**Defaults to** `round`.
*/
@property(nonatomic, readwrite) NSString *linecap;
/**
Polar charts only. Whether to connect the ends of a line series plot across the extremes.

**Try it**

* [Do not connect](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/line-connectends-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectEnds;
/**
Set the point threshold for when a series should enter boost mode. Setting it to e.g. 2000 will cause the series to enter boost mode when there are 2000 or more points in the series. To disable boosting on the series, set the `boostThreshold` to 0. Setting it to 1 will force boosting. Note that the `cropThreshold` also affects this setting. When zooming in on a series that has fewer points than the `cropThreshold`, all points are rendered although outside the visible plot area, and the `boostThreshold` won't take effect.

**Defaults to** `5000`.
*/
@property(nonatomic, readwrite) NSNumber *boostThreshold;
/**
Whether to display this particular series or series type in the legend. Standalone series are shown in legend by default, and linked series are not. Since v7.2.0 it is possible to show series that use colorAxis by setting this option to `true`.

**Try it**

* [One series in the legend, one hidden](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-showinlegend/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;

-(NSDictionary *)getParams;

/**
 Add a point to the series after render time. The point can be added at the end, or by giving it an X value, to the start or in the middle of the series.
 
 **Try it**
 
 * [Append point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append/)
 * [Append and shift](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append-and-shift/)
 * [Both X and Y values given](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-x-and-y/)
 * [Append pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-pie/)
 
 @param options The point options. If options is a single number, a point with that y value is appended to the series. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options as outlined under `series.data` are applied.
 */
-(void)addPoint:(HIData *)options;

/**
 Add a point to the series after render time. The point can be added at the end, or by giving it an X value, to the start or in the middle of the series.
 
 **Try it**
 
 * [Append point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append/)
 * [Append and shift](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append-and-shift/)
 * [Both X and Y values given](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-x-and-y/)
 * [Append pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-pie/)
 
 @param options The point options. If options is a single number, a point with that y value is appended to the series. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options as outlined under `series.data` are applied.
 @param redraw Whether to redraw the chart after the point is added. When adding more than one point, it is highly recommended that the redraw option be set to false, and instead [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) is explicitly called after the adding of points is finished. Otherwise, the chart will redraw after adding each point.
 */
-(void)addPoint:(HIData *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Add a point to the series after render time. The point can be added at the end, or by giving it an X value, to the start or in the middle of the series.
 
 **Try it**
 
 * [Append point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append/)
 * [Append and shift](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append-and-shift/)
 * [Both X and Y values given](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-x-and-y/)
 * [Append pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-pie/)
 
 @param options The point options. If options is a single number, a point with that y value is appended to the series. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options as outlined under `series.data` are applied.
 @param redraw Whether to redraw the chart after the point is added. When adding more than one point, it is highly recommended that the redraw option be set to false, and instead [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) is explicitly called after the adding of points is finished. Otherwise, the chart will redraw after adding each point.
 @param shift If true, a point is shifted off the start of the series as one is appended to the end.
 */
-(void)addPoint:(HIData *)options redraw:(NSNumber /* Bool */ *)redraw shift:(NSNumber /* Bool */ *)shift;

/**
 Add a point to the series after render time. The point can be added at the end, or by giving it an X value, to the start or in the middle of the series.
 
 **Try it**
 
 * [Append point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append/)
 * [Append and shift](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-append-and-shift/)
 * [Both X and Y values given](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-x-and-y/)
 * [Append pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-addpoint-pie/)
 
 @param options The point options. If options is a single number, a point with that y value is appended to the series. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options as outlined under `series.data` are applied.
 @param redraw Whether to redraw the chart after the point is added. When adding more than one point, it is highly recommended that the redraw option be set to false, and instead [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) is explicitly called after the adding of points is finished. Otherwise, the chart will redraw after adding each point.
 @param shift If true, a point is shifted off the start of the series as one is appended to the end.
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)addPoint:(HIData *)options redraw:(NSNumber /* Bool */ *)redraw shift:(NSNumber /* Bool */ *)shift animation:(HIAnimationOptionsObject *)animation;

/**
 Animate in the series. Called internally twice. First with the `init` parameter set to true, which sets up the initial state of the animation. Then when ready, it is called with the `init` parameter undefined, in order to perform the actual animation. After the second run, the function is removed.
 @param init Initialize the animation.
 */
-(void)animate:(NSNumber /* Bool */ *)init;

/**
 Draw the graph. Called internally when rendering line-like series types. The first time it generates the `series.graph` item and optionally other series-wide items like `series.area` for area charts. On subsequent calls these items are updated with new positions and attributes.
 */
-(void)drawGraph;

/**
 Draw the markers for line-like series types, and columns or other graphical representation for [Highcharts.Point](https://api.highcharts.com/class-reference/Highcharts.Point.html) objects for other series types. The resulting element is typically stored as [Highcharts.Point.graphic](https://api.highcharts.com/class-reference/Highcharts.Point.html#.graphic), and is created on the first call and updated and moved on subsequent calls.
 */
-(void)drawPoints;

/**
 Hide the series if visible. If the [chart.ignoreHiddenSeries](https://api.highcharts.com/highcharts/chart.ignoreHiddenSeries) option is true, the chart is redrawn without this series.
 
 **Fires:**
 
 * Highcharts.Series#event:hide
 
 **Try it**
 
 * [Toggle visibility from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-hide/)
 */
-(void)hide;

/**
 Runs on mouse out of the series graphical items.
 
 **Fires:**
 
 * Highcharts.Series#event:mouseOut
 */
-(void)onMouseOut;

/**
 Runs on mouse over the series graphical items.
 
 **Fires:**
 
 * Highcharts.Series#event:mouseOver
 */
-(void)onMouseOver;

/**
 Remove a series and optionally redraw the chart.
 
 **Fires:**
 
 * Highcharts.Series#event:remove
 
 **Try it**
 
 * [Remove first series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-remove/)
 */
-(void)remove;

/**
 Remove a series and optionally redraw the chart.
 
 **Fires:**
 
 * Highcharts.Series#event:remove
 
 **Try it**
 
 * [Remove first series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-remove/)
 
 @param redraw Whether to redraw the chart or wait for an explicit call to [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw).
 */
-(void)remove:(NSNumber /* Bool */ *)redraw;

/**
 Remove a series and optionally redraw the chart.
 
 **Fires:**
 
 * Highcharts.Series#event:remove
 
 **Try it**
 
 * [Remove first series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-remove/)
 
 @param redraw Whether to redraw the chart or wait for an explicit call to [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw).
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)remove:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Remove a series and optionally redraw the chart.
 
 **Fires:**
 
 * Highcharts.Series#event:remove
 
 **Try it**
 
 * [Remove first series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-remove/)
 
 @param redraw Whether to redraw the chart or wait for an explicit call to [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw).
 @param animation Whether to apply animation, and optionally animation configuration.
 @param withEvent Used internally, whether to fire the series `remove` event.
 */
-(void)remove:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation withEvent:(NSNumber /* Bool */ *)withEvent;

/**
 Remove a point from the series. Unlike the [Highcharts.Point#remove](https://api.highcharts.com/class-reference/Highcharts.Point.html#remove) method, this can also be done on a point that is not instanciated because it is outside the view or subject to Highstock data grouping.
 
 **Fires:**
 
 * Highcharts.Point#event:remove
 
 **Try it**
 
 * [Remove cropped point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-removepoint/)
 
 @param i The index of the point in the data array.
 */
-(void)removePoint:(NSNumber *)i;

/**
 Remove a point from the series. Unlike the [Highcharts.Point#remove](https://api.highcharts.com/class-reference/Highcharts.Point.html#remove) method, this can also be done on a point that is not instanciated because it is outside the view or subject to Highstock data grouping.
 
 **Fires:**
 
 * Highcharts.Point#event:remove
 
 **Try it**
 
 * [Remove cropped point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-removepoint/)
 
 @param i The index of the point in the data array.
 @param redraw Whether to redraw the chart after the point is added. When removing more than one point, it is highly recommended that the `redraw` option be set to `false`, and instead [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) is explicitly called after the adding of points is finished.
 */
-(void)removePoint:(NSNumber *)i redraw:(NSNumber /* Bool */ *)redraw;

/**
 Remove a point from the series. Unlike the [Highcharts.Point#remove](https://api.highcharts.com/class-reference/Highcharts.Point.html#remove) method, this can also be done on a point that is not instanciated because it is outside the view or subject to Highstock data grouping.
 
 **Fires:**
 
 * Highcharts.Point#event:remove
 
 **Try it**
 
 * [Remove cropped point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-removepoint/)
 
 @param i The index of the point in the data array.
 @param redraw Whether to redraw the chart after the point is added. When removing more than one point, it is highly recommended that the `redraw` option be set to `false`, and instead [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) is explicitly called after the adding of points is finished.
 @param animation Whether and optionally how the series should be animated.
 */
-(void)removePoint:(NSNumber *)i redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Render the graph and markers. Called internally when first rendering and later when redrawing the chart. This function can be extended in plugins, but normally shouldn't be called directly.
 
 **Fires:**
 
 * Highcharts.Series#event:afterRender
 */
-(void)render;

/**
 Select or unselect the series. This means its selected property is set, the checkbox in the legend is toggled and when selected, the series is returned by the [Highcharts.Chart#getSelectedSeries](https://api.highcharts.com/class-reference/Highcharts.Chart.html#getSelectedSeries) function.
 
 **Fires:**
 
 * Highcharts.Series#event:select
 * Highcharts.Series#event:unselect
 
 **Try it**
 
 * [Select a series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-select/)
 */
-(void)select;

/**
 Select or unselect the series. This means its selected property is set, the checkbox in the legend is toggled and when selected, the series is returned by the [Highcharts.Chart#getSelectedSeries](https://api.highcharts.com/class-reference/Highcharts.Chart.html#getSelectedSeries) function.
 
 **Fires:**
 
 * Highcharts.Series#event:select
 * Highcharts.Series#event:unselect
 
 **Try it**
 
 * [Select a series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-select/)
 
 @param selected True to select the series, false to unselect. If undefined, the selection state is toggled.
 */
-(void)select:(NSNumber /* Bool */ *)selected;

/**
 Apply a new set of data to the series and optionally redraw it. The new data array is passed by reference (except in case of `updatePoints`), and may later be mutated when updating the chart data.
 
 Note the difference in behaviour when setting the same amount of points, or a different amount of points, as handled by the `updatePoints` parameter.
 
 **Try it**
 
 * [Set new data from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata/)
 * [Set data in a pie](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata-pie/)
 
 @param data Takes an array of data in the same format as described under `series.{type}.data` for the given series type, for example a line series would take data in the form described under [series.line.data](https://api.highcharts.com/highcharts/series.line.data).
 */
-(void)setSeriesData:(NSArray /* <id, NSNumber, NSArray> */ *)data;

/**
 Apply a new set of data to the series and optionally redraw it. The new data array is passed by reference (except in case of `updatePoints`), and may later be mutated when updating the chart data.
 
 Note the difference in behaviour when setting the same amount of points, or a different amount of points, as handled by the `updatePoints` parameter.
 
 **Try it**
 
 * [Set new data from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata/)
 * [Set data in a pie](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata-pie/)
 
 @param data Takes an array of data in the same format as described under `series.{type}.data` for the given series type, for example a line series would take data in the form described under [series.line.data](https://api.highcharts.com/highcharts/series.line.data).
 @param redraw Whether to redraw the chart after the series is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after.
 */
-(void)setSeriesData:(NSArray /* <id, NSNumber, NSArray> */ *)data redraw:(NSNumber /* Bool */ *)redraw;

/**
 Apply a new set of data to the series and optionally redraw it. The new data array is passed by reference (except in case of `updatePoints`), and may later be mutated when updating the chart data.
 
 Note the difference in behaviour when setting the same amount of points, or a different amount of points, as handled by the `updatePoints` parameter.
 
 **Try it**
 
 * [Set new data from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata/)
 * [Set data in a pie](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata-pie/)
 
 @param data Takes an array of data in the same format as described under `series.{type}.data` for the given series type, for example a line series would take data in the form described under [series.line.data](https://api.highcharts.com/highcharts/series.line.data).
 @param redraw Whether to redraw the chart after the series is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after.
 @param animation When the updated data is the same length as the existing data, points will be updated by default, and animation visualizes how the points are changed. Set false to disable animation, or a configuration object to set duration or easing.
 */
-(void)setSeriesData:(NSArray /* <id, NSNumber, NSArray> */ *)data redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Apply a new set of data to the series and optionally redraw it. The new data array is passed by reference (except in case of `updatePoints`), and may later be mutated when updating the chart data.
 
 Note the difference in behaviour when setting the same amount of points, or a different amount of points, as handled by the `updatePoints` parameter.
 
 **Try it**
 
 * [Set new data from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata/)
 * [Set data in a pie](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-setdata-pie/)
 
 @param data Takes an array of data in the same format as described under `series.{type}.data` for the given series type, for example a line series would take data in the form described under [series.line.data](https://api.highcharts.com/highcharts/series.line.data).
 @param redraw Whether to redraw the chart after the series is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after.
 @param animation When the updated data is the same length as the existing data, points will be updated by default, and animation visualizes how the points are changed. Set false to disable animation, or a configuration object to set duration or easing.
 @param updatePoints When this is true, points will be updated instead of replaced whenever possible. This occurs a) when the updated data is the same length as the existing data, b) when points are matched by their id's, or c) when points can be matched by X values. This allows updating with animation and performs better. In this case, the original array is not passed by reference. Set `false` to prevent.
 */
-(void)setSeriesData:(NSArray /* <id, NSNumber, NSArray> */ *)data redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation updatePoints:(NSNumber /* Bool */ *)updatePoints;

/**
 Set the series options by merging from the options tree. Called internally on initiating and updating series. This function will not redraw the series. For API usage, use [Highcharts.Series#update](https://api.highcharts.com/class-reference/Highcharts.Series.html#update).
 
 **Fires:**
 
 * Highcharts.Series#event:afterSetOptions
 
 @param itemOptions The series options.
 */
-(void)setOptions:(HISeries *)itemOptions;

/**
 Set the state of the series. Called internally on mouse interaction operations, but it can also be called directly to visually highlight a series.
 */
-(void)setState;

/**
 Set the state of the series. Called internally on mouse interaction operations, but it can also be called directly to visually highlight a series.
 @param state Can be either `hover` or undefined to set to normal state.
 */
-(void)setState:(NSString *)state;

/**
 Show or hide the series.
 
 **Fires:**
 
 * Highcharts.Series#event:hide
 * Highcharts.Series#event:show
 */
-(void)setSeriesVisible;

/**
 Show or hide the series.
 
 **Fires:**
 
 * Highcharts.Series#event:hide
 * Highcharts.Series#event:show
 
 @param visible True to show the series, false to hide. If undefined, the visibility is toggled.
 */
-(void)setSeriesVisible:(NSNumber /* Bool */ *)visible;

/**
 Show or hide the series.
 
 **Fires:**
 
 * Highcharts.Series#event:hide
 * Highcharts.Series#event:show
 
 @param visible True to show the series, false to hide. If undefined, the visibility is toggled.
 @param redraw Whether to redraw the chart after the series is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [chart.redraw()](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after.
 */
-(void)setSeriesVisible:(NSNumber /* Bool */ *)visible redraw:(NSNumber /* Bool */ *)redraw;

/**
 Show the series if hidden.
 
 **Fires:**
 
 * Highcharts.Series#event:show
 
 **Try it**
 
 * [Toggle visibility from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-hide/)
 */
-(void)show;

/**
 Sonify a series.
 
 **Requires:**
 
 * module:modules/sonification
 
 **Try it**
 
 * [Click on series to sonify](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/series-basic/)
 * [Series with earcon](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/series-earcon/)
 * [Play y-axis by time](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-play-time/)
 * [Earcon set on point](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/earcon-on-point/)
 
 @param options The options for sonifying this series.
 */
-(void)sonify:(NSDictionary *)options;

/**
 Translate data points from raw data values to chart specific positioning data needed later in the `drawPoints` and `drawGraph` functions. This function can be overridden in plugins and custom series type implementations.
 
 **Fires:**
 
 * Highcharts.Series#events:translate
 */
-(void)translate;

/**
 Update the series with a new set of options. For a clean and precise handling of new options, all methods and elements from the series are removed, and it is initiated from scratch. Therefore, this method is more performance expensive than some other utility methods like [Highcharts.Series#setData](https://api.highcharts.com/class-reference/Highcharts.Series.html#setData) or [Highcharts.Series#setVisible](https://api.highcharts.com/class-reference/Highcharts.Series.html#setVisible).
 
 **Fires:**
 
 * Highcharts.Series#event:afterUpdate
 
 **Try it**
 
 * [Updating series options](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-update/)
 
 @param options New options that will be merged with the series' existing options.
 */
-(void)update:(HISeries *)options;

/**
 Update the series with a new set of options. For a clean and precise handling of new options, all methods and elements from the series are removed, and it is initiated from scratch. Therefore, this method is more performance expensive than some other utility methods like [Highcharts.Series#setData](https://api.highcharts.com/class-reference/Highcharts.Series.html#setData) or [Highcharts.Series#setVisible](https://api.highcharts.com/class-reference/Highcharts.Series.html#setVisible).
 
 **Fires:**
 
 * Highcharts.Series#event:afterUpdate
 
 **Try it**
 
 * [Updating series options](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/series-update/)
 
 @param options New options that will be merged with the series' existing options.
 @param redraw Whether to redraw the chart after the series is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after.
 */
-(void)update:(HISeries *)options redraw:(NSNumber /* Bool */ *)redraw;

@end
