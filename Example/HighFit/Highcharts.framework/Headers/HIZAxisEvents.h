/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Event handlers for the axis.
*/
@interface HIZAxisEvents: HIChartsJSONSerializable

/**
* description: As opposed to the setExtremes event, this event fires after the final min and max values are computed and corrected for minRange.
Fires when the minimum and maximum is set for the axis, either by calling the .setExtremes() method or by selecting an area in the chart. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on which library is used as the base for Highcharts.
The new user set minimum and maximum values can be found by event.min and event.max. These reflect the axis minimum and maximum in axis values. The actual data extremes are found in event.dataMin and event.dataMax.
*/
@property(nonatomic, readwrite) NSString /* Function */ *afterSetExtremes;
/**
* description: An event fired when a break from this axis occurs on a point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-visualized/ : Visualization of a Break
*/
@property(nonatomic, readwrite) NSString /* Function */ *pointBreak;
/**
* description: An event fired when a point falls inside a break from this axis.
*/
@property(nonatomic, readwrite) NSString /* Function */ *pointInBreak;
/**
* description: An event fired after the breaks have rendered.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-event// : afterBreak Event
*/
@property(nonatomic, readwrite) NSString /* Function */ *afterBreaks;
/**
* description: Fires when the minimum and maximum is set for the axis, either by calling the .setExtremes() method or by selecting an area in the chart. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on which library is used as the base for Highcharts.
The new user set minimum and maximum values can be found by event.min and event.max. These reflect the axis minimum and maximum in data values. When an axis is zoomed all the way out from the "Reset zoom" button, event.min and event.max are null, and the new extremes are set based on this.dataMin and this.dataMax.
*/
@property(nonatomic, readwrite) NSString /* Function */ *setExtremes;

-(NSDictionary *)getParams;

@end
