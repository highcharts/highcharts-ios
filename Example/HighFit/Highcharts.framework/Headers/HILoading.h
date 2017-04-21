/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The loading options control the appearance of the loading screen that covers the 
	plot area on chart operations. This screen only appears after an explicit call
	to chart.showLoading(). It is a utility for developers to communicate
	to the end user that something is going on, for example while retrieving new data
	via an XHR connection. The "Loading..." text itself is not part of this configuration
	object, but part of the lang object.
*/
@interface HILoading: HIChartsJSONSerializable

/**
* description: The duration in milliseconds of the fade in effect.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/loading/hideduration/ : Fade in and out over a second
* default: 100
*/
@property(nonatomic, readwrite) NSNumber *showDuration;
/**
* description: CSS styles for the loading screen that covers the plot area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/loading/style/ : Gray plot area, white text
* default: { "position": "absolute", "backgroundColor": "#ffffff", "opacity": 0.5, "textAlign": "center" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: CSS styles for the loading label span.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/loading/labelstyle/ : Vertically centered
* default: { "fontWeight": "bold", "position": "relative", "top": "45%" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *labelStyle;
/**
* description: The duration in milliseconds of the fade out effect.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/loading/hideduration/ : Fade in and out over a second
* default: 100
*/
@property(nonatomic, readwrite) NSNumber *hideDuration;

-(NSDictionary *)getParams;

@end
