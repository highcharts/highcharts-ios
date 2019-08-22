/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFunction.h"
#import "HIDataLabelsTextPathOptionsObject.h"


/**
Data labels options
*/
@interface HISeriesNetworkgraphDataLabelsOptionsObject: HIChartsJSONSerializable

/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _node_ in the networkgraph. In v7.0 defaults to `{key}`, since v7.1 defaults to `undefined` and `formatter` is used instead.
*/
@property(nonatomic, readwrite) NSString *format;
/**
Callback JavaScript function to format the data label for a node. Note that if a `format` is defined, the format takes precedence and the formatter is ignored.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _links_ in the networkgraph. (Default: `undefined`)
*/
@property(nonatomic, readwrite) NSString *linkFormat;
/**
Callback to format data labels for _links_ in the sankey diagram. The `linkFormat` option takes precedence over the `linkFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *linkFormatter;
/**
Options for a _link_ label text which should follow link connection. Border and background are disabled for a label that follows a path. **Note:** Only SVG-based renderer supports this option. Setting `useHTML` to true will disable this option.
*/
@property(nonatomic, readwrite) HIDataLabelsTextPathOptionsObject *linkTextPath;

-(NSDictionary *)getParams;

@end
