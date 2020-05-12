/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGDefinitionObject.h"


/**
Styled mode only. Configuration object for adding SVG definitions for reusable elements. See [gradients, shadows and patterns](https://www.highcharts.com/docs/chart-design-and-style/gradients-shadows-and-patterns) for more information and code examples.

**Try it**

* [Define a custom marker for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/)
* [Define markers in a styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations-markers/)
*/
@interface HIDefs: HIChartsJSONSerializable

@property(nonatomic, readwrite) HISVGDefinitionObject *reverseArrow;
@property(nonatomic, readwrite) HISVGDefinitionObject *arrow;

-(NSDictionary *)getParams;

@end
