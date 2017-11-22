/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPosition.h"
#import "HITheme.h"


/**
* description: The button that appears after a selection zoom, allowing the user
to reset zoom.
*/
@interface HIResetZoomButton: HIChartsJSONSerializable

/**
* description: What frame the button should be placed related to. Can be either
plot or chart

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-relativeto/ : Relative to the chart
* accepted values: ["plot", "chart"]
* default: plot
*/
@property(nonatomic, readwrite) NSString *relativeTo;
/**
* description: The position of the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-position/ : Above the plot area

*/
@property(nonatomic, readwrite) HIPosition *position;
/**
* description: A collection of attributes for the button. The object takes SVG
attributes like fill, stroke, stroke-width or r, the border
radius. The theme also supports style, a collection of CSS properties
for the text. Equivalent attributes for the hover state are given
in theme.states.hover.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-theme/ : Theming the button
*/
@property(nonatomic, readwrite) HITheme *theme;

-(NSDictionary *)getParams;

@end
