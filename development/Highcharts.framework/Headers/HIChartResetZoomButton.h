/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartResetZoomButtonPosition.h"


/**
* description: The button that appears after a selection zoom, allowing the user to reset zoom.
*/
@interface HIChartResetZoomButton: HIChartsJSONSerializable

/**
* description: The position of the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-position/ : Above the plot area
*/
@property(nonatomic, readwrite) HIChartResetZoomButtonPosition *position;
/**
* description: A collection of attributes for the button. The object takes SVG attributes like  fill, stroke, stroke-width or r, the border radius. The theme also supports style, a collection of CSS properties for the text. Equivalent attributes for the hover state are given in theme.states.hover.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-theme/ : Theming the button
*/
@property(nonatomic, readwrite) id theme;
/**
* description: What frame the button should be placed related to. Can be either "plot" or "chart".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-relativeto/ : Relative to the chart
* accepted values: ["plot", "chart"]
* default: plot
*/
@property(nonatomic, readwrite) NSString *relativeTo;

-(NSDictionary *)getParams;

@end
