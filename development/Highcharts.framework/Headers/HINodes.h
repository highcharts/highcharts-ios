/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
A collection of options for the individual nodes. The nodes in a sankey diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@interface HINodes: HIChartsJSONSerializable

/**
The name to display for the node in data labels and tooltips. Use this when the name is different from the `id`. Where the id must be unique for each node, this is not necessary for the name.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@property(nonatomic, readwrite) NSString *name;
/**
The color of the auto generated node.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
An optional column index of where to place the node. The default behaviour is to place it next to the preceding node.

**Defaults to** `undefined`.

**Try it**

* [Specified node column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) NSNumber *column;
/**
The vertical offset of a node in terms of weight. Positive values shift the node downwards, negative shift it upwards.

**Defaults to** `0`.

**Try it**

* [Specified node offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) NSNumber *offset;
/**
The id of the auto-generated node, refering to the `from` or `to` setting of the link.
*/
@property(nonatomic, readwrite) NSString *id;
/**
The color index of the auto generated node, especially for use in styled mode.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;

-(NSDictionary *)getParams;

@end
