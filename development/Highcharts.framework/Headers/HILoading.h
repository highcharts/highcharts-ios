/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
The loading options control the appearance of the loading screen that covers the plot area on chart operations. This screen only appears after an explicit call to `chart.showLoading()`. It is a utility for developers to communicate to the end user that something is going on, for example while retrieving new data via an XHR connection. The "Loading..." text itself is not part of this configuration object, but part of the `lang` object.
*/
@interface HILoading: HIChartsJSONSerializable

/**
CSS styles for the loading screen that covers the plot area. In styled mode, the loading label is styled with the `.highcharts-loading` class.

**Defaults to** `{"position": "absolute", "backgroundColor": "#ffffff", "opacity": 0.5, "textAlign": "center"}`.

**Try it**

* [Gray plot area, white text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/loading/style/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
CSS styles for the loading label `span`.

**Defaults to** `{"fontWeight": "bold", "position": "relative", "top": "45%"}`.

**Try it**

* [Vertically centered](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/loading/labelstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *labelStyle;
/**
The duration in milliseconds of the fade out effect.

**Defaults to** `100`.

**Try it**

* [Fade in and out over a second](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/loading/hideduration/)
*/
@property(nonatomic, readwrite) NSNumber *hideDuration;
/**
The duration in milliseconds of the fade in effect.

**Defaults to** `100`.

**Try it**

* [Fade in and out over a second](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/loading/hideduration/)
*/
@property(nonatomic, readwrite) NSNumber *showDuration;

-(NSDictionary *)getParams;

@end
