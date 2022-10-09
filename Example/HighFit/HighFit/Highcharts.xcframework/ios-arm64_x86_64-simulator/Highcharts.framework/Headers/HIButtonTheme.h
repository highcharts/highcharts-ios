/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"


/**
A collection of attributes for the buttons. The object takes SVG attributes like `fill`, `stroke`, `stroke-width`, as well as `style`, a collection of CSS properties for the text. The object can also be extended with states, so you can set presentational options for `hover`, `select` or `disabled` button states.

**Try it**

* [Themed, single button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@interface HIButtonTheme: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIStyle *style;

-(NSDictionary *)getParams;

@end
