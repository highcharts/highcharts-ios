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
Relevant only for pictorial series. The `stackShadow` forms the background of stacked points. Requires `series.stacking` to be defined.

**Try it**

* [Pictorial stackShadow option](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pictorial-stackshadow/)
*/
@interface HIStackShadow: HIChartsJSONSerializable

/**
The color of the `stackShadow` border.

**Defaults to** `transparent`.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The color of the `stackShadow`.

**Defaults to** `#dedede`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Enable or disable `stackShadow`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The width of the `stackShadow` border.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;

-(NSDictionary *)getParams;

@end
