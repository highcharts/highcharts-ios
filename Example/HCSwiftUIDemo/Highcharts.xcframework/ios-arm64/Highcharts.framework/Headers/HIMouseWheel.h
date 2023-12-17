/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The mouse wheel zoom is a feature included in Highcharts Stock, but is also available for Highcharts Core as a module. Zooming with the mouse wheel is enabled by default in Highcharts Stock. In Highcharts Core it is enabled if `chart.zooming.type` is set. It can be disabled by setting this option to `false`.

**Try it**

* [Enable or disable](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/mouse-wheel-zoom/enabled)
*/
@interface HIMouseWheel: HIChartsJSONSerializable

/**
Decides in what dimensions the user can zoom scrolling the wheel. Can be one of `x`, `y` or `xy`. In Highcharts Core, if not specified here, it will inherit the type from `chart.zooming.type`. In Highcharts Stock, it defaults to `x`. Note that particularly with mouse wheel in the y direction, the zoom is affected by the default `yAxis.startOnTick` and `endOnTick`) settings. In order to respect these settings, the zoom level will adjust after the user has stopped zooming. To prevent this, consider setting `startOnTick` and `endOnTick` to `false`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Adjust the sensitivity of the zoom. Sensitivity of mouse wheel or trackpad scrolling. `1` is no sensitivity, while with `2`, one mouse wheel delta will zoom in `50%`.

**Defaults to** `1.1`.

**Try it**

* [Change mouse wheel zoom sensitivity](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/mouse-wheel-zoom/sensitivity)
*/
@property(nonatomic, readwrite) NSNumber *sensitivity;
/**
Zooming with the mouse wheel can be disabled by setting this option to `false`.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
