/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: CSS styles for the hover state of the individual items within the
popup menu appearing by default when the export icon is clicked.
 The menu items are rendered in HTML.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/ : Bold text on hover

* default: { "background": "#335cad", "color": "#ffffff" }
*/
@interface HIMenuItemHoverStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *background;
@property(nonatomic, readwrite) NSString *color;

-(NSDictionary *)getParams;

@end
