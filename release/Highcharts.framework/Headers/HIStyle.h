/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Styles for the series label. The color defaults to the series color, or a contrast color if `onArea`.
*/
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSNumber *opacity;
@property(nonatomic, readwrite) NSString *position;
@property(nonatomic, readwrite) NSString *textAlign;
@property(nonatomic, readwrite) NSString *backgroundColor;
@property(nonatomic, readwrite) NSString *fontFamily;
@property(nonatomic, readwrite) NSString *textOutline;
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
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSString *pointerEvents;
@property(nonatomic, readwrite) NSString *whiteSpace;

-(NSDictionary *)getParams;

@end
