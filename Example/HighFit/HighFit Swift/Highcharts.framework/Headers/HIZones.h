/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMarker.h"
#import "HIColor.h"


/**
An array defining zones within marker clusters. In styled mode, the color zones are styled with the `.highcharts-cluster-zone-{n}` class, or custom classed from the `className` option.

**Try it**

* [Marker clusters zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/marker-clusters/basic)
* [Zones on maps](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/marker-clusters/custom-alg)
*/
@interface HIZones: HIChartsJSONSerializable

/**
Styled mode only. A custom class name for the zone.

**Try it**

* [Zones styled by class name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/color-zones/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
Settings for the cluster marker belonging to the zone.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
The value where the zone starts.
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
The value where the zone ends.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
Defines the color of the series.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
A name for the dash style to use for the graph.

**Try it**

* [Dashed line indicates prognosis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/color-zones-dashstyle-dot/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
Defines the fill color for the series (in area type series)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The value up to where the zone extends, if undefined the zones stretches to the last value in the series.
*/
@property(nonatomic, readwrite) NSNumber *value;

-(NSDictionary *)getParams;

@end
