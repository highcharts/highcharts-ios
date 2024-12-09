/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for formatting dates and times using the [Intl.DateTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DateTimeFormat) API, and extended with some custom options for Highcharts.
*/
@interface HIDateTimeFormatOptions: HIChartsJSONSerializable

/**
The representation of the day.
*/
@property(nonatomic, readwrite) NSString *day;
/**
The representation of the era.
*/
@property(nonatomic, readwrite) NSString *era;
/**
The format matching algorithm to use.
*/
@property(nonatomic, readwrite) NSString *formatMatcher;
/**
The number of fractional digits to use. 3 means milliseconds.
*/
@property(nonatomic, readwrite) NSNumber *fractionalSecondDigits;
/**
The representation of the hour.
*/
@property(nonatomic, readwrite) NSString *hour;
/**
Whether to use 12-hour time (as opposed to 24-hour time).
*/
@property(nonatomic, readwrite) NSString *hour12;
/**
The locale matching algorithm to use.
*/
@property(nonatomic, readwrite) NSString *localeMatcher;
/**
The representation of the minute.
*/
@property(nonatomic, readwrite) NSString *minute;
/**
The representation of the month. "narrow", "short", "long".
*/
@property(nonatomic, readwrite) NSString *month;
/**
A prefix for the time string. Custom Highcharts option.
*/
@property(nonatomic, readwrite) NSString *prefix;
/**
The representation of the second.
*/
@property(nonatomic, readwrite) NSString *second;
/**
A suffix for the time string. Custom Highcharts option.
*/
@property(nonatomic, readwrite) NSString *suffix;
/**
The time zone to use. The default is the browser's default time zone.
*/
@property(nonatomic, readwrite) NSString *timeZone;
/**
The representation of the time zone name.
*/
@property(nonatomic, readwrite) NSString *timeZoneName;
/**
The representation of the weekday.
*/
@property(nonatomic, readwrite) NSString *weekday;
/**
The representation of the year.
*/
@property(nonatomic, readwrite) NSString *year;

-(NSDictionary *)getParams;

@end
