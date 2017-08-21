/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISplineStatesHover.h"


/**
* description: A wrapper object for all the series options in specific states.
*/
@interface HISplineStates: HIChartsJSONSerializable

/**
* description: Options for the hovered series
*/
@property(nonatomic, readwrite) HISplineStatesHover *hover;

-(NSDictionary *)getParams;

@end
