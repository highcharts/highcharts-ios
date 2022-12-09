/**
* (c) 2009-2021 Highsoft AS
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
@property(nonatomic, readwrite) HILevels *levels;
/**
Options applied to collapse Button. The collape button is the small button which indicates, that the node is collapsable.
*/
@property(nonatomic, readwrite) HICollapseButton *collapseButton;
/**
Flips the positions of the nodes of a treegraph along the horizontal axis (vertical if chart is inverted).

**Defaults to** `false`.

**Try it**

* [Treegraph series with reversed nodes.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-treegraph/reversed-nodes)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
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
