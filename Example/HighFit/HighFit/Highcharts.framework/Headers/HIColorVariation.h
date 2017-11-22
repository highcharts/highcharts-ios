/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A configuration object to define how the color of a child varies from the
parent's color. The variation is distributed among the children of node.
For example when setting brightness, the brightness change will range
from the parent's original brightness on the first child, to the amount
set in the to setting on the last node. This allows a gradient-like
color scheme that sets children out from each other while highlighting
the grouping on treemaps and sectors on sunburst charts.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst/ : Sunburst with color variation
*/
@interface HIColorVariation: HIChartsJSONSerializable

/**
* description: The key of a color variation. Currently supports brightness only.

* accepted values: ["brightness"]
*/
@property(nonatomic, readwrite) NSString *key;
/**
* description: The ending value of a color variation. The last sibling will receive this
value.
*/
@property(nonatomic, readwrite) NSNumber *to;

-(NSDictionary *)getParams;

@end
