/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIWaterfallStatesHover.h"


/**
* description: A wrapper object for all the series options in specific states.
*/
@interface HIWaterfallStates: HIChartsJSONSerializable

/**
* description: Options for the hovered series
*/
@property(nonatomic, readwrite) HIWaterfallStatesHover *hover;

-(NSDictionary *)getParams;

@end
