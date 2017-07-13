/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Text labels for the plot bands
*/
@interface HIZAxisPlotBandsLabel: HIChartsJSONSerializable

/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html : use HTML to render the labels.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: The text alignment for the label. While align determines where the texts anchor point is placed within the plot band, textAlign determines how the text is aligned against its anchor point. Possible values are "left", "center" and "right". Defaults to the same as the align option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-rotation/ : Vertical text in center position but text-aligned left
*/
@property(nonatomic, readwrite) NSString *textAlign;
/**
* description: Vertical alignment of the label relative to the plot band. Can be one of "top", "middle" or "bottom".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-verticalalign/ : Vertically centered label
* default: top
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: CSS styles for the text label.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the labels are styled by the .highcharts-plot-band-label class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-style/ : Blue and bold label
*/
@property(nonatomic, readwrite) id style;
/**
* description: Vertical position of the text baseline relative to the alignment. Default varies by orientation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-y/ : Label on x axis
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Horizontal position relative the alignment. Default varies by orientation.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-align/ : Aligned 10px from the right edge
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The string text itself. A subset of HTML is supported.
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: Rotation of the text label in degrees .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-rotation/ : Vertical text
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: Horizontal alignment of the label. Can be one of "left", "center" or "right".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-align/ : Aligned to the right
* default: center
*/
@property(nonatomic, readwrite) NSString *align;

-(NSDictionary *)getParams;

@end
