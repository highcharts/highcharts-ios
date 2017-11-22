/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPosition.h"


/**
* description: Options for the drill up button that appears when drilling down
on a series. The text for the button is defined in lang.drillUpText.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/ : Drill up button
*/
@interface HIDrillUpButton: HIChartsJSONSerializable

/**
* description: The position of the button.
*/
@property(nonatomic, readwrite) HIPosition *position;
/**
* description: A collection of attributes for the button. The object takes SVG attributes
like fill, stroke, stroke-width or r, the border radius.
The theme also supports style, a collection of CSS properties for
the text. Equivalent attributes for the hover state are given in
theme.states.hover.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/ : Button theming
*/
@property(nonatomic, readwrite) id theme;
/**
* description: What box to align the button to. Can be either plotBox or
`spacingBox.

* accepted values: ["plotBox", "spacingBox"]
* default: plotBox
*/
@property(nonatomic, readwrite) NSString *relativeTo;

-(NSDictionary *)getParams;

@end
