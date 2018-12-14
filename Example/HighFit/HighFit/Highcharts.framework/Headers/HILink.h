/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Link style options
*/
@interface HILink: HIChartsJSONSerializable

/**
Color of the link between two nodes.
*/
@property(nonatomic, readwrite) NSString *color;
/**
Width (px) of the link between two nodes.
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
A name for the dash style to use for links.
*/
@property(nonatomic, readwrite) NSString *dashStyle;

-(NSDictionary *)getParams;

@end
