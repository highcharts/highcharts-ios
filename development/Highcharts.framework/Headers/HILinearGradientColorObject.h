/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Defines the start position and the end position for a gradient relative to the shape. Start position (x1, y1) and end position (x2, y2) are relative to the shape, where 0 means top/left and 1 is bottom/right.
*/
@interface HILinearGradientColorObject: HIChartsJSONSerializable

/**
Start horizontal position of the gradient. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *x1;
/**
End horizontal position of the gradient. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *x2;
/**
Start vertical position of the gradient. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *y1;
/**
End vertical position of the gradient. Float ranges 0-1.
*/
@property(nonatomic, readwrite) NSNumber *y2;

-(NSDictionary *)getParams;

@end
