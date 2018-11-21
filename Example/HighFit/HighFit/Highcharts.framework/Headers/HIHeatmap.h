/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
 A `heatmap` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `heatmap` series are defined in `plotOptions.heatmap`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        heatmap: {
            // shared options for all heatmap series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'heatmap'
    }]
 });
 <pre>
 */
@interface HIHeatmap: HISeries

/**
Padding between the points in the heatmap.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The column size - how many X axis units each column in the heatmap should span.

**Defaults to** `1`.

**Try it**

* [One day](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *colsize;
/**
The row size - how many Y axis units each heatmap row should span.

**Defaults to** `1`.

**Try it**

* [1 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *rowsize;
/**
The color applied to null points. In styled mode, a general CSS class is applied instead.
*/
@property(nonatomic, readwrite) HIColor *nullColor;

-(NSDictionary *)getParams;

@end
