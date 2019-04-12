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
 A `tilemap` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `tilemap` series are defined in `plotOptions.tilemap`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        tilemap: {
            // shared options for all tilemap series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'tilemap'
    }]
 });
 <pre>
 */
@interface HITilemap: HISeries

/**
The row size - how many Y axis units each tilemap row should span. Analogous to `colsize`.

**Defaults to** `1`.

**Try it**

* [1 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *rowsize;
/**
The padding between points in the tilemap.

**Defaults to** `0`.

**Try it**

* [Point padding on tiles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/tilemap-pointpadding)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The shape of the tiles in the tilemap. Possible values are `hexagon`, `circle`, `diamond`, and `square`.

**Try it**

* [Circular tile shapes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/circlemap-africa)
* [Diamond tile shapes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/diamondmap)
*/
@property(nonatomic, readwrite) NSString *tileShape;
/**
The column size - how many X axis units each column in the tilemap should span. Works as in `Heatmaps`.

**Defaults to** `1`.

**Try it**

* [One day](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *colsize;
/**
The color applied to null points. In styled mode, a general CSS class is applied instead.
*/
@property(nonatomic, readwrite) HIColor *nullColor;

-(NSDictionary *)getParams;

@end
