/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: A collection of options for the individual nodes. The nodes in a sankey 
diagram are auto-generated instances of Highcharts.Point, but options can
be applied here and linked by the id.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/ : Sankey diagram with node options
*/
@interface HINodes: HIChartsJSONSerializable

/**
* description: The color index of the auto generated node, especially for use in styled
mode.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
* description: The id of the auto-generated node, refering to the from or to setting of
the link.
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: The color of the auto generated node.
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
