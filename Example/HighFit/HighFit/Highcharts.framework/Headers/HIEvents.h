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
Mouse over event on a plot band.
*/
@property(nonatomic, readwrite) HIFunction *mouseover;
/**
Mouse out event on the corner of a plot band.
*/
@property(nonatomic, readwrite) HIFunction *mouseout;
/**
Click event on a plot band.
*/
@property(nonatomic, readwrite) HIFunction *click;
/**
Mouse move event on a plot band.
*/
@property(nonatomic, readwrite) HIFunction *mousemove;
/**
Fires when the chart is finished loading. Since v4.2.2, it also waits for images to be loaded, for example from point markers. One parameter, `event`, is passed to the function, containing common event information. There is also a second parameter to the chart constructor where a callback function can be passed to be executed on chart.load.

**Try it**

* [Alert on chart load](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-load/)
*/
@property(nonatomic, readwrite) HIFunction *load;
/**
Fires when an area of the chart has been selected. Selection is enabled by setting the chart's zoomType. One parameter, `event`, is passed to the function, containing common event information. The default action for the selection event is to zoom the chart to the selected area. It can be prevented by calling `event.preventDefault()` or return false. Information on the selected area can be found through `event.xAxis` and `event.yAxis`, which are arrays containing the axes of each dimension and each axis' min and max values. The primary axes are `event.xAxis[0]` and `event.yAxis[0]`. Remember the unit of a datetime axis is milliseconds since 1970-01-01 00:00:00. ```js selection: function(event) {   // log the min and max of the primary, datetime x-axis   console.log(     Highcharts.dateFormat(       '%Y-%m-%d %H:%M:%S',       event.xAxis[0].min     ),     Highcharts.dateFormat(       '%Y-%m-%d %H:%M:%S',       event.xAxis[0].max     )   );   // log the min and max of the y axis   console.log(event.yAxis[0].min, event.yAxis[0].max); } ```

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
Fires when a series is added to the chart after load time, using the `addSeries` method. One parameter, `event`, is passed to the function, containing common event information. Through `event.options` you can access the series options that were passed to the `addSeries` method. Returning false prevents the series from being added.

**Try it**

* [Alert on add series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-addseries/)
*/
@property(nonatomic, readwrite) HIFunction *addSeries;
/**
Fires when drilling up from a drilldown series.
*/
@property(nonatomic, readwrite) HIFunction *drillup;
/**
Fires before a chart is printed through the context menu item or the `Chart.print` method.

**Try it**

* [Rescale the chart to print](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/)
*/
@property(nonatomic, readwrite) HIFunction *beforePrint;
/**
In a chart with multiple drilldown series, this event fires after all the series have been drilled up.
*/
@property(nonatomic, readwrite) HIFunction *drillupall;
/**
Callback that fires while exporting data. This allows the modification of data rows before processed into the final format.
*/
@property(nonatomic, readwrite) HIFunction *exportData;
/**
Fires when a drilldown point is clicked, before the new series is added. This event is also utilized for async drilldown, where the seriesOptions are not added by option, but rather loaded async. Note that when clicking a category label to trigger multiple series drilldown, one `drilldown` event is triggered per point in the category. Event arguments: - `category`: If a category label was clicked, which index. - `originalEvent`: The original browser event (usually click) that triggered  the drilldown. - `point`: The originating point. - `points`: If a category label was clicked, this array holds all points  corresponing to the category. - `seriesOptions`: Options for the new series.

**Try it**

* [Async drilldown](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/async/)
*/
@property(nonatomic, readwrite) HIFunction *drilldown;
/**
Fires when the chart is redrawn, either after a call to `chart.redraw()` or after an axis, series or point is modified with the `redraw` option set to `true`. One parameter, `event`, is passed to the function, containing common event information.

**Try it**

* [Alert on chart redraw](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-redraw/)
*/
@property(nonatomic, readwrite) HIFunction *redraw;
/**
Fires after a chart is printed through the context menu item or the `Chart.print` method.

**Try it**

* [Rescale the chart to print](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-beforeprint-afterprint/)
*/
@property(nonatomic, readwrite) HIFunction *afterPrint;
/**
Fires when the cluster point is clicked and `drillToCluster` is enabled. One parameter, `event`, is passed to the function. The default action is to zoom to the cluster points range. This can be prevented by calling `event.preventDefault()`.
*/
@property(nonatomic, readwrite) HIFunction *drillToCluster;
/**
Fires when the point is unselected either programmatically or following a click on the point. One parameter, `event`, is passed to the function. Returning `false` cancels the operation.

**Try it**

* [Report the last unselected point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-unselect/)
*/
@property(nonatomic, readwrite) HIFunction *unselect;
/**
Callback that fires when the point is dropped. The parameters passed are the same as for `drag`. To stop the default drop action, return false. See `drag and drop options`.

**Try it**

* [Drag events](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) HIFunction *drop;
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
Callback that fires while dragging a point. The mouse event is passed in as parameter. The original data can be accessed from `e.origin`, and the new point values can be accessed from `e.newPoints`. If there is only a single point being updated, it can be accessed from `e.newPoint` for simplicity, and its ID can be accessed from `e.newPointId`. The `this` context is the point being dragged. To stop the default drag action, return false. See `drag and drop options`.

**Try it**

* [Drag events](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) HIFunction *drag;
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
Callback that fires when starting to drag a point. The mouse event object is passed in as an argument. If a drag handle is used, `e.updateProp` is set to the data property being dragged. The `this` context is the point. See `drag and drop options`.

**Try it**

* [Drag events](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) HIFunction *dragStart;
/**
Fires on a request for change of root node for the tree, before the update is made. An event object is passed to the function, containing additional properties `newRootId`, `previousRootId`, `redraw` and `trigger`.

**Defaults to** `undefined`.

**Try it**

* [Alert update information on setRootNode event.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-events-setrootnode/)
*/
@property(nonatomic, readwrite) HIFunction *setRootNode;
/**
A `closePopup` event. Fired when Popup should be hidden, for example when clicking on an annotation again.
*/
@property(nonatomic, readwrite) HIFunction *closePopup;
/**
Event fired on a button click.

**Try it**

* [Change icon in a dropddown on event](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/gui/)
* [Change button class on event](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/gui-buttons/)
*/
@property(nonatomic, readwrite) HIFunction *selectButton;
/**
A `showPopup` event. Fired when selecting for example an annotation.
*/
@property(nonatomic, readwrite) HIFunction *showPopup;
/**
Event fired when button state should change, for example after adding an annotation.

**Try it**

* [Change icon in a dropddown on event](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/gui/)
* [Change button class on event](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/gui-buttons/)
*/
@property(nonatomic, readwrite) HIFunction *deselectButton;
/**
Fires when the legend item belonging to the colorAxis is clicked. One parameter, `event`, is passed to the function.
*/
@property(nonatomic, readwrite) HIFunction *legendItemClick;
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
/**
Event callback when annotation is added to the chart.
*/
@property(nonatomic, readwrite) HIFunction *add;
/**
Event callback when annotation is updated (e.g.draganddropppedorresizedbycontrolpoints).
*/
@property(nonatomic, readwrite) HIFunction *afterUpdate;

-(NSDictionary *)getParams;

@end
