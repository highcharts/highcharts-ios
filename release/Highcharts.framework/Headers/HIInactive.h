/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimation.h"


/**
The opposite state of a hover for series.

**Try it**

* [Disabled inactive state](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/windbarb-series/)
*/
@interface HIInactive: HIChartsJSONSerializable

/**
Opacity of series elements (dataLabels, line, area).
*/
@property(nonatomic, readwrite) NSNumber *opacity;
@property(nonatomic, readwrite) HIAnimation *animation;
/**
Opacity for the links between nodes in the sankey diagram in inactive mode.
*/
@property(nonatomic, readwrite) NSNumber *linkOpacity;

-(NSDictionary *)getParams;

@end
