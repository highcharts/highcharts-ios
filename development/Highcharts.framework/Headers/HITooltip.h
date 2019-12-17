/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDateTimeLabelFormats.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HICSSObject.h"
#import "HIPoint.h"
#import "HIShadowOptionsObject.h"


/**
Options for the tooltip that appears when the user hovers over a series or point.
*/
@interface HITooltip: HIChartsJSONSerializable

/**
Whether the tooltip should update as the finger moves on a touch device. If this is `true` and `chart.panning` is set,`followTouchMove` will take over one-finger touches, so the user needs to use two fingers for zooming and panning. Note the difference to `followPointer` that only defines the _position_ of the tooltip. If `followPointer` is false in for example a column series, the tooltip will show above or below the column, but as `followTouchMove` is true, the tooltip will jump from column to column as the user swipes across the plot area.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followTouchMove;
/**
Callback function to format the text of the tooltip for visible null points. Works analogously to `formatter`.

**Try it**

* [Format data label and tooltip for null point.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-nullformat)
*/
@property(nonatomic, readwrite) HIFunction *nullFormatter;
/**
The HTML of the cluster point's in the tooltip. Works only with marker-clusters module and analogously to `pointFormat`. The cluster tooltip can be also formatted using `tooltip.formatter` callback function and `point.isCluster` flag.

**Try it**

* [Format tooltip for cluster points.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/grid)
* [Format tooltip for clusters using tooltip.formatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/europe/)
*/
@property(nonatomic, readwrite) id clusterFormat;
/**
The radius of the rounded border corners.

**Try it**

* [5px by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/)
* [Square borders](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/borderradius-0/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
The HTML of the tooltip header line. Variables are enclosed by curly brackets. Available variables are `point.key`, `series.name`, `series.color` and other members from the `point` and `series` objects. The `point.key` variable contains the category name, x value or datetime string depending on the type of axis. For datetime axes, the `point.key` date format can be set using `tooltip.xDateFormat`.

**Try it**

* [An HTML table in the tooltip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/)
*/
@property(nonatomic, readwrite) NSString *headerFormat;
/**
A string to append to each series' y value. Overridable in each series' tooltip options object.

**Try it**

* [Set decimals, prefix and suffix for the value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/)
*/
@property(nonatomic, readwrite) NSString *valueSuffix;
/**
A string to prepend to each series' y value. Overridable in each series' tooltip options object.

**Try it**

* [Set decimals, prefix and suffix for the value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/)
*/
@property(nonatomic, readwrite) NSString *valuePrefix;
/**
A callback function to place the tooltip in a default position. The callback receives three parameters: `labelWidth`, `labelHeight` and `point`, where point contains values for `plotX` and `plotY` telling where the reference point is in the plot area. Add `chart.plotLeft` and `chart.plotTop` to get the full coordinates. Since v7, when `tooltip.split` option is enabled, positioner is called for each of the boxes separately, including xAxis header. xAxis header is not a point, instead `point` argument contains info: `{ plotX: Number, plotY: Number, isHeader: Boolean }`  The return should be an object containing x and y values, for example `{ x: 100, y: 100 }`.

**Try it**

* [A fixed tooltip position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/positioner/)
*/
@property(nonatomic, readwrite) HIFunction *positioner;
/**
Use HTML to render the contents of the tooltip instead of SVG. Using HTML allows advanced formatting like tables and images in the tooltip. It is also recommended for rtl languages as it works around rtl bugs in early Firefox.

**Defaults to** `false`.

**Try it**

* [A table for value alignment](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/)
* [Full HTML tooltip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/fullhtml/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
The color of the tooltip border. When `undefined`, the border takes the color of the corresponding series or point.

**Try it**

* [Follow series by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/)
* [Black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-black/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
CSS styles for the tooltip. The tooltip can also be styled through the CSS class `.highcharts-tooltip`. Note that the default `pointerEvents` style makes the tooltip ignore mouse events, so in order to use clickable tooltips, this value must be set to `auto`.

**Try it**

* [Greater padding, bold text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/style/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The name of a symbol to use for the border around the tooltip header. Applies only when `tooltip.split` is enabled. Custom callbacks for symbol path generation can also be added to `Highcharts.SVGRenderer.prototype.symbols` the same way as for `series.marker.symbol`.

**Accepted values:** `["callout", "square"]`.

**Defaults to** `callout`.
*/
@property(nonatomic, readwrite) NSString *headerShape;
/**
A string to append to the tooltip format.

**Try it**

* [A table for value alignment](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/footerformat/)
*/
@property(nonatomic, readwrite) NSString *footerFormat;
/**
Whether to allow the tooltip to render outside the chart's SVG element box. By default (`false`), the tooltip is rendered within the chart's SVG element, which results in the tooltip being aligned inside the chart area. For small charts, this may result in clipping or overlapping. When `true`, a separate SVG element is created and overlaid on the page, allowing the tooltip to be aligned inside the page itself. Defaults to `true` if `chart.scrollablePlotArea` is activated, otherwise `false`.

**Defaults to** `undefined`.

**Try it**

* [Small charts with tooltips outside](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/outside)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *outside;
/**
Enable or disable animation of the tooltip.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *animation;
/**
Split the tooltip into one label per series, with the header close to the axis. This is recommended over `shared` tooltips for charts with multiple line series, generally making them easier to read. This option takes precedence over `tooltip.shared`.

**Defaults to** `false`.

**Try it**

* [Split tooltip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/split/)
* [Split tooltip and custom formatter callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-split/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *split;
/**
The background color or gradient for the tooltip. In styled mode, the stroke width is set in the `.highcharts-tooltip-box` class.

**Try it**

* [Yellowish background](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/backgroundcolor-solid/)
* [Gradient](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/backgroundcolor-gradient/)
* [Tooltip in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/tooltip-border-background/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
Proximity snap for graphs or single points. It defaults to 10 for mouse-powered devices and 25 for touch devices. Note that in most cases the whole plot area captures the mouse movement, and in these cases `tooltip.snap` doesn't make sense. This applies when `stickyTracking` is `true` (default) and when the tooltip is `shared` or `split`.

**Defaults to** `10/25`.

**Try it**

* [10 px by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/)
* [50 px on graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/snap-50/)
*/
@property(nonatomic, readwrite) NSNumber *snap;
/**
When the tooltip is shared, the entire plot area will capture mouse movement or touch events. Tooltip texts for series types with ordered data (not pie, scatter, flags etc) will be shown in a single bubble. This is recommended for single series charts and for tablet/mobile optimized charts. See also `tooltip.split`, that is better suited for charts with many series, especially line-type series. The `tooltip.split` option takes precedence over `tooltip.shared`.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-true/)
* [True with x axis crosshair](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-x-crosshair/)
* [True with mixed series types](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shared-true-mixed-types/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shared;
/**
Callback function to format the text of the tooltip from scratch. In case of single or `shared` tooltips, a string should be returned. In case of `split` tooltips, it should return an array where the first item is the header, and subsequent items are mapped to the points. Return `false` to disable tooltip for a specific point on series. A subset of HTML is supported. Unless `useHTML` is true, the HTML of the tooltip is parsed and converted to SVG, therefore this isn't a complete HTML renderer. The following HTML tags are supported: `b`, `br`, `em`, `i`, `span`, `strong`. Spans can be styled with a `style` attribute, but only text-related CSS, that is shared with SVG, is handled. The available data in the formatter differ a bit depending on whether the tooltip is shared or split, or belongs to a single point. In a shared/split tooltip, all properties except `x`, which is common for all points, are kept in an array, `this.points`. Available data are: - **this.percentage (not shared) **  **this.points[i].percentage (shared)**:  Stacked series and pies only. The point's percentage of the total. - **this.point (not shared) / this.points[i].point (shared)**:  The point object. The point name, if defined, is available through  `this.point.name`. - **this.points**:  In a shared tooltip, this is an array containing all other  properties for each point. - **this.series (not shared) / this.points[i].series (shared)**:  The series object. The series name is available through  `this.series.name`. - **this.total (not shared) / this.points[i].total (shared)**:  Stacked series only. The total value at this point's x value. - **this.x**:  The x value. This property is the same regardless of the tooltip  being shared or not. - **this.y (not shared) / this.points[i].y (shared)**:  The y value.

**Try it**

* [Simple string formatting](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-simple/)
* [Formatting with shared tooltip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-shared/)
* [Formatting with split tooltip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-split/)
* [Extending default formatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/formatter-conditional-default/)
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
The HTML of the null point's line in the tooltip. Works analogously to `pointFormat`.

**Try it**

* [Format data label and tooltip for null point.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-nullformat)
*/
@property(nonatomic, readwrite) NSString *nullFormat;
/**
The HTML of the point's line in the tooltip. Variables are enclosed by curly brackets. Available variables are point.x, point.y, series. name and series.color and other properties on the same form. Furthermore, `point.y` can be extended by the `tooltip.valuePrefix` and `tooltip.valueSuffix` variables. This can also be overridden for each series, which makes it a good hook for displaying units. In styled mode, the dot is colored by a class name rather than the point color.

**Try it**

* [A different point format with value suffix](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/pointformat/)
*/
@property(nonatomic, readwrite) NSString *pointFormat;
/**
The format for the date in the tooltip header if the X axis is a datetime axis. The default is a best guess based on the smallest distance between points in the chart.

**Try it**

* [A different format](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/xdateformat/)
*/
@property(nonatomic, readwrite) NSString *xDateFormat;
/**
For series on a datetime axes, the date format in the tooltip's header will by default be guessed based on the closest data points. This member gives the default string representations used for each unit. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) HIDateTimeLabelFormats *dateTimeLabelFormats;
/**
Padding inside the tooltip, in pixels.
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
Whether to apply a drop shadow to the tooltip.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/shadow/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;
/**
Distance from point to tooltip in pixels.

**Defaults to** `16`.
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
Enable or disable the tooltip.

**Try it**

* [Disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/enabled/)
* [Disable tooltip and show values on chart instead](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The name of a symbol to use for the border around the tooltip. Can be one of: `"callout"`, `"circle"`, or `"square"`. When `tooltip.split` option is enabled, shape is applied to all boxes except header, which is controlled by `tooltip.headerShape`. Custom callbacks for symbol path generation can also be added to `Highcharts.SVGRenderer.prototype.symbols` the same way as for `series.marker.symbol`.

**Defaults to** `callout`.
*/
@property(nonatomic, readwrite) NSString *shape;
/**
A callback function for formatting the HTML output for a single point in the tooltip. Like the `pointFormat` string, but with more flexibility.
*/
@property(nonatomic, readwrite) HIFunction *pointFormatter;
/**
A CSS class name to apply to the tooltip's container div, allowing unique CSS styling for each chart.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The pixel width of the tooltip border. In styled mode, the stroke width is set in the `.highcharts-tooltip-box` class.

**Try it**

* [2px by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/bordercolor-default/)
* [No border (shadow only)](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/borderwidth/)
* [Tooltip in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/tooltip-border-background/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Whether the tooltip should follow the mouse as it moves across columns, pie slices and other point types with an extent. By default it behaves this way for pie, polygon, map, sankey and wordcloud series by override in the `plotOptions` for those series types. For touch moves to behave the same way, `followTouchMove` must be `true` also.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *followPointer;
/**
The number of milliseconds to wait until the tooltip is hidden when mouse out from a point or chart.

**Defaults to** `500`.
*/
@property(nonatomic, readwrite) NSNumber *hideDelay;
/**
How many decimals to show in each series' y value. This is overridable in each series' tooltip options object. The default is to preserve all decimals.

**Try it**

* [Set decimals, prefix and suffix for the value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/valuedecimals/)
*/
@property(nonatomic, readwrite) NSNumber *valueDecimals;
@property(nonatomic, readwrite) NSString *nodeFormat;
/**
A callback for defining the format for _nodes_ in the chart's tooltip, as opposed to links.
*/
@property(nonatomic, readwrite) HIFunction *nodeFormatter;

-(NSDictionary *)getParams;

/**
 In case no user defined formatter is given, this will be used. Note that the context here is an object holding point, series, x, y etc.
 @param tooltip Tooltip
 */
-(void)defaultFormatter:(HITooltip *)tooltip;

/**
 Removes and destroys the tooltip and its elements.
 */
-(void)destroy;

/**
 Creates the Tooltip label element if it does not exist.
 */
-(void)getLabel;

/**
 Hides the tooltip with a fade out animation.
 */
-(void)hide;

/**
 Hides the tooltip with a fade out animation.
 @param delay The fade out in milliseconds. If no value is provided the value of the tooltip.hideDelay option is used. A value of 0 disables the fade out animation.
 */
-(void)hide:(NSNumber *)delay;

/**
 Refresh the tooltip's text and position.
 @param point A point.
 */
-(void)refreshByPoint:(HIPoint *)point;

/**
Refresh the tooltip's text and position.
@param points An array of points.
*/
-(void)refreshByPoints:(NSArray<HIPoint *> *)points;

/**
 Updates the tooltip with the provided tooltip options.
 @param options The tooltip options to update.
 */
-(void)update:(HITooltip *)options;

@end
