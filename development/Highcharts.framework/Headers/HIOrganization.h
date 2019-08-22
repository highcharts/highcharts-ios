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
 A `organization` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `organization` series are defined in `plotOptions.organization`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        organization: {
            // shared options for all organization series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'organization'
    }]
 });
 <pre>
 */
@interface HIOrganization: HISeries

/**
A collection of options for the individual nodes. The nodes in an org chart are auto-generated instances of `Highcharts.Point`, but options can be applied here and linked by the `id`.
*/
@property(nonatomic, readwrite) NSArray <HINodes *> *nodes;
/**
The border color of the node cards.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
In a horizontal chart, the width of the nodes in pixels. Node that most organization charts are vertical, so the name of this option is counterintuitive.
*/
@property(nonatomic, readwrite) NSNumber *nodeWidth;
/**
The border radius of the node cards.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Radius for the rounded corners of the links between nodes.

**Try it**

* [Square links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-options)
*/
@property(nonatomic, readwrite) NSNumber *linkRadius;
/**
The color of the links between nodes.
*/
@property(nonatomic, readwrite) HIColor *linkColor;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Defaults to** `undefined`.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The line width of the links connecting nodes, in pixels.

**Try it**

* [Square links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-options)
*/
@property(nonatomic, readwrite) NSNumber *linkLineWidth;
/**
The indentation in pixels of hanging nodes, nodes which parent has `layout` set to `hanging`.
*/
@property(nonatomic, readwrite) NSNumber *hangingIndent;
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
Set options on specific levels. Takes precedence over series options, but not node and link options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
Opacity for the links between nodes in the sankey diagram.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;

-(NSDictionary *)getParams;

@end
