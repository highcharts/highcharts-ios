/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDataClasses.h"
#import "HILabels.h"
#import "HIMarker.h"
#import "HIEvents.h"
#import "HIAccessibility.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
A color axis for series. Visually, the color axis will appear as a gradient or as separate items inside the legend, depending on whether the axis is scalar or based on data classes. For supported color formats, see the [docs article about colors](https://www.highcharts.com/docs/chart-design-and-style/colors). A scalar color axis is represented by a gradient. The colors either range between the `minColor` and the `maxColor`, or for more fine grained control the colors can be defined in `stops`. Often times, the color axis needs to be adjusted to get the right color spread for the data. In addition to stops, consider using a logarithmic `axis type`, or setting `min` and `max` to avoid the colors being determined by outliers. When `dataClasses` are used, the ranges are subdivided into separate classes like categories based on their values. This can be used for ranges between two values, but also for a true category. However, when your data is categorized, it may be as convenient to add each category to a separate series. Color axis does not work with: `sankey`, `sunburst`, `dependencywheel`, `networkgraph`, `wordcloud`, `venn`, `gauge` and `solidgauge` series types. Since v7.2.0 `colorAxis` can also be an array of options objects. See `the Axis object` for programmatic access to the axis.

**Try it**

* [Column chart with color axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/custom-color-key)
* [Horizontal layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/horizontal-layout)
*/
@interface HIColorAxis: HIChartsJSONSerializable

/**
An array of data classes or ranges for the choropleth map. If none given, the color axis is scalar and values are distributed as a gradient between the minimum and maximum colors.
*/
@property(nonatomic, readwrite) NSArray <HIDataClasses *> *dataClasses;
/**
Padding of the min value relative to the length of the axis. A padding of 0.05 will make a 100px axis 5px longer.

**Defaults to** `0.01`.

**Try it**

* [Min padding of 0.2](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minpadding/)
*/
@property(nonatomic, readwrite) NSNumber *minPadding;
/**
The axis labels show the number for each tick. For more live examples on label options, see `xAxis.labels in the Highcharts API.`
*/
@property(nonatomic, readwrite) HILabels *labels;
/**
The color to represent the maximum of the color axis. Unless `dataClasses` or `stops` are set, the gradient ends at this value. If dataClasses are set, the color is based on minColor and maxColor unless a color is set for each data class, or the `dataClassColor` is set.
*/
@property(nonatomic, readwrite) HIColor *maxColor;
/**
The triangular marker on a scalar color axis that points to the value of the hovered area. To disable the marker, set `marker: null`.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
The layout of the color axis. Can be `'horizontal'` or `'vertical'`. If none given, the color axis has the same layout as the legend.

**Try it**

* [Horizontal color axis layout with vertical legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/horizontal-layout/)
*/
@property(nonatomic, readwrite) NSString *layout;
/**
Whether to force the axis to start on a tick. Use this option with the `maxPadding` option to control the axis start.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startontick-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *startOnTick;
/**
Color stops for the gradient of a scalar color axis. Use this in cases where a linear gradient between a `minColor` and `maxColor` is not sufficient. The stops is an array of tuples, where the first item is a float between 0 and 1 assigning the relative position in the gradient, and the second item is the color.
*/
@property(nonatomic, readwrite) NSArray<NSArray *> /* <NSNumber, NSString> */ *stops;
/**
Determines how to set each data class' color if no individual color is set. The default value, `tween`, computes intermediate colors between `minColor` and `maxColor`. The other possible value, `category`, pulls colors from the global or chart specific `colors` array.

**Accepted values:** `["tween", "category"]`.

**Defaults to** `tween`.
*/
@property(nonatomic, readwrite) NSString *dataClassColor;
/**
Whether to force the axis to end on a tick. Use this option with the `maxPadding` option to control the axis end.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/endontick/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *endOnTick;
/**
The type of interpolation to use for the color axis. Can be `linear` or `logarithmic`.

**Defaults to** `linear`.

**Try it**

* [Logarithmic color axis with extension to emulate negative values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/logarithmic-with-emulate-negative-values/)
*/
@property(nonatomic, readwrite) NSString *type;
/**
Event handlers for the axis.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
If `tickInterval` is `null` this option sets the approximate pixel interval of the tick marks.

**Try it**

* [50 px on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpixelinterval-50/)
*/
@property(nonatomic, readwrite) NSNumber *tickPixelInterval;
/**
The maximum value of the axis in terms of map point values. If `null`, the max value is automatically calculated. If the `endOnTick` option is true, the max value might be rounded up.

**Try it**

* [Y axis max of 200](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/max-200/)
* [Y axis max on logarithmic axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/max-logarithmic/)
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
Whether to reverse the axis so that the highest number is closest to the origin. Defaults to `false` in a horizontal legend and `true` in a vertical legend, where the smallest value starts on top.

**Defaults to** `false`.

**Try it**

* [Reversed Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/reversed/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
The width of the grid lines extending from the axis across the gradient of a scalar color axis.

**Defaults to** `0`.

**Try it**

* [2px lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinewidth/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) NSNumber *gridLineWidth;
/**
The interval of the tick marks in axis units. When `null`, the tick interval is computed to approximately follow the `tickPixelInterval`.

**Try it**

* [Tick interval of 5 on a linear axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickinterval-5/)
*/
@property(nonatomic, readwrite) NSNumber *tickInterval;
/**
Color of the grid lines extending from the axis across the gradient.

**Defaults to** `#e6e6e6`.

**Try it**

* [Green lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinecolor/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) HIColor *gridLineColor;
/**
The color to represent the minimum of the color axis. Unless `dataClasses` or `stops` are set, the gradient starts at this value. If dataClasses are set, the color is based on minColor and maxColor unless a color is set for each data class, or the `dataClassColor` is set.
*/
@property(nonatomic, readwrite) HIColor *minColor;
/**
The minimum value of the axis in terms of map point values. If `null`, the min value is automatically calculated. If the `startOnTick` option is true, the min value might be rounded down.

**Try it**

* [-50 with startOnTick to false](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/min-startontick-false/)
* [-50 with startOnTick true by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/min-startontick-true/)
*/
@property(nonatomic, readwrite) NSNumber *min;
/**
Padding of the max value relative to the length of the axis. A padding of 0.05 will make a 100px axis 5px longer.

**Defaults to** `0.01`.

**Try it**

* [Max padding of 0.25 on y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/maxpadding/)
*/
@property(nonatomic, readwrite) NSNumber *maxPadding;
/**
The pixel length of the main tick marks on the color axis.

**Try it**

* [20 px tick length on the X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/ticklength/)
*/
@property(nonatomic, readwrite) NSNumber *tickLength;
/**
Whether to display the colorAxis in the legend.

**Try it**

* [Hidden color axis with 3d chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/hidden-coloraxis-with-3d-chart/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showInLegend;
/**
Color for the minor tick marks.

**Defaults to** `#999999`.

**Try it**

* [Black tick marks on Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickcolor/)
*/
@property(nonatomic, readwrite) HIColor *minorTickColor;
/**
For categorized axes only. If `on` the tick mark is placed in the center of the category, if `between` the tick mark is placed between categories. The default is `between` if the `tickInterval` is 1, else `on`.

**Accepted values:** `["on", "between"]`.

**Try it**

* ["between" by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-between/)
* ["on"](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickmarkplacement-on/)
*/
@property(nonatomic, readwrite) NSString *tickmarkPlacement;
/**
The Z index of the grid lines.

**Defaults to** `1`.

**Try it**

* [A Z index of 4 renders the grid above the graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/gridzindex/)
*/
@property(nonatomic, readwrite) NSNumber *gridZIndex;
/**
Accessibility options for an axis. Requires the accessibility module.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
/**
Whether axis, including axis title, line, ticks and labels, should be visible.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
The pixel width of the major tick marks. Defaults to 0 on category axes, otherwise 1. In styled mode, the stroke width is given in the `.highcharts-tick` class, but in order for the element to be generated on category axes, the option must be explicitly set to 1.

**Try it**

* [10 px width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickwidth/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) NSNumber *tickWidth;
/**
Whether to show the first tick label.

**Defaults to** `true`.

**Try it**

* [Set to false on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showfirstlabel-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showFirstLabel;
/**
For datetime axes, this decides where to put the tick between weeks. 0 = Sunday, 1 = Monday.

**Try it**

* [Monday by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-monday/)
* [Sunday](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/startofweek-sunday/)
*/
@property(nonatomic, readwrite) NSNumber *startOfWeek;
/**
An id for the axis. This can be used after render time to get a pointer to the axis object through `chart.get()`.

**Try it**

* [Get the object](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/id/)
*/
@property(nonatomic, readwrite) NSString *id;
/**
An array defining where the ticks are laid out on the axis. This overrides the default behaviour of `tickPixelInterval` and `tickInterval`.

**Try it**

* [Demo of tickPositions and tickPositioner](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/)
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *tickPositions;
/**
In a polar chart, this is the angle of the Y axis in degrees, where 0 is up and 90 is right. The angle determines the position of the axis line and the labels, though the coordinate system is unaffected. Since v8.0.0 this option is also applicable for X axis (inverted polar).

**Defaults to** `0`.

**Try it**

* [Custom X axis' angle on inverted polar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/angle/)
* [Dual axis polar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/angle/)
*/
@property(nonatomic, readwrite) NSNumber *angle;
/**
The lowest allowed value for automatically computed axis extremes.

**Try it**

* [Floor and ceiling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/)
*/
@property(nonatomic, readwrite) NSNumber *floor;
/**
Color of the minor, secondary grid lines. In styled mode, the stroke width is given in the `.highcharts-minor-grid-line` class.

**Defaults to** `#f2f2f2`.

**Try it**

* [Bright grey lines from Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinecolor/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) HIColor *minorGridLineColor;
/**
A callback function returning array defining where the ticks are laid out on the axis. This overrides the default behaviour of `tickPixelInterval` and `tickInterval`. The automatic tick positions are accessible through `this.tickPositions` and can be modified by the callback.

**Try it**

* [Demo of tickPositions and tickPositioner](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickpositions-tickpositioner/)
*/
@property(nonatomic, readwrite) HIFunction *tickPositioner;
/**
The dash or dot style of the minor grid lines. For possible values, see [this demonstration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/).

**Defaults to** `Solid`.

**Try it**

* [Long dashes on minor grid lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinedashstyle/)
*/
@property(nonatomic, readwrite) NSString *minorGridLineDashStyle;
/**
The pixel length of the minor tick marks.

**Try it**

* [10px on Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorticklength/)
*/
@property(nonatomic, readwrite) NSNumber *minorTickLength;
/**
Datetime axis only. An array determining what time intervals the ticks are allowed to fall on. Each array item is an array where the first value is the time unit and the second value another array of allowed multiples. Defaults to: ```js units: [[   'millisecond', // unit name   [1, 2, 5, 10, 20, 25, 50, 100, 200, 500] // allowed multiples ], [   'second',   [1, 2, 5, 10, 15, 30] ], [   'minute',   [1, 2, 5, 10, 15, 30] ], [   'hour',   [1, 2, 3, 4, 6, 8, 12] ], [   'day',   [1] ], [   'week',   [1] ], [   'month',   [1, 3, 6] ], [   'year',   null ]] ```
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *units;
/**
A soft minimum for the axis. If the series data minimum is greater than this, the axis will stay at this minimum, but if the series data minimum is lower, the axis will flex to show all data.

**Try it**

* [Soft min and max](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/)
*/
@property(nonatomic, readwrite) NSNumber *softMin;
/**
Polar charts only. Whether the grid lines should draw as a polygon with straight lines between categories, or as circles. Can be either `circle` or `polygon`. Since v8.0.0 this option is also applicable for X axis (inverted polar).

**Accepted values:** `["circle", "polygon"]`.

**Try it**

* [Polygon grid lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polar-spider/)
* [Circle and polygon on inverted polar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/gridlineinterpolation/)
* [Circle and polygon](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlineinterpolation/)
*/
@property(nonatomic, readwrite) NSString *gridLineInterpolation;
/**
The highest allowed value for automatically computed axis extremes.

**Try it**

* [Floor and ceiling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/floor-ceiling/)
*/
@property(nonatomic, readwrite) NSNumber *ceiling;
/**
The dash or dot style of the grid lines. For possible values, see [this demonstration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/).

**Defaults to** `Solid`.

**Try it**

* [Long dashes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/gridlinedashstyle/)
*/
@property(nonatomic, readwrite) NSString *gridLineDashStyle;
/**
The position of the minor tick marks relative to the axis line. Can be one of `inside` and `outside`.

**Accepted values:** `["inside", "outside"]`.

**Try it**

* [Outside by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-outside/)
* [Inside](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickposition-inside/)
*/
@property(nonatomic, readwrite) NSString *minorTickPosition;
/**
Enable or disable minor ticks. Unless `minorTickInterval` is set, the tick interval is calculated as a fifth of the `tickInterval`. On a logarithmic axis, minor ticks are laid out based on a best guess, attempting to enter approximately 5 minor ticks between each major tick. Prior to v6.0.0, ticks were unabled in auto layout by setting `minorTickInterval` to `"auto"`.

**Defaults to** `false`.

**Try it**

* [Enabled on linear Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorticks-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *minorTicks;
/**
The pixel width of the minor tick mark.

**Defaults to** `0`.

**Try it**

* [3px width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickwidth/)
*/
@property(nonatomic, readwrite) NSNumber *minorTickWidth;
/**
A soft maximum for the axis. If the series data maximum is less than this, the axis will stay at this maximum, but if the series data maximum is higher, the axis will flex to show all data.

**Try it**

* [Soft min and max](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/softmin-softmax/)
*/
@property(nonatomic, readwrite) NSNumber *softMax;
/**
Color for the main tick marks. In styled mode, the stroke is given in the `.highcharts-tick` class.

**Defaults to** `#ccd6eb`.

**Try it**

* [Red ticks on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickcolor/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) HIColor *tickColor;
/**
The position of the major tick marks relative to the axis line. Can be one of `inside` and `outside`.

**Accepted values:** `["inside", "outside"]`.

**Try it**

* ["outside" by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-outside/)
* ["inside"](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/tickposition-inside/)
*/
@property(nonatomic, readwrite) NSString *tickPosition;
/**
Whether to show the last tick label. Defaults to `true` on cartesian charts, and `false` on polar charts.

**Defaults to** `true`.

**Try it**

* [Set to true on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/showlastlabel-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showLastLabel;
/**
Applies only when the axis `type` is `category`. When `uniqueNames` is true, points are placed on the X axis according to their names. If the same point name is repeated in the same or another series, the point is placed on the same X position as other points of the same name. When `uniqueNames` is false, the points are laid out in increasing X positions regardless of their names, and the X axis category will take the name of the last point in each position.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/uniquenames-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *uniqueNames;
/**
A class name that opens for styling the axis by CSS, especially in Highcharts styled mode. The class name is applied to group elements for the grid, axis elements and labels.

**Try it**

* [Multiple axes with separate styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
The amount of ticks to draw on the axis. This opens up for aligning the ticks of multiple charts or panes within a chart. This option overrides the `tickPixelInterval` option. This option only has an effect on linear axes. Datetime, logarithmic or category axes are not affected.

**Try it**

* [8 ticks on Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/tickamount/)
*/
@property(nonatomic, readwrite) NSNumber *tickAmount;
/**
The color of the line marking the axis itself. In styled mode, the line stroke is given in the `.highcharts-axis-line` or `.highcharts-xaxis-line` class.

**Defaults to** `#ccd6eb`.

**Try it**

* [A red line on Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/linecolor/)
* [Axes in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
Width of the minor, secondary grid lines. In styled mode, the stroke width is given in the `.highcharts-grid-line` class.

**Try it**

* [2px lines from Y axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minorgridlinewidth/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/axis-grid/)
*/
@property(nonatomic, readwrite) NSNumber *minorGridLineWidth;
/**
Specific tick interval in axis units for the minor ticks. On a linear axis, if `"auto"`, the minor tick interval is calculated as a fifth of the tickInterval. If `null` or `undefined`, minor ticks are not shown. On logarithmic axes, the unit is the power of the value. For example, setting the minorTickInterval to 1 puts one tick on each of 0.1, 1, 10, 100 etc. Setting the minorTickInterval to 0.1 produces 9 ticks between 1 and 10, 10 and 100 etc. If user settings dictate minor ticks to become too dense, they don't make sense, and will be ignored to prevent performance problems.

**Try it**

* [Null by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-null/)
* [5 units](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-5/)
* ["auto"](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log-auto/)
* [0.1](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/minortickinterval-log/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ minorTickInterval;
/**
If there are multiple axes on the same side of the chart, the pixel margin between the axes. Defaults to 0 on vertical axes, 15 on horizontal axes.
*/
@property(nonatomic, readwrite) NSNumber *margin;

-(NSDictionary *)getParams;

@end
