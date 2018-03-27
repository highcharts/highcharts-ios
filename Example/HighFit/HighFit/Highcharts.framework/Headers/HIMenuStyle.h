/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the popup menu appearing by default when the export icon is clicked. This menu is rendered in HTML.

**Defaults to** `{ "border": "1px solid #999999", "background": "#ffffff", "padding": "5px 0" }`.

**Try it**

* [Light gray menu background](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menustyle/)
*/
@interface HIMenuStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *padding;
@property(nonatomic, readwrite) NSString *border;
@property(nonatomic, readwrite) NSString *background;

-(NSDictionary *)getParams;

@end
