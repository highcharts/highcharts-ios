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
* description: An array of background items for the pane.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/ : Speedometer gauge with multiple backgrounds
*/
@interface HIBackground: HIChartsJSONSerializable

/**
* description: The class name for this background.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pane/ : Panes styled by CSS

*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Tha shape of the pane background. When solid, the background
is circular. When arc, the background extends only from the min
to the max of the value axis.

* accepted values: ["solid", "arc"]
* default: solid
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: The background color or gradient for the pane.
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: The outer radius of the circular pane background. Can be either
numeric (pixels) or a percentage string.
* default: 105%
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ outerRadius;
/**
* description: The pane background border color.
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The pixel border width of the pane background.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The inner radius of the pane background. Can be either numeric
(pixels) or a percentage string.
* default: 0
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;

-(NSDictionary *)getParams;

@end
