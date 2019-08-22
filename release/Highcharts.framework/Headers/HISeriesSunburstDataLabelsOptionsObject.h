/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for data labels in the sunburst series.
*/
@interface HISeriesSunburstDataLabelsOptionsObject: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *align;
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
Decides how the data label will be rotated relative to the perimeter of the sunburst. Valid values are `auto`, `parallel` and `perpendicular`. When `auto`, the best fit will be computed for the point. The `series.rotation` option takes precedence over `rotationMode`.
*/
@property(nonatomic, readwrite) NSString *rotationMode;

-(NSDictionary *)getParams;

@end
