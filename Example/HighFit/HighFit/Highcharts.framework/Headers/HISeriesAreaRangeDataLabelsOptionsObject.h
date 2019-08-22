/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Extended data labels for range series types. Range series data labels use no `x` and `y` options. Instead, they have `xLow`, `xHigh`, `yLow` and `yHigh` options to allow the higher and lower data label sets individually.
*/
@interface HISeriesAreaRangeDataLabelsOptionsObject: HIChartsJSONSerializable

/**
X offset of the higher data labels relative to the point value.
*/
@property(nonatomic, readwrite) NSNumber *xHigh;
/**
X offset of the lower data labels relative to the point value.
*/
@property(nonatomic, readwrite) NSNumber *xLow;
/**
Y offset of the higher data labels relative to the point value.
*/
@property(nonatomic, readwrite) NSNumber *yHigh;
/**
Y offset of the lower data labels relative to the point value.
*/
@property(nonatomic, readwrite) NSNumber *yLow;

-(NSDictionary *)getParams;

@end
