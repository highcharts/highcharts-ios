/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HINodes.h"


/**
A `sankey` series. If the `type` option is not specified, it is inherited from `chart.type`.

Configuration options for the series are given in three levels:
 
1. Options for all series in a chart are defined in the `plotOptions.series` object.

2. Options for all `sankey` series are defined in `plotOptions.sankey`.

3. Options for one single series are given in `the series instance array`.
 
<pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        sankey: {
            // shared options for all sankey series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'sankey'
    }]
 });
<pre>
*/
@interface HISankey: HISeries

/**
When using automatic point colors pulled from the `options.colors` collection, this option determines whether the chart should receive one color per series or one color per point.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Higher numbers makes the links in a sankey diagram render more curved. A `curveFactor` of 0 makes the lines straight.
*/
@property(nonatomic, readwrite) NSNumber *curveFactor;
/**
The padding between nodes in a sankey diagram, in pixels.
*/
@property(nonatomic, readwrite) NSNumber *nodePadding;
/**
The pixel width of each node in a sankey diagram, or the height in case the chart is inverted.
*/
@property(nonatomic, readwrite) NSNumber *nodeWidth;
/**
Opacity for the links between nodes in the sankey diagram.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
The minimal height for a column or width for a bar. By default, 0 values are not shown. To visualize a 0 (or close to zero) point, set the minimal point length to a pixel value like 3\. In stacked column charts, minPointLength might not be respected for tightly packed values.

**Try it**

* [Zero base value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-minpointlength/)
* [Positive and negative close to zero values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-minpointlength-pos-and-neg/)
*/
@property(nonatomic, readwrite) NSNumber *minPointLength;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
A collection of options for the individual nodes. The nodes in a sankey diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.

**Try it**

* [Sankey diagram with node options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/sankey/)
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;

-(NSDictionary *)getParams;

@end
