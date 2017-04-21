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
* description: The bottom of the frame around a 3D chart.
*/
@interface HIChartOptions3dFrameBottom: HIChartsJSONSerializable

/**
* description: The thickness of the panel.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *size;
/**
* description: The color of the panel.
* default: transparent
*/
@property(nonatomic, readwrite) HIColor *color;

-(NSDictionary *)getParams;

@end
