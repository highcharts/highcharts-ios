/**
* (c) 2009-2021 Highsoft AS
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
Opacity of the link between two nodes.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
A name for the dash style to use for links.
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
Width (px) of the link between two nodes.
*/
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
