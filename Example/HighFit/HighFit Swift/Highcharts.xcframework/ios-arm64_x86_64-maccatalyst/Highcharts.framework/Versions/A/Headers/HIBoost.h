/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDebug.h"


/**
Options for the Boost module. The Boost module allows certain series types to be rendered by WebGL instead of the default SVG. This allows hundreds of thousands of data points to be rendered in milliseconds. In addition to the WebGL rendering it saves time by skipping processing and inspection of the data wherever possible. This introduces some limitations to what features are available in boost mode. See [the docs](https://www.highcharts.com/docs/advanced-chart-features/boost-module) for details. In addition to the global `boost` option, each series has a `boostThreshold` that defines when the boost should kick in. Requires the `modules/boost.js` module.

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/line)
* [Line chart with hundreds of series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/line-series-heavy)
* [Scatter chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/scatter)
* [Area chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/area)
* [Area range chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/arearange)
* [Column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/column)
* [Column range chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/columnrange)
* [Bubble chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/bubble)
* [Heat map](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/heatmap)
* [Tree map](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/treemap)
*/
@interface HIBoost: HIChartsJSONSerializable

/**
If set to true, the whole chart will be boosted if one of the series crosses its threshold, and all the series can be boosted.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowForce;
/**
The pixel ratio for the WebGL content. If 0, the `window.devicePixelRatio` is used. This ensures sharp graphics on high DPI displays like Apple's Retina, as well as when a page is zoomed. The default is left at 1 for now, as this is a new feature that has the potential to break existing setups. Over time, when it has been battle tested, the intention is to set it to 0 by default. Another use case for this option is to set it to 2 in order to make exported and upscaled charts render sharp. One limitation when using the `pixelRatio` is that the line width of graphs is scaled down. Since the Boost module currently can only render 1px line widths, it is scaled down to a thin 0.5 pixels on a Retina display.

**Defaults to** `1`.

**Try it**

* [Enable the `devicePixelRatio`](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/line-devicepixelratio)
* [Sharper graphics in export](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/boost/line-export-pixelratio)
*/
@property(nonatomic, readwrite) NSNumber *pixelRatio;
/**
Enable or disable boost on a chart.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Set the series threshold for when the boost should kick in globally. Setting to e.g. 20 will cause the whole chart to enter boost mode if there are 20 or more series active. When the chart is in boost mode, every series in it will be rendered to a common canvas. This offers a significant speed improvment in charts with a very high amount of series.

**Defaults to** `50`.
*/
@property(nonatomic, readwrite) NSNumber *seriesThreshold;
/**
Enable or disable pre-allocation of vertex buffers. Enabling this will make it so that the binary data arrays required for storing the series data will be allocated prior to transforming the data to a WebGL-compatible format. This saves a copy operation on the order of O(n) and so is significantly more performant. However, this is currently an experimental option, and may cause visual artifacts with some datasets. As such, care should be taken when using this setting to make sure that it doesn't cause any rendering glitches with the given use-case.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *usePreallocated;
/**
Enable or disable GPU translations. GPU translations are faster than doing the translation in JavaScript. This option may cause rendering issues with certain datasets. Namely, if your dataset has large numbers with small increments (such as timestamps), it won't work correctly. This is due to floating point precission.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useGPUTranslations;
/**
Debugging options for boost. Useful for benchmarking, and general timing.
*/
@property(nonatomic, readwrite) HIDebug *debug;

-(NSDictionary *)getParams;

@end
