/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Event listeners for the chart.
*/
@interface HIChartEvents: HIChartsJSONSerializable

/**
* description: Fires after a chart is printed through the context menu item or the Chart.print method. Requires the exporting module.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/ : Rescale the chart to print
*/
@property(nonatomic, readwrite) NSString /* Function */ *afterPrint;
/**
* description: Fires when the chart is finished loading. Since v4.2.2, it also waits for images to be loaded, for example from point markers. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts.
There is also a second parameter to the chart constructor where a callback function can be passed to be executed on chart.load.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-load/ : Alert on chart load
*/
@property(nonatomic, readwrite) NSString /* Function */ *load;
/**
* description: Fires when drilling up from a drilldown series.
*/
@property(nonatomic, readwrite) NSString /* Function */ *drillup;
/**
* description: Fires before a chart is printed through the context menu item or the Chart.print method. Requires the exporting module.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/ : Rescale the chart to print
*/
@property(nonatomic, readwrite) NSString /* Function */ *beforePrint;
/**
* description: Fires when a series is added to the chart after load time, using the addSeries method. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. Through event.options you can access the series options that was passed to the addSeries  method. Returning false prevents the series from being added.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-addseries/ : Alert on add series
*/
@property(nonatomic, readwrite) NSString /* Function */ *addSeries;
/**
* description: Fires when an area of the chart has been selected. Selection is enabled by setting the chart's zoomType. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. The default action for the  selection event is to zoom the  chart to the selected area. It can be prevented by calling  event.preventDefault(). Information on the selected area can be found through event.xAxis and  event.yAxis, which are arrays containing the axes of each dimension and each axis' min and max values. The primary axes are event.xAxis[0] and event.yAxis[0]. Remember the unit of a datetime axis is milliseconds since 1970-01-01 00:00:00.
selection: function(event) {
	// log the min and max of the primary, datetime x-axis
	console.log(
		Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', event.xAxis[0].min),
		Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', event.xAxis[0].max)
	);
	// log the min and max of the y axis
	console.log(event.yAxis[0].min, event.yAxis[0].max);
}
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection/ : Report on selection and reset, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/ : select a range of points through a drag selection.
*/
@property(nonatomic, readwrite) NSString /* Function */ *selection;
/**
* description: Fires when a drilldown point is clicked, before the new series is added. This event is also utilized for async drilldown, where the seriesOptions are not added by option, but rather loaded async. Note that when clicking a category label to trigger multiple series drilldown, one drilldown event is triggered per point in the category.
Event arguments:

category
If a category label was clicked, which index.
point
The originating point.
originalEvent
The original browser event (usually click) that triggered the drilldown.
points
If a category label was clicked, this array holds all points corresponing to the category.
seriesOptions
Options for the new series


* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/drilldown/async/ : Async drilldown
*/
@property(nonatomic, readwrite) NSString /* Function */ *drilldown;
/**
* description: Fires after initial load of the chart (directly after the load event), and after each redraw (directly after the redraw event).
*/
@property(nonatomic, readwrite) NSString /* Function */ *render;
/**
* description: Fires when the chart is redrawn, either after a call to chart.redraw() or after an axis, series or point is modified with the redraw option set to true. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-redraw/ : Alert on chart redraw
*/
@property(nonatomic, readwrite) NSString /* Function */ *redraw;
/**
* description: Fires when clicking on the plot background. One parameter, event, is passed to the function. This contains common event information based on jQuery or MooTools depending on  which library is used as the base for Highcharts. Information on the clicked spot can be found through event.xAxis and  event.yAxis, which are arrays containing the axes of each dimension and each axis' value at the clicked spot. The primary axes are event.xAxis[0] and event.yAxis[0]. Remember the unit of a datetime axis is milliseconds since 1970-01-01 00:00:00.
click: function(e) {
	console.log(
		Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', e.xAxis[0].value), 
		e.yAxis[0].value
	)
}
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-click/ : Alert coordinates on click. http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/events-container/ : Alternatively, attach event to container
*/
@property(nonatomic, readwrite) NSString /* Function */ *click;
/**
* description: In a chart with multiple drilldown series, this event fires after all the series have been drilled up.
*/
@property(nonatomic, readwrite) NSString /* Function */ *drillupall;

-(NSDictionary *)getParams;

@end
