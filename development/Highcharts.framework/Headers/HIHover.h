/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimation.h"
#import "HIHalo.h"
#import "HIColor.h"


/**
Options for the hovered series. These settings override the normal state options when a series is moused over or touched.
*/
@interface HIHover: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *radiusPlus;
/**
Enable separate styles for the hovered series to visualize that the user hovers either the series itself or the legend. .

**Defaults to** `true`.

**Try it**

* [Line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled/)
* [Column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-column/)
* [Pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-pie/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Animation setting for hovering the graph in line-type series.

**Defaults to** `{ "duration": 50 }`.
*/
@property(nonatomic, readwrite) HIAnimation *animation;
/**
Pixel width of the graph line. By default this property is undefined, and the `lineWidthPlus` property dictates how much to increase the linewidth from normal state.

**Try it**

* [5px line on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidth/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The additional line width for the graph of a hovered series.

**Defaults to** `1`.

**Try it**

* [5 pixels wider](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
Options for the halo appearing around the hovered point in line- type series as well as outside the hovered slice in pie charts. By default the halo is filled by the current point or series color with an opacity of 0.25\. The halo can be disabled by setting the `halo` option to `false`. In styled mode, the halo is styled with the `.highcharts-halo` class, with colors inherited from `.highcharts-color-{n}`.

**Try it**

* [Halo options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/halo/)
*/
@property(nonatomic, readwrite) HIHalo *halo;
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
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2 as per the `radiusPlus` option.

**Try it**

* [10px radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-radius/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
How much to brighten the point on interaction. Requires the main color to be defined in hex or rgb(a) format. In styled mode, the hover brightening is by default replaced with a fill-opacity set in the `.highcharts-point:hover` rule.
*/
@property(nonatomic, readwrite) NSNumber *brightness;
/**
Opacity for the links between nodes in the sankey diagram in hover mode.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
The border color for the hovered state.
*/
@property(nonatomic, readwrite) NSString *borderColor;
/**
The opacity of a point in treemap. When a point has children, the visibility of the children is determined by the opacity.

**Defaults to** `0.75`.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
The shadow option for hovered state.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
A specific color for the hovered point.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
