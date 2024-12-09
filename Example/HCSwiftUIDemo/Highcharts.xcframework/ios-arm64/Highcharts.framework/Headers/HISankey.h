/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILevels.h"
#import "HINodes.h"
#import "HIColor.h"


/**
 A `sankey` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `sankey` series are defined in `plotOptions.sankey`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        sankey: {
            // shared options for all sankey series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'sankey'
    }]
 });
 <pre>
 */
@interface HISankey: HISeries

/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `True`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
The minimal width for a line of a sankey. By default, 0 values are not shown.

**Defaults to** `0`.

**Try it**

* [Sankey diagram with minimal link height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-minlinkwidth)
*/
@property(nonatomic, readwrite) NSNumber *minLinkWidth;
/**
Higher numbers makes the links in a sankey diagram or dependency wheelrender more curved. A `curveFactor` of 0 makes the lines straight.

**Defaults to** `0.33`.
*/
@property(nonatomic, readwrite) NSNumber *curveFactor;
/**
The padding between nodes in a sankey diagram or dependency wheel, in pixels. For sankey charts, this applies to the nodes of the same column, so vertical distance by default, or horizontal distance in an inverted (vertical) sankey. If the number of nodes is so great that it is impossible to lay them out within the plot area with the given `nodePadding`, they will be rendered with a smaller padding as a strategy to avoid overflow.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *nodePadding;
/**
The distance between nodes in a sankey diagram in the longitudinal direction. The longitudinal direction means the direction that the chart flows - in a horizontal chart the distance is horizontal, in an inverted chart (vertical), the distance is vertical. If a number is given, it denotes pixels. If a percentage string is given, the distance is a percentage of the rendered node width. A `nodeDistance` of `100%` will render equal widths for the nodes and the gaps between them. This option applies only when the `nodeWidth` option is `auto`, making the node width respond to the number of columns.

**Defaults to** `30`.

**Try it**

* [Sankey with dnode distance of 100% means equal to node width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/node-distance)
* [Organization chart with node distance of 50%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeDistance;
/**
Set options on specific levels. Takes precedence over series options, but not node and link options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Determines which side of the chart the nodes are to be aligned to. When the chart is inverted, `top` aligns to the left and `bottom` to the right.

**Try it**

* [Node alignment demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-nodealignment)
*/
@property(nonatomic, readwrite) NSString *nodeAlignment;
/**
The pixel width of each node in a sankey diagram or dependency wheel, or the height in case the chart is inverted. Can be a number or a percentage string. Sankey series also support setting it to `auto`. With this setting, the nodes are sized to fill up the plot area in the longitudinal direction, regardless of the number of levels.

**Defaults to** `20`.

**Try it**

* [Sankey with auto node width combined with node distance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/node-distance)
* [Organization chart with node distance of 50%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeWidth;
/**
Opacity for the links between nodes in the sankey diagram.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
Determines color mode for sankey links. Available options: - `from` color of the sankey link will be the same as the 'from node' - `gradient` color of the sankey link will be set to gradient between colors of 'from node' and 'to node' - `to` color of the sankey link will be same as the 'to node'.

**Defaults to** `from`.

**Try it**

* [Vertical sankey diagram with gradients](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/vertical-sankey)
* [Sankey diagram with gradients and explanation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-sankey/link-color-mode)
*/
@property(nonatomic, readwrite) NSString *linkColorMode;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The color of the border surrounding each column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
When `true`, the columns will center in the category, ignoring null or missing points. When `false`, space will be reserved for null or missing points.

**Try it**

* [Center in category](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-column/centerincategory/)
* [Center in category, stacked and grouped](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/stack-centerincategory/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *centerInCategory;
/**
A collection of options for the individual nodes. The nodes in a sankey diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;

-(NSDictionary *)getParams;

@end
