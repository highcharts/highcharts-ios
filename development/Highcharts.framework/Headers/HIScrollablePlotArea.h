/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for a scrollable plot area. This feature provides a minimum width for the plot area of the chart. If the width gets smaller than this, typically on mobile devices, a native browser scrollbar is presented below the chart. This scrollbar provides smooth scrolling for the contents of the plot area, whereas the title, legend and axes are fixed.

**Try it**

* [Scrollable plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea)
*/
@interface HIScrollablePlotArea: HIChartsJSONSerializable

/**
The minimum width for the plot area. If it gets smaller than this, the plot area will become scrollable.
*/
@property(nonatomic, readwrite) NSNumber *minWidth;
/**
The initial scrolling position of the scrollable plot area. Ranges from 0 to 1, where 0 aligns the plot area to the left and 1 aligns it to the right. Typically we would use 1 if the chart has right aligned Y axes.
*/
@property(nonatomic, readwrite) NSNumber *scrollPositionX;

-(NSDictionary *)getParams;

@end
