/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
A ellipse annotation bindings. Includes `start` and two events in `steps` array. First updates the second point, responsible for a rx width, and second updates the ry width.
*/
@interface HIEllipseAnnotation: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *className;

-(NSDictionary *)getParams;

@end
