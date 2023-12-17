/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMouseWheel.h"
#import "HIResetButton.h"


/**
Chart zooming options.
*/
@interface HIZooming: HIChartsJSONSerializable

/**
The mouse wheel zoom is a feature included in Highcharts Stock, but is also available for Highcharts Core as a module. Zooming with the mouse wheel is enabled by default in Highcharts Stock. In Highcharts Core it is enabled if `chart.zooming.type` is set. It can be disabled by setting this option to `false`.

**Try it**

* [Enable or disable](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/mouse-wheel-zoom/enabled)
*/
@property(nonatomic, readwrite) HIMouseWheel *mouseWheel;
/**
Equivalent to `type`, but for multitouch gestures only. By default, the `pinchType` is the same as the `type` setting. However, pinching can be enabled separately in some cases, for example in stock charts where a mouse drag pans the chart, while pinching is enabled. When `tooltip.followTouchMove` is true, pinchType only applies to two-finger touches.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *pinchType;
/**
The button that appears after a selection zoom, allowing the user to reset zoom.
*/
@property(nonatomic, readwrite) HIResetButton *resetButton;
/**
Set a key to hold when dragging to zoom the chart. This is useful to avoid zooming while moving points. Should be set different than `chart.panKey`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *key;
/**
Enables zooming by a single touch, in combination with `chart.zooming.type`. When enabled, two-finger pinch will still work as set up by [chart.zooming.pinchType] (#chart.zooming.pinchType). However, `singleTouch` will interfere with touch-dragging the chart to read the tooltip. And especially when vertical zooming is enabled, it will make it hard to scroll vertically on the page.

**Try it**

* [Zoom by single touch enabled, with buttons to toggle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoombysingletouch)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *singleTouch;
/**
Decides in what dimensions the user can zoom by dragging the mouse. Can be one of `x`, `y` or `xy`.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *type;

-(NSDictionary *)getParams;

@end
