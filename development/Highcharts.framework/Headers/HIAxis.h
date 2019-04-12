/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Axis description format strings.
*/
@interface HIAxis: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *xAxisDescriptionSingular;
@property(nonatomic, readwrite) NSString *timeRangeMinutes;
@property(nonatomic, readwrite) NSString *timeRangeHours;
@property(nonatomic, readwrite) NSString *rangeCategories;
@property(nonatomic, readwrite) NSString *timeRangeSeconds;
@property(nonatomic, readwrite) NSString *yAxisDescriptionPlural;
@property(nonatomic, readwrite) NSString *rangeFromTo;
@property(nonatomic, readwrite) NSString *timeRangeDays;
@property(nonatomic, readwrite) NSString *xAxisDescriptionPlural;
@property(nonatomic, readwrite) NSString *yAxisDescriptionSingular;

-(NSDictionary *)getParams;

@end
