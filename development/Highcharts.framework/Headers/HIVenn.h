/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HICluster.h"


/**
 A `venn` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `venn` series are defined in `plotOptions.venn`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        venn: {
            // shared options for all venn series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'venn'
    }]
 });
 <pre>
 */
@interface HIVenn: HISeries

@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
@property(nonatomic, readwrite) NSString *borderDashStyle;
@property(nonatomic, readwrite) NSNumber *brighten;
/**
Options for marker clusters, the concept of sampling the data values into larger blocks in order to ease readability and increase performance of the JavaScript charts. Note: marker clusters module is not working with `boost` and `draggable-points` modules. The marker clusters feature requires the marker-clusters.js file to be loaded, found in the modules directory of the download package, or online at `https://code.highcharts.com/modules/marker-clusters.js`.

**Try it**

* [Maps marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/europe)
* [Scatter marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
* [Marker clusters with colorAxis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/optimized-kmeans)
*/
@property(nonatomic, readwrite) HICluster *cluster;

-(NSDictionary *)getParams;

@end
