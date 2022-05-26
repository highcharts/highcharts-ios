/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIEvents.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HIAnimationOptionsObject.h"


/**
Point accessibility options for a series.
*/
@interface HIPoint: HIChartsJSONSerializable

/**
Formatter function to use instead of the default for point descriptions. Same as `accessibility.point.descriptionFormatter`, but applies to a series instead of the whole chart. Note: Prefer using `accessibility.point.valueDescriptionFormat` instead if possible, as default functionality such as describing annotations will be preserved.
*/
@property(nonatomic, readwrite) HIFunction *descriptionFormatter;
/**
Format to use for describing the values of data points to assistive technology - including screen readers. The point context is available as `{point}`. Other available context variables include `{index}`, `{value}`, and `{xDescription}`. Additionally, the series name, annotation info, and description added in `point.accessibility.description` is added by default if relevant. To override this, use the `accessibility.point.descriptionFormatter` option.
*/
@property(nonatomic, readwrite) NSString *valueDescriptionFormat;
/**
Suffix to add to the values in the point descriptions. Uses `tooltip.valueSuffix` if not defined.
*/
@property(nonatomic, readwrite) NSString *valueSuffix;
/**
Whether or not to describe points with the value `null` to assistive technology, such as screen readers.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeNull;
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
Decimals to use for the values in the point descriptions. Uses `tooltip.valueDecimals` if not defined.
*/
@property(nonatomic, readwrite) NSNumber *valueDecimals;
/**
For categorized axes this property holds the category name for the point. For other axes it holds the X value.
*/
@property(nonatomic, readwrite) NSString *category;
/**
The point's current color.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
The point's current color index, used in styled mode instead of `color`. The color index is inserted in class names used for styling.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
The name of the point. The name can be given as the first position of the point configuration array, or as a `name` property in the configuration:
*/
@property(nonatomic, readwrite) NSString *name;
/**
The percentage for points in a stacked series or pies.
*/
@property(nonatomic, readwrite) NSNumber *percentage;
/**
The translated X value for the point in terms of pixels. Relative to the X axis position if the series has one, otherwise relative to the plot area. Depending on the series type this value might not be defined.
*/
@property(nonatomic, readwrite) NSNumber *plotX;
/**
The translated Y value for the point in terms of pixels. Relative to the Y axis position if the series has one, otherwise relative to the plot area. Depending on the series type this value might not be defined.
*/
@property(nonatomic, readwrite) NSNumber *plotY;
/**
Whether the point is selected or not.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
Pie series only. Whether to display a slice offset from the center.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sliced;
/**
The total of values in either a stack for stacked series, or a pie in a pie series.
*/
@property(nonatomic, readwrite) NSNumber *total;
/**
For certain series types, like pie charts, where individual points can be shown or hidden.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
The x value of the point.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The y value of the point.
*/
@property(nonatomic, readwrite) NSNumber *y;
@property(nonatomic, readwrite) HIEvents *events;

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
