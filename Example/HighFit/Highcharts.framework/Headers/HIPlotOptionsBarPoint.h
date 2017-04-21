/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPlotOptionsBarPointEvents.h"


/**
* description: Properties for each single point
*/
@interface HIPlotOptionsBarPoint: HIChartsJSONSerializable

/**
* description: Events for each single point
*/
@property(nonatomic, readwrite) HIPlotOptionsBarPointEvents *events;

-(NSDictionary *)getParams;

@end
