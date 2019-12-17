/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for a _parentNode_ label text. **Note:** Only SVG-based renderer supports this option.

**Try it**

* [Dashboard with dataLabels on parentNodes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/packed-dashboard)
*/
@interface HIParentNodeTextPath: HIChartsJSONSerializable

/**
Enable or disable `textPath` option for link's or marker's data labels.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
