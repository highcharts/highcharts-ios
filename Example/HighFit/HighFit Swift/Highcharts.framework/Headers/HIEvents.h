/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
General event handlers for the series items. These event hooks can also be attached to the series at run time using the `Highcharts.addEvent` function.
*/
@interface HIEvents: HIChartsJSONSerializable

/**
Not applicable to pies, as the legend item is per point. See point. events.
*/
@property(nonatomic, readwrite) HIFunction *legendItemClick;
/**
Fires when the checkbox next to the point name in the legend is clicked. One parameter, event, is passed to the function. The state of the checkbox is found by event.checked. The checked item is found by event.item. Return false to prevent the default action which is to toggle the select state of the series.

**Try it**

* [Alert checkbox status](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-checkboxclick/)
*/
@property(nonatomic, readwrite) HIFunction *checkboxClick;
/**
An event fired when a point falls inside a break from this axis.
*/
@property(nonatomic, readwrite) HIFunction *pointInBreak;
/**
An event fired after the breaks have rendered.

**Try it**

* [AfterBreak Event](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-event/)
*/
@property(nonatomic, readwrite) HIFunction *afterBreaks;
/**
An event fired when a break from this axis occurs on a point.

**Try it**

* [Visualization of a Break](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-visualized/)
*/
@property(nonatomic, readwrite) HIFunction *pointBreak;
/**
Fires when the minimum and maximum is set for the axis, either by calling the `.setExtremes()` method or by selecting an area in the chart. One parameter, `event`, is passed to the function, containing common event information. The new user set minimum and maximum values can be found by `event.min` and `event.max`. These reflect the axis minimum and maximum in data values. When an axis is zoomed all the way out from the "Reset zoom" button, `event.min` and `event.max` are null, and the new extremes are set based on `this.dataMin` and `this.dataMax`.
*/
@property(nonatomic, readwrite) HIFunction *setExtremes;
/**
As opposed to the `setExtremes` event, this event fires after the final min and max values are computed and corrected for `minRange`. Fires when the minimum and maximum is set for the axis, either by calling the `.setExtremes()` method or by selecting an area in the chart. One parameter, `event`, is passed to the function, containing common event information. The new user set minimum and maximum values can be found by `event.min` and `event.max`. These reflect the axis minimum and maximum in axis values. The actual data extremes are found in `event.dataMin` and `event.dataMax`.
*/
@property(nonatomic, readwrite) HIFunction *afterSetExtremes;
/**
Fires when the chart is finished loading. Since v4.2.2, it also waits for images to be loaded, for example from point markers. One parameter, `event`, is passed to the function, containing common event information. There is also a second parameter to the chart constructor where a callback function can be passed to be executed on chart.load.

**Try it**

* [Alert on chart load](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-load/)
*/
@property(nonatomic, readwrite) HIFunction *load;
/**
Fires when an area of the chart has been selected. Selection is enabled by setting the chart's zoomType. One parameter, `event`, is passed to the function, containing common event information. The default action for the selection event is to zoom the chart to the selected area. It can be prevented by calling `event.preventDefault()`. Information on the selected area can be found through `event.xAxis` and `event.yAxis`, which are arrays containing the axes of each dimension and each axis' min and max values. The primary axes are `event.xAxis[0]` and `event.yAxis[0]`. Remember the unit of a datetime axis is milliseconds since 1970-01-01 00:00:00. selection: function(event) {   // log the min and max of the primary, datetime x-axis   console.log(     Highcharts.dateFormat(       '%Y-%m-%d %H:%M:%S',       event.xAxis[0].min     ),     Highcharts.dateFormat(       '%Y-%m-%d %H:%M:%S',       event.xAxis[0].max     )   );   // log the min and max of the y axis   console.log(event.yAxis[0].min, event.yAxis[0].max); }

**Try it**

* [Report on selection and reset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection/)
* [Select a range of points through a drag selection](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/)
*/
@property(nonatomic, readwrite) HIFunction *selection;
/**
Fires after initial load of the chart (directly after the `load` event), and after each redraw (directly after the `redraw` event).
*/
@property(nonatomic, readwrite) HIFunction *render;
/**
Fires when a series is added to the chart after load time, using the `addSeries` method. One parameter, `event`, is passed to the function, containing common event information. Through `event.options` you can access the series options that was passed to the `addSeries` method. Returning false prevents the series from being added.

**Try it**

* [Alert on add series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-addseries/)
*/
@property(nonatomic, readwrite) HIFunction *addSeries;
/**
Fires when drilling up from a drilldown series.
*/
@property(nonatomic, readwrite) HIFunction *drillup;
/**
Fires before a chart is printed through the context menu item or the `Chart.print` method. Requires the exporting module.

**Try it**

* [Rescale the chart to print](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/)
*/
@property(nonatomic, readwrite) HIFunction *beforePrint;
/**
In a chart with multiple drilldown series, this event fires after all the series have been drilled up.
*/
@property(nonatomic, readwrite) HIFunction *drillupall;
/**
Fires when a drilldown point is clicked, before the new series is added. This event is also utilized for async drilldown, where the seriesOptions are not added by option, but rather loaded async. Note that when clicking a category label to trigger multiple series drilldown, one `drilldown` event is triggered per point in the category. Event arguments:   If a category label was clicked, which index.  The originating point.  The original browser event (usually click) that triggered the drilldown.  If a category label was clicked, this array holds all points corresponing to the category.  Options for the new series 

**Try it**

* [Async drilldown](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/async/)
*/
@property(nonatomic, readwrite) HIFunction *drilldown;
/**
Fires when the chart is redrawn, either after a call to `chart.redraw()` or after an axis, series or point is modified with the `redraw` option set to true. One parameter, `event`, is passed to the function, containing common event information.

**Try it**

* [Alert on chart redraw](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-redraw/)
*/
@property(nonatomic, readwrite) HIFunction *redraw;
/**
Fires when clicking on the plot background. One parameter, `event`, is passed to the function, containing common event information. Information on the clicked spot can be found through `event.xAxis` and `event.yAxis`, which are arrays containing the axes of each dimension and each axis' value at the clicked spot. The primary axes are `event.xAxis[0]` and `event.yAxis[0]`. Remember the unit of a datetime axis is milliseconds since 1970-01-01 00:00:00. click: function(e) {   console.log(     Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', e.xAxis[0].value),     e.yAxis[0].value   ) }

**Try it**

* [Alert coordinates on click](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-click/)
* [Alternatively, attach event to container](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-container/)
*/
@property(nonatomic, readwrite) HIFunction *click;
/**
Fires after a chart is printed through the context menu item or the `Chart.print` method. Requires the exporting module.

**Try it**

* [Rescale the chart to print](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/)
*/
@property(nonatomic, readwrite) HIFunction *afterPrint;
/**
Fires when the point is unselected either programmatically or following a click on the point. One parameter, `event`, is passed to the function. Returning `false` cancels the operation.

**Try it**

* [Report the last unselected point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-unselect/)
*/
@property(nonatomic, readwrite) HIFunction *unselect;
/**
Fires when the point is updated programmatically through the `.update()` method. One parameter, `event`, is passed to the function. The new point options can be accessed through `event.options`. Returning `false` cancels the operation.

**Try it**

* [Confirm point updating](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-update/)
*/
@property(nonatomic, readwrite) HIFunction *update;
/**
Fires when the point is removed using the `.remove()` method. One parameter, `event`, is passed to the function. Returning `false` cancels the operation.

**Try it**

* [Remove point and confirm](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-remove/)
*/
@property(nonatomic, readwrite) HIFunction *remove;
/**
Fires when the mouse leaves the area close to the point. One parameter, `event`, is passed to the function, containing common event information.

**Try it**

* [Show values in the chart's corner on mouse over](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/)
*/
@property(nonatomic, readwrite) HIFunction *mouseOut;
/**
Fires when the mouse enters the area close to the point. One parameter, `event`, is passed to the function, containing common event information.

**Try it**

* [Show values in the chart's corner on mouse over](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/)
*/
@property(nonatomic, readwrite) HIFunction *mouseOver;
/**
Fires when the point is selected either programmatically or following a click on the point. One parameter, `event`, is passed to the function. Returning `false` cancels the operation.

**Try it**

* [Report the last selected point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-select/)
*/
@property(nonatomic, readwrite) HIFunction *select;
/**
Fires when the series is hidden after chart generation time, either by clicking the legend item or by calling `.hide()`.

**Try it**

* [Alert when the series is hidden by clicking the legend item](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-hide/)
*/
@property(nonatomic, readwrite) HIFunction *hide;
/**
Fires when the series is shown after chart generation time, either by clicking the legend item or by calling `.show()`.

**Try it**

* [Alert when the series is shown by clicking the legend item.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-show/)
*/
@property(nonatomic, readwrite) HIFunction *show;
/**
Fires after the series has finished its initial animation, or in case animation is disabled, immediately as the series is displayed.

**Try it**

* [Show label after animate](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-afteranimate/)
*/
@property(nonatomic, readwrite) HIFunction *afterAnimate;

-(NSDictionary *)getParams;

@end
