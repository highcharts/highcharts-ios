/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIJitter.h"
#import "HICluster.h"


/**
 A `scatter` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `scatter` series are defined in `plotOptions.scatter`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        scatter: {
            // shared options for all scatter series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'scatter'
    }]
 });
 <pre>
 */
@interface HIScatter: HISeries

/**
Apply a jitter effect for the rendered markers. When plotting discrete values, a little random noise may help telling the points apart. The jitter setting applies a random displacement of up to `n` axis units in either direction. So for example on a horizontal X axis, setting the `jitter.x` to 0.24 will render the point in a random position between 0.24 units to the left and 0.24 units to the right of the true axis position. On a category axis, setting it to 0.5 will fill up the bin and make the data appear continuous. When rendered on top of a box plot or a column series, a jitter value of 0.24 will correspond to the underlying series' default [groupPadding](https://api.highcharts.com/highcharts/plotOptions.column.groupPadding) and [pointPadding](https://api.highcharts.com/highcharts/plotOptions.column.pointPadding) settings.

**Try it**

* [Jitter on a scatter plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter)
* [Jittered scatter plot on top of a box plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter-boxplot)
*/
@property(nonatomic, readwrite) HIJitter *jitter;
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
