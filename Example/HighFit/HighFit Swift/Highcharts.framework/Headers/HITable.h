/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Accessibility language options for the data table.
*/
@interface HITable: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *tableSummary;
@property(nonatomic, readwrite) NSString *viewAsDataTableButtonText;

-(NSDictionary *)getParams;

@end
