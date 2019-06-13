/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMarker.h"


/**
Layout algorithm options for parent nodes.
*/
@interface HIParentNodeOptions: HIChartsJSONSerializable

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
When `initialPositions` are set to 'circle', `initialPositionRadius` is a distance from the center of circle, in which nodes are created.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *initialPositionRadius;
/**
Verlet integration only. Max speed that node can get in one iteration. In terms of simulation, it's a maximum translation (in pixels) that node can move (in both, x and y, dimensions). While `friction` is applied on all nodes, max speed is applied only for nodes that move very fast, for example small or disconnected ones.
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

**Try it**

* [Initial positions with callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-networkgraph/initial-positions/)
*/
@property(nonatomic, readwrite) NSString *initialPositions;
/**
Friction applied on forces to prevent nodes rushing to fast to the desired positions.
*/
@property(nonatomic, readwrite) NSNumber *friction;
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

-(NSDictionary *)getParams;

@end
