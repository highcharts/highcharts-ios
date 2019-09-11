/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILevelSize.h"
#import "HITraverseUpButton.h"
#import "HILevels.h"
#import "HIColor.h"


/**
 A `sunburst` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `sunburst` series are defined in `plotOptions.sunburst`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        sunburst: {
            // shared options for all sunburst series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'sunburst'
    }]
 });
 <pre>
 */
@interface HISunburst: HISeries

@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Which point to use as a root in the visualization.
*/
@property(nonatomic, readwrite) NSString *rootId;
/**
Determines the width of the ring per level.

**Try it**

* [Sunburst with various sizes per level](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sunburst-levelsize/)
*/
@property(nonatomic, readwrite) HILevelSize *levelSize;
/**
The center of the sunburst chart relative to the plot area. Can be percentages or pixel values.

**Defaults to** `["50%", "50%"]`.

**Try it**

* [Centered at 100, 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-center/)
*/
@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *center;
/**
Options for the button appearing when traversing down in a treemap.
*/
@property(nonatomic, readwrite) HITraverseUpButton *traverseUpButton;
/**
If a point is sliced, moved out from the center, how many pixels should it be moved?.

**Try it**

* [Sliced sunburst](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sunburst-sliced)
*/
@property(nonatomic, readwrite) NSNumber *slicedOffset;
/**
Set options on specific levels. Takes precedence over series options, but not point options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
Used together with the levels and `allowDrillToNode` options. When set to false the first level visible when drilling is considered to be level one. Otherwise the level will be the same as the tree structure.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *levelIsConstant;
/**
When enabled the user can click on a point which is a parent and zoom in on its children.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowTraversingTree;
/**
A series specific or series type specific color set to use instead of the global `colors`.

**Try it**

* [Set default colors for all pies](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome/)
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The diameter of the pie relative to the plot area. Can be a percentage or pixel value. Pixel values are given as integers. The default behaviour (as of 3.0) is to scale to the plot area and give room for data labels within the plot area. `slicedOffset` is also included in the default size calculation. As a consequence, the size of the pie may vary when points are updated and data labels more around. In that case it is best to set a fixed value, for example `"75%"`.

**Try it**

* [Smaller pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ size;
/**
The color of the border surrounding each slice. When `null`, the border takes the same color as the slice fill. This can be used together with a `borderWidth` to fill drawing gaps created by antialiazing artefacts in borderless pies. In styled mode, the border stroke is given in the `.highcharts-point` class.

**Defaults to** `#ffffff`.

**Try it**

* [Black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-bordercolor-black/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
If the total sum of the pie's values is 0, the series is represented as an empty circle . The `fillColor` option defines the color of that circle. Use `pie.borderWidth` to set the border thickness.

**Try it**

* [Empty pie series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-emptyseries/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The start angle of the pie slices in degrees where 0 is top and 90 right.

**Defaults to** `0`.

**Try it**

* [Start from right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-startangle-90/)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
The width of the border surrounding each slice. When setting the border width to 0, there may be small gaps between the slices due to SVG antialiasing artefacts. To work around this, keep the border width at 0.5 or 1, but set the `borderColor` to `null` instead. In styled mode, the border stroke width is given in the `.highcharts-point` class.

**Try it**

* [3px border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;

-(NSDictionary *)getParams;

@end
