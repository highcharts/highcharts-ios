/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIBoxplotPointEvents.h"


/**
* description: Properties for each single point
*/
@interface HIBoxplotPoint: HIChartsJSONSerializable

/**
* description: Events for each single point
*/
@property(nonatomic, readwrite) HIBoxplotPointEvents *events;

-(NSDictionary *)getParams;

@end
