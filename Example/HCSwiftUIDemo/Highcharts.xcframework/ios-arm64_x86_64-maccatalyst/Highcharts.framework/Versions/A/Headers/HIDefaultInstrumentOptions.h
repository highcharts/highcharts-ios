/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMapping.h"
#import "HIPointGrouping.h"
#import "HISynthPatchOptionsObject.h"
#import "HIFunction.h"


/**
Default sonification options for all instrument tracks. If specific options are also set on individual tracks or per series, those will override these options.

**Try it**

* [Sonify points on click](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-sonify)
*/
@interface HIDefaultInstrumentOptions: HIChartsJSONSerializable

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
Mapping options for the audio parameters. All parameters can be either: - A string, referencing a point property to map to. - A number, setting the value of the audio parameter directly. - A callback function, returning the value programmatically. - An object defining detailed configuration of the mapping. If a function is used, it should return the desired value for the audio parameter. The function is called for each audio event to be played, and receives a context object parameter with `time`, and potentially `point` and `value` depending on the track. `point` is available if the audio event is related to a data point, and `value` is available if the track is used for a context track using `valueInterval`.

**Try it**

* [Overview of common mapping parameters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-overview)
* [Various types of mapping used](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/pitch-mapping)
* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) HIMapping *mapping;
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
@property(nonatomic, readwrite) HIFunction *activeWhen;
/**
Name to use for a track when exporting to MIDI. By default it uses the series name if the track is related to a series.
*/
@property(nonatomic, readwrite) NSString *midiName;

-(NSDictionary *)getParams;

@end
