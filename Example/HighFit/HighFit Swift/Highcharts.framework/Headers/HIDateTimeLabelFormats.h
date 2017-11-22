/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: For series on a datetime axes, the date format in the tooltip's
header will by default be guessed based on the closest data points.
This member gives the default string representations used for
each unit. For an overview of the replacement codes, see dateFormat.
Defaults to:
{
    millisecond:"%A, %b %e, %H:%M:%S.%L",
    second:"%A, %b %e, %H:%M:%S",
    minute:"%A, %b %e, %H:%M",
    hour:"%A, %b %e, %H:%M",
    day:"%A, %b %e, %Y",
    week:"Week from %A, %b %e, %Y",
    month:"%B %Y",
    year:"%Y"
}
*/
@interface HIDateTimeLabelFormats: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *hour;
@property(nonatomic, readwrite) NSString *month;
@property(nonatomic, readwrite) NSString *year;
@property(nonatomic, readwrite) NSString *second;
@property(nonatomic, readwrite) NSString *week;
@property(nonatomic, readwrite) NSString *millisecond;
@property(nonatomic, readwrite) NSString *minute;
@property(nonatomic, readwrite) NSString *day;

-(NSDictionary *)getParams;

@end
