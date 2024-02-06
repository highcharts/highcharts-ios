/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Map to tremolo speed, from 0 to 1. This determines the speed of the tremolo effect, how fast the volume changes.
*/
@interface HISpeed: HIChartsJSONSerializable

/**
How to perform the mapping.

**Try it**

* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) NSString *mapFunction;
/**
The minimum value for the audio parameter. This is the lowest value the audio parameter will be mapped to.
*/
@property(nonatomic, readwrite) NSNumber *min;
/**
The maximum value for the audio parameter. This is the highest value the audio parameter will be mapped to.
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
What data values to map the parameter within. Mapping within `"series"` will make the lowest value point in the series map to the min audio parameter value, and the highest value will map to the max audio parameter. Mapping within `"chart"` will make the lowest value point in the whole chart map to the min audio parameter value, and the highest value in the whole chart will map to the max audio parameter. You can also map within the X or Y axis of each series.

**Try it**

* [Mapping within demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-within)
*/
@property(nonatomic, readwrite) NSString *within;
/**
A fixed value to use for the prop when mapping. For example, if mapping to `y`, setting value to `4` will map as if all points had a y value of 4.

**Try it**

* [Map to fixed y value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
A point property to map the mapping parameter to. A negative sign `-` can be placed before the property name to make mapping inverted.

**Try it**

* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
*/
@property(nonatomic, readwrite) NSString *mapTo;

-(NSDictionary *)getParams;

@end
