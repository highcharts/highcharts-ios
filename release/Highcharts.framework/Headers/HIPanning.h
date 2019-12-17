/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Allow panning in a chart. Best used with `panKey` to combine zooming and panning. On touch devices, when the `tooltip.followTouchMove` option is `true` (default), panning requires two fingers. To allow panning with one finger, set `followTouchMove` to `false`.

**Try it**

* [Zooming and panning](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/pankey/)
*/
@interface HIPanning: HIChartsJSONSerializable

/**
Decides in what dimensions the user can pan the chart. Can be one of `x`, `y`, or `xy`.

**Accepted values:** `["x", "y", "xy"]`.

**Defaults to** `x`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Enable or disable chart panning.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
