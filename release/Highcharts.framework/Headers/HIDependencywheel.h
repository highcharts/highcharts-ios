/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HINodes.h"
#import "HILevels.h"
#import "HIColor.h"


/**
 A `dependencywheel` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `dependencywheel` series are defined in `plotOptions.dependencywheel`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        dependencywheel: {
            // shared options for all dependencywheel series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'dependencywheel'
    }]
 });
 <pre>
 */
@interface HIDependencywheel: HISeries

/**
A collection of options for the individual nodes. The nodes in a dependency diagram are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;
/**
The start angle of the dependency wheel, in degrees where 0 is up.
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
The center of the wheel relative to the plot area. Can be percentages or pixel values. The default behaviour is to center the wheel inside the plot area.

**Defaults to** `[null, null]`.
*/
@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *center;
/**
Higher numbers makes the links in a sankey diagram or dependency wheelrender more curved. A `curveFactor` of 0 makes the lines straight.
*/
@property(nonatomic, readwrite) NSNumber *curveFactor;
/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
The minimal width for a line of a sankey. By default, 0 values are not shown.

**Defaults to** `0`.

**Try it**

* [Sankey diagram with minimal link height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-minlinkwidth)
*/
@property(nonatomic, readwrite) NSNumber *minLinkWidth;
/**
The padding between nodes in a sankey diagram or dependency wheel, in pixels.
*/
@property(nonatomic, readwrite) NSNumber *nodePadding;
/**
The pixel width of each node in a sankey diagram or dependency wheel, or the height in case the chart is inverted.
*/
@property(nonatomic, readwrite) NSNumber *nodeWidth;
/**
Set options on specific levels. Takes precedence over series options, but not node and link options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Defaults to** `undefined`.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Opacity for the links between nodes in the sankey diagram.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The color of the border surrounding each column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;

-(NSDictionary *)getParams;

@end
