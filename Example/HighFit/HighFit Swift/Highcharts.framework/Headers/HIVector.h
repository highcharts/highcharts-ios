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
 A `vector` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `vector` series are defined in `plotOptions.vector`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        vector: {
            // shared options for all vector series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'vector'
    }]
 });
 <pre>
 */
@interface HIVector: HISeries

/**
Maximum length of the arrows in the vector plot. The individual arrow length is computed between 0 and this value.
*/
@property(nonatomic, readwrite) NSNumber *vectorLength;
/**
What part of the vector it should be rotated around. Can be one of `start`, `center` and `end`. When `start`, the vectors will start from the given [x, y] position, and when `end` the vectors will end in the [x, y] position.

**Accepted values:** `["start", "center", "end"]`.

**Try it**

* [Rotate from start](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/vector-rotationorigin-start/)
*/
@property(nonatomic, readwrite) NSString *rotationOrigin;
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
