/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAttributes.h"


/**
 */
@interface HIReverseArrow: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIAttributes *attributes;
@property(nonatomic, readwrite) NSString *tagName;

-(NSDictionary *)getParams;

@end
