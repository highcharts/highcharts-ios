/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMarker.h"
#import "HIFunction.h"


/**
Layout algorithm options for parent nodes.
*/
@interface HIParentNodeOptions: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber /* Bool */ *seriesInteraction;
/**
Gravitational const used in the barycenter force of the algorithm.

**Defaults to** `0.03`.

**Try it**

* [Custom forces with Euler integration](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/forces/)
*/
@property(nonatomic, readwrite) NSNumber *gravitationalConstant;
/**
Max number of iterations before algorithm will stop. In general, algorithm should find positions sooner, but when rendering huge number of nodes, it is recommended to increase this value as finding perfect graph positions can require more time.

**Defaults to** `400`.
*/
@property(nonatomic, readwrite) NSNumber *maxIterations;
/**
When `initialPositions` are set to 'circle', `initialPositionRadius` is a distance from the center of circle, in which nodes are created.

**Defaults to** `100`.
*/
@property(nonatomic, readwrite) NSNumber *initialPositionRadius;
/**
Verlet integration only. Max speed that node can get in one iteration. In terms of simulation, it's a maximum translation (in pixels) that node can move (in both, x and y, dimensions). While `friction` is applied on all nodes, max speed is applied only for nodes that move very fast, for example small or disconnected ones.

**Defaults to** `50`.
*/
@property(nonatomic, readwrite) NSNumber *maxSpeed;
/**
Styling options for parentNodes markers. Similar to line.marker options.

**Try it**

* [Bubble size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/parentnode-style/)
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
Initial layout algorithm for positioning nodes. Can be one of built-in options ("circle", "random") or a function where positions should be set on each node (`this.nodes`) as `node.plotX` and `node.plotY`

**Defaults to** `circle`.

**Try it**

* [Initial positions with callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/initial-positions/)
*/
@property(nonatomic, readwrite) NSString *initialPositions;
/**
Friction applied on forces to prevent nodes rushing to fast to the desired positions.

**Defaults to** `-0.981`.
*/
@property(nonatomic, readwrite) NSNumber *friction;
/**
Integration type. Available options are `'euler'` and `'verlet'`. Integration determines how forces are applied on particles. In Euler integration, force is applied direct as `newPosition += velocity;`. In Verlet integration, new position is based on a previous posittion without velocity: `newPosition += previousPosition - newPosition`. Note that different integrations give different results as forces are different. In Highcharts v7.0.x only `'euler'` integration was supported.

**Defaults to** `euler`.

**Try it**

* [Comparison of Verlet and Euler integrations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/integration-comparison/)
*/
@property(nonatomic, readwrite) NSString *integration;
/**
Approximation used to calculate repulsive forces affecting nodes. By default, when calculateing net force, nodes are compared against each other, which gives O(N^2) complexity. Using Barnes-Hut approximation, we decrease this to O(N log N), but the resulting graph will have different layout. Barnes-Hut approximation divides space into rectangles via quad tree, where forces exerted on nodes are calculated directly for nearby cells, and for all others, cells are treated as a separate node with center of mass.

**Defaults to** `none`.

**Try it**

* [A graph with Barnes-Hut approximation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/barnes-hut-approximation/)
*/
@property(nonatomic, readwrite) NSString *approximation;
/**
Experimental. Enables live simulation of the algorithm implementation. All nodes are animated as the forces applies on them.

**Try it**

* [Live simulation enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/network-graph/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enableSimulation;
/**
Ideal length (px) of the link between two nodes. When not defined, length is calculated as: `Math.pow(availableWidth * availableHeight / nodesLength, 0.4);` Note: Because of the algorithm specification, length of each link might be not exactly as specified.

**Try it**

* [Numerical values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/styled-links/)
*/
@property(nonatomic, readwrite) NSNumber *linkLength;
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

**Defaults to** `0.5`.
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
/**
Type of the algorithm used when positioning nodes.

**Defaults to** `reingold-fruchterman`.
*/
@property(nonatomic, readwrite) NSString *type;

-(NSDictionary *)getParams;

@end
