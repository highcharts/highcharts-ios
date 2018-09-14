/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML.

**Defaults to** `{ "padding": "0.5em 1em", "color": "#333333", "background": "none" }`.

**Try it**

* [Add a grey stripe to the left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemstyle/)
*/
@interface HIMenuItemStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *padding;
@property(nonatomic, readwrite) NSString *transition;
/**
Defaults to `14px` on touch devices and `11px` on desktop.
*/
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *background;

-(NSDictionary *)getParams;

@end
