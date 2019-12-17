/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMillisecond.h"
#import "HIWeek.h"
#import "HIHour.h"
#import "HIMonth.h"
#import "HISecond.h"
#import "HIYear.h"
#import "HIDay.h"
#import "HIMinute.h"


/**
For a datetime axis, the scale will automatically adjust to the appropriate unit. This member gives the default string representations used for each unit. For intermediate values, different units may be used, for example the `day` unit can be used on midnight and `hour` unit be used for intermediate values on the same axis. For an overview of the replacement codes, see `dateFormat`. Defaults to: ```js {   millisecond: '%H:%M:%S.%L',   second: '%H:%M:%S',   minute: '%H:%M',   hour: '%H:%M',   day: '%e. %b',   week: '%e. %b',   month: '%b \'%y',   year: '%Y' } ```

**Try it**

* [Different day format on X axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/datetimelabelformats/)
*/
@interface HIDateTimeLabelFormats: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIMillisecond *millisecond;
@property(nonatomic, readwrite) HIWeek *week;
@property(nonatomic, readwrite) HIHour *hour;
@property(nonatomic, readwrite) HIMonth *month;
@property(nonatomic, readwrite) HISecond *second;
@property(nonatomic, readwrite) HIYear *year;
@property(nonatomic, readwrite) HIDay *day;
@property(nonatomic, readwrite) HIMinute *minute;

-(NSDictionary *)getParams;

@end
