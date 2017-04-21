/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartOptions3d.h"
#import "HIChartEvents.h"
#import "HIChartResetZoomButton.h"
#import "HIColor.h"


/**
* description: Options regarding the chart area and plot area as well as general chart options.
*/
@interface HIChart: HIChartsJSONSerializable

/**
* description: The pixel width of the outer chart border.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/borderwidth/ : 5px border
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Alias of type.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/defaultseriestype/ : Bar
* accepted values: ["line", "spline", "column", "area", "areaspline", "pie"]
* default: line
*/
@property(nonatomic, readwrite) NSString *defaultSeriesType;
/**
* description: Options to render charts in 3 dimensions. This feature requires highcharts-3d.js, found in the download package or online at http://code.highcharts.com/highcharts-3d.js : code.highcharts.com/highcharts-3d.js.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/column/ : Basic 3D columns, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-pie/ : basic 3D pie, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter/ : basic 3D scatter chart.
*/
@property(nonatomic, readwrite) HIChartOptions3d *options3d;
/**
* description: A text description of the chart type.
If the Accessibility module is loaded, this will be included in the description of the chart in the screen reader information region.
Highcharts will by default attempt to guess the chart type, but for more complex charts it is recommended to specify this property for clarity.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/accessibility/advanced-accessible/ : Accessible complex chart
* default: undefined
*/
@property(nonatomic, readwrite) NSString *typeDescription;
/**
* description: Set the overall animation for all chart updating. Animation can be disabled throughout
 the chart by setting it to false here. It can be overridden for each individual
 API method as a function parameter. The only animation not affected by this option is the 
 initial series animation, see plotOptions.series.animation.
The animation can either be set as a boolean or a configuration object. If true,
 it will use the 'swing' jQuery easing and a duration of 500 ms. If used as a configuration object,
 the following properties are supported: 
 
duration
The duration of the animation in milliseconds.
easing
A string reference to an easing function set on the Math object. See http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/ : the easing demo.

* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-none/ : Updating with no animation, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-duration/ : with a longer duration,  
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/animation-easing/ : with a jQuery UI easing.
* default: true
*/
@property(nonatomic, readwrite) id /* Bool, Object */ animation;
/**
* description: The URL for an image to use as the plot background. To set an image as the background for the entire chart, set a CSS background image to the container element. Note that for the image to be applied to exported charts, its URL needs to be accessible by the export server.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundimage/ : Skies
*/
@property(nonatomic, readwrite) NSString *plotBackgroundImage;
/**
* description: The corner radius of the outer chart border.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/borderradius/ : 20px radius
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: The margin between the outer edge of the chart and the plot area. The numbers in the array designate top, right, bottom and left respectively. Use the options marginTop, marginRight, marginBottom and marginLeft for shorthand setting of one option. Since version 2.1, the margin is 0 by default. The actual space is dynamically calculated  from the offset of axis labels, axis title, title, subtitle and legend in addition to the spacingTop, spacingRight, spacingBottom and spacingLeft options.
		 Defaults to [null].
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/margins-zero/ : Zero margins
*/
@property(nonatomic, readwrite) NSArray *margin;
/**
* description: The pixel width of the plot area border.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotborderwidth/ : 1px border
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *plotBorderWidth;
/**
* description: The margin between the left outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingLeft.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/marginleft/ : 150px left margin
*/
@property(nonatomic, readwrite) NSNumber *marginLeft;
/**
* description: Allows setting a key to switch between zooming and panning. Can be one of alt, ctrl, meta (the command key on Mac and Windows key on Windows) or shift. The keys are mapped directly to the key properties of the click event argument (event.altKey, event.ctrlKey, event.metaKey and event.shiftKey).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/pankey/ : Hold down 
* accepted values: [null, "alt", "ctrl", "meta", "shift"]
*/
@property(nonatomic, readwrite) NSString *panKey;
/**
* description: An explicit width for the chart. By default (when null) the width is calculated from the offset width of the containing element.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/width/ : 800px wide
* default: null
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: Event listeners for the chart.
*/
@property(nonatomic, readwrite) HIChartEvents *events;
/**
* description: Whether to show the axes initially. This only applies to empty charts where series are added dynamically, as axes are automatically added to cartesian series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/showaxes-false/ : False by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/showaxes-true/ : true
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showAxes;
/**
* description: Whether to apply a drop shadow to the outer chart area. Requires that  backgroundColor be set. Since 2.3 the shadow can be an object configuration containing color, offsetX, offsetY, opacity and width.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/shadow/ : Shadow
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, Object */ shadow;
/**
* description: The background color or gradient for the plot area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundcolor-color/ : Color,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbackgroundcolor-gradient/ : gradient
*/
@property(nonatomic, readwrite) HIColor *plotBackgroundColor;
/**
* description: The color of the inner chart or plot area border.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotbordercolor/ : Blue border
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *plotBorderColor;
/**
* description: Allow panning in a chart. Best used with panKey to combine zooming and panning.
On touch devices, when the tooltip.followTouchMove option is true (default), panning requires two fingers. To allow panning with one finger, set followTouchMove to false.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/pankey/ : Zooming and panning
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *panning;
/**
* description: The background color or gradient for the outer chart area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/backgroundcolor-color/ : Color,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/backgroundcolor-gradient/ : gradient
* default: #FFFFFF
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: A text description of the chart.
If the Accessibility module is loaded, this is included by default as a long description of the chart and its contents in the hidden screen reader information region.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/accessibility/accessible-line/ : Accessible line chart
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: The HTML element where the chart will be rendered. If it is a string, the element by that id is used. The HTML element can also be passed by direct reference.
When using the Highcharts.chart constructor, the renderTo is given as a parameter, and can be skipped in the options set.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : String,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/renderto-object/ : object reference,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/renderto-jquery/ : object reference through jQuery,
*/
@property(nonatomic, readwrite) id /* NSString, id */ renderTo;
/**
* description: Whether to invert the axes so that the x axis is vertical and y axis is horizontal. When true, the x axis is reversed by default. If a bar series is present in the chart, it will be inverted automatically.
Inverting the chart doesn't have an effect if there are no cartesian series in the chart, or if the chart is polar.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/inverted/ : Inverted line
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *inverted;
/**
* description: When true, cartesian charts like line, spline, area and column are transformed into the polar coordinate system. Requires highcharts-more.js.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/polar-line/ : Polar line, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/polar-area/ : polar area, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/polar-column/ : polar column, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/polar/ : combined series types, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/polar-spider/ : spider chart, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/polar-wind-rose/ : wind rose.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *polar;
/**
* description: Equivalent to zoomType, but for multitouch gestures only. By default, the pinchType is the same as the zoomType setting. However, pinching can be enabled separately in some cases, for example in stock charts where a mouse drag pans the chart, while pinching is enabled. When tooltip.followTouchMove is true, pinchType only applies to two-finger touches.
* accepted values: ["x", "y", "xy"]
* default: null
*/
@property(nonatomic, readwrite) NSString *pinchType;
/**
* description: The margin between the bottom outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingBottom.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/marginbottom/ : 100px bottom margin
*/
@property(nonatomic, readwrite) NSNumber *marginBottom;
/**
* description: The margin between the right outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingRight.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/marginright/ : 100px right margin
*/
@property(nonatomic, readwrite) NSNumber *marginRight;
/**
* description: In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, this sets how many colors the class names should rotate between. With ten colors, series (or points) are given class names like highcharts-color-0, highcharts-color-0 [...] highcharts-color-9. The equivalent in non-styled mode is to set colors using the colors setting.
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *colorCount;
/**
* description: The distance between the outer edge of the chart and the content, like title, legend, axis title or labels. The numbers in the array designate top, right, bottom and left respectively. Use the options spacingTop, spacingRight, spacingBottom and spacingLeft options for shorthand setting of one option.
* default: [10, 10, 15, 10]
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *spacing;
/**
* description: The color of the outer chart border.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/bordercolor/ : Brown border
* default: #335cad
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: When using multiple axis, the ticks of two or more opposite axes will  automatically be aligned by adding ticks to the axis or axes with the least ticks, as if tickAmount were specified.
This can be prevented by setting alignTicks to false. If the grid lines look messy, it's a good idea to hide them for the secondary axis by setting gridLineWidth to 0.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/alignticks-true/ : True by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/alignticks-false/ : false.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alignTicks;
/**
* description: An explicit height for the chart. By default (when null) the height is calculated from the offset height of the containing element, or 400 pixels if the containing element's height is 0.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/height/ : 500px height
* default: null
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
* description: Whether to reflow the chart to fit the width of the container div on resizing the window.
* demo: Move the bar between the JavaScript frame and the Preview frame to see the effect: 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : True by default, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-false/ : false.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reflow;
/**
* description: If true, the axes will scale to the remaining visible series once one series is hidden. If false, hiding and showing a series will not affect the axes or the other series. For stacks, once one series within the stack is hidden, the rest of the stack will close in around it even if the axis is not affected.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-true/ : True by default
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-false/ : false,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/ignorehiddenseries-true-stacked/ : true with stack
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenSeries;
/**
* description: The default series type for the chart. Can be any of the chart types listed under plotOptions.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/type-bar/ : Bar
* accepted values: ["line", "spline", "column", "bar", "area", "areaspline", "pie", "arearange", "areasplinerange", "boxplot", "bubble", "columnrange", "errorbar", "funnel", "gauge", "heatmap", "polygon", "pyramid", "scatter", "solidgauge", "treemap", "waterfall"]
* default: line
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: The space between the top edge of the chart and the content (plot area, axis title and labels, title, subtitle or 
 legend in top position).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingtop-100/ : A top spacing of 100,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingtop-10/ : floating chart title makes the plot area align to the 
			default spacingTop of 10..
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *spacingTop;
/**
* description: The space between the bottom edge of the chart and the content (plot area, axis title and labels, title, subtitle or  legend in top position).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingbottom/ : Spacing bottom set to 100.
* default: 15
*/
@property(nonatomic, readwrite) NSNumber *spacingBottom;
/**
* description: The space between the right edge of the chart and the content (plot area, axis title and labels, title, subtitle or  legend in top position).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingright-100/ : Spacing set to 100,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingright-legend/ : legend in right position with default spacing
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *spacingRight;
/**
* description: The margin between the top outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingTop.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/margintop/ : 100px top margin
*/
@property(nonatomic, readwrite) NSNumber *marginTop;
/**
* description: A CSS class name to apply to the charts container div, allowing unique CSS styling for each chart.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The space between the left edge of the chart and the content (plot area, axis title and labels, title, subtitle or  legend in top position).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/spacingleft/ : Spacing left set to 100
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *spacingLeft;
/**
* description: Whether to apply a drop shadow to the plot area. Requires that plotBackgroundColor be set. Since 2.3 the shadow can be an object configuration containing color, offsetX, offsetY, opacity and width.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/plotshadow/ : Plot shadow
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, Object */ plotShadow;
/**
* description: Decides in what dimensions the user can zoom by dragging the mouse. Can be one of x, y or xy.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-none/ : None by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-x/ : x,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-y/ : y,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-xy/ : xy
* accepted values: [null, "x", "y", "xy"]
*/
@property(nonatomic, readwrite) NSString *zoomType;
/**
* description: The button that appears after a selection zoom, allowing the user to reset zoom.
*/
@property(nonatomic, readwrite) HIChartResetZoomButton *resetZoomButton;
/**
* description: The background color of the marker square when selecting (zooming in on) an area of the chart.
* default: rgba(51,92,173,0.25)
*/
@property(nonatomic, readwrite) HIColor *selectionMarkerFill;
/**
* description: Additional CSS styles to apply inline to the container div. Note that since the default font styles are applied in the renderer, it is ignorant of the individual chart  options and must be set globally.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/style-serif-font/ : Using a serif type font.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/em/ : Styled mode with relative font sizes.

* default: {"fontFamily":"\"Lucida Grande\", \"Lucida Sans Unicode\", Verdana, Arial, Helvetica, sans-serif","fontSize":"12px"}
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;

-(NSDictionary *)getParams;

@end
