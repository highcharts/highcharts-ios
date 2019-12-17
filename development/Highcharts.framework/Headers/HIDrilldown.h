/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDrillUpButton.h"
#import "HIAnimationOptionsObject.h"
#import "HICSSObject.h"


/**
Options for drill down, the concept of inspecting increasingly high resolution data through clicking on chart items like columns or pie slices. The drilldown feature requires the drilldown.js file to be loaded, found in the modules directory of the download package, or online at [https://code.highcharts.com/modules/drilldown.js](https://code.highcharts.com/modules/drilldown.js).
*/
@interface HIDrilldown: HIChartsJSONSerializable

/**
Additional styles to apply to the data label of a point that has drilldown data. By default it is underlined and blue to invite to interaction. In styled mode, active data label styles can be applied with the `.highcharts-drilldown-data-label` class.

**Defaults to** `{ "cursor": "pointer", "color": "#003399", "fontWeight": "bold", "textDecoration": "underline" }`.

**Try it**

* [Label styles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/labels/)
*/
@property(nonatomic, readwrite) HICSSObject *activeDataLabelStyle;
/**
An array of series configurations for the drill down. Each series configuration uses the same syntax as the `series` option set. These drilldown series are hidden by default. The drilldown series is linked to the parent series' point by its `id`.
*/
@property(nonatomic, readwrite) NSArray *series;
/**
When this option is false, clicking a single point will drill down all points in the same category, equivalent to clicking the X axis label.

**Defaults to** `true`.

**Try it**

* [Don't allow point drilldown](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/allowpointdrilldown-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointDrilldown;
/**
Set the animation for all drilldown animations. Animation of a drilldown occurs when drilling between a column point and a column series, or a pie slice and a full pie series. Drilldown can still be used between series and points of different types, but animation will not occur. The animation can either be set as a boolean or a configuration object. If `true`, it will use the 'swing' jQuery easing and a duration of 500 ms. If used as a configuration object, the following properties are supported: - `duration`: The duration of the animation in milliseconds. - `easing`: A string reference to an easing function set on the `Math`  object. See  [the easing demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-animation-easing/).
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Options for the drill up button that appears when drilling down on a series. The text for the button is defined in `lang.drillUpText`.

**Try it**

* [Drill up button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/drillupbutton/)
*/
@property(nonatomic, readwrite) HIDrillUpButton *drillUpButton;
/**
Additional styles to apply to the X axis label for a point that has drilldown data. By default it is underlined and blue to invite to interaction. In styled mode, active label styles can be set with the `.highcharts-drilldown-axis-label` class.

**Defaults to** `{ "cursor": "pointer", "color": "#003399", "fontWeight": "bold", "textDecoration": "underline" }`.

**Try it**

* [Label styles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/labels/)
*/
@property(nonatomic, readwrite) HICSSObject *activeAxisLabelStyle;

-(NSDictionary *)getParams;

@end
