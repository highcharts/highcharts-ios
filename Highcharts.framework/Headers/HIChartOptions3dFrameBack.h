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
* description: Defines the back panel of the frame around 3D charts.
*/
@interface HIChartOptions3dFrameBack: HIChartsJSONSerializable

/**
* description: The color of the panel.
* default: transparent
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: Thickness of the panel.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *size;

-(NSDictionary *)getParams;

@end
