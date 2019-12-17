/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the label. Use `whiteSpace: 'nowrap'` to prevent wrapping of category labels. Use `textOverflow: 'none'` to prevent ellipsis (dots). In styled mode, the labels are styled with the `.highcharts-axis-labels` class.

**Try it**

* [Red X axis labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-style/)
*/
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *textOutline;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSNumber *borderRadius;
@property(nonatomic, readwrite) NSNumber *lineWidth;
@property(nonatomic, readwrite) NSString *textOverflow;
@property(nonatomic, readwrite) NSString *pointerEvents;
@property(nonatomic, readwrite) NSString *whiteSpace;
@property(nonatomic, readwrite) NSString *stroke;
@property(nonatomic, readwrite) NSNumber *strokeWidth;
@property(nonatomic, readwrite) NSString *fill;

-(NSDictionary *)getParams;

@end
