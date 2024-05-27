/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"


/**
Disabled state overrides for the buttons are applied in addition to the normal state options
*/
@interface HIDisabled: HIChartsJSONSerializable

/**
Disabled state CSS style overrides for the buttons' text
*/
@property(nonatomic, readwrite) HIStyle *style;

-(NSDictionary *)getParams;

@end
