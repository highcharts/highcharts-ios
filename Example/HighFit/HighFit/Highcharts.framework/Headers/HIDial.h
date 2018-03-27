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
Options for the dial or arrow pointer of the gauge. In styled mode, the dial is styled with the `.highcharts-gauge-series .highcharts-dial` rule.

**Try it**

* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/gauge/)
*/
@interface HIDial: HIChartsJSONSerializable

/**
The border color or stroke of the gauge's dial. By default, the borderWidth is 0, so this must be set in addition to a custom border color.

**Defaults to** `#cccccc`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The length of the dial's rear end, the part that extends out on the other side of the pivot. Relative to the dial's length.

**Defaults to** `10%`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSString *rearLength;
/**
The length of the dial's base part, relative to the total radius or length of the dial.

**Defaults to** `70%`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSString *baseLength;
/**
The radius or length of the dial, in percentages relative to the radius of the gauge itself.

**Defaults to** `80%`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSString *radius;
/**
The width of the gauge dial border in pixels.

**Defaults to** `0`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The background or fill color of the gauge's dial.

**Defaults to** `#000000`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
The width of the top of the dial, closest to the perimeter. The pivot narrows in from the base to the top.

**Defaults to** `1`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSNumber *topWidth;
/**
The pixel width of the base of the gauge dial. The base is the part closest to the pivot, defined by baseLength.

**Defaults to** `3`.

**Try it**

* [Dial options demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-dial/)
*/
@property(nonatomic, readwrite) NSNumber *baseWidth;

-(NSDictionary *)getParams;

@end
