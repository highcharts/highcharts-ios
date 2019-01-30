/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Apply a jitter effect for the rendered markers. When plotting discrete values, a little random noise may help telling the points apart. The jitter setting applies a random displacement of up to `n` axis units in either direction. So for example on a horizontal X axis, setting the `jitter.x` to 0.24 will render the point in a random position between 0.24 units to the left and 0.24 units to the right of the true axis position. On a category axis, setting it to 0.5 will fill up the bin and make the data appear continuous. When rendered on top of a box plot or a column series, a jitter value of 0.24 will correspond to the underlying series' default [groupPadding](https://api.highcharts.com/highcharts/plotOptions.column.groupPadding) and [pointPadding](https://api.highcharts.com/highcharts/plotOptions.column.pointPadding) settings.

**Try it**

* [Jitter on a scatter plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter)
* [Jittered scatter plot on top of a box plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-scatter/jitter-boxplot)
*/
@interface HIJitter: HIChartsJSONSerializable

/**
The maximal Y offset for the random jitter effect.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The maximal X offset for the random jitter effect.
*/
@property(nonatomic, readwrite) NSNumber *x;

-(NSDictionary *)getParams;

@end
