/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
* description: A areasplinerange series. If the type option is not specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
areasplinerange.
*/
@interface HIAreasplinerange: HISeries

/**
* description: Fill opacity for the area. When you set an explicit fillColor,
the fillOpacity is not applied. Instead, you should define the
opacity in the fillColor with an rgba color definition. The fillOpacity
setting, also the default setting, overrides the alpha component
of the color setting.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillopacity/ : Automatic fill color and fill opacity of 0.1
*/
@property(nonatomic, readwrite) NSNumber *fillOpacity;
/**
* description: A separate color for the graph line. By default the line takes the
color of the series, but the lineColor setting allows setting a
separate color for the line without altering the fillColor.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-linecolor/ : Dark gray line
* default: null
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: Whether the whole area or just the line should respond to mouseover
tooltips and other mouse or touch events.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-trackbyarea/ : Display the tooltip when the area is hovered
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *trackByArea;
/**
* description: Fill color or gradient for the area. When null, the series' color
is used with the series' fillOpacity.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-default/ : Null by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-gradient/ : Gradient
* default: null
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
* description: A separate color for the negative part of the area.
*/
@property(nonatomic, readwrite) HIColor *negativeFillColor;

-(NSDictionary *)getParams;

@end
