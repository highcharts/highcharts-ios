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
An array of objects defining plot bands on the Y axis.
*/
@interface HIPlotBands: HIChartsJSONSerializable

/**
In a gauge chart, this option determines the outer radius of the plot band that stretches along the perimeter. It can be given as a percentage string, like `"100%"`, or as a pixel number, like `100`.

**Defaults to** `100%`.

**Try it**

* [Gauge plot band](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ outerRadius;
/**
In a gauge chart, this option determines the inner radius of the plot band that stretches along the perimeter. It can be given as a percentage string, like `"100%"`, or as a pixel number, like `100`. By default, the inner radius is controlled by the `thickness` option.

**Try it**

* [Gauge plot band](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;
/**
In a gauge chart, this option sets the width of the plot band stretching along the perimeter. It can be given as a percentage string, like `"10%"`, or as a pixel number, like `10`. The default value 10 is the same as the default `tickLength`, thus making the plot band act as a background for the tick markers.

**Defaults to** `10`.

**Try it**

* [Gauge plot band](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ thickness;
/**
Border color for the plot band. Also requires `borderWidth` to be set.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The z index of the plot band within the chart, relative to other elements. Using the same z index as another element may give unpredictable results, as the last rendered element will be on top. Values from 0 to 20 make sense.

**Try it**

* [Behind plot lines by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/)
* [Above plot lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex/)
* [Above plot lines and series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex-above-series/)
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The start position of the plot band in axis units.

**Try it**

* [Datetime axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/)
* [Categorized axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/)
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
The color of the plot band.

**Defaults to** `#e6ebf5`.

**Try it**

* [Color band](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
A custom class name, in addition to the default `highcharts-plot-band`, to apply to each individual band.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The end position of the plot band in axis units.

**Try it**

* [Datetime axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/)
* [Categorized axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/)
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
Border width for the plot band. Also requires `borderColor` to be set.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
An id used for identifying the plot band in Axis.removePlotBand.

**Try it**

* [Remove plot band by id](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-id/)
*/
@property(nonatomic, readwrite) NSString *id;
/**
Text labels for the plot bands
*/
@property(nonatomic, readwrite) HILabel *label;
/**
An object defining mouse events for the plot band. Supported properties are `click`, `mouseover`, `mouseout`, `mousemove`.

**Try it**

* [Mouse events demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-events/)
*/
@property(nonatomic, readwrite) HIEvents *events;

-(NSDictionary *)getParams;

/**
 Remove the plot band.
 */
-(void)destroy;

@end
