/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStates.h"
#import "HIZones.h"
#import "HILayoutAlgorithm.h"
#import "HIMarker.h"
#import "HIEvents.h"
#import "HIAnimationOptionsObject.h"
#import "HIDataLabels.h"


/**
Options for marker clusters, the concept of sampling the data values into larger blocks in order to ease readability and increase performance of the JavaScript charts. Note: marker clusters module is not working with `boost` and `draggable-points` modules. The marker clusters feature requires the marker-clusters.js file to be loaded, found in the modules directory of the download package, or online at `https://code.highcharts.com/modules/marker-clusters.js`.

**Try it**

* [Maps marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/europe)
* [Scatter marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
* [Marker clusters with colorAxis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/optimized-kmeans)
*/
@interface HICluster: HIChartsJSONSerializable

/**
When set to `false` prevent cluster overlapping - this option works only when `layoutAlgorithm.type = "grid"`.

**Try it**

* [Prevent overlapping](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/grid)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
@property(nonatomic, readwrite) HIStates *states;
/**
An array defining zones within marker clusters. In styled mode, the color zones are styled with the `.highcharts-cluster-zone-{n}` class, or custom classed from the `className` option.

**Try it**

* [Marker clusters zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
* [Zones on maps](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/custom-alg)
*/
@property(nonatomic, readwrite) NSArray <HIZones *> *zones;
/**
Whether to enable the marker-clusters module.

**Try it**

* [Maps marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/basic)
* [Scatter marker clusters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Options for layout algorithm. Inside there are options to change the type of the algorithm, gridSize, distance or iterations.
*/
@property(nonatomic, readwrite) HILayoutAlgorithm *layoutAlgorithm;
/**
Options for the cluster data labels.
*/
@property(nonatomic, readwrite) HIDataLabels *dataLabels;
/**
Zoom the plot area to the cluster points range when a cluster is clicked.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *drillToCluster;
/**
Options for the cluster marker animation.

**Defaults to** `{ "duration": 500 }`.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Options for the cluster marker.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
The minimum amount of points to be combined into a cluster. This value has to be greater or equal to 2.

**Try it**

* [At least three points in the cluster](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
*/
@property(nonatomic, readwrite) NSNumber *minimumClusterSize;
@property(nonatomic, readwrite) HIEvents *events;

-(NSDictionary *)getParams;

@end
