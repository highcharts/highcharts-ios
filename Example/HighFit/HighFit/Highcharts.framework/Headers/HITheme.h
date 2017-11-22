/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A collection of attributes for the button. The object takes SVG
attributes like fill, stroke, stroke-width or r, the border
radius. The theme also supports style, a collection of CSS properties
for the text. Equivalent attributes for the hover state are given
in theme.states.hover.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-theme/ : Theming the button
*/
@interface HITheme: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: The default fill exists only to capture hover events.
* default: #ffffff
*/
@property(nonatomic, readwrite) NSString *fill;
@property(nonatomic, readwrite) NSString *stroke;
/**
* description: The Z index for the reset zoom button.
* default: 20
*/
@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
