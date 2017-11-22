/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A collection of SVG attributes to override the appearance of the
halo, for example fill, stroke and stroke-width.
*/
@interface HIAttributes: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
