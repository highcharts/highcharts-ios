/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HINodes.h"
#import "HILayoutAlgorithm.h"
#import "HILink.h"


/**
 A `networkgraph` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `networkgraph` series are defined in `plotOptions.networkgraph`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        networkgraph: {
            // shared options for all networkgraph series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'networkgraph'
    }]
 });
 <pre>
 */
@interface HINetworkgraph: HISeries

/**
A collection of options for the individual nodes. The nodes in a networkgraph diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Networkgraph diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/data-options/)
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;
@property(nonatomic, readwrite) HILayoutAlgorithm *layoutAlgorithm;
/**
Flag to determine if nodes are draggable or not.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggable;
/**
Link style options
*/
@property(nonatomic, readwrite) HILink *link;

-(NSDictionary *)getParams;

@end
