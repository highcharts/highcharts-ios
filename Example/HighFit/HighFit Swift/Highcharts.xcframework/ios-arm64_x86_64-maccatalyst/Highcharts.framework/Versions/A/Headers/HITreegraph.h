/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILink.h"
#import "HILevels.h"
#import "HICollapseButton.h"
#import "HIColor.h"


/**
 A `treegraph` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `treegraph` series are defined in `plotOptions.treegraph`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        treegraph: {
            // shared options for all treegraph series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'treegraph'
    }]
 });
 <pre>
 */
@interface HITreegraph: HISeries

@property(nonatomic, readwrite) HILink *link;
/**
Set options on specific levels. Takes precedence over series options, but not point options.

**Try it**

* [Treegraph chart with level options applied](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/level-options)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
Options applied to collapse Button. The collape button is the small button which indicates, that the node is collapsable.
*/
@property(nonatomic, readwrite) HICollapseButton *collapseButton;
/**
The pixel width of each node in a, or the height in case the chart is inverted. For tree graphs, the node width is only applied if the marker symbol is `rect`, otherwise the `marker` sizing options apply. Can be a number or a percentage string, or `auto`. If `auto`, the nodes are sized to fill up the plot area in the longitudinal direction, regardless of the number of levels.

**Defaults to** `undefined`.

**Try it**

* [Node width is auto and combined with node distance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeWidth;
/**
Flips the positions of the nodes of a treegraph along the horizontal axis (vertical if chart is inverted).

**Defaults to** `false`.

**Try it**

* [Treegraph series with reversed nodes.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/reversed-nodes)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
The distance between nodes in a tree graph in the longitudinal direction. The longitudinal direction means the direction that the chart flows - in a horizontal chart the distance is horizontal, in an inverted chart (vertical), the distance is vertical. If a number is given, it denotes pixels. If a percentage string is given, the distance is a percentage of the rendered node width. A `nodeDistance` of `100%` will render equal widths for the nodes and the gaps between them. This option applies only when the `nodeWidth` option is `auto`, making the node width respond to the number of columns.

**Defaults to** `30`.

**Try it**

* [Node distance of 100% means equal to node width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/node-distance)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ nodeDistance;
/**
Whether the treegraph series should fill the entire plot area in the X axis direction, even when there are collapsed points.

**Try it**

* [Fill space demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/fillspace)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *fillSpace;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
When using automatic point colors pulled from the `options.colors` collection, this option determines whether the chart should receive one color per series or one color per point.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;

-(NSDictionary *)getParams;

@end
