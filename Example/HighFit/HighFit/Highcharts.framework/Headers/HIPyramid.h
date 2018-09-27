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
A `pyramid` series. If the `type` option is not specified, it is inherited from `chart.type`.

Configuration options for the series are given in three levels:
 
1. Options for all series in a chart are defined in the `plotOptions.series` object.

2. Options for all `pyramid` series are defined in `plotOptions.pyramid`.

3. Options for one single series are given in `the series instance array`.
 
<pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        pyramid: {
            // shared options for all pyramid series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'pyramid'
    }]
 });
<pre>
*/
@interface HIPyramid: HISeries

/**
The pyramid is reversed by default, as opposed to the funnel, which shares the layout engine, and is not reversed.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
The pyramid neck width is zero by default, as opposed to the funnel, which shares the same layout logic.
*/
@property(nonatomic, readwrite) NSString *neckHeight;
/**
The pyramid neck width is zero by default, as opposed to the funnel, which shares the same layout logic.

**Try it**

* [Funnel demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/)
*/
@property(nonatomic, readwrite) NSString *neckWidth;
/**
The center of the series. By default, it is centered in the middle of the plot area, so it fills the plot area height.

**Defaults to** `["50%", "50%"]`.

**Try it**

* [Centered at 100, 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-center/)
*/
@property(nonatomic, readwrite) NSArray /* <NSString, NSNumber> */ *center;
/**
The height of the funnel or pyramid. If it is a number it defines the pixel height, if it is a percentage string it is the percentage of the plot area height.

**Try it**

* [Funnel demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ height;
/**
The width of the funnel compared to the width of the plot area, or the pixel width if it is a number.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ width;
/**
The end angle of the pie in degrees where 0 is top and 90 is right. Defaults to `startAngle` plus 360.

**Defaults to** `null`.

**Try it**

* [Semi-circle donut](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-semi-circle/)
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
The size of the inner diameter for the pie. A size greater than 0 renders a donut chart. Can be a percentage or pixel value. Percentages are relative to the pie size. Pixel values are given as integers. Note: in Highcharts < 4.1.2, the percentage was relative to the plot area, not the pie size.

**Defaults to** `0`.

**Try it**

* [80px inner size](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-innersize-80px/)
* [50% of the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-innersize-50percent/)
* [3D donut](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-pie-donut/)
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ innerSize;
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
A series specific or series type specific color set to use instead of the global `colors`.

**Try it**

* [Set default colors for all pies](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome/)
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The minimum size for a pie in response to auto margins. The pie will try to shrink to make room for data labels in side the plot area, but only to this size.

**Defaults to** `80`.
*/
@property(nonatomic, readwrite) NSNumber *minSize;
/**
The start angle of the pie slices in degrees where 0 is top and 90 right.

**Defaults to** `0`.

**Try it**

* [Start from right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-startangle-90/)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
Equivalent to `chart.ignoreHiddenSeries`, this option tells whether the series shall be redrawn as if the hidden point were `null`. The default value changed from `false` to `true` with Highcharts 3.0.

**Defaults to** `true`.

**Try it**

* [True, the hiddden point is ignored](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-ignorehiddenpoint/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;

-(NSDictionary *)getParams;

@end
