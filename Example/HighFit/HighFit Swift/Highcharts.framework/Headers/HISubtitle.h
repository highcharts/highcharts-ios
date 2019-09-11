/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
The chart's subtitle. This can be used both to display a subtitle below the main title, and to display random text anywhere in the chart. The subtitle can be updated after chart initialization through the `Chart.setTitle` method.
*/
@interface HISubtitle: HIChartsJSONSerializable

/**
CSS styles for the title. In styled mode, the subtitle style is given in the `.highcharts-subtitle` class.

**Defaults to** `{"color": "#666666"}`.

**Try it**

* [Custom color and weight](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/style/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/titles/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The vertical alignment of the title. Can be one of `"top"`, `"middle"` and `"bottom"`. When middle, the subtitle behaves as floating.

**Try it**

* [Footnote at the bottom right of plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/verticalalign/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The subtitle of the chart.

**Try it**

* [Custom subtitle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/text/)
* [Formatted and linked text.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/text-formatted/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
The horizontal alignment of the subtitle. Can be one of "left", "center" and "right".

**Try it**

* [Footnote at right of plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/align/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
The y position of the subtitle relative to the alignment within `chart.spacingTop` and `chart.spacingBottom`. By default the subtitle is laid out below the title unless the title is floating.

**Try it**

* [Footnote at the bottom right of plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/verticalalign/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position of the subtitle relative to the alignment within `chart.spacingLeft` and `chart.spacingRight`.

**Defaults to** `0`.

**Try it**

* [Footnote at right of plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/align/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
When the subtitle is floating, the plot area will not move to make space for it.

**Defaults to** `false`.

**Try it**

* [Floating title and subtitle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/subtitle/floating/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
Adjustment made to the subtitle width, normally to reserve space for the exporting burger menu.

**Try it**

* [Wider menu, greater padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/widthadjust/)
*/
@property(nonatomic, readwrite) NSNumber *widthAdjust;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the text.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;

-(NSDictionary *)getParams;

@end
