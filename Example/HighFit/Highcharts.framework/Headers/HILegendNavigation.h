/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Options for the paging or navigation appearing when the legend is overflown. Navigation works well on screen, but not in static exported images. One way of working around that is to http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation-enabled-false/ : increase the chart height in export.
*/
@interface HILegendNavigation: HIChartsJSONSerializable

/**
* description: The color of the inactive up or down arrow in the legend page navigation.  .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : 
				Legend page navigation demonstrated
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *inactiveColor;
/**
* description: How to animate the pages when navigating up or down. A value of true applies the default navigation given in  the chart.animation option. Additional options can be given as an object containing values for easing and duration.  .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : 
				Legend page navigation demonstrated
* default: true
*/
@property(nonatomic, readwrite) id /* Bool, Object */ animation;
/**
* description: Whether to enable the legend navigation. In most cases, disabling the navigation results in an unwanted overflow.
See also the http://www.highcharts.com/plugin-registry/single/8/Adapt-Chart-To-Legend : adapt chart to legend plugin for a solution to extend the chart height to make room for the legend, optionally in exported charts only.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The pixel size of the up and down arrows in the legend paging navigation.  .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : 
				Legend page navigation demonstrated
* default: 12
*/
@property(nonatomic, readwrite) NSNumber *arrowSize;
/**
* description: The color for the active up or down arrow in the legend page navigation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : 
				Legend page navigation demonstrated
* default: #003399
*/
@property(nonatomic, readwrite) HIColor *activeColor;
/**
* description: Text styles for the legend page navigation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : 
				Legend page navigation demonstrated
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;

-(NSDictionary *)getParams;

@end
