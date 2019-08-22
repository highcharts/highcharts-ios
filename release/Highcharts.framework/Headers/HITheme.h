/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
A collection of attributes for the button. The object takes SVG attributes like `fill`, `stroke`, `stroke-width` or `r`, the border radius. The theme also supports `style`, a collection of CSS properties for the text. Equivalent attributes for the hover state are given in `theme.states.hover`.

**Try it**

* [Theming the button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-theme/)
*/
@interface HITheme: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *zIndex;
/**
Padding for the button.
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
Default stroke for the buttons.

**Defaults to** `none`.
*/
@property(nonatomic, readwrite) HIColor *stroke;
/**
The default fill exists only to capture hover events.

**Defaults to** `#ffffff`.
*/
@property(nonatomic, readwrite) HIColor *fill;

-(NSDictionary *)getParams;

@end
