/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the hover state of the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML.

**Defaults to** `{ "background": "#335cad", "color": "#ffffff" }`.

**Try it**

* [Bold text on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/)
*/
@interface HIMenuItemHoverStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *background;

-(NSDictionary *)getParams;

@end
