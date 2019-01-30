/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAlignObject.h"
#import "HISVGAttributes.h"
#import "HICSSObject.h"


/**
Options for displaying a message like "No data to display". This feature requires the file no-data-to-display.js to be loaded in the page. The actual text to display is set in the lang.noData option.

**Try it**

* [Line chart with no-data module](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
* [Pie chart with no-data module](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-pie)
*/
@interface HINoData: HIChartsJSONSerializable

/**
The position of the no-data label, relative to the plot area.
*/
@property(nonatomic, readwrite) HIAlignObject *position;
/**
CSS styles for the no-data label.

**Try it**

* [Styled no-data text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
An object of additional SVG attributes for the no-data label.
*/
@property(nonatomic, readwrite) HISVGAttributes *attr;
/**
Whether to insert the label as HTML, or as pseudo-HTML rendered with SVG.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;

-(NSDictionary *)getParams;

@end
