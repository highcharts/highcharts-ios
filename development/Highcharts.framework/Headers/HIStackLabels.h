/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFunction.h"
#import "HICSSObject.h"


/**
The stack labels show the total value for each bar in a stacked column or bar chart. The label will be placed on top of positive columns and below negative columns. In case of an inverted column chart or a bar chart the label is placed to the right of positive bars and to the left of negative bars.
*/
@interface HIStackLabels: HIChartsJSONSerializable

/**
Allow the stack labels to overlap.

**Try it**

* [Default false](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-allowoverlap-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
CSS styles for the label. In styled mode, the styles are set in the `.highcharts-stack-label` class.

**Try it**

* [Red stack total labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-style/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
Defines the vertical alignment of the stack total label. Can be one of `"top"`, `"middle"` or `"bottom"`. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.

**Try it**

* [Vertically aligned top](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-top/)
* [Vertically aligned middle](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-middle/)
* [Vertically aligned bottom](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-bottom/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
A [format string](http://docs.highcharts.com/#formatting) for the data label. Available variables are the same as for `formatter`.

**Defaults to** `{total}`.
*/
@property(nonatomic, readwrite) NSString *format;
/**
Defines the horizontal alignment of the stack total label. Can be one of `"left"`, `"center"` or `"right"`. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.

**Try it**

* [Aligned to the left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-left/)
* [Aligned in center](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-center/)
* [Aligned to the right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-right/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
Enable or disable the stack total labels.

**Try it**

* [Enabled stack total labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-enabled/)
* [Enabled stack labels in waterfall chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-enabled-waterfall/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Whether to hide stack labels that are outside the plot area. By default, the stack label is moved inside the plot area according to the `overflow` option.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
The text alignment for the label. While `align` determines where the texts anchor point is placed with regards to the stack, `textAlign` determines how the text is aligned against its anchor point. Possible values are `"left"`, `"center"` and `"right"`. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.

**Try it**

* [Label in center position but text-aligned left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-textalign-left/)
*/
@property(nonatomic, readwrite) NSString *textAlign;
/**
The y position offset of the label relative to the tick position on the axis. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.

**Try it**

* [Stack total labels with y offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-y/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position offset of the label relative to the left of the stacked bar. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.

**Try it**

* [Stack total labels with x offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-x/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
How to handle stack total labels that flow outside the plot area. The default is set to `"justify"`, which aligns them inside the plot area. For columns and bars, this means it will be moved inside the bar. To display stack labels outside the plot area, set `crop` to `false` and `overflow` to `"allow"`.

**Try it**

* [Stack labels flows outside the plot area.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-overflow/)
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
Callback JavaScript function to format the label. The value is given by `this.total`.

**Try it**

* [Added units to stack total value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-formatter/)
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
Rotation of the labels in degrees.

**Defaults to** `0`.

**Try it**

* [Labels rotated 45Â°](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-rotation/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;

-(NSDictionary *)getParams;

@end
