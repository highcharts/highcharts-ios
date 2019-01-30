/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
The chart's main title.
*/
@interface HITitle: HIChartsJSONSerializable

/**
Adjustment made to the title width, normally to reserve space for the exporting burger menu.

**Try it**

* [Wider menu, greater padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/widthadjust/)
*/
@property(nonatomic, readwrite) NSNumber *widthAdjust;
/**
CSS styles for the title. Use this for font styling, but use `align`, `x` and `y` for text alignment. In styled mode, the title style is given in the `.highcharts-title` class.

**Defaults to** `{ "color": "#333333", "fontSize": "18px" }`.

**Try it**

* [Custom color and weight](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/style/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/titles/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The vertical alignment of the title. Can be one of `"top"`, `"middle"` and `"bottom"`. When a value is given, the title behaves as if `floating` were `true`.

**Try it**

* [Chart title in bottom right corner](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/verticalalign/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The title of the chart. To disable the title, set the `text` to `undefined`.

**Defaults to** `Chart title`.

**Try it**

* [Custom title](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/text/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
The horizontal alignment of the title. Can be one of "left", "center" and "right".

**Try it**

* [Aligned to the plot area (x = 70px = margin left - spacing left)](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/align/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
The y position of the title relative to the alignment within `chart.spacingTop` and `chart.spacingBottom`. By default it depends on the font size.

**Try it**

* [Title inside the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/y/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position of the title relative to the alignment within `chart.spacingLeft` and `chart.spacingRight`.

**Defaults to** `0`.

**Try it**

* [Aligned to the plot area (x = 70px = margin left - spacing left)](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/align/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
When the title is floating, the plot area will not move to make space for it.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/zoomtype-none/)
* [True - title on top of the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/floating/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
The margin between the title and the plot area, or if a subtitle is present, the margin between the subtitle and the plot area.

**Try it**

* [A chart title margin of 50](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/margin-50/)
* [The same margin applied with a subtitle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/title/margin-subtitle/)
*/
@property(nonatomic, readwrite) NSNumber *margin;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the text.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
The rotation of the text in degrees. 0 is horizontal, 270 is vertical reading from bottom to top.

**Try it**

* [Horizontal](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/title-offset/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
Whether to reserve space for the title when laying out the axis.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reserveSpace;
/**
If enabled, the axis title will skewed to follow the perspective. This will fix overlapping labels and titles, but texts become less legible due to the distortion. The final appearance depends heavily on `title.position3d`. A `null` value will use the config from `labels.skew3d`.

**Try it**

* [Skewed labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skew3d;
/**
Defines how the title is repositioned according to the 3D chart orientation. - `'offset'`: Maintain a fixed horizontal/vertical distance from the  tick marks, despite the chart orientation. This is the backwards  compatible behavior, and causes skewing of X and Z axes. - `'chart'`: Preserve 3D position relative to the chart. This looks nice, but hard to read if the text isn't  forward-facing. - `'flap'`: Rotated text along the axis to compensate for the chart  orientation. This tries to maintain text as legible as possible on  all orientations. - `'ortho'`: Rotated text along the axis direction so that the labels  are orthogonal to the axis. This is very similar to `'flap'`, but  prevents skewing the labels (X and Y scaling are still present). - `undefined`: Will use the config from `labels.position3d`

**Try it**

* [Skewed labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/)
*/
@property(nonatomic, readwrite) NSString *position3d;
/**
The distance of the axis title from the axis line. By default, this distance is computed from the offset width of the labels, the labels' distance from the axis and the title's margin. However when the offset option is set, it overrides all this.

**Try it**

* [Place the axis title on top of the axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/title-offset/)
*/
@property(nonatomic, readwrite) NSNumber *offset;
/**
Alignment of the text, can be `"left"`, `"right"` or `"center"`. Default alignment depends on the `title.align`: Horizontal axes: - for `align` = `"low"`, `textAlign` is set to `left` - for `align` = `"middle"`, `textAlign` is set to `center` - for `align` = `"high"`, `textAlign` is set to `right` Vertical axes: - for `align` = `"low"` and `opposite` = `true`, `textAlign` is  set to `right` - for `align` = `"low"` and `opposite` = `false`, `textAlign` is  set to `left` - for `align` = `"middle"`, `textAlign` is set to `center` - for `align` = `"high"` and `opposite` = `true` `textAlign` is  set to `left` - for `align` = `"high"` and `opposite` = `false` `textAlign` is  set to `right`
*/
@property(nonatomic, readwrite) NSString *textAlign;

-(NSDictionary *)getParams;

@end
