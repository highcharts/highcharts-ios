/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
Data labels options
*/
@interface HIPlotPackedBubbleDataLabelsOptionsObject: HIChartsJSONSerializable

/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _node_ in the networkgraph. In v7.0 defaults to `{key}`, since v7.1 defaults to `undefined` and `formatter` is used instead.
*/
@property(nonatomic, readwrite) NSString *format;
/**
Callback JavaScript function to format the data label for a node. Note that if a `format` is defined, the format takes precedence and the formatter is ignored.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
Options for a _node_ label text which should follow marker's shape. **Note:** Only SVG-based renderer supports this option.
*/
@property(nonatomic, readwrite) id textPath;

-(NSDictionary *)getParams;

@end
