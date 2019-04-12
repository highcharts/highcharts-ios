/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names.
*/
@interface HIPlotSankeyDataLabelsOptionsObject: HIChartsJSONSerializable

/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _nodes_ in the sankey diagram. By default the `nodeFormatter` returns `{point.name}`.
*/
@property(nonatomic, readwrite) NSString *nodeFormat;
/**
Callback to format data labels for _nodes_ in the sankey diagram. The `nodeFormat` option takes precedence over the `nodeFormatter`.
*/
@property(nonatomic, readwrite) id nodeFormatter;

-(NSDictionary *)getParams;

@end
