/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILayoutAlgorithm.h"
#import "HIParentNode.h"
#import "HIJitter.h"
#import "HICluster.h"


/**
 A `packedbubble` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `packedbubble` series are defined in `plotOptions.packedbubble`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        packedbubble: {
            // shared options for all packedbubble series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'packedbubble'
    }]
 });
 <pre>
 */
@interface HIPackedbubble: HISeries

/**
Minimum bubble size. Bubbles will automatically size between the `minSize` and `maxSize` to reflect the value of each bubble. Can be either pixels (when no unit is given), or a percentage of the smallest one of the plot width and height, divided by the square root of total number of points.

**Defaults to** `10%`.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ minSize;
/**
Whether the bubble's value should be represented by the area or the width of the bubble. The default, `area`, corresponds best to the human perception of the size of each bubble.

**Defaults to** `area`.

**Try it**

* [Comparison of area and size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-sizeby/)
*/
@property(nonatomic, readwrite) NSString *sizeBy;
/**
Options for layout algorithm when simulation is enabled. Inside there are options to change the speed, padding, initial bubbles positions and more.
*/
@property(nonatomic, readwrite) HILayoutAlgorithm *layoutAlgorithm;
/**
Flag to determine if nodes are draggable or not. Available for graph with useSimulation set to true only.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggable;
/**
Maximum bubble size. Bubbles will automatically size between the `minSize` and `maxSize` to reflect the value of each bubble. Can be either pixels (when no unit is given), or a percentage of the smallest one of the plot width and height, divided by the square root of total number of points.

**Defaults to** `50%`.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ maxSize;
/**
Series options for parent nodes.
*/
@property(nonatomic, readwrite) HIParentNode *parentNode;
/**
An option is giving a possibility to choose between using simulation for calculating bubble positions. These reflects in both animation and final position of bubbles. Simulation is also adding options to the series graph based on used layout. In case of big data sets, with any performance issues, it is possible to disable animation and pack bubble in a simple circular way.

**Defaults to** `True`.

**Try it**

* [useSimulation set to false](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/spiral/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useSimulation;
/**
The minimum for the Z value range. Defaults to the highest Z value in the data.

**Try it**

* [Z has a possible range of 0-100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-zmin-zmax/)
*/
@property(nonatomic, readwrite) NSNumber *zMax;
/**
The minimum for the Z value range. Defaults to the lowest Z value in the data.

**Try it**

* [Z has a possible range of 0-100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-zmin-zmax/)
*/
@property(nonatomic, readwrite) NSNumber *zMin;
/**
Whether to display negative sized bubbles. The threshold is given by the `zThreshold` option, and negative bubbles can be visualized by setting `negativeColor`.

**Defaults to** `true`.

**Try it**

* [Negative bubbles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-negative/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *displayNegative;
/**
When `displayNegative` is `false`, bubbles with lower Z values are skipped. When `displayNegative` is `true` and a `negativeColor` is given, points with lower Z is colored.

**Try it**

* [Negative bubbles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-negative/)
*/
@property(nonatomic, readwrite) NSNumber *zThreshold;
/**
When this is true, the absolute value of z determines the size of the bubble. This means that with the default `zThreshold` of 0, a bubble of value -1 will have the same size as a bubble of value 1, while a bubble of value 0 will have a smaller size according to `minSize`.

**Defaults to** `false`.

**Try it**

* [Size by absolute value, various thresholds](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-sizebyabsolutevalue/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sizeByAbsoluteValue;
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
