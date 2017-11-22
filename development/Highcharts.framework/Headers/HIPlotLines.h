/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabel.h"
#import "HIColor.h"


/**
* description: An array of objects representing plot lines on the X axis
*/
@interface HIPlotLines: HIChartsJSONSerializable

/**
* description: The z index of the plot line within the chart.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-behind/ : Behind plot lines by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-above/ : Above plot lines
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-above-all/ : Above plot lines and series
* default: null
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: A custom class name, in addition to the default highcharts-plot-
line, to apply to each individual line.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The width or thickness of the plot line.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/ : 2px wide line from X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotlines/ : Plot line on Y axis
* default: null
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: The dashing or dot style for the plot line. For possible values see
http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-
dashstyle-all/ : this overview.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-dashstyle/ : Dash and dot pattern
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotlines/ : Plot line on Y axis
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
* description: Text labels for the plot bands
*/
@property(nonatomic, readwrite) HILabel *label;
/**
* description: An id used for identifying the plot line in Axis.removePlotLine.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-id/ : Remove plot line by id
* default: null
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: An object defining mouse events for the plot line. Supported properties
are click, mouseover, mouseout, mousemove.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-events/ : Mouse events demonstrated
*/
@property(nonatomic, readwrite) id events;
/**
* description: The color of the line.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/ : A red line from X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotlines/ : Plot line on Y axis
* default: null
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: The position of the line in axis units.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/ : Between two categories on X axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotlines/ : Plot line on Y axis
* default: null
*/
@property(nonatomic, readwrite) NSNumber *value;

-(NSDictionary *)getParams;

@end
