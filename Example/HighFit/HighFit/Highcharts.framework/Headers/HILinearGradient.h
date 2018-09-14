/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Definition of the gradient, similar to SVG: object literal holds start position (x1, y1) and the end position (x2, y2) relative to the shape, where 0 means top/left and 1 is bottom/right. All positions are floats between 0 and 1.
*/
@interface HILinearGradient: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *x2;
@property(nonatomic, readwrite) NSNumber *y1;
@property(nonatomic, readwrite) NSNumber *x1;
@property(nonatomic, readwrite) NSNumber *y2;

-(NSDictionary *)getParams;

@end
