/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
 */
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *textOutline;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSString *stroke;
@property(nonatomic, readwrite) NSNumber *strokeWidth;
@property(nonatomic, readwrite) NSString *fill;

-(NSDictionary *)getParams;

@end
