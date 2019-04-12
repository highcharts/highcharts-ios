/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The position of the no-data label, relative to the plot area.
*/
@interface HIPosition: HIChartsJSONSerializable

/**
Vertical offset of the label, in pixels.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
Horizontal offset of the label, in pixels.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Horizontal alignment of the label.
*/
@property(nonatomic, readwrite) NSString *align;
/**
Vertical alignment of the label.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
