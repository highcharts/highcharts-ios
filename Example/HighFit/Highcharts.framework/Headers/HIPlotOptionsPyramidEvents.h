/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


@interface HIPlotOptionsPyramidEvents: HIChartsJSONSerializable

/**
* description: Fires after the series has finished its initial animation, or in case animation is disabled, immediately as the series is displayed.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-afteranimate/ : Show label after animate
*/
@property(nonatomic, readwrite) NSString /* Function */ *afterAnimate;
/**
* description: Fires when the series is shown after chart generation time, either by clicking the legend item or by calling .show().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-show/ : Alert when the series is shown by clicking 
			the legend item.
*/
@property(nonatomic, readwrite) NSString /* Function */ *show;
/**
* description: Fires when the series is clicked. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. Additionally, event.point holds a pointer to the nearest point on the graph.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-click/ : Alert click info
*/
@property(nonatomic, readwrite) NSString /* Function */ *click;
/**
* description: Not applicable to pies, as the legend item is per point. See point.events.
*/
@property(nonatomic, readwrite) NSString /* Function */ *legendItemClick;
/**
* description: Fires when the mouse leaves the graph. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. If the  stickyTracking option is true, mouseOut doesn't happen before the mouse enters another graph or leaves the plot area.
* demo: Log mouse over and out http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-mouseover-sticky/ : with sticky tracking
			by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-mouseover-no-sticky/ : without sticky tracking
*/
@property(nonatomic, readwrite) NSString /* Function */ *mouseOut;
/**
* description: Fires when the series is hidden after chart generation time, either by clicking the legend item or by calling .hide().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-hide/ : Alert when the series is hidden by clicking 
			the legend item
*/
@property(nonatomic, readwrite) NSString /* Function */ *hide;
/**
* description: Fires when the mouse enters the graph. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts.
* demo: Log mouse over and out http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-mouseover-sticky/ : with sticky tracking
			by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-mouseover-no-sticky/ : without sticky tracking
*/
@property(nonatomic, readwrite) NSString /* Function */ *mouseOver;
/**
* description: Fires when the checkbox next to the point name in the legend is clicked. One parameter, event, is passed to the function. The state of the checkbox is found by event.checked. The checked item is found by event.item. Return false to prevent the default action which is to toggle the select state of the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-checkboxclick/ : Alert checkbox status
*/
@property(nonatomic, readwrite) NSString /* Function */ *checkboxClick;

-(NSDictionary *)getParams;

@end
