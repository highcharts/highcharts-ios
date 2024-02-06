/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDefaultInstrumentOptions.h"
#import "HIGlobalContextTracks.h"
#import "HIEvents.h"
#import "HIPointGrouping.h"
#import "HIGlobalTracks.h"
#import "HIDefaultSpeechOptions.h"
#import "HITracks.h"
#import "HIContextTracks.h"


/**
Options for configuring sonification and audio charts. Requires the [sonification module](https://code.highcharts.com/modules/sonification.js) to be loaded.

**Try it**

* [All predefined instruments](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/all-instruments)
* [Audio boxplots](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/audio-boxplot)
* [Context tracks](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
* [Musical chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sonification-music)
*/
@interface HISonification: HIChartsJSONSerializable

/**
Show X and Y axis crosshairs (if they exist) as the chart plays. Note that if multiple tracks that play at different times try to show the crosshairs, it can be glitchy, so it is recommended in those cases to turn this on/off for individual tracks using the `showPlayMarker` option.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showCrosshair;
/**
The time to wait in milliseconds after each data series when playing the series one after the other.

**Defaults to** `700`.

**Try it**

* [Notification after series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-earcon)
*/
@property(nonatomic, readwrite) NSNumber *afterSeriesWait;
/**
Overall/master volume for the sonification, from 0 to 1.

**Defaults to** `0.7`.
*/
@property(nonatomic, readwrite) NSNumber *masterVolume;
/**
Show tooltip as the chart plays. Note that if multiple tracks that play at different times try to show the tooltip, it can be glitchy, so it is recommended in those cases to turn this on/off for individual tracks using the `showPlayMarker` option.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showTooltip;
/**
Default sonification options for all instrument tracks. If specific options are also set on individual tracks or per series, those will override these options.

**Try it**

* [Sonify points on click](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-sonify)
*/
@property(nonatomic, readwrite) HIDefaultInstrumentOptions *defaultInstrumentOptions;
/**
Enable sonification functionality for the chart.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Context tracks to add globally, an array of either instrument tracks, speech tracks, or a mix. Context tracks are not tied to data points, but play at a set interval - either based on time or on prop values.

**Try it**

* [Using contexts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/plotline-context)
*/
@property(nonatomic, readwrite) NSArray <HIGlobalContextTracks *> *globalContextTracks;
/**
Set up event handlers for the sonification
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
Options for grouping data points together when sonifying. This allows for the visual presentation to contain more points than what is being played. If not enabled, all visible / uncropped points are played.
*/
@property(nonatomic, readwrite) HIPointGrouping *pointGrouping;
/**
The total duration of the sonification, in milliseconds.

**Defaults to** `6000`.
*/
@property(nonatomic, readwrite) NSNumber *duration;
/**
Global tracks to add to every series. Defined as an array of either instrument or speech tracks, or a combination.
*/
@property(nonatomic, readwrite) NSArray <HIGlobalTracks *> *globalTracks;
/**
How long to wait between each recomputation of the sonification, if the chart updates rapidly. This avoids slowing down processes like panning. Given in milliseconds.

**Defaults to** `200`.
*/
@property(nonatomic, readwrite) NSNumber *updateInterval;
/**
What order to play the data series in, either `sequential` where the series play individually one after the other, or `simultaneous` where the series play all at once.

**Defaults to** `sequential`.

**Try it**

* [Simultaneous sonification](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-simultaneous)
*/
@property(nonatomic, readwrite) NSString *order;
/**
Default sonification options for all speech tracks. If specific options are also set on individual tracks or per series, those will override these options.

**Try it**

* [Speak values](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/speak-values)
*/
@property(nonatomic, readwrite) HIDefaultSpeechOptions *defaultSpeechOptions;
@property(nonatomic, readwrite) NSString *playAsSoundClickAnnouncement;
@property(nonatomic, readwrite) NSString *playAsSoundButtonText;
/**
Tracks for this series. Given as an array of instrument tracks, speech tracks, or a mix of both.
*/
@property(nonatomic, readwrite) NSArray <HITracks *> *tracks;
/**
Context tracks for this series. Context tracks are tracks that are not tied to data points. Given as an array of instrument tracks, speech tracks, or a mix of both.
*/
@property(nonatomic, readwrite) NSArray <HIContextTracks *> *contextTracks;

-(NSDictionary *)getParams;

@end
