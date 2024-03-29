/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Range selector language options for accessibility.
*/
@interface HIRangeSelector: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *dropdownLabel;
@property(nonatomic, readwrite) NSString *maxInputLabel;
@property(nonatomic, readwrite) NSString *clickButtonAnnouncement;
@property(nonatomic, readwrite) NSString *minInputLabel;

-(NSDictionary *)getParams;

@end
