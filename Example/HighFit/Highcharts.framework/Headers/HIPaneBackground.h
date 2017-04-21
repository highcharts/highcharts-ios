/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: An object, or array of objects, for backgrounds.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/ : Multiple backgrounds on a gauge.
*/
@interface HIPaneBackground: HIChartsJSONSerializable

/**
* description: The pane background border color.
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Tha shape of the pane background. When solid, the background is circular. When arc, the background extends only from the min to the max of the value axis.
* accepted values: ["solid", "arc"]
* default: solid
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: The class name for this background.
* demo:  http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/pane/ : Panes styled by CSS in http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode
* default: highcharts-pane
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The background color or gradient for the pane.
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: The pixel border width of the pane background.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The inner radius of the pane background. Can be either numeric (pixels) or a percentage string.
* default: 0
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ innerRadius;
/**
* description: The outer radius of the circular pane background. Can be either numeric (pixels) or a percentage string.
* default: 105%
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ outerRadius;

-(NSDictionary *)getParams;

@end
