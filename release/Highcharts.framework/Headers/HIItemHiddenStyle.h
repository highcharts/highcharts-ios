/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for each legend item when the corresponding series or point is hidden. Only a subset of CSS is supported, notably those options related to text. Properties are inherited from `style` unless overridden here.

**Defaults to** `{"color": "#cccccc"}`.

**Try it**

* [Darker gray color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemhiddenstyle/)
*/
@interface HIItemHiddenStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;

-(NSDictionary *)getParams;

@end
