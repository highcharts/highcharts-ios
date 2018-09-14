/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Default styling for the checkbox next to a legend item when `showCheckbox` is true.
*/
@interface HIItemCheckboxStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *position;
@property(nonatomic, readwrite) NSString *width;
@property(nonatomic, readwrite) NSString *height;

-(NSDictionary *)getParams;

@end
