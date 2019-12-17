/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The position of the button.

**Try it**

* [Above the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/resetzoombutton-position/)
*/
@interface HIPosition: HIChartsJSONSerializable

/**
The vertical offset of the button.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The horizontal offset of the button.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The horizontal alignment of the button.
*/
@property(nonatomic, readwrite) NSString *align;
/**
The vertical alignment of the button.

**Defaults to** `top`.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
