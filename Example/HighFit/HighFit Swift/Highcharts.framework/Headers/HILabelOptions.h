/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: Options for annotation's labels. Each label inherits options
from the labelOptions object. An option from the labelOptions can be
overwritten by config for a specific label.
*/
@interface HILabelOptions: HIChartsJSONSerializable

/**
* description: The background color or gradient for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: rgba(0, 0, 0, 0.75)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: How to handle the annotation's label that flow outside the plot
area. The justify option aligns the label inside the plot area.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/ : Crop or justify labels
* accepted values: ["none", "justify"]
* default: justify
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
* description: The border width in pixels for the annotation's label

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The border color for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: black
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The label's pixel distance from the point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-
and-string-formatting#html : use HTML to render the annotation's label.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: Whether to hide the annotation's label that is outside the plot area.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/ : Crop or justify labels
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
* description: The shadow of the box. The shadow can be an object configuration
containing color, offsetX, offsetY, opacity and width.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
*/
@property(nonatomic, readwrite) id /* Bool, id */ shadow;
/**
* description: The vertical alignment of the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* accepted values: ["top", "middle", "bottom"]
* default: bottom
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: The alignment of the annotation's label. If right,
the right side of the label should be touching the point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* accepted values: ["left", "center", "right"]
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: Styles for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
* description: Whether to allow the annotation's labels to overlap.
To make the labels less sensitive for overlapping, 
the can be set to 0.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/tooltip-like/ : Hide overlapping labels
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
* description: When either the borderWidth or the backgroundColor is set,
this    is the padding within the box.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: The x position offset of the label relative to the point.
Note that if a distance is defined, the distance takes
precedence over x and y options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The y position offset of the label relative to the point.
Note that if a distance is defined, the distance takes
precedence over x and y options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* default: -16
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The border radius in pixels for the annotaiton's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: Alias for the format option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/ : Set labels text
* default: undefined
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: Callback JavaScript function to format the annotation's label. Note that
if a format or text are defined, the format or text take precedence
and the formatter is ignored. This refers to a point object.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/ : Set labels text
* default: function () {
	return defined(this.y) ? this.y : 'Annotation label';
}
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
* description: The name of a symbol to use for the border around the label.
Symbols are predefined functions on the Renderer object.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shapes/ : Available shapes for labels
* default: callout
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: A https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting : format string for the data label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/ : Set labels text
* default: undefined
*/
@property(nonatomic, readwrite) NSString *format;

-(NSDictionary *)getParams;

@end
