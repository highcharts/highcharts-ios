/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import "HIKeyboardNavigation.h"
#import "HIFunction.h"

/**
 Accessibility options for a series. Requires the accessibility module.
 */
@interface HISeriesAccessibility: HIChartsJSONSerializable

/**
 Provide a description of the series, announced to screen readers.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) NSString *definition;
/**
 Enable/disable accessibility functionality for a specific series.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
 Expose only the series element to screen readers, not its points.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) NSNumber /* Bool */ *exposeAsGroupOnly;
/**
 Keyboard navigation for a series.
 */
@property(nonatomic, readwrite) HIKeyboardNavigation *keyboardNavigation;
/**
 Formatter function to use instead of the default for point descriptions. Same as `accessibility.pointDescriptionFormatter`, but for a single series.
 
 **Defaults to** `undefined`.
 */
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;

-(NSDictionary *)getParams;

@end
