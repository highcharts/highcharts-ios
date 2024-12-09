/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDateTimeFormatOptions.h"


/**
 */
@interface HIYear: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIDateTimeFormatOptions *main;
@property(nonatomic, readwrite) NSArray *list;

-(NSDictionary *)getParams;

@end
