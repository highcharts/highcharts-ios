/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAlignObject.h"


/**
Options for the drill up button that appears when drilling down on a series. The text for the button is defined in `lang.drillUpText`.

**Try it**

* [Drill up button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/)
*/
@interface HIDrillUpButton: HIChartsJSONSerializable

/**
Positioning options for the button within the `relativeTo` box. Available properties are `x`, `y`, `align` and `verticalAlign`.
*/
@property(nonatomic, readwrite) HIAlignObject *position;
/**
A collection of attributes for the button. The object takes SVG attributes like `fill`, `stroke`, `stroke-width` or `r`, the border radius. The theme also supports `style`, a collection of CSS properties for the text. Equivalent attributes for the hover state are given in `theme.states.hover`. In styled mode, drill-up button styles can be applied with the `.highcharts-drillup-button` class.

**Try it**

* [Button theming](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/)
*/
@property(nonatomic, readwrite) id theme;
/**
What box to align the button to. Can be either `plotBox` or `spacingBox`.

**Defaults to** `plotBox`.
*/
@property(nonatomic, readwrite) NSString *relativeTo;

-(NSDictionary *)getParams;

@end
