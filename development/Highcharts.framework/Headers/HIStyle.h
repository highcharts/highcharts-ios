/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the no-data label.

**Try it**

* [Styled no-data text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
*/
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *fontFamily;
/**
Border radius of the focus border.

**Defaults to** `3`.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Line width of the focus border.

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
@property(nonatomic, readwrite) NSString *textOverflow;
@property(nonatomic, readwrite) NSString *whiteSpace;

-(NSDictionary *)getParams;

@end
