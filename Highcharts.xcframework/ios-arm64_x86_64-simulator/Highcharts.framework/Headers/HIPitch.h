/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Musical pitch refers to how high or low notes are played. By default it is mapped to `y` so low `y` values are played with a lower pitch, and high values are played with a higher pitch. Pitch mapping has a few extra features compared to other audio parameters. Firstly, it accepts not only number values, but also string values denoting note names. These are given in the form `<note><octave>`, for example `"c6"` or `"F#2"`. Secondly, it is possible to map pitch to an array of notes. In this case, the ``gapBetweenNotes`` mapping determines the delay between these notes. Thirdly, it is possible to define a musical scale to follow when mapping. Can be set to a fixed value, an array, a prop to map to, a function, or a mapping object.

**Try it**

* [Various types of mapping used](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/pitch-mapping)
* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@interface HIPitch: HIChartsJSONSerializable

/**
What data values to map the parameter within. Mapping within `"series"` will make the lowest value point in the series map to the min audio parameter value, and the highest value will map to the max audio parameter. Mapping within `"chart"` will make the lowest value point in the whole chart map to the min audio parameter value, and the highest value in the whole chart will map to the max audio parameter. You can also map within the X or Y axis of each series.

**Defaults to** `yAxis`.

**Try it**

* [Mapping within demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-within)
*/
@property(nonatomic, readwrite) NSString *within;
/**
The maximum value for the audio parameter. This is the highest value the audio parameter will be mapped to.

**Defaults to** `c6`.
*/
@property(nonatomic, readwrite) NSString *max;
/**
Map pitches to a musical scale. The scale is defined as an array of semitone offsets from the root note.

**Try it**

* [Predefined scale presets](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/all-scales)
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *scale;
/**
A point property to map the mapping parameter to. A negative sign `-` can be placed before the property name to make mapping inverted.

**Defaults to** `y`.

**Try it**

* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
*/
@property(nonatomic, readwrite) NSString *mapTo;
/**
The minimum value for the audio parameter. This is the lowest value the audio parameter will be mapped to.

**Defaults to** `c2`.
*/
@property(nonatomic, readwrite) NSString *min;
/**
How to perform the mapping.

**Try it**

* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) NSString *mapFunction;
/**
A fixed value to use for the prop when mapping. For example, if mapping to `y`, setting value to `4` will map as if all points had a y value of 4.

**Try it**

* [Map to fixed y value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSNumber *value;

-(NSDictionary *)getParams;

@end
