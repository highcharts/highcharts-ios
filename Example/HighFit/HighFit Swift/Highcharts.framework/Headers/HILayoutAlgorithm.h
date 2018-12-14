/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
 */
@interface HILayoutAlgorithm: HIChartsJSONSerializable

/**
Ideal length (px) of the link between two nodes. When not defined, length is calculated as: `Math.pow(availableWidth * availableHeight / nodesLength, 0.4);` Note: Because of the algorithm specification, length of each link might be not exactly as specified.
*/
@property(nonatomic, readwrite) NSNumber *linkLength;
/**
Gravitational const used in the barycenter force of the algorithm.

**Try it**

* [Custom forces](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
*/
@property(nonatomic, readwrite) NSNumber *gravitationalConstant;
/**
Max number of iterations before algorithm will stop. In general, algorithm should find positions sooner, but when rendering huge number of nodes, it is recommended to increase this value as finding perfect graph positions can require more time.
*/
@property(nonatomic, readwrite) NSNumber *maxIterations;
/**
Initial layout algorithm for positioning nodes. Can be one of built-in options ("circle", "random") or a function where positions should be set on each node (`this.nodes`) as `node.plotX` and `node.plotY`

**Accepted values:** `["circle", "random"]`.

**Try it**

* [Initial positions with callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/initial-positions/)
*/
@property(nonatomic, readwrite) NSString *initialPositions;
/**
Friction applied on forces to prevent nodes rushing to fast to the desired positions.
*/
@property(nonatomic, readwrite) NSNumber *friction;
/**
Experimental. Enables live simulation of the algorithm implementation. All nodes are animated as the forces applies on them.

**Try it**

* [Live simulation enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/network-graph/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableSimulation;
/**
Repulsive force applied on a node. Passed are two arguments: - `d` - which is current distance between two nodes - `k` - which is desired distance between two nodes

**Defaults to** `function (d, k) { return k * k / d; }`.

**Try it**

* [Custom forces](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
*/
@property(nonatomic, readwrite) HIFunction *repulsiveForce;
/**
Attraction force applied on a node which is conected to another node by a link. Passed are two arguments: - `d` - which is current distance between two nodes - `k` - which is desired distance between two nodes

**Defaults to** `function (d, k) { return k * k / d; }`.

**Try it**

* [Custom forces](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
*/
@property(nonatomic, readwrite) HIFunction *attractiveForce;
/**
Type of the algorithm used when positioning nodes.

**Accepted values:** `["reingold-fruchterman"]`.
*/
@property(nonatomic, readwrite) NSString *type;

-(NSDictionary *)getParams;

@end
