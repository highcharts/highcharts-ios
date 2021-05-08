/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
 */
@interface HIAttributes: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *refX;
@property(nonatomic, readwrite) NSNumber *markerWidth;
@property(nonatomic, readwrite) NSNumber *refY;
@property(nonatomic, readwrite) NSString *id;
@property(nonatomic, readwrite) NSNumber *markerHeight;
@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
