/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIHalo.h"
#import "HIColor.h"
#import "HIAnimationOptionsObject.h"


/**
Options for the hovered series. These settings override the normal state options when a series is moused over or touched.
*/
@interface HIHover: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *radiusPlus;
@property(nonatomic, readwrite) NSString *borderColor;
@property(nonatomic, readwrite) NSNumber *opacity;
@property(nonatomic, readwrite) HIHalo *halo;
/**
Enable separate styles for the hovered series to visualize that the user hovers either the series itself or the legend.

**Defaults to** `true`.

**Try it**

* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-column/)
* [Pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-pie/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Animation setting for hovering the graph in line-type series.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Pixel width of the graph line. By default this property is undefined, and the `lineWidthPlus` property dictates how much to increase the linewidth from normal state.

**Try it**

* [5px line on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidth/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The additional line width for the graph of a hovered series.

**Try it**

* [5 pixels wider](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2 as per the `radiusPlus` option.

**Try it**

* [10px radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-radius/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
The fill color of the marker in hover state. When `undefined`, the series' or point's fillColor for normal state is used.
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The color of the point marker's outline. When `undefined`, the series' or point's lineColor for normal state is used.

**Try it**

* [White fill color, black line color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-linecolor/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
How much to brighten the point on interaction. Requires the main color to be defined in hex or rgb(a) format. In styled mode, the hover brightening is by default replaced with a fill-opacity set in the `.highcharts-point:hover` rule.
*/
@property(nonatomic, readwrite) NSNumber *brightness;
/**
Opacity for the links between nodes in the sankey diagram in hover mode.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
The shadow option for hovered state.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
A specific color for the hovered point.
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
