/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Configure a crosshair that follows either the mouse pointer or the hovered point.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the crosshairs are styled in the .highcharts-crosshair, .highcharts-crosshair-thin or .highcharts-xaxis-category classes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-both/ : Crosshair on both axes
* default: false
*/
@interface HIXAxisCrosshair: HIChartsJSONSerializable

/**
* description: The pixel width of the crosshair. Defaults to 1 for numeric or datetime axes, and for one category width for category axes.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-customized/ : Customized crosshairs.
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: The Z index of the crosshair. Higher Z indices allow drawing the crosshair on top of the series or behind the grid lines.
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: A class name for the crosshair, especially as a hook for styling.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Whether the crosshair should snap to the point or follow the pointer independent of points.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-snap-false/ : True by default
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *snap;
/**
* description: The dash style for the crosshair. See series.dashStyle for possible values.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-dotted/ : Dotted crosshair
* accepted values: ["Solid", "ShortDash", "ShortDot", "ShortDashDot", "ShortDashDotDot", "Dot", "Dash" ,"LongDash", "DashDot", "LongDashDot", "LongDashDotDot"]
* default: Solid
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
* description: The color of the crosshair. Defaults to #cccccc for numeric and datetime axes, and rgba(204,214,235,0.25) for category axes, where the crosshair by default highlights the whole category.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-customized/ : Customized crosshairs.
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
