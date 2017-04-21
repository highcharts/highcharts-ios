/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: An array defining breaks in the axis, the sections defined will be left out and all the points shifted closer to each other. Requires that the broken-axis.js module is loaded.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-simple/ : Simple break, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-visualized/ : advanced with callback
*/
@interface HIYAxisBreaks: HIChartsJSONSerializable

/**
* description: A number indicating how much space should be left between the start and the end of the break. The break size is given in axis units, so for instance on a datetime axis, a break size of 3600000 would indicate the equivalent of an hour.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *breakSize;
/**
* description: The point where the break ends.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
* description: The point where the break starts.
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
* description: Defines an interval after which the break appears again. By default the breaks do not repeat.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-repeated/ : Repeated Break
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *repeat;

-(NSDictionary *)getParams;

@end
