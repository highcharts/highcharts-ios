/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPoint.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HICSSObject.h"
#import "HIShadowOptionsObject.h"


/**
The axis labels show the number or category for each tick. Since v8.0.0: Labels are animated in categorized x-axis with updating data if `tickInterval` and `step` is set to 1.
*/
@interface HILabels: HIChartsJSONSerializable

/**
Angular gauges and solid gauges only. The label's pixel distance from the perimeter of the plot area. Since v7.1.2: If it's a percentage string, it is interpreted the same as `series.radius`, so label can be aligned under the gauge's shape.

**Defaults to** `-25`.

**Try it**

* [Labels centered under the arc](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/labels-distance/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ distance;
/**
What part of the string the given position is anchored to. Can be one of `"left"`, `"center"` or `"right"`. The exact position also depends on the `labels.x` setting. Angular gauges and solid gauges defaults to `"center"`. Solid gauges with two labels have additional option `"auto"` for automatic horizontal and vertical alignment.

**Defaults to** `right`.

**Try it**

* [Left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/labels-align-left/)
* [Solid gauge labels auto aligned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-solidgauge/labels-auto-aligned/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
The y position offset of the label relative to the tick position on the axis.

**Defaults to** `3`.

**Try it**

* [Y axis labels placed on grid lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-x/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position offset of the label relative to the tick position on the axis. Defaults to -15 for left axis, 15 for right axis.

**Try it**

* [Y axis labels placed on grid lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-x/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Horizontal axes only. The number of lines to spread the labels over to make room or tighter labels.

**Try it**

* [Show labels over two lines](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-staggerlines/)
*/
@property(nonatomic, readwrite) NSNumber *staggerLines;
/**
When each category width is more than this many pixels, we don't apply auto rotation. Instead, we lay out the axis label with word wrap. A lower limit makes sense when the label contains multiple short words that don't extend the available horizontal space for each label.

**Defaults to** `80`.

**Try it**

* [Lower limit](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotationlimit/)
*/
@property(nonatomic, readwrite) NSNumber *autoRotationLimit;
/**
Defines how the labels are be repositioned according to the 3D chart orientation. - `'offset'`: Maintain a fixed horizontal/vertical distance from the  tick marks, despite the chart orientation. This is the backwards  compatible behavior, and causes skewing of X and Z axes. - `'chart'`: Preserve 3D position relative to the chart. This looks nice, but hard to read if the text isn't  forward-facing. - `'flap'`: Rotated text along the axis to compensate for the chart  orientation. This tries to maintain text as legible as possible  on all orientations. - `'ortho'`: Rotated text along the axis direction so that the labels  are orthogonal to the axis. This is very similar to `'flap'`,  but prevents skewing the labels (X and Y scaling are still  present).

**Accepted values:** `['offset', 'chart', 'flap', 'ortho']`.

**Try it**

* [Skewed labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/)
*/
@property(nonatomic, readwrite) NSString *position3d;
/**
Rotation of the labels in degrees.

**Defaults to** `0`.

**Try it**

* [X axis labels rotated 90Â°](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-rotation/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
CSS styles for the label. Use `whiteSpace: 'nowrap'` to prevent wrapping of category labels. Use `textOverflow: 'none'` to prevent ellipsis (dots). In styled mode, the labels are styled with the `.highcharts-axis-labels` class.

**Try it**

* [Red X axis labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-style/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
Whether to reserve space for the labels. By default, space is reserved for the labels in these cases: * On all horizontal axes. * On vertical axes if `label.align` is `right` on a left-side axis or `left` on a right-side axis. * On vertical axes if `label.align` is `center`. This can be turned off when for example the labels are rendered inside the plot area instead of outside.

**Try it**

* [No reserved space, labels inside plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-reservespace/)
* [Left-aligned labels on a vertical category axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-reservespace-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reserveSpace;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
If enabled, the axis labels will skewed to follow the perspective. This will fix overlapping labels and titles, but texts become less legible due to the distortion. The final appearance depends heavily on `labels.position3d`.

**Try it**

* [Skewed labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skew3d;
/**
Callback JavaScript function to format the label. The value is given by `this.value`. Additional properties for `this` are `axis`, `chart`, `isFirst` and `isLast`. The value of the default label formatter can be retrieved by calling `this.axis.defaultLabelFormatter.call(this)` within the function. Defaults to: ```js function() {   return this.value; } ```

**Try it**

* [Linked category names](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-formatter-linked/)
* [Modified numeric labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-formatter-extended/)
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
For horizontal axes, the allowed degrees of label rotation to prevent overlapping labels. If there is enough space, labels are not rotated. As the chart gets narrower, it will start rotating the labels -45 degrees, then remove every second label and try again with rotations 0 and -45 etc. Set it to `false` to disable rotation, which will cause the labels to word-wrap if possible.

**Defaults to** `[-45]`.

**Try it**

* [Default auto rotation of 0 or -45](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-default/)
* [Custom graded auto rotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-0-90/)
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *autoRotation;
/**
The pixel padding for axis labels, to ensure white space between them.

**Defaults to** `5`.
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
A [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) for the axis label.

**Defaults to** `{value}`.

**Try it**

* [Add units to Y axis label](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/labels-format/)
*/
@property(nonatomic, readwrite) NSString *format;
/**
The Z index for the axis labels.

**Defaults to** `7`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
To show only every _n_'th label on the axis, set the step to _n_. Setting the step to 2 shows every other label. By default, the step is calculated automatically to avoid overlap. To prevent this, set it to 1\. This usually only happens on a category axis, and is often a sign that you have chosen the wrong axis type. Read more at [Axis docs](https://www.highcharts.com/docs/chart-concepts/axes) => What axis should I use?

**Try it**

* [Showing only every other axis label on a categorized x-axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step/)
* [Auto steps on a category axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step-auto/)
*/
@property(nonatomic, readwrite) NSNumber *step;
/**
How to handle overflowing labels on horizontal axis. If set to `"allow"`, it will not be aligned at all. By default it `"justify"` labels inside the chart area. If there is room to move it, it will be aligned to the edge, else it will be removed.

**Accepted values:** `["allow", "justify"]`.

**Defaults to** `justify`.
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
Enable or disable the axis labels.

**Defaults to** `true`.

**Try it**

* [X axis labels disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
This option defines the point to which the label will be connected. It can be either the point which exists in the series - it is referenced by the point's id - or a new point with defined x, y properties and optionally axes.

**Try it**

* [Attach annotation to a mock point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/mock-point/)
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
Whether to allow the annotation's labels to overlap. To make the labels less sensitive for overlapping, the can be set to 0.

**Try it**

* [Hide overlapping labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/tooltip-like/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
The border color for the annotation's label.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The vertical alignment of the annotation's label.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The border radius in pixels for the annotaiton's label.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Alias for the format option.

**Try it**

* [Set labels text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
Whether to hide the annotation's label that is outside the plot area.

**Try it**

* [Crop or justify labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
A class name for styling by CSS.

**Try it**

* [Styled mode annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations)
*/
@property(nonatomic, readwrite) NSString *className;
/**
The name of a symbol to use for the border around the label. Symbols are predefined functions on the Renderer object.

**Try it**

* [Available shapes for labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shapes/)
*/
@property(nonatomic, readwrite) NSString *shape;
/**
The border width in pixels for the annotation's label

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The background color or gradient for the annotation's label.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
The shadow of the box. The shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;

-(NSDictionary *)getParams;

@end
