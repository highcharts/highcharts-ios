/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColor.h"
#import "HIFunction.h"
#import "HICSSObject.h"
#import "HIShadowOptionsObject.h"


/**
Options for annotation's labels. Each label inherits options from the labelOptions object. An option from the labelOptions can be overwritten by config for a specific label.
*/
@interface HILabelOptions: HIChartsJSONSerializable

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
Styles for the annotation's label.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
When either the borderWidth or the backgroundColor is set, this  is the padding within the box.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
The vertical alignment of the annotation's label.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The label's pixel distance from the point.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSNumber *distance;
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
The alignment of the annotation's label. If right, the right side of the label should be touching the point.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
A [format](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) string for the data label.

**Try it**

* [Set labels text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/)
*/
@property(nonatomic, readwrite) NSString *format;
/**
Whether to hide the annotation's label that is outside the plot area.

**Try it**

* [Crop or justify labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the annotation's label.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
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
The y position offset of the label relative to the point. Note that if a `distance` is defined, the distance takes precedence over `x` and `y` options.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x position offset of the label relative to the point. Note that if a `distance` is defined, the distance takes precedence over `x` and `y` options.

**Try it**

* [Set labels position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
How to handle the annotation's label that flow outside the plot area. The justify option aligns the label inside the plot area.

**Accepted values:** `["allow", "justify"]`.

**Try it**

* [Crop or justify labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/)
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
Callback JavaScript function to format the annotation's label. Note that if a `format` or `text` are defined, the format or text take precedence and the formatter is ignored. `This` refers to a point object.

**Defaults to** `function () { return defined(this.y) ? this.y : 'Annotation label'; }`.

**Try it**

* [Set labels text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/)
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
The shadow of the box. The shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Try it**

* [Set labels graphic options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;

-(NSDictionary *)getParams;

@end
