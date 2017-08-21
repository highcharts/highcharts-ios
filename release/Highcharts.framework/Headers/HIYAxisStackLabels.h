/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The stack labels show the total value for each bar in a stacked column or bar chart. The label will be placed on top of
	positive columns and below negative columns. In case of an inverted column chart or a bar chart the label is placed to 
	the right of positive bars and to the left of negative bars.
*/
@interface HIYAxisStackLabels: HIChartsJSONSerializable

/**
* description: CSS styles for the label.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the styles are set in the .highcharts-stack-label class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-style/ : Red stack total labels
* default: { "color": "#000000", "fontSize": "11px", "fontWeight": "bold", "textShadow": "1px 1px contrast, -1px -1px contrast, -1px 1px contrast, 1px -1px contrast" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: A http://docs.highcharts.com/#formatting : format string for the data label. Available variables are the same as for formatter.
* default: {total}
*/
@property(nonatomic, readwrite) NSString *format;
/**
* description: Defines the horizontal alignment of the stack total label.  Can be one of "left", "center" or "right". The default value is calculated at runtime and depends on orientation and whether  the stack is positive or negative.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-left/ : aligned to the left,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-center/ : aligned in center,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-align-right/ : aligned to the right
* accepted values: ["left", "center", "right"]
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: The x position offset of the label relative to the left of the stacked bar. The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-x/ : Stack total labels with x offset
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The y position offset of the label relative to the tick position on the axis. The default value is calculated at runtime and depends on orientation and whether  the stack is positive or negative.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-y/ : Stack total labels with y offset
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Whether to http://docs.highcharts.com/#formatting$html : use HTML to render the labels.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: Rotation of the labels in degrees.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-rotation/ : Labels rotated 45Â°
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: The text alignment for the label. While align determines where the texts anchor point is placed with regards to the stack, textAlign determines how the text is aligned against its anchor point. Possible values are "left", "center" and "right". The default value is calculated at runtime and depends on orientation and whether the stack is positive or negative.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-textalign-left/ : Label in center position but text-aligned left
* accepted values: ["left", "center", "right"]
*/
@property(nonatomic, readwrite) NSString *textAlign;
/**
* description: Enable or disable the stack total labels.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-enabled/ : Enabled stack total labels
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Defines the vertical alignment of the stack total label. Can be one of "top", "middle" or "bottom". The default value is calculated at runtime and depends on orientation and whether  the stack is positive or negative.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-top/ : "Vertically aligned top",
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-middle/ : "Vertically aligned middle",
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-verticalalign-bottom/ : "Vertically aligned bottom"
* accepted values: ["top", "middle", "bottom"]
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: Callback JavaScript function to format the label. The value is  given by this.total. Defaults to: 
function() {
	return this.total;
}
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/yaxis/stacklabels-formatter/ : Added units to stack total value
*/
@property(nonatomic, readwrite) NSString /* Function */ *formatter;

-(NSDictionary *)getParams;

@end
