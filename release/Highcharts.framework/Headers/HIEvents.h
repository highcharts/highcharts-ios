/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
* description: Event listeners for the chart.
*/
@interface HIEvents: HIChartsJSONSerializable

/**
* description: Fires when the mouse enters the area close to the point. One parameter,
event, is passed to the function, containing common event information.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/ : Show values in the chart's corner on mouse over
*/
@property(nonatomic, readwrite) HIFunction *mouseOver;
/**
* description: Fires when a point is clicked. One parameter, event, is passed
to the function, containing common event information.
If the series.allowPointSelect option is true, the default action
for the point's click event is to toggle the point's select state.
 Returning false cancels this action.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click/ : Click marker to alert values
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click-column/ : Click column
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-click-url/ : Go to URL
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-point-events-click/ : Click marker to display values
*/
@property(nonatomic, readwrite) HIFunction *click;
/**
* description: Fires when the point is selected either programmatically or following
a click on the point. One parameter, event, is passed to the function.
 Returning false cancels the operation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-select/ : Report the last selected point
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-allowpointselect/ : Report select and unselect
*/
@property(nonatomic, readwrite) HIFunction *select;
/**
* description: Fires when the mouse leaves the area close to the point. One parameter,
event, is passed to the function, containing common event information.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-mouseover/ : Show values in the chart's corner on mouse over
*/
@property(nonatomic, readwrite) HIFunction *mouseOut;
/**
* description: Fires when the point is unselected either programmatically or following
a click on the point. One parameter, event, is passed to the function.
 Returning false cancels the operation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-unselect/ : Report the last unselected point
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-allowpointselect/ : Report select and unselect
*/
@property(nonatomic, readwrite) HIFunction *unselect;
/**
* description: Fires when the point is updated programmatically through the .update()
method. One parameter, event, is passed to the function. The new
point options can be accessed through event.options. Returning
false cancels the operation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-update/ : Confirm point updating
*/
@property(nonatomic, readwrite) HIFunction *update;
/**
* description: Fires when the point is removed using the .remove() method. One
parameter, event, is passed to the function. Returning false
cancels the operation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-remove/ : Remove point and confirm
*/
@property(nonatomic, readwrite) HIFunction *remove;
/**
* description: Fires when the series is shown after chart generation time, either
by clicking the legend item or by calling .show().

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-show/ : Alert when the series is shown by clicking the legend item.
*/
@property(nonatomic, readwrite) HIFunction *show;
/**
* description: Fires when the checkbox next to the series' name in the legend is
clicked. One parameter, event, is passed to the function. The state
of the checkbox is found by event.checked. The checked item is
found by event.item. Return false to prevent the default action
which is to toggle the select state of the series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-checkboxclick/ : Alert checkbox status
*/
@property(nonatomic, readwrite) HIFunction *checkboxClick;
/**
* description: Fires when the series is hidden after chart generation time, either
by clicking the legend item or by calling .hide().

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-hide/ : Alert when the series is hidden by clicking the legend item
*/
@property(nonatomic, readwrite) HIFunction *hide;
/**
* description: Fires after the series has finished its initial animation, or in
case animation is disabled, immediately as the series is displayed.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-afteranimate/ : Show label after animate
*/
@property(nonatomic, readwrite) HIFunction *afterAnimate;
/**
* description: Fires when the legend item belonging to the series is clicked. One
parameter, event, is passed to the function. The default action
is to toggle the visibility of the series. This can be prevented
by returning false or calling event.preventDefault().

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-events-legenditemclick/ : Confirm hiding and showing
*/
@property(nonatomic, readwrite) HIFunction *legendItemClick;
/**
* description: As opposed to the setExtremes event, this event fires after the
final min and max values are computed and corrected for minRange.
Fires when the minimum and maximum is set for the axis, either by
calling the .setExtremes() method or by selecting an area in the
chart. One parameter, event, is passed to the function, containing common event information.
The new user set minimum and maximum values can be found by event.
min and event.max. These reflect the axis minimum and maximum
in axis values. The actual data extremes are found in event.dataMin
and event.dataMax.
*/
@property(nonatomic, readwrite) HIFunction *afterSetExtremes;
/**
* description: An event fired when a point falls inside a break from this axis.
*/
@property(nonatomic, readwrite) HIFunction *pointInBreak;
/**
* description: Fires when the minimum and maximum is set for the axis, either by
calling the .setExtremes() method or by selecting an area in the
chart. One parameter, event, is passed to the function, containing common event information.
The new user set minimum and maximum values can be found by event.
min and event.max. These reflect the axis minimum and maximum
in data values. When an axis is zoomed all the way out from the "Reset
zoom" button, event.min and event.max are null, and the new extremes
are set based on this.dataMin and this.dataMax.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/events-setextremes/ : Log new extremes on x axis
*/
@property(nonatomic, readwrite) HIFunction *setExtremes;
/**
* description: An event fired when a break from this axis occurs on a point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-visualized/ : Visualization of a Break
*/
@property(nonatomic, readwrite) HIFunction *pointBreak;
/**
* description: An event fired after the breaks have rendered.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-event// : AfterBreak Event
*/
@property(nonatomic, readwrite) HIFunction *afterBreaks;
/**
* description: Fires when an area of the chart has been selected. Selection is enabled
by setting the chart's zoomType. One parameter, event, is passed
to the function, containing common event information. The default action for the selection event is to
zoom the chart to the selected area. It can be prevented by calling
event.preventDefault().
Information on the selected area can be found through event.xAxis
and event.yAxis, which are arrays containing the axes of each dimension
and each axis' min and max values. The primary axes are event.xAxis[0]
and event.yAxis[0]. Remember the unit of a datetime axis is milliseconds
since 1970-01-01 00:00:00.
selection: function(event) {
    // log the min and max of the primary, datetime x-axis
    console.log(
        Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', event.xAxis[0].min),
        Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', event.xAxis[0].max)
    );
    // log the min and max of the y axis
    console.log(event.yAxis[0].min, event.yAxis[0].max);
}
* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection/ : Report on selection and reset
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/ : Select a range of points through a drag selection
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/ : Select a range of points through a drag selection (Highcharts)
*/
@property(nonatomic, readwrite) HIFunction *selection;
/**
* description: Fires after initial load of the chart (directly after the load
event), and after each redraw (directly after the redraw event).
*/
@property(nonatomic, readwrite) HIFunction *render;
/**
* description: Fires when the chart is finished loading. Since v4.2.2, it also waits
for images to be loaded, for example from point markers. One parameter,
event, is passed to the function, containing common event information.
There is also a second parameter to the chart constructor where a
callback function can be passed to be executed on chart.load.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-load/ : Alert on chart load
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/chart/events-load/ : Add series on chart load
*/
@property(nonatomic, readwrite) HIFunction *load;
/**
* description: In a chart with multiple drilldown series, this event fires after
all the series have been drilled up.
*/
@property(nonatomic, readwrite) HIFunction *drillupall;
/**
* description: Fires when a series is added to the chart after load time, using
the addSeries method. One parameter, event, is passed to the
function, containing common event information.
Through event.options you can access the series options that was
passed to the addSeries method. Returning false prevents the series
from being added.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-addseries/ : Alert on add series
*/
@property(nonatomic, readwrite) HIFunction *addSeries;
/**
* description: Fires when drilling up from a drilldown series.
*/
@property(nonatomic, readwrite) HIFunction *drillup;
/**
* description: Fires when the chart is redrawn, either after a call to chart.redraw()
or after an axis, series or point is modified with the redraw option
set to true. One parameter, event, is passed to the function, containing common event information.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-redraw/ : Alert on chart redraw
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/chart/events-redraw/ : Alert on chart redraw when adding a series or moving the zoomed range
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/chart/events-redraw/ : Set subtitle on chart redraw
*/
@property(nonatomic, readwrite) HIFunction *redraw;
/**
* description: Fires when a drilldown point is clicked, before the new series is
added. This event is also utilized for async drilldown, where the
seriesOptions are not added by option, but rather loaded async. Note
that when clicking a category label to trigger multiple series drilldown,
one drilldown event is triggered per point in the category.
Event arguments:

category
If a category label was clicked, which index.
point
The originating point.
originalEvent
The original browser event (usually click) that triggered the
drilldown.
points
If a category label was clicked, this array holds all points
corresponing to the category.
seriesOptions
Options for the new series

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/async/ : Async drilldown
*/
@property(nonatomic, readwrite) HIFunction *drilldown;
/**
* description: Fires after a chart is printed through the context menu item or the
Chart.print method. Requires the exporting module.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/ : Rescale the chart to print

*/
@property(nonatomic, readwrite) HIFunction *afterPrint;
/**
* description: Fires before a chart is printed through the context menu item or
the Chart.print method. Requires the exporting module.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/ : Rescale the chart to print

*/
@property(nonatomic, readwrite) HIFunction *beforePrint;

-(NSDictionary *)getParams;

@end
