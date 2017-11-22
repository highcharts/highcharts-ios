/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimation.h"
#import "HIHalo.h"
#import "HIColor.h"

@class HIMarker;
/**
* description: Options for the hovered series
*/
@interface HIHover: HIChartsJSONSerializable

/**
* description: A specific color for the hovered point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-states-hover/ : Hover options
* default: undefined
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: A specific border color for the hovered point. Defaults to
inherit the normal state border color.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Animation setting for hovering the graph in line-type series.
* default: { "duration": 50 }
*/
@property(nonatomic, readwrite) HIAnimation *animation;
/**
* description: The additional line width for the graph of a hovered series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/ : 5 pixels wider
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
* description: How much to brighten the point on interaction. Requires the main
color to be defined in hex or rgb(a) format.
In styled mode, the hover brightening is by default replaced
with a fill-opacity set in the .highcharts-point:hover rule.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-states-hover-brightness/ : Brighten by 0.5
* default: 0.1
*/
@property(nonatomic, readwrite) NSNumber *brightness;
/**
* description: In Highcharts 1.0, the appearance of all markers belonging to
the hovered series. For settings on the hover state of the individual
point, see marker.states.hover.
*/
@property(nonatomic, readwrite) HIMarker *marker;
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
* description: Pixel with of the graph line. By default this property is
undefined, and the lineWidthPlus property dictates how much
to increase the linewidth from normal state.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidth/ : 5px line on hover
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Options for the halo appearing around the hovered point in line-
type series as well as outside the hovered slice in pie charts.
By default the halo is filled by the current point or series
color with an opacity of 0.25. The halo can be disabled by setting
the halo option to false.
In styled mode, the halo is styled with the .highcharts-halo class, with colors inherited from .highcharts-color-{n}.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/halo/ : Halo options
*/
@property(nonatomic, readwrite) HIHalo *halo;
/**
* description: Enable separate styles for the hovered series to visualize that the
user hovers either the series itself or the legend. .

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled/ : Line
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-column/ : Column
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-pie/ : Pie
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The radius of the point marker. In hover state, it defaults to the
normal state's radius + 2 as per the radiusPlus option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-radius/ : 10px radius
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
* description: The number of pixels to increase the radius of the hovered point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/ : 5 pixels greater radius on hover
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *radiusPlus;
/**
* description: The fill color of the marker in hover state.
* default: null
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
* description: The color of the point marker's outline. When null, the
series' or point's color is used.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-linecolor/ : White fill color, black line color
* default: #ffffff
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: Opacity for the links between nodes in the sankey diagram in
hover mode.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
* description: The opacity of a point in treemap. When a point has children,
the visibility of the children is determined by the opacity.
* default: 0.75
*/
@property(nonatomic, readwrite) NSNumber *opacity;

-(NSDictionary *)getParams;

@end
