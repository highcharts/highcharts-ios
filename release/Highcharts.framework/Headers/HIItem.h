/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
 A `item` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `item` series are defined in `plotOptions.item`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        item: {
            // shared options for all item series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'item'
    }]
 });
 <pre>
 */
@interface HIItem: HISeries

/**
In circular view, the size of the inner diameter of the circle. Can be a percentage or pixel value. Percentages are relative to the outer perimeter. Pixel values are given as integers. If the `rows` option is set, it overrides the `innerSize` setting.

**Defaults to** `0`.

**Try it**

* [Parliament chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/parliament-chart)
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ innerSize;
/**
The number of rows to display in the rectangular or circular view. If the `innerSize` is set, it will be overridden by the `rows` setting.

**Try it**

* [Fixed row count](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-item/rows-columns)
*/
@property(nonatomic, readwrite) NSNumber *rows;
/**
The layout of the items in rectangular view. Can be either `horizontal` or `vertical`.

**Try it**

* [Horizontal layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-item/symbols)
*/
@property(nonatomic, readwrite) NSString *layout;
/**
The padding between the items, given in relative size where the size of the item is 1.
*/
@property(nonatomic, readwrite) NSNumber *itemPadding;
/**
In circular view, the end angle of the item layout, in degrees where 0 is up.

**Try it**

* [Parliament chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/parliament-chart)
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
In circular view, the start angle of the item layout, in degrees where 0 is up.

**Defaults to** `0`.

**Try it**

* [Parliament chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/parliament-chart)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
Equivalent to `chart.ignoreHiddenSeries`, this option tells whether the series shall be redrawn as if the hidden point were `null`. The default value changed from `false` to `true` with Highcharts 3.0.

**Try it**

* [True, the hiddden point is ignored](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-ignorehiddenpoint/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;
/**
A series specific or series type specific color set to use instead of the global `colors`.

**Try it**

* [Set default colors for all pies](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome/)
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The diameter of the pie relative to the plot area. Can be a percentage or pixel value. Pixel values are given as integers. The default behaviour (as of 3.0) is to scale to the plot area and give room for data labels within the plot area. `slicedOffset` is also included in the default size calculation. As a consequence, the size of the pie may vary when points are updated and data labels more around. In that case it is best to set a fixed value, for example `"75%"`.

**Try it**

* [Smaller pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ size;
/**
The minimum size for a pie in response to auto margins. The pie will try to shrink to make room for data labels in side the plot area, but only to this size.

**Defaults to** `80`.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ minSize;
/**
If the total sum of the pie's values is 0, the series is represented as an empty circle . The `fillColor` option defines the color of that circle. Use `pie.borderWidth` to set the border thickness.

**Try it**

* [Empty pie series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-emptyseries/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The center of the pie chart relative to the plot area. Can be percentages or pixel values. The default behaviour (as of 3.0) is to center the pie so that all slices and data labels are within the plot area. As a consequence, the pie may actually jump around in a chart with dynamic values, as the data labels move. In that case, the center should be explicitly set, for example to `["50%", "50%"]`.

**Defaults to** `[null, null]`.

**Try it**

* [Centered at 100, 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-center/)
*/
@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *center;

-(NSDictionary *)getParams;

@end
