/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
An array defining breaks in the axis, the sections defined will be left out and all the points shifted closer to each other.

**Try it**

* [Simple break](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-simple/)
* [Advanced with callback](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/axisbreak/break-visualized/)
*/
@interface HIBreaks: HIChartsJSONSerializable

/**
The point where the break ends.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
A number indicating how much space should be left between the start and the end of the break. The break size is given in axis units, so for instance on a `datetime` axis, a break size of 3600000 would indicate the equivalent of an hour.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *breakSize;
/**
The point where the break starts.
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
Defines an interval after which the break appears again. By default the breaks do not repeat.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *repeat;

-(NSDictionary *)getParams;

@end
