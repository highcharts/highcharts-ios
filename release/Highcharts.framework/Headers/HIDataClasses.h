/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: An array of data classes or ranges for the choropleth map. If none
given, the color axis is scalar and values are distributed as a gradient
between the minimum and maximum colors.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/data-class-ranges/ : Multiple ranges
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/data-class-two-ranges/ : Two ranges
*/
@interface HIDataClasses: HIChartsJSONSerializable

/**
* description: The name of the data class as it appears in the legend. If no name
is given, it is automatically created based on the from and to
values. For full programmatic control, legend.labelFormatter can be used. In the formatter, this.from and this.
to can be accessed.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/dataclasses-name/ : Named data classes
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/coloraxis/dataclasses-labelformatter/ : Formatted data classes
*/
@property(nonatomic, readwrite) NSString *name;
/**
* description: The end of the value range that the data class represents, relating
to the point value.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
* description: The color of each data class. If not set, the color is pulled from
the global or chart-specific colors array. In 
styled mode, this option is ignored. Instead, use colors defined in
CSS.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/data-class-two-ranges/ : Explicit colors
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: The start of the value range that the data class represents, relating
to the point value.
*/
@property(nonatomic, readwrite) NSNumber *from;

-(NSDictionary *)getParams;

@end
