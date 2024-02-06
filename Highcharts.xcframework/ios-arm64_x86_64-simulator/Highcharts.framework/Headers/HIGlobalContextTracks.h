/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMapping.h"
#import "HIPointGrouping.h"
#import "HIActiveWhen.h"
#import "HISynthPatchOptionsObject.h"


/**
Context tracks to add globally, an array of either instrument tracks, speech tracks, or a mix. Context tracks are not tied to data points, but play at a set interval - either based on time or on prop values.

**Try it**

* [Using contexts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@interface HIGlobalContextTracks: HIChartsJSONSerializable

/**
Set a context track to play periodically every `timeInterval` milliseconds while the sonification is playing.

**Try it**

* [Using contexts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSNumber *timeInterval;
/**
Set a context track to play periodically every `valueInterval` units of a data property `valueProp` while the sonification is playing. For example, setting `valueProp` to `x` and `valueInterval` to 5 will play the context track for every 5th X value. The context audio events will be mapped to time according to the prop value relative to the min/max values for that prop.

**Try it**

* [Using contexts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSNumber *valueInterval;
/**
How to map context events to time when using the `valueInterval` option.

**Defaults to** `"linear"`.
*/
@property(nonatomic, readwrite) NSString *valueMapFunction;
/**
The point property to play context for when using `valueInterval`.

**Defaults to** `"x"`.
*/
@property(nonatomic, readwrite) NSString *valueProp;
/**
Mapping options for the audio parameters. All parameters can be either: - A string, referencing a point property to map to. - A number, setting the value of the audio parameter directly. - A callback function, returning the value programmatically. - An object defining detailed configuration of the mapping. If a function is used, it should return the desired value for the audio parameter. The function is called for each audio event to be played, and receives a context object parameter with `time`, and potentially `point` and `value` depending on the track. `point` is available if the audio event is related to a data point, and `value` is available if the track is used for a context track using `valueInterval`.

**Try it**

* [Overview of common mapping parameters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-overview)
* [Various types of mapping used](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/pitch-mapping)
* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) HIMapping *mapping;
/**
Show play marker (tooltip and/or crosshair) for a track.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showPlayMarker;
/**
Type of track. Always `"instrument"` for instrument tracks, and `"speech"` for speech tracks.

**Defaults to** `instrument`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Round pitch mapping to musical notes. If `false`, will play the exact mapped note, even if it is out of tune compared to the musical notes as defined by 440Hz standard tuning.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *roundToMusicalNotes;
/**
Options for point grouping, specifically for instrument tracks.
*/
@property(nonatomic, readwrite) HIPointGrouping *pointGrouping;
/**
Instrument to use for playing. Can either be a string referencing a synth preset, or it can be a synth configuration object.

**Defaults to** `piano`.

**Try it**

* [Overview of available presets](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/all-instruments)
* [Custom instrument](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/custom-instrument)
*/
@property(nonatomic, readwrite) HISynthPatchOptionsObject *instrument;
/**
Define a condition for when a track should be active and not. Can either be a function callback or a configuration object. If a function is used, it should return a `boolean` for whether or not the track should be active. The function is called for each audio event, and receives a parameter object with `time`, and potentially `point` and `value` properties depending on the track. `point` is available if the audio event is related to a data point. `value` is available if the track is used as a context track, and `valueInterval` is used.

**Try it**

* [Mapping zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-zones)
*/
@property(nonatomic, readwrite) HIActiveWhen *activeWhen;
/**
Name to use for a track when exporting to MIDI. By default it uses the series name if the track is related to a series.
*/
@property(nonatomic, readwrite) NSString *midiName;

-(NSDictionary *)getParams;

@end
