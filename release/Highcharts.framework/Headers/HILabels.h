/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPoint.h"
#import "HIStyle.h"
#import "HIItems.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: HTML labels that can be positioned anywhere in the chart area.
*/
@interface HILabels: HIChartsJSONSerializable

/**
* description: Whether to allow the annotation's labels to overlap.
To make the labels less sensitive for overlapping, 
the can be set to 0.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/tooltip-like/ : Hide overlapping labels
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
* description: A https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting : format string for the data label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/ : Set labels text
* default: undefined
*/
@property(nonatomic, readwrite) NSString *format;
/**
* description: How to handle the annotation's label that flow outside the plot
area. The justify option aligns the label inside the plot area.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/ : Crop or justify labels
* accepted values: ["none", "justify"]
* default: justify
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
* description: When either the borderWidth or the backgroundColor is set,
this    is the padding within the box.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: This option defines the point to which the label will be connected.
It can be either the point which exists in the series - it is referenced
by the point's id - or a new point with defined x, y properies
and optionally axes.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/mock-point/ : Attach annotation to a mock point
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
* description: The border radius in pixels for the annotaiton's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
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
* description: Styles for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
* description: Whether to hide the annotation's label that is outside the plot area.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-crop-overflow/ : Crop or justify labels
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-
and-string-formatting#html : use HTML to render the annotation's label.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: The vertical alignment of the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* accepted values: ["top", "middle", "bottom"]
* default: bottom
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: The label's pixel distance from the point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
* description: The border width in pixels for the annotation's label

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Alias for the format option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-text/ : Set labels text
* default: undefined
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: The shadow of the box. The shadow can be an object configuration
containing color, offsetX, offsetY, opacity and width.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
*/
@property(nonatomic, readwrite) id /* Bool, id */ shadow;
/**
* description: The y position offset of the label relative to the point.
Note that if a distance is defined, the distance takes
precedence over x and y options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* default: -16
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The x position offset of the label relative to the point.
Note that if a distance is defined, the distance takes
precedence over x and y options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The name of a symbol to use for the border around the label.
Symbols are predefined functions on the Renderer object.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shapes/ : Available shapes for labels
* default: callout
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: The background color or gradient for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: rgba(0, 0, 0, 0.75)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: The border color for the annotation's label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-presentation/ : Set labels graphic options
* default: black
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The alignment of the annotation's label. If right,
the right side of the label should be touching the point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/label-position/ : Set labels position
* accepted values: ["left", "center", "right"]
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: When each category width is more than this many pixels, we don't
apply auto rotation. Instead, we lay out the axis label with word
wrap. A lower limit makes sense when the label contains multiple
short words that don't extend the available horizontal space for
each label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotationlimit/ : Lower limit
* default: 80
*/
@property(nonatomic, readwrite) NSNumber *autoRotationLimit;
/**
* description: If enabled, the axis labels will skewed to follow the perspective. 
This will fix overlapping labels and titles, but texts become less
legible due to the distortion.
The final appearance depends heavily on labels.position3d.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/ : Skewed labels
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skew3d;
/**
* description: Rotation of the labels in degrees.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-rotation/ : X axis labels rotated 90°
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: Horizontal axes only. The number of lines to spread the labels over
to make room or tighter labels. .

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-staggerlines/ : Show labels over two lines
* default: null
*/
@property(nonatomic, readwrite) NSNumber *staggerLines;
/**
* description: The Z index for the axis labels.
* default: 7
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: Whether to reserve space for the labels. This can be turned off when
for example the labels are rendered inside the plot area instead
of outside.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-reservespace/ : No reserved space, labels inside plot
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reserveSpace;
/**
* description: For horizontal axes, the allowed degrees of label rotation to prevent
overlapping labels. If there is enough space, labels are not rotated.
As the chart gets narrower, it will start rotating the labels -45
degrees, then remove every second label and try again with rotations
0 and -45 etc. Set it to false to disable rotation, which will
cause the labels to word-wrap if possible.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-default/ : Default auto rotation of 0 or -45
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-0-90/ : Custom graded auto rotation
* default: [-45]
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *autoRotation;
/**
* description: Enable or disable the axis labels.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-enabled/ : X axis labels disabled
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Defines how the labels are be repositioned according to the 3D chart
orientation.

'offset': Maintain a fixed horizontal/vertical distance from the
   tick marks, despite the chart orientation. This is the backwards
   compatible behavior, and causes skewing of X and Z axes.
'chart': Preserve 3D position relative to the chart.
This looks nice, but hard to read if the text isn't
forward-facing.
'flap': Rotated text along the axis to compensate for the chart
   orientation. This tries to maintain text as legible as possible on
   all orientations.
'ortho': Rotated text along the axis direction so that the labels
   are orthogonal to the axis. This is very similar to 'flap', but
   prevents skewing the labels (X and Y scaling are still present).


* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/skewed-labels/ : Skewed labels
* accepted values: ['offset', 'chart', 'flap', 'ortho']
* default: offset
*/
@property(nonatomic, readwrite) NSString *position3d;
/**
* description: To show only every n'th label on the axis, set the step to n.
Setting the step to 2 shows every other label.
By default, the step is calculated automatically to avoid overlap.
To prevent this, set it to 1. This usually only happens on a category
axis, and is often a sign that you have chosen the wrong axis type.
Read more at http://www.highcharts.com/docs/chart-concepts/axes : Axis docs
=> What axis should I use?

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step/ : Showing only every other axis label on a categorized x axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step-auto/ : Auto steps on a category axis
* default: null
*/
@property(nonatomic, readwrite) NSNumber *step;
/**
* description: A HTML label that can be positioned anywhere in the chart area.
*/
@property(nonatomic, readwrite) NSArray <HIItems *> *items;

-(NSDictionary *)getParams;

@end
