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
Options for the pivot or the center point of the gauge. In styled mode, the pivot is styled with the `.highcharts-gauge-series .highcharts-pivot` rule.

**Try it**

* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/gauge/)
*/
@interface HIPivot: HIChartsJSONSerializable

/**
The border or stroke color of the pivot. In able to change this, the borderWidth must also be set to something other than the default 0.

**Defaults to** `#cccccc`.

**Try it**

* [Pivot options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The pixel radius of the pivot.

**Defaults to** `5`.

**Try it**

* [Pivot options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
The border or stroke width of the pivot.

**Defaults to** `0`.

**Try it**

* [Pivot options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The background color or fill of the pivot.

**Defaults to** `#000000`.

**Try it**

* [Pivot options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;

-(NSDictionary *)getParams;

@end
