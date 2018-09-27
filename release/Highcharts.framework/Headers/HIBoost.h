/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDebug.h"


/**
Options for the Boost module. The Boost module allows certain series types to be rendered by WebGL instead of the default SVG. This allows hundreds of thousands of data points to be rendered in milliseconds. In addition to the WebGL rendering it saves time by skipping processing and inspection of the data wherever possible. This introduces some limitations to what features are available in Boost mode. See `the docs` for details. In addition to the global `boost` option, each series has a `boostThreshold` that defines when the boost should kick in. Requires the `modules/boost.js` module.

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
Debugging options for boost. Useful for benchmarking, and general timing.
*/
@property(nonatomic, readwrite) HIDebug *debug;
/**
If set to true, the whole chart will be boosted if one of the series crosses its threshold, and all the series can be boosted.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowForce;
/**
Enable or disable GPU translations. GPU translations are faster than doing the translation in JavaScript. This option may cause rendering issues with certain datasets. Namely, if your dataset has large numbers with small increments (such as timestamps), it won't work correctly. This is due to floating point precission.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useGPUTranslations;
/**
Enable or disable boost on a chart.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Set the series threshold for when the boost should kick in globally. Setting to e.g. 20 will cause the whole chart to enter boost mode if there are 20 or more series active. When the chart is in boost mode, every series in it will be rendered to a common canvas. This offers a significant speed improvment in charts with a very high amount of series.

**Defaults to** `null`.
*/
@property(nonatomic, readwrite) NSNumber *seriesThreshold;

-(NSDictionary *)getParams;

@end
