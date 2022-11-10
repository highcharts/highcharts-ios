/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIBreadcrumbs.h"
#import "HILevels.h"
#import "HIJitter.h"
#import "HICluster.h"
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
Whether to ignore hidden points when the layout algorithm runs. If `false`, hidden points will leave open spaces.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;
/**
The border radius for each treemap item.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The sort index of the point inside the treemap level.

**Try it**

* [Sort by years](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-sortindex/)
*/
@property(nonatomic, readwrite) NSNumber *sortIndex;
/**
When using automatic point colors pulled from the `options.colors` collection, this option determines whether the chart should receive one color per series or one color per point.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
Options for the breadcrumbs, the navigation at the top leading the way up through the traversed levels.
*/
@property(nonatomic, readwrite) HIBreadcrumbs *breadcrumbs;
/**
When enabled the user can click on a point which is a parent and zoom in on its children.

**Try it**

* [Enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-allowtraversingtree/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowTraversingTree;
/**
Defines which direction the layout algorithm will start drawing.

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
This option decides if the user can interact with the parent nodes or just the leaf nodes. When this option is undefined, it will be true by default. However when allowTraversingTree is true, then it will be false by default.

**Try it**

* [False](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-false/)
* [InteractByLeaf and allowTraversingTree is true](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-true-and-allowtraversingtree/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *interactByLeaf;
/**
Enabling this option will make the treemap alternate the drawing direction between vertical and horizontal. The next levels starting direction will always be the opposite of the previous.

**Try it**

* [Enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-alternatestartingdirection-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternateStartingDirection;
/**
This option decides which algorithm is used for setting position and dimensions of the points.

**Defaults to** `sliceAndDice`.

**Try it**

* [SliceAndDice by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-sliceanddice/)
* [Stripes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-stripes/)
* [Squarified](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-squarified/)
* [Strip](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-strip/)
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
Used together with the levels and allowTraversingTree options. When set to false the first level visible to be level one, which is dynamic when traversing the tree. Otherwise the level will be the same as the tree structure.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *levelIsConstant;
/**
Apply a jitter effect for the rendered markers. When plotting discrete values, a little random noise may help telling the points apart. The jitter setting applies a random displacement of up to `n` axis units in either direction. So for example on a horizontal X axis, setting the `jitter.x` to 0.24 will render the point in a random position between 0.24 units to the left and 0.24 units to the right of the true axis position. On a category axis, setting it to 0.5 will fill up the bin and make the data appear continuous. When rendered on top of a box plot or a column series, a jitter value of 0.24 will correspond to the underlying series' default [groupPadding](https://api.highcharts.com/highcharts/plotOptions.column.groupPadding) and [pointPadding](https://api.highcharts.com/highcharts/plotOptions.column.pointPadding) settings.

**Try it**

* [Jitter on a scatter plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter)
* [Jittered scatter plot on top of a box plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter-boxplot)
*/
@property(nonatomic, readwrite) HIJitter *jitter;
/**
Options for marker clusters, the concept of sampling the data values into larger blocks in order to ease readability and increase performance of the JavaScript charts. Note: marker clusters module is not working with `boost` and `draggable-points` modules. The marker clusters feature requires the marker-clusters.js file to be loaded, found in the modules directory of the download package, or online at `https://code.highcharts.com/modules/marker-clusters.js`.

**Try it**

* [Maps marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/europe)
* [Scatter marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
* [Marker clusters with colorAxis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/optimized-kmeans)
*/
@property(nonatomic, readwrite) HICluster *cluster;

-(NSDictionary *)getParams;

@end
