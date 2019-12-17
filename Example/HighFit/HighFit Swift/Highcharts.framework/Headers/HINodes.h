/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDataLabels.h"
#import "HIColor.h"


/**
A collection of options for the individual nodes. The nodes in a sankey diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@interface HINodes: HIChartsJSONSerializable

/**
The color index of the auto generated node, especially for use in styled mode.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
An optional level index of where to place the node. The default behaviour is to place it next to the preceding node. Alias of `nodes.column`, but in inverted sankeys and org charts, the levels are laid out as rows.
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
The color of the auto generated node.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Individual data label for each node. The options are the same as the ones for `series.sankey.dataLabels`.
*/
@property(nonatomic, readwrite) NSArray <HIDataLabels *> *dataLabels;
/**
An optional column index of where to place the node. The default behaviour is to place it next to the preceding node. Note that this option name is counter intuitive in inverted charts, like for example an organization chart rendered top down. In this case the "columns" are horizontal.

**Try it**

* [Specified node column](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) NSNumber *column;
/**
In a horizontal layout, the vertical offset of a node in terms of weight. Positive values shift the node downwards, negative shift it upwards. In a vertical layout, like organization chart, the offset is horizontal. If a percantage string is given, the node is offset by the percentage of the node size plus `nodePadding`.

**Defaults to** `0`.

**Try it**

* [Specified node offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-node-column/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ offset;
/**
The id of the auto-generated node, refering to the `from` or `to` setting of the link.
*/
@property(nonatomic, readwrite) NSString *id;
/**
The name to display for the node in data labels and tooltips. Use this when the name is different from the `id`. Where the id must be unique for each node, this is not necessary for the name.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@property(nonatomic, readwrite) NSString *name;
/**
An image for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with images](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *image;
/**
The job title for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with job titles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *title;
/**
Layout for the node's children. If `hanging`, this node's children will hang below their parent, allowing a tighter packing of nodes in the diagram.

**Defaults to** `normal`.

**Try it**

* [Hanging layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *layout;
/**
The job description for the node card, will be inserted by the default `dataLabel.nodeFormatter`.

**Try it**

* [Org chart with job descriptions](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart)
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Mass of the node. By default, each node has mass equal to it's marker radius . Mass is used to determine how two connected nodes should affect each other: Attractive force is multiplied by the ratio of two connected nodes; if a big node has weights twice as the small one, then the small one will move towards the big one twice faster than the big one to the small one .

**Try it**

* [Mass determined by marker.radius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/ragdoll/)
*/
@property(nonatomic, readwrite) NSNumber *mass;

-(NSDictionary *)getParams;

@end
