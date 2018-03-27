/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
An array of data classes or ranges for the choropleth map. If none given, the color axis is scalar and values are distributed as a gradient between the minimum and maximum colors.
*/
@interface HIDataClasses: HIChartsJSONSerializable

/**
The color of each data class. If not set, the color is pulled from the global or chart-specific `colors` array. In styled mode, this option is ignored. Instead, use colors defined in CSS.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
The end of the value range that the data class represents, relating to the point value. The range of each `dataClass` is closed in both ends, but can be overridden by the next `dataClass`.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
The start of the value range that the data class represents, relating to the point value. The range of each `dataClass` is closed in both ends, but can be overridden by the next `dataClass`.
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
The name of the data class as it appears in the legend. If no name is given, it is automatically created based on the `from` and `to` values. For full programmatic control, `legend.labelFormatter` can be used. In the formatter, `this.from` and `this.to` can be accessed.
*/
@property(nonatomic, readwrite) NSString *name;

-(NSDictionary *)getParams;

@end
