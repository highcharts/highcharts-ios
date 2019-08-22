/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILayoutAlgorithm.h"


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
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggable;
/**
Maximum bubble size. Bubbles will automatically size between the `minSize` and `maxSize` to reflect the value of each bubble. Can be either pixels (when no unit is given), or a percentage of the smallest one of the plot width and height, divided by the square root of total number of points.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ maxSize;
/**
An option is giving a possibility to choose between using simulation for calculating bubble positions. These reflects in both animation and final position of bubbles. Simulation is also adding options to the series graph based on used layout. In case of big data sets, with any performance issues, it is possible to disable animation and pack bubble in a simple circular way.

**Try it**

* [useSimulation set to false](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/spiral/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useSimulation;
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

-(NSDictionary *)getParams;

@end
