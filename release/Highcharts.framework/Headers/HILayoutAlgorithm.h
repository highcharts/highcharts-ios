/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIParentNodeOptions.h"
#import "HIFunction.h"


/**
Options for layout algorithm when simulation is enabled. Inside there are options to change the speed, padding, initial bubbles positions and more.
*/
@interface HILayoutAlgorithm: HIChartsJSONSerializable

/**
Whether series should interact with each other or not. When `parentNodeLimit` is set to true, thi option should be set to false to avoid sticking points in wrong series parentNode.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *seriesInteraction;
/**
Gravitational const used in the barycenter force of the algorithm.

**Try it**

* [Custom forces with Euler integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
*/
@property(nonatomic, readwrite) NSNumber *gravitationalConstant;
/**
Max number of iterations before algorithm will stop. In general, algorithm should find positions sooner, but when rendering huge number of nodes, it is recommended to increase this value as finding perfect graph positions can require more time.
*/
@property(nonatomic, readwrite) NSNumber *maxIterations;
/**
Initial layout algorithm for positioning nodes. Can be one of the built-in options ("circle", "random") or a function where positions should be set on each node (`this.nodes`) as `node.plotX` and `node.plotY`.

**Try it**

* [Initial positions with callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/initial-positions/)
*/
@property(nonatomic, readwrite) NSString *initialPositions;
/**
Layout algorithm options for parent nodes.
*/
@property(nonatomic, readwrite) HIParentNodeOptions *parentNodeOptions;
/**
When `initialPositions` are set to 'circle', `initialPositionRadius` is a distance from the center of circle, in which nodes are created.

**Defaults to** `1`.

**Try it**

* [Initial radius set to 200](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/initial-radius/)
*/
@property(nonatomic, readwrite) NSNumber *initialPositionRadius;
/**
Friction applied on forces to prevent nodes rushing to fast to the desired positions.
*/
@property(nonatomic, readwrite) NSNumber *friction;
/**
In case of split series, this option allows user to drag and drop points between series, for changing point related series.

**Try it**

* [Example of drag'n drop bubbles for bubble kanban](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/packed-dashboard/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *dragBetweenSeries;
/**
Max speed that node can get in one iteration. In terms of simulation, it's a maximum translation (in pixels) that a node can move (in both, x and y, dimensions). While `friction` is applied on all nodes, max speed is applied only for nodes that move very fast, for example small or disconnected ones.
*/
@property(nonatomic, readwrite) NSNumber *maxSpeed;
/**
Experimental. Enables live simulation of the algorithm implementation. All nodes are animated as the forces applies on them.

**Try it**

* [Live simulation enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/network-graph/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableSimulation;
/**
The distance between two bubbles, when the algorithm starts to treat two bubbles as overlapping. The `bubblePadding` is also the expected distance between all the bubbles on simulation end.
*/
@property(nonatomic, readwrite) NSNumber *bubblePadding;
/**
Whether to split series into individual groups or to mix all series together.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSString *splitSeries;
/**
Whether bubbles should interact with their parentNode to keep them inside.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *parentNodeLimit;
/**
Integration type. Available options are `'euler'` and `'verlet'`. Integration determines how forces are applied on particles. In Euler integration, force is applied direct as `newPosition += velocity;`. In Verlet integration, new position is based on a previous posittion without velocity: `newPosition += previousPosition - newPosition`. Note that different integrations give different results as forces are different. In Highcharts v7.0.x only `'euler'` integration was supported.

**Accepted values:** `["euler", "verlet"]`.

**Try it**

* [Comparison of Verlet and Euler integrations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/integration-comparison/)
*/
@property(nonatomic, readwrite) NSString *integration;
/**
Ideal length (px) of the link between two nodes. When not defined, length is calculated as: `Math.pow(availableWidth * availableHeight / nodesLength, 0.4);` Note: Because of the algorithm specification, length of each link might be not exactly as specified.

**Try it**

* [Numerical values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/styled-links/)
*/
@property(nonatomic, readwrite) NSNumber *linkLength;
/**
Type of the algorithm used when positioning nodes.

**Accepted values:** `["reingold-fruchterman"]`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
When `type` is set to `kmeans`, `distance` is a maximum distance between point and cluster center so that this point will be inside the cluster. The distance is either a number defining pixels or a percentage defining a percentage of the plot area width.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ distance;
/**
When `type` is set to the `grid`, `gridSize` is a size of a grid square element either as a number defining pixels, or a percentage defining a percentage of the plot area width.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ gridSize;
/**
When `type` is set to `undefined` and there are more visible points than the kmeansThreshold the `grid` algorithm is used to find clusters, otherwise `kmeans`. It ensures good performance on large datasets and better clusters arrangement after the zoom.
*/
@property(nonatomic, readwrite) NSNumber *kmeansThreshold;
/**
When `type` is set to `kmeans`, `iterations` are the number of iterations that this algorithm will be repeated to find clusters positions.
*/
@property(nonatomic, readwrite) NSNumber *iterations;
/**
Approximation used to calculate repulsive forces affecting nodes. By default, when calculateing net force, nodes are compared against each other, which gives O(N^2) complexity. Using Barnes-Hut approximation, we decrease this to O(N log N), but the resulting graph will have different layout. Barnes-Hut approximation divides space into rectangles via quad tree, where forces exerted on nodes are calculated directly for nearby cells, and for all others, cells are treated as a separate node with center of mass.

**Accepted values:** `["barnes-hut", "none"]`.

**Try it**

* [A graph with Barnes-Hut approximation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/barnes-hut-approximation/)
*/
@property(nonatomic, readwrite) NSString *approximation;
/**
Repulsive force applied on a node. Passed are two arguments: - `d` - which is current distance between two nodes - `k` - which is desired distance between two nodes In `verlet` integration, defaults to: `function (d, k) { return (k-d) / d * (k > d ? 1 : 0) }`

**Defaults to** `function (d, k) { return k * k / d; }`.

**Try it**

* [Custom forces with Euler integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
* [Custom forces with Verlet integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/cuboids/)
*/
@property(nonatomic, readwrite) HIFunction *repulsiveForce;
/**
Barnes-Hut approximation only. Deteremines when distance between cell and node is small enough to caculate forces. Value of `theta` is compared directly with quotient `s / d`, where `s` is the size of the cell, and `d` is distance between center of cell's mass and currently compared node.
*/
@property(nonatomic, readwrite) NSNumber *theta;
/**
Attraction force applied on a node which is conected to another node by a link. Passed are two arguments: - `d` - which is current distance between two nodes - `k` - which is desired distance between two nodes In `verlet` integration, defaults to: `function (d, k) { return (k-d) / d; }`

**Defaults to** `function (d, k) { return k * k / d; }`.

**Try it**

* [Custom forces with Euler integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
* [Custom forces with Verlet integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/cuboids/)
*/
@property(nonatomic, readwrite) HIFunction *attractiveForce;

-(NSDictionary *)getParams;

@end
