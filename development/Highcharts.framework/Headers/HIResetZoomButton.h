/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAlignObject.h"
#import "HISVGAttributes.h"


/**
The button that appears after a selection zoom, allowing the user to reset zoom.
*/
@interface HIResetZoomButton: HIChartsJSONSerializable

/**
The position of the button.

**Try it**

* [Above the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-position/)
*/
@property(nonatomic, readwrite) HIAlignObject *position;
/**
A collection of attributes for the button. The object takes SVG attributes like `fill`, `stroke`, `stroke-width` or `r`, the border radius. The theme also supports `style`, a collection of CSS properties for the text. Equivalent attributes for the hover state are given in `theme.states.hover`.

**Try it**

* [Theming the button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-theme/)
*/
@property(nonatomic, readwrite) HISVGAttributes *theme;
/**
What frame the button placement should be related to. Can be either `plotBox` or `spacingBox`.

**Defaults to** `plot`.

**Try it**

* [Relative to the chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-relativeto/)
*/
@property(nonatomic, readwrite) NSString *relativeTo;

-(NSDictionary *)getParams;

@end
