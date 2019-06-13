/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for a scrollable plot area. This feature provides a minimum size for the plot area of the chart. If the size gets smaller than this, typically on mobile devices, a native browser scrollbar is presented. This scrollbar provides smooth scrolling for the contents of the plot area, whereas the title, legend and unaffected axes are fixed. Since v7.1.2, a scrollable plot area can be defined for either horizontal or vertical scrolling, depending on whether the `minWidth` or `minHeight` option is set.

**Try it**

* [Scrollable plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea)
* [Vertically scrollable plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea-vertical)
*/
@interface HIScrollablePlotArea: HIChartsJSONSerializable

/**
The minimum width for the plot area. If it gets smaller than this, the plot area will become scrollable.
*/
@property(nonatomic, readwrite) NSNumber *minWidth;
/**
The opacity of mask applied on one of the sides of the plot area.

**Defaults to** `0.85`.

**Try it**

* [Disabled opacity for the mask](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/scrollable-plotarea-opacity)
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
The minimum height for the plot area. If it gets smaller than this, the plot area will become scrollable.
*/
@property(nonatomic, readwrite) NSNumber *minHeight;
/**
The initial scrolling position of the scrollable plot area. Ranges from 0 to 1, where 0 aligns the plot area to the top and 1 aligns it to the bottom.
*/
@property(nonatomic, readwrite) NSNumber *scrollPositionY;
/**
The initial scrolling position of the scrollable plot area. Ranges from 0 to 1, where 0 aligns the plot area to the left and 1 aligns it to the right. Typically we would use 1 if the chart has right aligned Y axes.
*/
@property(nonatomic, readwrite) NSNumber *scrollPositionX;

-(NSDictionary *)getParams;

@end
