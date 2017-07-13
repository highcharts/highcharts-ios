/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The chart's subtitle
*/
@interface HISubtitle: HIChartsJSONSerializable

/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html : use HTML to render the text.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: The horizontal alignment of the subtitle. Can be one of "left", "center" and "right".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/align/ : Footnote at right of plot area
* accepted values: ["left", "center", "right"]
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: The vertical alignment of the title. Can be one of "top", "middle" and "bottom". When a value is given, the title behaves as floating.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/verticalalign/ : Footnote at the bottom right of plot area
* accepted values: ["top", "middle", "bottom"]
* default:  
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: CSS styles for the title.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the subtitle style is given in the .highcharts-subtitle class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/style/ : Custom color and weight.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/titles/ : Styled mode.
* default: { "color": "#666666" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: The subtitle of the chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/text/ : Custom subtitle,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/text-formatted/ : formatted and linked text.
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: When the subtitle is floating, the plot area will not move to make space for it.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/floating/ : Floating title and subtitle.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
* description: The x position of the subtitle relative to the alignment within chart.spacingLeft and chart.spacingRight.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/align/ : Footnote at right of plot area
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The y position of the subtitle relative to the alignment within chart.spacingTop and chart.spacingBottom. By default the subtitle is laid out below the title unless the title is floating.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/subtitle/verticalalign/ : Footnote at the bottom right of plot area
* default:  null
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Adjustment made to the subtitle width, normally to reserve space for the exporting burger menu.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/title/widthadjust/ : Wider menu, greater padding
* default: -44
*/
@property(nonatomic, readwrite) NSNumber *widthAdjust;

-(NSDictionary *)getParams;

@end
