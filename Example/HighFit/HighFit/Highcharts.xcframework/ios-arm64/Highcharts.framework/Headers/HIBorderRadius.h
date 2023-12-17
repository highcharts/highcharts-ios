/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The corner radius of the border surrounding each column or bar. A number signifies pixels. A percentage string, like for example `50%`, signifies a relative size. For columns this is relative to the column width, for pies it is relative to the radius and the inner radius.

**Defaults to** `3`.

**Try it**

* [Rounded columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderradius/)
* [Column and pie with rounded border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-border-radius)
*/
@interface HIBorderRadius: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *where;

-(NSDictionary *)getParams;

@end
