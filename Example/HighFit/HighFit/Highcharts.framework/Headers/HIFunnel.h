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
 A `funnel` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `funnel` series are defined in `plotOptions.funnel`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        funnel: {
            // shared options for all funnel series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'funnel'
    }]
 });
 <pre>
 */
@interface HIFunnel: HISeries

/**
The center of the series. By default, it is centered in the middle of the plot area, so it fills the plot area height.

**Defaults to** `["50%", "50%"]`.

**Try it**

* [Centered at 100, 100](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-center/)
*/
@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *center;
/**
A reversed funnel has the widest area down. A reversed funnel with no neck width and neck height is a pyramid.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
The width of the neck, the lower part of the funnel. A number defines pixel width, a percentage string defines a percentage of the plot area width.

**Try it**

* [Funnel demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ neckWidth;
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
The height of the neck, the lower part of the funnel. A number defines pixel width, a percentage string defines a percentage of the plot area height.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ neckHeight;
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
The color of the border surrounding each slice. When `null`, the border takes the same color as the slice fill. This can be used together with a `borderWidth` to fill drawing gaps created by antialiazing artefacts in borderless pies. In styled mode, the border stroke is given in the `.highcharts-point` class.

**Defaults to** `#ffffff`.

**Try it**

* [Black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-bordercolor-black/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
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
The start angle of the pie slices in degrees where 0 is top and 90 right.

**Defaults to** `0`.

**Try it**

* [Start from right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-startangle-90/)
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
The end angle of the pie in degrees where 0 is top and 90 is right. Defaults to `startAngle` plus 360.

**Try it**

* [Semi-circle donut](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-semi-circle/)
*/
@property(nonatomic, readwrite) NSNumber *endAngle;
/**
If a point is sliced, moved out from the center, how many pixels should it be moved?.

**Try it**

* [20px offset](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-slicedoffset-20/)
*/
@property(nonatomic, readwrite) NSNumber *slicedOffset;
/**
The thickness of a 3D pie.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
The width of the border surrounding each slice. When setting the border width to 0, there may be small gaps between the slices due to SVG antialiasing artefacts. To work around this, keep the border width at 0.5 or 1, but set the `borderColor` to `null` instead. In styled mode, the border stroke width is given in the `.highcharts-point` class.

**Try it**

* [3px border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;

-(NSDictionary *)getParams;

@end
