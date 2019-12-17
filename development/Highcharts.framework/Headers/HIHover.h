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
The hover state for a single point marker.
*/
@interface HIHover: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *radiusPlus;
@property(nonatomic, readwrite) NSString *borderColor;
@property(nonatomic, readwrite) NSNumber *opacity;
/**
Enable or disable the point marker.

**Try it**

* [Disabled hover state](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The additional line width for a hovered point.

**Try it**

* [2 pixels wider on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/)
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
The width of the point marker's outline. When `undefined`, the series' or point's lineWidth for normal state is used.

**Try it**

* [3px line width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-linewidth/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
Animation when hovering over the marker.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
@property(nonatomic, readwrite) HIHalo *halo;
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
/**
The additional connector line width for a hovered point.
*/
@property(nonatomic, readwrite) NSNumber *connectorWidthPlus;

-(NSDictionary *)getParams;

@end
