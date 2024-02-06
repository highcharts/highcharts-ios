/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIRate.h"
#import "HIPitch.h"
#import "HIPlayDelay.h"
#import "HIVolume.h"
#import "HITime.h"
#import "HINoteDuration.h"
#import "HITremolo.h"
#import "HIHighpass.h"
#import "HIFrequency.h"
#import "HIGapBetweenNotes.h"
#import "HILowpass.h"
#import "HIPan.h"


/**
Mapping options for the audio parameters. All parameters can be either: - A string, referencing a point property to map to. - A number, setting the value of the audio parameter directly. - A callback function, returning the value programmatically. - An object defining detailed configuration of the mapping. If a function is used, it should return the desired value for the audio parameter. The function is called for each audio event to be played, and receives a context object parameter with `time`, and potentially `point` and `value` depending on the track. `point` is available if the audio event is related to a data point, and `value` is available if the track is used for a context track using `valueInterval`.

**Try it**

* [Overview of common mapping parameters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/mapping-overview)
* [Various types of mapping used](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/pitch-mapping)
* [Inverted mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/polarity-invert)
* [Logarithmic mapping to property](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/log-mapping)
*/
@interface HIMapping: HIChartsJSONSerializable

/**
Text mapping for speech tracks.
*/
@property(nonatomic, readwrite) NSString *text;
/**
Rate mapping for speech tracks.
*/
@property(nonatomic, readwrite) HIRate *rate;
/**
Speech pitch (how high/low the voice is) multiplier.

**Defaults to** `1`.

**Try it**

* [Speak values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/speak-values)
*/
@property(nonatomic, readwrite) HIPitch *pitch;
/**
Milliseconds to wait before playing, comes in addition to the time determined by the `time` mapping. Can also be negative to play before the mapped time.
*/
@property(nonatomic, readwrite) HIPlayDelay *playDelay;
/**
Volume of the speech announcement.

**Defaults to** `0.4`.
*/
@property(nonatomic, readwrite) HIVolume *volume;
/**
Time mapping determines what time each point plays. It is defined as an offset in milliseconds, where 0 means it plays immediately when the chart is sonified. By default time is mapped to `x`, meaning points with the lowest `x` value plays first, and points with the highest `x` value plays last. Can be set to a fixed value, a prop to map to, a function, or a mapping object.

**Defaults to** `"x"`.

**Try it**

* [Play points in order of Y value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-play-time)
*/
@property(nonatomic, readwrite) HITime *time;
/**
Note duration determines for how long a note plays, in milliseconds. It only affects instruments that are able to play continuous sustained notes. Examples of these instruments from the presets include `flute`, `saxophone`, `trumpet`, `sawsynth`, `wobble`, `basic1`, `basic2`, `sine`, `sineGlide`, `triangle`, `square`, `sawtooth`, `noise`, `filteredNoise`, and `wind`. Can be set to a fixed value, a prop to map to, a function, or a mapping object.

**Defaults to** `200`.
*/
@property(nonatomic, readwrite) HINoteDuration *noteDuration;
/**
Mapping options for tremolo effects. Tremolo is repeated changes of volume over time.
*/
@property(nonatomic, readwrite) HITremolo *tremolo;
/**
Mapping options for the highpass filter. A highpass filter lets high frequencies through, but stops low frequencies, making the sound thinner.
*/
@property(nonatomic, readwrite) HIHighpass *highpass;
/**
Frequency in Hertz of notes. Overrides pitch mapping if set.
*/
@property(nonatomic, readwrite) HIFrequency *frequency;
/**
Gap in milliseconds between notes if pitch is mapped to an array of notes. Can be set to a fixed value, a prop to map to, a function, or a mapping object.

**Defaults to** `100`.

**Try it**

* [Mapping to gap between notes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/audio-map)
*/
@property(nonatomic, readwrite) HIGapBetweenNotes *gapBetweenNotes;
/**
Mapping options for the lowpass filter. A lowpass filter lets low frequencies through, but stops high frequencies, making the sound more dull.
*/
@property(nonatomic, readwrite) HILowpass *lowpass;
/**
Pan refers to the stereo panning position of the sound. It is defined from -1 (left) to 1 (right). By default it is mapped to `x`, making the sound move from left to right as the chart plays. Can be set to a fixed value, a prop to map to, a function, or a mapping object.

**Defaults to** `"x"`.
*/
@property(nonatomic, readwrite) HIPan *pan;

-(NSDictionary *)getParams;

@end
