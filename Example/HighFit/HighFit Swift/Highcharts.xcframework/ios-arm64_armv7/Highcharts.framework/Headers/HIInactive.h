/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimationOptionsObject.h"


/**
The opposite state of a hover for a single point node. Applied to all not connected nodes to the hovered one.
*/
@interface HIInactive: HIChartsJSONSerializable

/**
Opacity of inactive markers.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
Animation when not hovering over the node.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Enable or disable the inactive state for a series

**Defaults to** `true`.

**Try it**

* [Disabled inactive state](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-inactive-disabled)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Opacity for the links between nodes in the sankey diagram in inactive mode.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;

-(NSDictionary *)getParams;

@end
