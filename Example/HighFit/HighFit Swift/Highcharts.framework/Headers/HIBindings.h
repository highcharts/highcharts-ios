/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStockToolsBindingsObject.h"


/**
Bindings definitions for custom HTML buttons. Each binding implements simple event-driven interface: - `className`: classname used to bind event to - `init`: initial event, fired on button click - `start`: fired on first click on a chart - `steps`: array of sequential events fired one after another on each  of users clicks - `end`: last event to be called after last step event

**Try it**

* [Custom bindings in Highstock](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/stock/stocktools/stocktools-thresholds)
*/
@interface HIBindings: HIChartsJSONSerializable

/**
A rectangle annotation bindings. Includes `start` and one event in `steps` array.
*/
@property(nonatomic, readwrite) HIStockToolsBindingsObject *rectangleAnnotation;
/**
A label annotation bindings. Includes `start` event only.
*/
@property(nonatomic, readwrite) HIStockToolsBindingsObject *labelAnnotation;
/**
A circle annotation bindings. Includes `start` and one event in `steps` array.
*/
@property(nonatomic, readwrite) HIStockToolsBindingsObject *circleAnnotation;

-(NSDictionary *)getParams;

@end
