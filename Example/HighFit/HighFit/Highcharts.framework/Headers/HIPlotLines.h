/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabel.h"
#import "HIEvents.h"
#import "HIColor.h"


/**
An array of objects representing plot lines on the X axis

**Try it**

* [Basic plot line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/)
* [Solid gauge plot line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-solidgauge/labels-auto-aligned/)
*/
@interface HIPlotLines: HIChartsJSONSerializable

/**
The z index of the plot line within the chart.

**Try it**

* [Behind plot lines by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-behind/)
* [Above plot lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-above/)
* [Above plot lines and series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-zindex-above-all/)
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The dashing or dot style for the plot line. For possible values see [this overview](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/).

**Defaults to** `Solid`.

**Try it**

* [Dash and dot pattern](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-dashstyle/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
The color of the line.

**Defaults to** `#999999`.

**Try it**

* [A red line from X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Text labels for the plot bands
*/
@property(nonatomic, readwrite) HILabel *label;
/**
The position of the line in axis units.

**Try it**

* [Between two categories on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/)
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
An object defining mouse events for the plot line. Supported properties are `click`, `mouseover`, `mouseout`, `mousemove`.

**Try it**

* [Mouse events demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-events/)
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
A custom class name, in addition to the default `highcharts-plot-line`, to apply to each individual line.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The width or thickness of the plot line.

**Defaults to** `2`.

**Try it**

* [2px wide line from X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-color/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
An id used for identifying the plot line in Axis.removePlotLine.

**Try it**

* [Remove plot line by id](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-id/)
*/
@property(nonatomic, readwrite) NSString *id;

-(NSDictionary *)getParams;

/**
 Remove the plot line.
 */
-(void)destroy;

@end
