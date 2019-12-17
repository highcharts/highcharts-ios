/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Language options for accessibility of the legend.
*/
@interface HIAccessibilityLegend: HIChartsJSONSerializable

/**
**Defaults to** `"Toggle visibility of {itemName}"`.
*/
@property(nonatomic, readwrite) NSString *legendItem;
/**
**Defaults to** `"Toggle series visibility"`.
*/
@property(nonatomic, readwrite) NSString *legendLabel;

-(NSDictionary *)getParams;

@end
