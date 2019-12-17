/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
An object of additional SVG attributes for the no-data label.
*/
@interface HIAttr: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
