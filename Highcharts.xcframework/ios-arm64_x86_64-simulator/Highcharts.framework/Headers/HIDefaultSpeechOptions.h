/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPointGrouping.h"
#import "HIMapping.h"
#import "HIActiveWhen.h"


/**
Default sonification options for all speech tracks. If specific options are also set on individual tracks or per series, those will override these options.

**Try it**

* [Speak values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/speak-values)
*/
@interface HIDefaultSpeechOptions: HIChartsJSONSerializable

/**
Options for point grouping, specifically for instrument tracks.
*/
@property(nonatomic, readwrite) HIPointGrouping *pointGrouping;
/**
Type of track. Always `"instrument"` for instrument tracks, and `"speech"` for speech tracks.

**Defaults to** `speech`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Mapping configuration for the speech/audio parameters. All parameters except `text` can be either: - A string, referencing a point property to map to. - A number, setting the value of the speech parameter directly. - A callback function, returning the value programmatically. - An object defining detailed configuration of the mapping. If a function is used, it should return the desired value for the speech parameter. The function is called for each speech event to be played, and receives a context object parameter with `time`, and potentially `point` and `value` depending on the track. `point` is available if the audio event is related to a data point, and `value` is available if the track is used for a context track using `valueInterval`.

**Try it**

* [Overview of common mapping parameters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-overview)
* [Various types of mapping used](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/pitch-mapping)
* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@property(nonatomic, readwrite) HIMapping *mapping;
/**
The language to speak in for speech tracks, as an IETF BCP 47 language tag.

**Defaults to** `en-US`.

**Try it**

* [French language speech](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/audio-map)
*/
@property(nonatomic, readwrite) NSString *language;
/**
Name of the voice synthesis to prefer for speech tracks. If not available, falls back to the default voice for the selected language. Different platforms provide different voices for web speech synthesis.
*/
@property(nonatomic, readwrite) NSString *preferredVoice;
/**
Show play marker (tooltip and/or crosshair) for a track.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showPlayMarker;
/**
Define a condition for when a track should be active and not. Can either be a function callback or a configuration object. If a function is used, it should return a `boolean` for whether or not the track should be active. The function is called for each audio event, and receives a parameter object with `time`, and potentially `point` and `value` properties depending on the track. `point` is available if the audio event is related to a data point. `value` is available if the track is used as a context track, and `valueInterval` is used.

**Try it**

* [Mapping zones](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-zones)
*/
@property(nonatomic, readwrite) HIActiveWhen *activeWhen;

-(NSDictionary *)getParams;

@end
