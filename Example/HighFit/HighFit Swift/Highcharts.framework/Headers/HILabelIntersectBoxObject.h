/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Containing the position of a box that should be avoided by labels.
*/
@interface HILabelIntersectBoxObject: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *bottom;
@property(nonatomic, readwrite) NSNumber *left;
@property(nonatomic, readwrite) NSNumber *right;
@property(nonatomic, readwrite) NSNumber *top;

-(NSDictionary *)getParams;

@end
