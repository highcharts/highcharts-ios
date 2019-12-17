/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimationOptionsObject.h"


/**
The opposite state of a hover for series.

**Try it**

* [Disabled inactive state by setting opacity](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-inactive-opacity)
*/
@interface HIInactive: HIChartsJSONSerializable

/**
Opacity of series elements (dataLabels, line, area). Set to 1 to disable inactive state.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
The animation for entering the inactive state.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Opacity for the links between nodes in the sankey diagram in inactive mode.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;

-(NSDictionary *)getParams;

@end
