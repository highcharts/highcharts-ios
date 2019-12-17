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
 A `errorbar` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `errorbar` series are defined in `plotOptions.errorbar`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        errorbar: {
            // shared options for all errorbar series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'errorbar'
    }]
 });
 <pre>
 */
@interface HIErrorbar: HISeries

/**
The line width of the whiskers, the horizontal lines marking low and high values. When `null`, the general `lineWidth` applies.

**Try it**

* [Error bar styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/)
*/
@property(nonatomic, readwrite) NSNumber *whiskerWidth;
/**
Whether to group non-stacked columns or to let them render independent of each other. Non-grouped columns will be laid out individually and overlap each other.

**Defaults to** `true`.

**Try it**

* [Grouping disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouping-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *grouping;
/**
The width of the stem, the vertical line extending from the box to the whiskers. If `undefined`, the width is inherited from the `lineWidth` option. In styled mode, the stem stroke width can be set with the `.highcharts-boxplot-stem` class.

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
* [Box plot in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/boxplot/)
* [Error bar styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/)
*/
@property(nonatomic, readwrite) NSNumber *stemWidth;
/**
The pixel width of the median line. If `null`, the `lineWidth` is used. In styled mode, the median stroke width can be set with the `.highcharts-boxplot-median` class.

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
* [Box plot in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/boxplot/)
*/
@property(nonatomic, readwrite) NSNumber *medianWidth;
/**
The color of the whiskers, the horizontal lines marking low and high values. When `undefined`, the general series color is used. In styled mode, the whisker stroke can be set with the `.highcharts-boxplot-whisker` class .

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
* [Box plot in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/boxplot/)
*/
@property(nonatomic, readwrite) HIColor *whiskerColor;
/**
The color of the median line. If `undefined`, the general series color applies. In styled mode, the median stroke width can be set with the `.highcharts-boxplot-median` class.

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
* [Box plot in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/boxplot/)
* [Error bar styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/)
*/
@property(nonatomic, readwrite) HIColor *medianColor;
/**
The dash style of the stem, the vertical line extending from the box to the whiskers.

**Defaults to** `Solid`.

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
* [Box plot in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/boxplot/)
* [Error bar styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/error-bar-styling/)
*/
@property(nonatomic, readwrite) NSString *stemDashStyle;
/**
The length of the whiskers, the horizontal lines marking low and high values. It can be a numerical pixel value, or a percentage value of the box width. Set `0` to disable whiskers.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ whiskerLength;
/**
The fill color of the box. In styled mode, the fill color can be set with the `.highcharts-boxplot-box` class.

**Defaults to** `#ffffff`.

**Try it**

* [Box plot styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/box-plot-styling/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
Padding between each column or bar, in x axis units.

**Try it**

* [0.1 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-default/)
* [0.25](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-025/)
* [0 for tightly packed columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointpadding-none/)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The X axis range that each point is valid for. This determines the width of the column. On a categorized axis, the range will be 1 by default (one category unit). On linear and datetime axes, the range will be computed as the distance between the two closest data points. The default `null` means it is computed automatically, but this option can be used to override the automatic value. This option is set by default to 1 if data sorting is enabled.

**Try it**

* [Set the point range to one day on a data set with one week between the points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointrange/)
*/
@property(nonatomic, readwrite) NSNumber *pointRange;
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
3D columns only. The color of the edges. Similar to `borderColor`, except it defaults to the same color as the column.
*/
@property(nonatomic, readwrite) HIColor *edgeColor;
/**
The maximum allowed pixel width for a column, translated to the height of a bar in a bar chart. This prevents the columns from becoming too wide when there is a small number of points in the chart.

**Try it**

* [Limited to 50](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-maxpointwidth-20/)
*/
@property(nonatomic, readwrite) NSNumber *maxPointWidth;
/**
A pixel value specifying a fixed width for each column or bar. When `null`, the width is calculated from the `pointPadding` and `groupPadding`.

**Try it**

* [20px wide columns regardless of chart width or the amount of data points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-pointwidth-20/)
*/
@property(nonatomic, readwrite) NSNumber *pointWidth;
/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Padding between each value groups, in x axis units.

**Try it**

* [0.2 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouppadding-default/)
* [No group padding - all columns are evenly spaced](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-grouppadding-none/)
*/
@property(nonatomic, readwrite) NSNumber *groupPadding;
/**
3D columns only. The width of the colored edges.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *edgeWidth;
/**
When true, each column edge is rounded to its nearest pixel in order to render sharp on screen. In some cases, when there are a lot of densely packed columns, this leads to visible difference in column widths or distance between columns. In these cases, setting `crisp` to `false` may look better, even though each column is rendered blurry.

**Try it**

* [Crisp is false](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-crisp-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crisp;
/**
Depth of the columns in a 3D column chart.

**Defaults to** `25`.
*/
@property(nonatomic, readwrite) NSNumber *depth;

-(NSDictionary *)getParams;

@end
