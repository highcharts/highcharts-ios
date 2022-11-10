/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
A configuration object for the button theme. The object accepts SVG properties like `stroke-width`, `stroke` and `fill`. Tri-state button styles are supported by the `states.hover` and `states.select` objects.

**Try it**

* [Theming the buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-theme/)
*/
@interface HITheme: HIChartsJSONSerializable

/**
Padding for the button.

**Defaults to** `5`.
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
@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
