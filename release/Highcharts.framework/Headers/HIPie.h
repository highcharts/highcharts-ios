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
A `pie` series. If the `type` option is not specified, it is inherited from `chart.type`.

Configuration options for the series are given in three levels:
 
1. Options for all series in a chart are defined in the `plotOptions.series` object.

2. Options for all `pie` series are defined in `plotOptions.pie`.

3. Options for one single series are given in `the series instance array`.
 
<pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        pie: {
            // shared options for all pie series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'pie'
    }]
 });
<pre>
*/
@interface HIPie: HISeries

/**
The minimum size for a pie in response to auto margins. The pie will try to shrink to make room for data labels in side the plot area, but only to this size.

**Defaults to** `80`.
*/
@property(nonatomic, readwrite) NSNumber *minSize;
/**
The size of the inner diameter for the pie. A size greater than 0 renders a donut chart. Can be a percentage or pixel value. Percentages are relative to the pie size. Pixel values are given as integers. Note: in Highcharts < 4.1.2, the percentage was relative to the plot area, not the pie size.

**Defaults to** `0`.

**Try it**

* [80px inner size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-innersize-80px/)
* [50% of the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-innersize-50percent/)
* [3D donut](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-pie-donut/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerSize;
/**
The center of the pie chart relative to the plot area. Can be percentages or pixel values. The default behaviour (as of 3.0) is to center the pie so that all slices and data labels are within the plot area. As a consequence, the pie may actually jump around in a chart with dynamic values, as the data labels move. In that case, the center should be explicitly set, for example to `["50%", "50%"]`.

**Defaults to** `[null, null]`.

**Try it**

* [Centered at 100, 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-center/)
*/
@property(nonatomic, readwrite) NSArray /* <NSString, NSNumber> */ *center;
/**
If a point is sliced, moved out from the center, how many pixels should it be moved?.

**Defaults to** `10`.

**Try it**

* [20px offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-slicedoffset-20/)
*/
@property(nonatomic, readwrite) NSNumber *slicedOffset;
/**
The thickness of a 3D pie. Requires `highcharts-3d.js`

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
The end angle of the pie in degrees where 0 is top and 90 is right. Defaults to `startAngle` plus 360.

**Defaults to** `null`.

**Try it**

* [Semi-circle donut](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-semi-circle/)
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
A series specific or series type specific color set to use instead of the global `colors`.

**Try it**

* [Set default colors for all pies](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome/)
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The start angle of the pie slices in degrees where 0 is top and 90 right.

**Defaults to** `0`.

**Try it**

* [Start from right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-startangle-90/)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
The diameter of the pie relative to the plot area. Can be a percentage or pixel value. Pixel values are given as integers. The default behaviour (as of 3.0) is to scale to the plot area and give room for data labels within the plot area. `slicedOffset` is also included in the default size calculation. As a consequence, the size of the pie may vary when points are updated and data labels more around. In that case it is best to set a fixed value, for example `"75%"`.

**Try it**

* [Smaller pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-size/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ size;
/**
Equivalent to `chart.ignoreHiddenSeries`, this option tells whether the series shall be redrawn as if the hidden point were `null`. The default value changed from `false` to `true` with Highcharts 3.0.

**Defaults to** `true`.

**Try it**

* [True, the hiddden point is ignored](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-ignorehiddenpoint/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;

-(NSDictionary *)getParams;

@end
