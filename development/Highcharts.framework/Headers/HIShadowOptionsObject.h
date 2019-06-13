/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The shadow options.
*/
@interface HIShadowOptionsObject: HIChartsJSONSerializable

/**
The shadow color.
*/
@property(nonatomic, readwrite) NSString *color;
/**
The horizontal offset from the element.
*/
@property(nonatomic, readwrite) NSNumber *offsetX;
/**
The vertical offset from the element.
*/
@property(nonatomic, readwrite) NSNumber *offsetY;
/**
The shadow opacity.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
The shadow width or distance from the element.
*/
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
