/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIJitter.h"


/**
 A `bubble` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `bubble` series are defined in `plotOptions.bubble`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        bubble: {
            // shared options for all bubble series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'bubble'
    }]
 });
 <pre>
 */
@interface HIBubble: HISeries

/**
The minimum for the Z value range. Defaults to the highest Z value in the data.

**Try it**

* [Z has a possible range of 0-100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-zmin-zmax/)
*/
@property(nonatomic, readwrite) NSNumber *zMax;
/**
Whether the bubble's value should be represented by the area or the width of the bubble. The default, `area`, corresponds best to the human perception of the size of each bubble.

**Defaults to** `area`.

**Try it**

* [Comparison of area and size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-sizeby/)
*/
@property(nonatomic, readwrite) NSString *sizeBy;
/**
The minimum for the Z value range. Defaults to the lowest Z value in the data.

**Try it**

* [Z has a possible range of 0-100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-zmin-zmax/)
*/
@property(nonatomic, readwrite) NSNumber *zMin;
/**
Maximum bubble size. Bubbles will automatically size between the `minSize` and `maxSize` to reflect the `z` value of each bubble. Can be either pixels (when no unit is given), or a percentage of the smallest one of the plot width and height.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ maxSize;
/**
Minimum bubble size. Bubbles will automatically size between the `minSize` and `maxSize` to reflect the `z` value of each bubble. Can be either pixels (when no unit is given), or a percentage of the smallest one of the plot width and height.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bubble-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ minSize;
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

-(NSDictionary *)getParams;

@end
