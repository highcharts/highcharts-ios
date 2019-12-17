#import "HIColor.h"
#import "HISubtitle.h"
#import "HIYAxis.h"
#import "HISeries.h"
#import "HIAccessibility.h"
#import "HIPane.h"
#import "HIResponsive.h"
#import "HINoData.h"
#import "HILoading.h"
#import "HITitle.h"
#import "HITooltip.h"
#import "HIPlotOptions.h"
#import "HIExporting.h"
#import "HIBoost.h"
#import "HIAnnotations.h"
#import "HIChart.h"
#import "HICredits.h"
#import "HIZAxis.h"
#import "HIXAxis.h"
#import "HIDrilldown.h"
#import "HIData.h"
#import "HILegend.h"
#import "HIColorAxis.h"
#import "HICaption.h"
#import "HITime.h"
#import "HINavigation.h"


/**
 */
@interface HIOptions: HIChartsJSONSerializable

/**
The chart's subtitle. This can be used both to display a subtitle below the main title, and to display random text anywhere in the chart. The subtitle can be updated after chart initialization through the `Chart.setTitle` method.
*/
@property(nonatomic, readwrite) HISubtitle *subtitle;

/**
The Y axis or value axis. Normally this is the vertical axis, though if the chart is inverted this is the horizontal axis. In case of multiple axes, the yAxis node is an array of configuration objects. See `the Axis object` for programmatic access to the axis.
*/
@property(nonatomic, readwrite) NSArray<HIYAxis *> *yAxis;

/**
Series options for specific data and the data itself. In TypeScript you have to cast the series options to specific series types, to get all possible options for a series.
*/
@property(nonatomic, readwrite) NSArray<HISeries *> *series;

/**
Options for configuring accessibility for the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](http://www.highcharts.com/docs/chart-concepts/accessibility).
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;

/**
An array containing the default colors for the chart's series. When all colors are used, new colors are pulled from the start again. Default colors can also be set on a series or series.type basis, see `column.colors`, `pie.colors`. In styled mode, the colors option doesn't exist. Instead, colors are defined in CSS and applied either through series or point class names, or through the `chart.colorCount` option. ### Legacy In Highcharts 3.x, the default colors were: ```js colors: ['#2f7ed8', '#0d233a', '#8bbc21', '#910000', '#1aadce',     '#492970', '#f28f43', '#77a1e5', '#c42525', '#a6c96a'] ``` In Highcharts 2.x, the default colors were: ```js colors: ['#4572A7', '#AA4643', '#89A54E', '#80699B', '#3D96AE',     '#DB843D', '#92A8CD', '#A47D7C', '#B5CA92'] ```

**Defaults to** `["#7cb5ec", "#434348", "#90ed7d", "#f7a35c", "#8085e9",
         "#f15c80", "#e4d354", "#2b908f", "#f45b5b", "#91e8e1"]`.

**Try it**

* [Assign a global color theme](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/colors/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *colors;

/**
The pane serves as a container for axes and backgrounds for circular gauges and polar charts.
*/
@property(nonatomic, readwrite) HIPane *pane;

/**
Allows setting a set of rules to apply for different screen or chart sizes. Each rule specifies additional chart options.

**Try it**

* [Axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/axis/)
* [Legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/legend/)
* [Class name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/responsive/classname/)
*/
@property(nonatomic, readwrite) HIResponsive *responsive;

/**
Options for displaying a message like "No data to display". This feature requires the file no-data-to-display.js to be loaded in the page. The actual text to display is set in the lang.noData option.

**Try it**

* [Line chart with no-data module](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
* [Pie chart with no-data module](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-pie)
*/
@property(nonatomic, readwrite) HINoData *noData;

/**
The loading options control the appearance of the loading screen that covers the plot area on chart operations. This screen only appears after an explicit call to `chart.showLoading()`. It is a utility for developers to communicate to the end user that something is going on, for example while retrieving new data via an XHR connection. The "Loading..." text itself is not part of this configuration object, but part of the `lang` object.
*/
@property(nonatomic, readwrite) HILoading *loading;

/**
The chart's main title.
*/
@property(nonatomic, readwrite) HITitle *title;

/**
Options for the tooltip that appears when the user hovers over a series or point.
*/
@property(nonatomic, readwrite) HITooltip *tooltip;

/**
The plotOptions is a wrapper object for config objects for each series type. The config objects for each series can also be overridden for each series item as given in the series array. Configuration options for the series are given in three levels. Options for all series in a chart are given in the `plotOptions.series` object. Then options for all series of a specific type are given in the plotOptions of that type, for example `plotOptions.line`. Next, options for one single series are given in `the series array`.
*/
@property(nonatomic, readwrite) HIPlotOptions *plotOptions;

/**
Options for the exporting module. For an overview on the matter, see [the docs](https://www.highcharts.com/docs/export-module/export-module-overview).
*/
@property(nonatomic, readwrite) HIExporting *exporting;

@property(nonatomic, readwrite) HIBoost *boost;

/**
A basic type of an annotation. It allows to add custom labels or shapes. The items can be tied to points, axis coordinates or chart pixel coordinates.

**Try it**

* [Basic annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/basic/)
* [Advanced annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/annotations/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations)
* [Controllable items](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations-advanced/controllable)
*/
@property(nonatomic, readwrite) NSArray<HIAnnotations *> *annotations;

/**
Styled mode only. Configuration object for adding SVG definitions for reusable elements. See [gradients, shadows and patterns](https://www.highcharts.com/docs/chart-design-and-style/gradients-shadows-and-patterns) for more information and code examples.

**Try it**

* [Define a custom marker for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/)
* [Define markers in a styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations-markers/)
*/
@property(nonatomic, readwrite) id defs;

/**
General options for the chart.
*/
@property(nonatomic, readwrite) HIChart *chart;

/**
Highchart by default puts a credits label in the lower right corner of the chart. This can be changed using these options.
*/
@property(nonatomic, readwrite) HICredits *credits;

/**
The Z axis or depth axis for 3D plots. See the `Axis class` for programmatic access to the axis.

**Try it**

* [Z-Axis with Categories](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-zaxis-categories/)
* [Z-Axis with styling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-zaxis-grid/)
*/
@property(nonatomic, readwrite) NSArray<HIZAxis *> *zAxis;

/**
The X axis or category axis. Normally this is the horizontal axis, though if the chart is inverted this is the vertical axis. In case of multiple axes, the xAxis node is an array of configuration objects. See the `Axis class` for programmatic access to the axis.
*/
@property(nonatomic, readwrite) NSArray<HIXAxis *> *xAxis;

/**
Options for drill down, the concept of inspecting increasingly high resolution data through clicking on chart items like columns or pie slices. The drilldown feature requires the drilldown.js file to be loaded, found in the modules directory of the download package, or online at [https://code.highcharts.com/modules/drilldown.js](https://code.highcharts.com/modules/drilldown.js).
*/
@property(nonatomic, readwrite) HIDrilldown *drilldown;

/**
The Data module provides a simplified interface for adding data to a chart from sources like CVS, HTML tables or grid views. See also the [tutorial article on the Data module](https://www.highcharts.com/docs/working-with-data/data-module). It requires the `modules/data.js` file to be loaded. Please note that the default way of adding data in Highcharts, without the need of a module, is through the `series._type_.data` option.

**Try it**

* [HTML table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/)
* [CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/)
*/
@property(nonatomic, readwrite) HIData *data;

/**
The legend is a box containing a symbol and name for each series item or point item in the chart. Each series (or points in case of pie charts) is represented by a symbol and its name in the legend. It is possible to override the symbol creator function and create [custom legend symbols](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/studies/legend-custom-symbol/).
*/
@property(nonatomic, readwrite) HILegend *legend;

/**
A color axis for series. Visually, the color axis will appear as a gradient or as separate items inside the legend, depending on whether the axis is scalar or based on data classes. For supported color formats, see the [docs article about colors](https://www.highcharts.com/docs/chart-design-and-style/colors). A scalar color axis is represented by a gradient. The colors either range between the `minColor` and the `maxColor`, or for more fine grained control the colors can be defined in `stops`. Often times, the color axis needs to be adjusted to get the right color spread for the data. In addition to stops, consider using a logarithmic `axis type`, or setting `min` and `max` to avoid the colors being determined by outliers. When `dataClasses` are used, the ranges are subdivided into separate classes like categories based on their values. This can be used for ranges between two values, but also for a true category. However, when your data is categorized, it may be as convenient to add each category to a separate series. Color axis does not work with: `sankey`, `sunburst`, `dependencywheel`, `networkgraph`, `wordcloud`, `venn`, `gauge` and `solidgauge` series types. Since v7.2.0 `colorAxis` can also be an array of options objects. See `the Axis object` for programmatic access to the axis.

**Try it**

* [Column chart with color axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/custom-color-key)
* [Horizontal layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/coloraxis/horizontal-layout)
*/
@property(nonatomic, readwrite) NSArray<HIColorAxis *> *colorAxis;

/**
The chart's caption, which will render below the chart and will be part of exported charts. The caption can be updated after chart initialization through the `Chart.update` or `Chart.caption.update` methods.

**Try it**

* [A chart with a caption](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/caption/text/)
*/
@property(nonatomic, readwrite) HICaption *caption;

/**
Time options that can apply globally or to individual charts. These settings affect how `datetime` axes are laid out, how tooltips are formatted, how series `pointIntervalUnit` works and how the Highstock range selector handles time. The common use case is that all charts in the same Highcharts object share the same time settings, in which case the global settings are set using `setOptions`. ```js // Apply time settings globally Highcharts.setOptions({   time: {     timezone: 'Europe/London'   } }); // Apply time settings by instance var chart = Highcharts.chart('container', {   time: {     timezone: 'America/New_York'   },   series: [{     data: [1, 4, 3, 5]   }] }); // Use the Time object console.log(    'Current time in New York',    chart.time.dateFormat('%Y-%m-%d %H:%M:%S', Date.now()) ); ``` Since v6.0.5, the time options were moved from the `global` obect to the `time` object, and time options can be set on each individual chart.

**Try it**

* [Set the timezone globally](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/timezone/)
* [Set the timezone per chart instance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/time/individual/)
*/
@property(nonatomic, readwrite) HITime *time;

/**
A collection of options for buttons and menus appearing in the exporting module.
*/
@property(nonatomic, readwrite) HINavigation *navigation;

/**
* Additional options that are not listed above but are accepted by API
*/
@property(nonatomic, readwrite) NSDictionary *additionalOptions;

-(NSDictionary *)getParams;

@end
