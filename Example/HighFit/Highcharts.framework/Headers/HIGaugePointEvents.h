/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Events for each single point
*/
@interface HIGaugePointEvents: HIChartsJSONSerializable

/**
* description: Fires when a point is clicked. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. If the series.allowPointSelect option is true, the default action for the point's click event is to toggle the point's select state. Returning false cancels this action.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click/ : Click marker to alert values,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click-column/ : click column, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click-url/ : go to URL
*/
@property(nonatomic, readwrite) NSString /* Function */ *click;
/**
* description: Fires when the point is selected either programmatically or following a click on the point. One parameter, event, is passed to the function. Returning false cancels the operation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-select/ : Report the last selected point
*/
@property(nonatomic, readwrite) NSString /* Function */ *select;
/**
* description: Fires when the point is updated programmatically through the .update() method. One parameter, event, is passed to the function. The  new point options can be accessed through event.options. Returning false cancels the operation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-update/ : Confirm point updating
*/
@property(nonatomic, readwrite) NSString /* Function */ *update;
/**
* description: Fires when the mouse enters the area close to the point. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/ : Show values in the chart's corner on mouse over
*/
@property(nonatomic, readwrite) NSString /* Function */ *mouseOver;
/**
* description: Fires when the point is unselected either programmatically or following a click on the point. One parameter, event, is passed to the function. Returning false cancels the operation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-unselect/ : Report the last unselected point
*/
@property(nonatomic, readwrite) NSString /* Function */ *unselect;
/**
* description: Fires when the point is removed using the .remove() method. One parameter, event, is passed to the function. Returning false cancels the operation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-remove/ : Remove point and confirm
*/
@property(nonatomic, readwrite) NSString /* Function */ *remove;
/**
* description: Fires when the mouse leaves the area close to the point. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/ : Show values in the chart's corner on mouse over
*/
@property(nonatomic, readwrite) NSString /* Function */ *mouseOut;

-(NSDictionary *)getParams;

@end
