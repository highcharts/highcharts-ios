/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the label. In styled mode, the styles are set in the `.highcharts-stack-label` class.

**Try it**

* [Red stack total labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-style/)
*/
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *transition;
@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSNumber *fontSize;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSNumber *textOutline;
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSString *whiteSpace;
@property(nonatomic, readwrite) NSNumber *borderRadius;
@property(nonatomic, readwrite) NSNumber *lineWidth;
@property(nonatomic, readwrite) NSString *textOverflow;
@property(nonatomic, readwrite) NSString *stroke;
@property(nonatomic, readwrite) NSNumber *strokeWidth;
@property(nonatomic, readwrite) NSString *fill;

-(NSDictionary *)getParams;

@end
