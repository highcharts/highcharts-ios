/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIStates.h"


/**
A collection of attributes for the buttons. The object takes SVG attributes like `fill`, `stroke`, `stroke-width`, as well as `style`, a collection of CSS properties for the text. The object can also be extended with states, so you can set presentational options for `hover`, `select` or `disabled` button states.

**Try it**

* [Themed, single button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@interface HIButtonTheme: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIStyle *style;
/**
State overrides for the buttons
*/
@property(nonatomic, readwrite) HIStates *states;
/**
The padding of buttons

**Defaults to** `8`.
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
The stroke color for buttons

**Defaults to** `#cccccc`.
*/
@property(nonatomic, readwrite) NSString *stroke;
/**
The border radius for buttons

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *r;
/**
The stroke width for buttons

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *strokeWidth;
/**
The fill color for buttons

**Defaults to** `#f7f7f7`.
*/
@property(nonatomic, readwrite) NSString *fill;

-(NSDictionary *)getParams;

@end
