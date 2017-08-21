/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The axis labels show the number or category for each tick.
*/
@interface HIZAxisLabels: HIChartsJSONSerializable

/**
* description: Horizontal axes only. The number of lines to spread the labels over to make room or tighter labels.  .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-staggerlines/ : Show labels over two lines
*/
@property(nonatomic, readwrite) NSNumber *staggerLines;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html : use HTML to render the labels.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: The x position offset of the label relative to the tick position on the axis.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-x/ : Y axis labels placed on grid lines
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The y position offset of the label relative to the tick position on the axis. The default makes it adapt to the font size on bottom axis.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-x/ : Y axis labels placed on grid lines
* default: null
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Polar charts only. The label's pixel distance from the perimeter of the plot area.
* default: 15
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
* description: To show only every n'th label on the axis, set the step to n. Setting the step to 2 shows every other label.
By default, the step is calculated automatically to avoid overlap. To prevent this, set it to 1. This usually only happens on a category axis, and is often a sign that you have chosen the wrong axis type. Read more at http://www.highcharts.com/docs/chart-concepts/axes : Axis docs => What axis should I use? 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step/ : Showing only every other axis label on a categorized x axis. http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-step-auto/ : Auto steps on a category axis.
*/
@property(nonatomic, readwrite) NSNumber *step;
/**
* description: How to handle overflowing labels on horizontal axis. Can be undefined, false or "justify". By default it aligns inside the chart area. If "justify", labels will not render outside the plot area. If false, it will not be aligned at all. If there is room to move it, it will be aligned to the edge, else it will be removed.
* accepted values: [null, "justify"]
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
* description: Whether to reserve space for the labels. This can be turned off when for example the labels are rendered inside the plot area instead of outside.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-reservespace/ : No reserved space, labels inside plot.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reserveSpace;
/**
* description: The pixel padding for axis labels, to ensure white space between them.
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: Rotation of the labels in degrees.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-rotation/ : X axis labels rotated 90Â°
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: A http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting : format string for the axis label. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/labels-format/ : Add units to Y axis label
* default: {value}
*/
@property(nonatomic, readwrite) NSString *format;
/**
* description: Horizontal axis only. When staggerLines is not set, maxStaggerLines defines how many lines the axis is allowed to add to automatically avoid overlapping X labels. Set to 1 to disable overlap detection. 
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *maxStaggerLines;
/**
* description: The Z index for the axis labels.
* default: 7
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: Enable or disable the axis labels.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-enabled/ : X axis labels disabled
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: What part of the string the given position is anchored to. If left, the left side of the string is at the axis position. Can be one of "left", "center" or "right". Defaults to an intelligent guess based on which side of the chart the axis is on and the rotation of the label.
* demo: Align http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-align-left/ : left and, 
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-align-right/ : right on X axis.

http://jsfiddle.net/highcharts/72sbw0Lz/ : Understand alignment to boxes, lines and points
* accepted values: ["left", "center", "right"]
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: When each category width is more than this many pixels, we don't apply auto rotation. Instead, we lay out the axis label with word wrap. A lower limit makes sense when the label contains multiple short words that don't extend the available horizontal space for each label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotationlimit/ : Lower limit
* default: 80
*/
@property(nonatomic, readwrite) NSNumber *autoRotationLimit;
/**
* description: Callback JavaScript function to format the label. The value is given by this.value. Additional properties for this are
 axis, chart, isFirst and isLast. The value of the default label formatter can be retrieved by calling this.axis.defaultLabelFormatter.call(this) within the function.
Defaults to: 
function() {
	return this.value;
}

* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-formatter-linked/ : Linked category names. http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-formatter-extended/ : Modified numeric labels.
*/
@property(nonatomic, readwrite) NSString /* Function */ *formatter;
/**
* description: For horizontal axes, the allowed degrees of label rotation to prevent overlapping labels. If there is enough space, labels are not rotated. As the chart gets narrower, it will start rotating the labels -45 degrees, then remove every second label and try again with rotations 0 and -45 etc. Set it to false to disable rotation, which will cause the labels to word-wrap if possible.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-default/ : Default auto rotation of 0 or -45, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-autorotation-0-90/ : custom graded auto rotation
* default: [-45]
*/
@property(nonatomic, readwrite) NSArray<NSNumber *> *autoRotation;
/**
* description: CSS styles for the label. Use whiteSpace: 'nowrap' to prevent wrapping of category labels. Use textOverflow: 'none' to prevent ellipsis (dots).
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the labels are styled with the .highcharts-axis-labels class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/labels-style/ : Red X axis labels
* default: { "color": "#666666", "cursor": "default", "fontSize": "11px" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;

-(NSDictionary *)getParams;

@end
