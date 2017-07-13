/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Options for the pivot or the center point of the gauge.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the pivot is styled with the .highcharts-gauge-series .highcharts-pivot rule.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/gauge/ : Styled mode.



*/
@interface HIPlotOptionsGaugePivot: HIChartsJSONSerializable

/**
* description: The background color or fill of the pivot.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/ : Pivot options demonstrated
* default: #000000
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: The pixel radius of the pivot.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/ : Pivot options demonstrated
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
* description: The border or stroke color of the pivot. In able to change this, the borderWidth must also be set to something other than the default 0.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/ : Pivot options demonstrated
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The border or stroke width of the pivot.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/gauge-pivot/ : Pivot options demonstrated
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;

-(NSDictionary *)getParams;

@end
