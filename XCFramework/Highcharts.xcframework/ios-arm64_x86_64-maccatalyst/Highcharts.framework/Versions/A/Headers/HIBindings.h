/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HINavigationBindingsOptionsObject.h"


/**
Bindings definitions for custom HTML buttons. Each binding implements simple event-driven interface: - `className`: classname used to bind event to - `init`: initial event, fired on button click - `start`: fired on first click on a chart - `steps`: array of sequential events fired one after another on each  of users clicks - `end`: last event to be called after last step event
*/
@interface HIBindings: HIChartsJSONSerializable

/**
A rectangle annotation bindings. Includes `start` and one event in `steps` array.
*/
@property(nonatomic, readwrite) HINavigationBindingsOptionsObject *rectangleAnnotation;
/**
A label annotation bindings. Includes `start` event only.
*/
@property(nonatomic, readwrite) HINavigationBindingsOptionsObject *labelAnnotation;
/**
A circle annotation bindings. Includes `start` and one event in `steps` array.
*/
@property(nonatomic, readwrite) HINavigationBindingsOptionsObject *circleAnnotation;
/**
A ellipse annotation bindings. Includes `start` and two events in `steps` array. First updates the second point, responsible for a rx width, and second updates the ry width.
*/
@property(nonatomic, readwrite) HINavigationBindingsOptionsObject *ellipseAnnotation;

-(NSDictionary *)getParams;

@end
