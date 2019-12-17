/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIEvents.h"
#import "HIFunction.h"
#import "HIAnimationOptionsObject.h"


/**
Properties for each single point.
*/
@interface HIPoint: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIEvents *events;
/**
The y position of the point. Units can be either in axis or chart pixel coordinates.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position of the point. Units can be either in axis or chart pixel coordinates.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
This number defines which xAxis the point is connected to. It refers to either the axis id or the index of the axis in the xAxis array. If the option is not configured or the axis is not found the point's x coordinate refers to the chart pixels.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ xAxis;
/**
This number defines which yAxis the point is connected to. It refers to either the axis id or the index of the axis in the yAxis array. If the option is not configured or the axis is not found the point's y coordinate refers to the chart pixels.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ yAxis;
/**
Suffix to add to the values in the point descriptions. Uses `tooltip.valueSuffix` if not defined.
*/
@property(nonatomic, readwrite) NSString *valueSuffix;
/**
Date format to use for points on datetime axes when describing them to screen reader users. Defaults to the same format as in tooltip. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) NSString *dateFormat;
/**
Formatter function to determine the date/time format used with points on datetime axes when describing them to screen reader users. Receives one argument, `point`, referring to the point to describe. Should return a date format string compatible with `dateFormat`.
*/
@property(nonatomic, readwrite) HIFunction *dateFormatter;
/**
Prefix to add to the values in the point descriptions. Uses `tooltip.valuePrefix` if not defined.
*/
@property(nonatomic, readwrite) NSString *valuePrefix;
/**
Formatter function to use instead of the default for point descriptions. Receives one argument, `point`, referring to the point to describe. Should return a string with the description of the point for a screen reader user. If `false` is returned, the default formatter will be used for that point.
*/
@property(nonatomic, readwrite) HIFunction *descriptionFormatter;
/**
Decimals to use for the values in the point descriptions. Uses `tooltip.valueDecimals` if not defined.
*/
@property(nonatomic, readwrite) NSNumber *valueDecimals;

-(NSDictionary *)getParams;

/**
 Cancel sonification of a point. Calls onEnd functions.
 
 **Requires:**
 
 * module:modules/sonification
 */
-(void)cancelSonify;

/**
 Cancel sonification of a point. Calls onEnd functions.
 
 **Requires:**
 
 * module:modules/sonification
 
 @param fadeOut Whether or not to fade out as we stop. If false, the points are cancelled synchronously.
 */
-(void)cancelSonify:(NSNumber /* Bool */ *)fadeOut;

/**
 Runs on mouse out from the point. Called internally from mouse and touch events.
 
 **Fires:**
 
 * Highcharts.Point#event:mouseOut
 */
-(void)onMouseOut;

/**
 Runs on mouse over the point. Called internally from mouse and touch events.
 */
-(void)onMouseOver;

/**
 Remove a point and optionally redraw the series and if necessary the axes
 
 **Try it**
 
 * [Remove point and confirm](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-remove/)
 * [Remove pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-remove/)
 
 @param redraw Whether to redraw the chart or wait for an explicit call. When doing more operations on the chart, for example running `point.remove()` in a loop, it is best practice to set `redraw` to false and call `chart.redraw()` after.
 */
-(void)remove:(NSNumber /* Bool */ *)redraw;

/**
 Remove a point and optionally redraw the series and if necessary the axes
 
 **Try it**
 
 * [Remove point and confirm](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-point-events-remove/)
 * [Remove pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-remove/)
 
 @param redraw Whether to redraw the chart or wait for an explicit call. When doing more operations on the chart, for example running `point.remove()` in a loop, it is best practice to set `redraw` to false and call `chart.redraw()` after.
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)remove:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Toggle the selection status of a point.
 
 **See also:**
 
 * [Highcharts.Chart#getSelectedPoints](https://api.highcharts.com/class-reference/Highcharts.Chart#getSelectedPoints)
 
 **Fires:**
 
 * Highcharts.Point#event:select
 * Highcharts.Point#event:unselect
 
 **Try it**
 
 * [Select a point from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-select/)
 * [Select a range of points through a drag selection](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/)
 */
-(void)select;

/**
 Toggle the selection status of a point.
 
 **See also:**
 
 * [Highcharts.Chart#getSelectedPoints](https://api.highcharts.com/class-reference/Highcharts.Chart#getSelectedPoints)
 
 **Fires:**
 
 * Highcharts.Point#event:select
 * Highcharts.Point#event:unselect
 
 **Try it**
 
 * [Select a point from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-select/)
 * [Select a range of points through a drag selection](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/)
 
 @param selected When `true`, the point is selected. When `false`, the point is unselected. When `null` or `undefined`, the selection state is toggled.
 */
-(void)select:(NSNumber /* Bool */ *)selected;

/**
 Toggle the selection status of a point.
 
 **See also:**
 
 * [Highcharts.Chart#getSelectedPoints](https://api.highcharts.com/class-reference/Highcharts.Chart#getSelectedPoints)
 
 **Fires:**
 
 * Highcharts.Point#event:select
 * Highcharts.Point#event:unselect
 
 **Try it**
 
 * [Select a point from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-select/)
 * [Select a range of points through a drag selection](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/events-selection-points/)
 
 @param selected When `true`, the point is selected. When `false`, the point is unselected. When `null` or `undefined`, the selection state is toggled.
 @param accumulate When `true`, the selection is added to other selected points. When `false`, other selected points are deselected. Internally in Highcharts, when [allowPointSelect](http://api.highcharts.com/highcharts/plotOptions.series.allowPointSelect) is `true`, selected points are accumulated on Control, Shift or Cmd clicking the point.
 */
-(void)select:(NSNumber /* Bool */ *)selected accumulate:(NSNumber /* Bool */ *)accumulate;

/**
 Set a value in an object, on the property defined by key. The key supports nested properties using dot notation. The function modifies the input object and does not make a copy.
 @param object The object to set the value on.
 @param value The value to set.
 @param key Key to the property to set.
 */
-(void)setNestedProperty:(id)object value:(id)value key:(NSString *)key;

/**
 Set the point's state.
 
 **Fires:**
 
 * Highcharts.Point#event:afterSetState
 */
-(void)setState;

/**
 Set the point's state.
 
 **Fires:**
 
 * Highcharts.Point#event:afterSetState
 
 @param state The new state, can be one of `''` (an empty string), `hover` or `select`.
 */
-(void)setState:(NSString *)state;

/**
 Set the point's state.
 
 **Fires:**
 
 * Highcharts.Point#event:afterSetState
 
 @param state The new state, can be one of `''` (an empty string), `hover` or `select`.
 @param move State for animation.
 */
-(void)setState:(NSString *)state move:(NSNumber /* Bool */ *)move;

/**
 Sonify a single point.
 
 **Requires:**
 
 * module:modules/sonification
 
 **Try it**
 
 * [Click on points to sonify](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-basic/)
 * [Sonify bubbles](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/point-advanced/)
 
 @param options Options for the sonification of the point.
 */
-(void)sonify:(NSDictionary *)options;

/**
 Extendable method for formatting each point's tooltip line.
 @param pointFormat The point format.
 */
-(void)tooltipFormatter:(NSString *)pointFormat;

/**
 Update point with new options (typically x/y data) and optionally redraw the series.
 
 **Fires:**
 
 * Highcharts.Point#event:update
 
 **Try it**
 
 * [Update column value](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-column/)
 * [Update pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-pie/)
 
 @param options The point options. Point options are handled as described under the `series.type.data` item for each series type. For example for a line series, if options is a single number, the point will be given that number as the marin y value. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options are applied.
 */
-(void)update:(HIPoint *)options;

/**
 Update point with new options (typically x/y data) and optionally redraw the series.
 
 **Fires:**
 
 * Highcharts.Point#event:update
 
 **Try it**
 
 * [Update column value](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-column/)
 * [Update pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-pie/)
 
 @param options The point options. Point options are handled as described under the `series.type.data` item for each series type. For example for a line series, if options is a single number, the point will be given that number as the marin y value. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options are applied.
 @param redraw Whether to redraw the chart after the point is updated. If doing more operations on the chart, it is best practice to set `redraw` to false and call `chart.redraw()` after.
 */
-(void)update:(HIPoint *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Update point with new options (typically x/y data) and optionally redraw the series.
 
 **Fires:**
 
 * Highcharts.Point#event:update
 
 **Try it**
 
 * [Update column value](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-column/)
 * [Update pie slice](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/point-update-pie/)
 
 @param options The point options. Point options are handled as described under the `series.type.data` item for each series type. For example for a line series, if options is a single number, the point will be given that number as the marin y value. If it is an array, it will be interpreted as x and y values respectively. If it is an object, advanced options are applied.
 @param redraw Whether to redraw the chart after the point is updated. If doing more operations on the chart, it is best practice to set `redraw` to false and call `chart.redraw()` after.
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)update:(HIPoint *)options redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

@end
