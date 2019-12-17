/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIParallelAxes.h"
#import "HIPanning.h"
#import "HIOptions3d.h"
#import "HIEvents.h"
#import "HIScrollablePlotArea.h"
#import "HIResetZoomButton.h"
#import "HIColor.h"
#import "HIAnimationOptionsObject.h"
#import "HICSSObject.h"
#import "HIFunction.h"


/**
General options for the chart.
*/
@interface HIChart: HIChartsJSONSerializable

/**
Common options for all yAxes rendered in a parallel coordinates plot. This feature requires `modules/parallel-coordinates.js`. The default options are: ```js parallelAxes: {  lineWidth: 1,    // classic mode only  gridlinesWidth: 0, // classic mode only  title: {    text: '',    reserveSpace: false  },  labels: {    x: 0,    y: 0,    align: 'center',    reserveSpace: false  },  offset: 0 } ```

**Try it**

* [Set the same tickAmount for all yAxes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/parallel-coordinates/parallelaxes/)
*/
@property(nonatomic, readwrite) HIParallelAxes *parallelAxes;
/**
The corner radius of the outer chart border.

**Try it**

* [20px radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/borderradius/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
The space between the bottom edge of the chart and the content (plot area, axis title and labels, title, subtitle or legend in top position).

**Defaults to** `15`.

**Try it**

* [Spacing bottom set to 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingbottom/)
*/
@property(nonatomic, readwrite) NSNumber *spacingBottom;
/**
Whether to apply a drop shadow to the plot area. Requires that plotBackgroundColor be set. The shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Plot shadow](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotshadow/)
*/
@property(nonatomic, readwrite) HICSSObject *plotShadow;
/**
An explicit height for the chart. If a _number_, the height is given in pixels. If given a _percentage string_ (for example `'56%'`), the height is given as the percentage of the actual chart width. This allows for preserving the aspect ratio across responsive sizes. By default (when `null`) the height is calculated from the offset height of the containing element, or 400 pixels if the containing element's height is 0.

**Try it**

* [500px height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/height/)
* [Highcharts with percentage height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/height-percent/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ height;
/**
When using multiple axis, the ticks of two or more opposite axes will automatically be aligned by adding ticks to the axis or axes with the least ticks, as if `tickAmount` were specified. This can be prevented by setting `alignTicks` to false. If the grid lines look messy, it's a good idea to hide them for the secondary axis by setting `gridLineWidth` to 0. If `startOnTick` or `endOnTick` in an Axis options are set to false, then the `alignTicks ` will be disabled for the Axis. Disabled for logarithmic axes.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/alignticks-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/alignticks-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alignTicks;
/**
Whether to display errors on the chart. When `false`, the errors will be shown only in the console.

**Try it**

* [Show errors on chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/display-errors/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *displayErrors;
/**
The margin between the right outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also `spacingRight`.

**Try it**

* [100px right margin](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/marginright/)
*/
@property(nonatomic, readwrite) NSNumber *marginRight;
/**
The color of the inner chart or plot area border.

**Try it**

* [Blue border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbordercolor/)
*/
@property(nonatomic, readwrite) HIColor *plotBorderColor;
/**
The space between the right edge of the chart and the content (plot area, axis title and labels, title, subtitle or legend in top position).

**Defaults to** `10`.

**Try it**

* [Spacing set to 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingright-100/)
* [Legend in right position with default spacing](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingright-legend/)
*/
@property(nonatomic, readwrite) NSNumber *spacingRight;
/**
The color of the outer chart border.

**Try it**

* [Brown border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
A CSS class name to apply to the charts container `div`, allowing unique CSS styling for each chart.
*/
@property(nonatomic, readwrite) NSString *className;
/**
When true, cartesian charts like line, spline, area and column are transformed into the polar coordinate system. This produces _polar charts_, also known as _radar charts_.

**Defaults to** `false`.

**Try it**

* [Polar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polar/)
* [Wind rose, stacked polar column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polar-wind-rose/)
* [Spider web chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polar-spider/)
* [Star plot, multivariate data in a polar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/parallel-coordinates/polar/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *polar;
/**
The HTML element where the chart will be rendered. If it is a string, the element by that id is used. The HTML element can also be passed by direct reference, or as the first argument of the chart constructor, in which case the option is not needed.

**Try it**

* [String](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/)
* [Object reference](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/renderto-object/)
* [Object reference through jQuery](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/renderto-jquery/)
*/
@property(nonatomic, readwrite) NSString *renderTo;
/**
Whether to reflow the chart to fit the width of the container div on resizing the window.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reflow;
/**
Decides in what dimensions the user can zoom by dragging the mouse. Can be one of `x`, `y` or `xy`.

**Accepted values:** `["x", "y", "xy"]`.

**Try it**

* [None by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-none/)
* [X](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-x/)
* [Y](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-y/)
* [Xy](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-xy/)
*/
@property(nonatomic, readwrite) NSString *zoomType;
/**
The space between the top edge of the chart and the content (plot area, axis title and labels, title, subtitle or legend in top position).

**Defaults to** `10`.

**Try it**

* [A top spacing of 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingtop-100/)
* [Floating chart title makes the plot area align to the default spacingTop of 10.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingtop-10/)
*/
@property(nonatomic, readwrite) NSNumber *spacingTop;
/**
The margin between the bottom outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also `spacingBottom`.

**Try it**

* [100px bottom margin](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/marginbottom/)
*/
@property(nonatomic, readwrite) NSNumber *marginBottom;
/**
An explicit width for the chart. By default (when `null`) the width is calculated from the offset width of the containing element.

**Try it**

* [800px wide](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/width/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ width;
/**
The margin between the left outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also `spacingLeft`.

**Try it**

* [150px left margin](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/marginleft/)
*/
@property(nonatomic, readwrite) NSNumber *marginLeft;
/**
The background color or gradient for the plot area.

**Try it**

* [Color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundcolor-color/)
* [Gradient](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundcolor-gradient/)
*/
@property(nonatomic, readwrite) HIColor *plotBackgroundColor;
/**
The background color or gradient for the outer chart area.

**Try it**

* [Color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/backgroundcolor-color/)
* [Gradient](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/backgroundcolor-gradient/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
Allow panning in a chart. Best used with `panKey` to combine zooming and panning. On touch devices, when the `tooltip.followTouchMove` option is `true` (default), panning requires two fingers. To allow panning with one finger, set `followTouchMove` to `false`.

**Try it**

* [Zooming and panning](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/pankey/)
*/
@property(nonatomic, readwrite) HIPanning *panning;
/**
Options to render charts in 3 dimensions. This feature requires `highcharts-3d.js`, found in the download package or online at [https://code.highcharts.com/highcharts-3d.js](http://code.highcharts.com/highcharts-3d.js).
*/
@property(nonatomic, readwrite) HIOptions3d *options3d;
/**
The default series type for the chart. Can be any of the chart types listed under `plotOptions` and `series` or can be a series provided by an additional module. In TypeScript this option has no effect in sense of typing and instead the `type` option must always be set in the series.

**Defaults to** `line`.

**Try it**

* [Bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/type-bar/)
*/
@property(nonatomic, readwrite) NSString *type;
/**
Event listeners for the chart.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
The space between the left edge of the chart and the content (plot area, axis title and labels, title, subtitle or legend in top position).

**Defaults to** `10`.

**Try it**

* [Spacing left set to 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingleft/)
*/
@property(nonatomic, readwrite) NSNumber *spacingLeft;
/**
The distance between the outer edge of the chart and the content, like title or legend, or axis title and labels if present. The numbers in the array designate top, right, bottom and left respectively. Use the options spacingTop, spacingRight, spacingBottom and spacingLeft options for shorthand setting of one option.

**Defaults to** `[10, 10, 15, 10]`.
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *spacing;
/**
Allows setting a key to switch between zooming and panning. Can be one of `alt`, `ctrl`, `meta` (the command key on Mac and Windows key on Windows) or `shift`. The keys are mapped directly to the key properties of the click event argument (`event.altKey`, `event.ctrlKey`, `event.metaKey` and `event.shiftKey`).

**Accepted values:** `["alt", "ctrl", "meta", "shift"]`.
*/
@property(nonatomic, readwrite) NSString *panKey;
/**
Additional CSS styles to apply inline to the container `div`. Note that since the default font styles are applied in the renderer, it is ignorant of the individual chart options and must be set globally.

**Defaults to** `{"fontFamily": "\"Lucida Grande\", \"Lucida Sans Unicode\", Verdana, Arial, Helvetica, sans-serif","fontSize":"12px"}`.

**Try it**

* [Using a serif type font](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/style-serif-font/)
* [Styled mode with relative font sizes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/em/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
Options for a scrollable plot area. This feature provides a minimum size for the plot area of the chart. If the size gets smaller than this, typically on mobile devices, a native browser scrollbar is presented. This scrollbar provides smooth scrolling for the contents of the plot area, whereas the title, legend and unaffected axes are fixed. Since v7.1.2, a scrollable plot area can be defined for either horizontal or vertical scrolling, depending on whether the `minWidth` or `minHeight` option is set.

**Try it**

* [Scrollable plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea)
* [Vertically scrollable plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea-vertical)
*/
@property(nonatomic, readwrite) HIScrollablePlotArea *scrollablePlotArea;
/**
Whether to apply a drop shadow to the outer chart area. Requires that backgroundColor be set. The shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Shadow](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/shadow/)
*/
@property(nonatomic, readwrite) HICSSObject *shadow;
/**
Whether to invert the axes so that the x axis is vertical and y axis is horizontal. When `true`, the x axis is `reversed` by default.

**Defaults to** `false`.

**Try it**

* [Inverted line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/inverted/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *inverted;
/**
Set the overall animation for all chart updating. Animation can be disabled throughout the chart by setting it to false here. It can be overridden for each individual API method as a function parameter. The only animation not affected by this option is the initial series animation, see `plotOptions.series.animation`. The animation can either be set as a boolean or a configuration object. If `true`, it will use the 'swing' jQuery easing and a duration of 500 ms. If used as a configuration object, the following properties are supported: - **duration**: The duration of the animation in milliseconds. - **easing**: A string reference to an easing function set on the  `Math` object. See  [the easing demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/).

**Defaults to** `true`.

**Try it**

* [Updating with no animation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-none/)
* [With a longer duration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-duration/)
* [With a jQuery UI easing](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-easing/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
The pixel width of the plot area border.

**Defaults to** `0`.

**Try it**

* [1px border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotborderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *plotBorderWidth;
/**
Set a key to hold when dragging to zoom the chart. This is useful to avoid zooming while moving points. Should be set different than `chart.panKey`.

**Accepted values:** `["alt", "ctrl", "meta", "shift"]`.
*/
@property(nonatomic, readwrite) NSString *zoomKey;
/**
If true, the axes will scale to the remaining visible series once one series is hidden. If false, hiding and showing a series will not affect the axes or the other series. For stacks, once one series within the stack is hidden, the rest of the stack will close in around it even if the axis is not affected.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-true/)
* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-false/)
* [True with stack](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-true-stacked/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenSeries;
/**
The background color of the marker square when selecting (zooming in on) an area of the chart.

**Defaults to** `rgba(51,92,173,0.25)`.
*/
@property(nonatomic, readwrite) HIColor *selectionMarkerFill;
/**
The URL for an image to use as the plot background. To set an image as the background for the entire chart, set a CSS background image to the container element. Note that for the image to be applied to exported charts, its URL needs to be accessible by the export server.

**Try it**

* [Skies](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundimage/)
*/
@property(nonatomic, readwrite) NSString *plotBackgroundImage;
/**
Callback function to override the default function that formats all the numbers in the chart. Returns a string with the formatted number.

**Try it**

* [Arabic digits in Highcharts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/highcharts-numberformat)
*/
@property(nonatomic, readwrite) HIFunction *numberFormatter;
/**
Equivalent to `zoomType`, but for multitouch gestures only. By default, the `pinchType` is the same as the `zoomType` setting. However, pinching can be enabled separately in some cases, for example in stock charts where a mouse drag pans the chart, while pinching is enabled. When `tooltip.followTouchMove` is true, pinchType only applies to two-finger touches.

**Accepted values:** `["x", "y", "xy"]`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *pinchType;
/**
In styled mode, this sets how many colors the class names should rotate between. With ten colors, series (or points) are given class names like `highcharts-color-0`, `highcharts-color-0` `...] `highcharts-color-9`. The equivalent in non-styled mode is to set colors using the [colors` setting.
*/
@property(nonatomic, readwrite) NSNumber *colorCount;
/**
Flag to render charts as a parallel coordinates plot. In a parallel coordinates plot (||-coords) by default all required yAxes are generated and the legend is disabled. This feature requires `modules/parallel-coordinates.js`.

**Try it**

* [Parallel coordinates demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples//highcharts/demo/parallel-coordinates/)
* [Star plot, multivariate data in a polar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/parallel-coordinates/polar/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *parallelCoordinates;
/**
The button that appears after a selection zoom, allowing the user to reset zoom.
*/
@property(nonatomic, readwrite) HIResetZoomButton *resetZoomButton;
/**
Whether to show the axes initially. This only applies to empty charts where series are added dynamically, as axes are automatically added to cartesian series.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/showaxes-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/showaxes-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showAxes;
/**
The pixel width of the outer chart border.

**Defaults to** `0`.

**Try it**

* [5px border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The margin between the top outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also `spacingTop`.

**Try it**

* [100px top margin](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/margintop/)
*/
@property(nonatomic, readwrite) NSNumber *marginTop;
/**
The margin between the outer edge of the chart and the plot area. The numbers in the array designate top, right, bottom and left respectively. Use the options `marginTop`, `marginRight`, `marginBottom` and `marginLeft` for shorthand setting of one option. By default there is no margin. The actual space is dynamically calculated from the offset of axis labels, axis title, title, subtitle and legend in addition to the `spacingTop`, `spacingRight`, `spacingBottom` and `spacingLeft` options.

**Try it**

* [Zero margins](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/margins-zero/)
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *margin;
/**
Whether to apply styled mode. When in styled mode, no presentational attributes or CSS are applied to the chart SVG. Instead, CSS rules are required to style the chart. The default style sheet is available from `https://code.highcharts.com/css/highcharts.css`.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *styledMode;

-(NSDictionary *)getParams;

@end
