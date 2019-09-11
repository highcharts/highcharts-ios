/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
Under which conditions the rule applies.
*/
@interface HICondition: HIChartsJSONSerializable

/**
The responsive rule applies if the chart width is greater than this.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *minWidth;
/**
A callback function to gain complete control on when the responsive rule applies. Return `true` if it applies. This opens for checking against other metrics than the chart size, for example the document size or other elements.
*/
@property(nonatomic, readwrite) HIFunction *callback;
/**
The responsive rule applies if the chart height is greater than this.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *minHeight;
/**
The responsive rule applies if the chart width is less than this.

**Try it**

* [Max width is 500](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
*/
@property(nonatomic, readwrite) NSNumber *maxWidth;
/**
The responsive rule applies if the chart height is less than this.
*/
@property(nonatomic, readwrite) NSNumber *maxHeight;

-(NSDictionary *)getParams;

@end
