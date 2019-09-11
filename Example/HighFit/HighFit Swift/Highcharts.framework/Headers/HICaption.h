/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
The chart's caption, which will render below the chart and will be part of exported charts. The caption can be updated after chart initialization through the `Chart.update` or `Chart.caption.update` methods.

**Try it**

* [A chart with a caption](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/caption/text/)
*/
@interface HICaption: HIChartsJSONSerializable

/**
CSS styles for the caption. In styled mode, the caption style is given in the `.highcharts-caption` class.

**Defaults to** `{"color": "#666666"}`.

**Try it**

* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/titles/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The vertical alignment of the caption. Can be one of `"top"`, `"middle"` and `"bottom"`. When middle, the caption behaves as floating.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The caption text of the chart.

**Try it**

* [Custom caption](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/caption/text/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
The horizontal alignment of the caption. Can be one of "left", "center" and "right".
*/
@property(nonatomic, readwrite) NSString *align;
/**
The y position of the caption relative to the alignment within `chart.spacingTop` and `chart.spacingBottom`.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position of the caption relative to the alignment within `chart.spacingLeft` and `chart.spacingRight`.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
When the caption is floating, the plot area will not move to make space for it.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
The margin between the caption and the plot area.
*/
@property(nonatomic, readwrite) NSNumber *margin;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the text.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;

-(NSDictionary *)getParams;

@end
