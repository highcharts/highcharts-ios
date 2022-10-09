/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPosition.h"
#import "HISVGAttributes.h"


/**
Options for the _Series on point_ feature. Only `pie` and `sunburst` series are supported at this moment.

**Try it**

* [Series on point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-on-point/series-on-point)
*/
@interface HIOnPoint: HIChartsJSONSerializable

/**
Options allowing to set a position and an offset of the series in the _Series on point_ feature.
*/
@property(nonatomic, readwrite) HIPosition *position;
/**
Options for the connector in the _Series on point_ feature. In styled mode, the connector can be styled with the `.highcharts-connector-seriesonpoint` class name.
*/
@property(nonatomic, readwrite) HISVGAttributes *connectorOptions;
/**
The `id` of the point that we connect the series to. Only points with a given `plotX` and `plotY` values and map points are valid.
*/
@property(nonatomic, readwrite) NSString *id;

-(NSDictionary *)getParams;

@end
