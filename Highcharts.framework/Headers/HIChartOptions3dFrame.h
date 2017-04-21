/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartOptions3dFrameBack.h"
#import "HIChartOptions3dFrameSide.h"
#import "HIChartOptions3dFrameBottom.h"


/**
* description: Provides the option to draw a frame around the charts by defining a bottom, front and back panel. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/3d/column-frame/ : Framed column chart
*/
@interface HIChartOptions3dFrame: HIChartsJSONSerializable

/**
* description: Defines the back panel of the frame around 3D charts.
*/
@property(nonatomic, readwrite) HIChartOptions3dFrameBack *back;
/**
* description: The side for the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIChartOptions3dFrameSide *side;
/**
* description: The bottom of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIChartOptions3dFrameBottom *bottom;

-(NSDictionary *)getParams;

@end
