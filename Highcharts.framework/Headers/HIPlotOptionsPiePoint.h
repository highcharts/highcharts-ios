/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPlotOptionsPiePointEvents.h"


/**
* description: Properties for each single point
*/
@interface HIPlotOptionsPiePoint: HIChartsJSONSerializable

/**
* description: Events for each single point
*/
@property(nonatomic, readwrite) HIPlotOptionsPiePointEvents *events;

-(NSDictionary *)getParams;

@end
