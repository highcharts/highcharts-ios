/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Define a condition for when a track should be active and not. Can either be a function callback or a configuration object. If a function is used, it should return a `boolean` for whether or not the track should be active. The function is called for each audio event, and receives a parameter object with `time`, and potentially `point` and `value` properties depending on the track. `point` is available if the audio event is related to a data point. `value` is available if the track is used as a context track, and `valueInterval` is used.

**Try it**

* [Mapping zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-zones)
*/
@interface HIActiveWhen: HIChartsJSONSerializable

/**
Track is only active when `prop` was above, and is now at or below this value. If both `crossingUp` and `crossingDown` are defined, the track is active if either condition is met.
*/
@property(nonatomic, readwrite) NSNumber *crossingDown;
/**
Track is only active when `prop` is below or at this value.
*/
@property(nonatomic, readwrite) NSNumber *max;
/**
The point property to compare, for example `y` or `x`.
*/
@property(nonatomic, readwrite) NSString *prop;
/**
Track is only active when `prop` was below, and is now at or above this value. If both `crossingUp` and `crossingDown` are defined, the track is active if either condition is met.
*/
@property(nonatomic, readwrite) NSNumber *crossingUp;
/**
Track is only active when `prop` is above or at this value.
*/
@property(nonatomic, readwrite) NSNumber *min;

-(NSDictionary *)getParams;

@end
