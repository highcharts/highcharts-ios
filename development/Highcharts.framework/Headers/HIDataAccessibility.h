/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import "HIChartsJSONSerializable.h"

@interface HIDataAccessibility: HIChartsJSONSerializable

/**
 Provide a description of the data point, announced to screen readers.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) NSString *definition;

-(NSDictionary *)getParams;

@end
