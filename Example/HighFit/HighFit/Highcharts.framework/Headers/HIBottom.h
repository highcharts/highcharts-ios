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
* description: The bottom of the frame around a 3D chart.
*/
@interface HIBottom: HIChartsJSONSerializable

/**
* description: The thickness of the panel.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *size;
/**
* description: Whether to display the frame. Possible values are true, false,
"auto" to display only the frames behind the data, and "default"
to display faces behind the data based on the axis layout, ignoring
the point of view.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-frame/ : Auto frames
* accepted values: ["default", "auto", true, false]
* default: default
*/
@property(nonatomic, readwrite) id /* Bool, NSString */ visible;
/**
* description: The color of the panel.
* default: transparent
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
