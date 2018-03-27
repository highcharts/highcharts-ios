/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Descriptions of lesser known series types. The relevant description is added to the screen reader information region when these series types are used.
*/
@interface HISeriesTypeDescriptions: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *funnel;
@property(nonatomic, readwrite) NSString *pyramid;
@property(nonatomic, readwrite) NSString *columnrange;
@property(nonatomic, readwrite) NSString *errorbar;
@property(nonatomic, readwrite) NSString *areasplinerange;
@property(nonatomic, readwrite) NSString *waterfall;
@property(nonatomic, readwrite) NSString *arearange;
@property(nonatomic, readwrite) NSString *bubble;
@property(nonatomic, readwrite) NSString *boxplot;

-(NSDictionary *)getParams;

@end
