/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILevels.h"
#import "HIDrillUpButton.h"
#import "HIColor.h"


/**
A `treemap` series. If the `type` option is not specified, it is inherited from `chart.type`.

Configuration options for the series are given in three levels:
 
1. Options for all series in a chart are defined in the `plotOptions.series` object.

2. Options for all `treemap` series are defined in `plotOptions.treemap`.

3. Options for one single series are given in `the series instance array`.
 
<pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        treemap: {
            // shared options for all treemap series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'treemap'
    }]
 });
<pre>
*/
@interface HITreemap: HISeries

/**
When using automatic point colors pulled from the `options.colors` collection, this option determines whether the chart should receive one color per series or one color per point.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
The opacity of a point in treemap. When a point has children, the visibility of the children is determined by the opacity.

**Defaults to** `0.15`.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
Whether to ignore hidden points when the layout algorithm runs. If `false`, hidden points will leave open spaces.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;
/**
When enabled the user can click on a point which is a parent and zoom in on its children.

**Defaults to** `false`.

**Try it**

* [Enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-allowdrilltonode/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowDrillToNode;
/**
The sort index of the point inside the treemap level.

**Try it**

* [Sort by years](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-sortindex/)
*/
@property(nonatomic, readwrite) NSNumber *sortIndex;
/**
This option decides if the user can interact with the parent nodes or just the leaf nodes. When this option is undefined, it will be true by default. However when allowDrillToNode is true, then it will be false by default.

**Try it**

* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-false/)
* [InteractByLeaf and allowDrillToNode is true](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-true-and-allowdrilltonode/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *interactByLeaf;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
This option decides which algorithm is used for setting position and dimensions of the points. Can be one of `sliceAndDice`, `stripes`, `squarified` or `strip`.

**Accepted values:** `["sliceAndDice", "stripes", "squarified", "strip"]`.

**Defaults to** `sliceAndDice`.

**Try it**

* [SliceAndDice by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-sliceanddice/)
* [Stripes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-stripes/)
* [Squarified](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-squarified/)
* [Strip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-strip/)
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
Used together with the levels and allowDrillToNode options. When set to false the first level visible when drilling is considered to be level one. Otherwise the level will be the same as the tree structure.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *levelIsConstant;
/**
Defines which direction the layout algorithm will start drawing. Possible values are "vertical" and "horizontal".

**Accepted values:** `["vertical", "horizontal"]`.

**Defaults to** `vertical`.
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;
/**
Set options on specific levels. Takes precedence over series options, but not point options.

**Try it**

* [Styling dataLabels and borders](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/)
* [Different layoutAlgorithm](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/)
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
Options for the button appearing when drilling down in a treemap.
*/
@property(nonatomic, readwrite) HIDrillUpButton *drillUpButton;
/**
Enabling this option will make the treemap alternate the drawing direction between vertical and horizontal. The next levels starting direction will always be the opposite of the previous.

**Defaults to** `false`.

**Try it**

* [Enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-alternatestartingdirection-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternateStartingDirection;

-(NSDictionary *)getParams;

@end
