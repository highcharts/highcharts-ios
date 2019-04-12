/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import "HIChartsJSONSerializable.h"

/**
 Accessibility options for the exporting menu. Requires the Accessibility module.
 */
@interface HIExportingAccessibility: HIChartsJSONSerializable

/**
 Enable accessibility support for the export menu.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
