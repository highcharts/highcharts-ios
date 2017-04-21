/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Options for the drill up button that appears when drilling down on a series. The text for the button is defined in lang.drillUpText.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/ : Drill up button
*/
@interface HIDrilldownDrillUpButton: HIChartsJSONSerializable

/**
* description: A collection of attributes for the button. The object takes SVG attributes like  fill, stroke, stroke-width or r, the border radius. The theme also supports style, a collection of CSS properties for the text. Equivalent attributes for the hover state are given in theme.states.hover.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/ : Button theming
*/
@property(nonatomic, readwrite) id theme;
/**
* description: Positioning options for the button within the relativeTo box. Available properties are x, y, align and verticalAlign.
*/
@property(nonatomic, readwrite) id position;
/**
* description: What box to align the button to. Can be either "plotBox" or "spacingBox".
* default: plotBox
*/
@property(nonatomic, readwrite) NSString *relativeTo;

-(NSDictionary *)getParams;

@end
