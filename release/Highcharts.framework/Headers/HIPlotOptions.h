/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HITilemap.h"
#import "HIBellcurve.h"
#import "HIPyramid.h"
#import "HIColumnrange.h"
#import "HIPie.h"
#import "HIGauge.h"
#import "HIPareto.h"
#import "HISpline.h"
#import "HIAreaspline.h"
#import "HIPolygon.h"
#import "HIArea.h"
#import "HIXrange.h"
#import "HIHeatmap.h"
#import "HISeries.h"
#import "HIScatter3d.h"
#import "HIBubble.h"
#import "HIBoxplot.h"
#import "HISolidgauge.h"
#import "HIFunnel.h"
#import "HIErrorbar.h"
#import "HIHistogram.h"
#import "HIVector.h"
#import "HIWaterfall.h"
#import "HILine.h"
#import "HIWindbarb.h"
#import "HIBar.h"
#import "HIVariwide.h"
#import "HIBullet.h"
#import "HIColumn.h"
#import "HIStreamgraph.h"
#import "HITreemap.h"
#import "HIAreasplinerange.h"
#import "HIWordcloud.h"
#import "HISunburst.h"
#import "HIArearange.h"
#import "HIVariablepie.h"
#import "HIScatter.h"
#import "HISankey.h"


/**
The plotOptions is a wrapper object for config objects for each series type. The config objects for each series can also be overridden for each series item as given in the series array. Configuration options for the series are given in three levels. Options for all series in a chart are given in the `plotOptions.series` object. Then options for all series of a specific type are given in the plotOptions of that type, for example `plotOptions.line`. Next, options for one single series are given in `the series array`.
*/
@interface HIPlotOptions: HIChartsJSONSerializable

/**
A tilemap series is a type of heatmap where the tile shapes are configurable. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `tilemap` series are defined in  `plotOptions.tilemap`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     tilemap: {       // shared options for all tilemap series     }   },   series: [{     // specific options for this series instance     type: 'tilemap'   }] });  

**Try it**

* [Honeycomb tilemap, USA](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/honeycomb-usa/)
* [Honeycomb tilemap, Brazil](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-brazil/)
* [Honeycomb tilemap, China](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-china/)
* [Honeycomb tilemap, Europe](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-europe/)
* [Circlemap tilemap, Africa](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/circlemap-africa/)
* [Diamondmap tilemap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/diamondmap)
*/
@property(nonatomic, readwrite) HITilemap *tilemap;
/**
A bell curve is an areaspline series which represents the probability density function of the normal distribution. It calculates mean and standard deviation of the base series data and plots the curve according to the calculated parameters. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bellcurve` series are defined in  `plotOptions.bellcurve`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bellcurve: {       // shared options for all bellcurve series     }   },   series: [{     // specific options for this series instance     type: 'bellcurve'   }] });  

**Try it**

* [Bell curve](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bellcurve/)
*/
@property(nonatomic, readwrite) HIBellcurve *bellcurve;
/**
A pyramid series is a special type of funnel, without neck and reversed by default. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pyramid` series are defined in  `plotOptions.pyramid`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pyramid: {       // shared options for all pyramid series     }   },   series: [{     // specific options for this series instance     type: 'pyramid'   }] });  

**Try it**

* [Pyramid chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pyramid/)
*/
@property(nonatomic, readwrite) HIPyramid *pyramid;
/**
The column range is a cartesian series type with higher and lower Y values along an X axis. Requires `highcharts-more.js`. To display horizontal bars, set `chart.inverted` to `true`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `columnrange` series are defined in  `plotOptions.columnrange`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     columnrange: {       // shared options for all columnrange series     }   },   series: [{     // specific options for this series instance     type: 'columnrange'   }] });  

**Try it**

* [Inverted column range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/columnrange/)
*/
@property(nonatomic, readwrite) HIColumnrange *columnrange;
/**
A pie chart is a circular graphic which is divided into slices to illustrate numerical proportion. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pie` series are defined in  `plotOptions.pie`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pie: {       // shared options for all pie series     }   },   series: [{     // specific options for this series instance     type: 'pie'   }] });  

**Try it**

* [Pie chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-basic/)
*/
@property(nonatomic, readwrite) HIPie *pie;
/**
Gauges are circular plots displaying one or more values with a dial pointing to values along the perimeter. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `gauge` series are defined in  `plotOptions.gauge`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     gauge: {       // shared options for all gauge series     }   },   series: [{     // specific options for this series instance     type: 'gauge'   }] });  

**Try it**

* [Gauge chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/)
*/
@property(nonatomic, readwrite) HIGauge *gauge;
/**
A pareto diagram is a type of chart that contains both bars and a line graph, where individual values are represented in descending order by bars, and the cumulative total is represented by the line. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pareto` series are defined in  `plotOptions.pareto`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pareto: {       // shared options for all pareto series     }   },   series: [{     // specific options for this series instance     type: 'pareto'   }] });  

**Try it**

* [Pareto diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pareto/)
*/
@property(nonatomic, readwrite) HIPareto *pareto;
/**
A spline series is a special type of line series, where the segments between the data points are smoothed. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `spline` series are defined in  `plotOptions.spline`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     spline: {       // shared options for all spline series     }   },   series: [{     // specific options for this series instance     type: 'spline'   }] });  

**Try it**

* [Spline chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/spline-irregular-time/)
*/
@property(nonatomic, readwrite) HISpline *spline;
/**
The area spline series is an area series where the graph between the points is smoothed into a spline. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `areaspline` series are defined in  `plotOptions.areaspline`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     areaspline: {       // shared options for all areaspline series     }   },   series: [{     // specific options for this series instance     type: 'areaspline'   }] });  

**Try it**

* [Area spline chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/areaspline/)
*/
@property(nonatomic, readwrite) HIAreaspline *areaspline;
/**
A polygon series can be used to draw any freeform shape in the cartesian coordinate system. A fill is applied with the `color` option, and stroke is applied through `lineWidth` and `lineColor` options. Requires the `highcharts-more.js` file. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `polygon` series are defined in  `plotOptions.polygon`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     polygon: {       // shared options for all polygon series     }   },   series: [{     // specific options for this series instance     type: 'polygon'   }] });  

**Try it**

* [Polygon](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polygon/)
*/
@property(nonatomic, readwrite) HIPolygon *polygon;
/**
The area series type. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `area` series are defined in  `plotOptions.area`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     area: {       // shared options for all area series     }   },   series: [{     // specific options for this series instance     type: 'area'   }] });  

**Try it**

* [Area chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/area-basic/)
*/
@property(nonatomic, readwrite) HIArea *area;
/**
The X-range series displays ranges on the X axis, typically time intervals with a start and end date. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `xrange` series are defined in  `plotOptions.xrange`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     xrange: {       // shared options for all xrange series     }   },   series: [{     // specific options for this series instance     type: 'xrange'   }] });  

**Try it**

* [X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range/)
* [Styled mode X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/x-range/)
* [Inverted X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/inverted-xrange/)
*/
@property(nonatomic, readwrite) HIXrange *xrange;
/**
A heatmap is a graphical representation of data where the individual values contained in a matrix are represented as colors. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `heatmap` series are defined in  `plotOptions.heatmap`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     heatmap: {       // shared options for all heatmap series     }   },   series: [{     // specific options for this series instance     type: 'heatmap'   }] });  

**Try it**

* [Simple heatmap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap/)
* [Heavy heatmap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap-canvas/)
*/
@property(nonatomic, readwrite) HIHeatmap *heatmap;
/**
General options for all series types. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `line` series are defined in  `plotOptions.line`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     line: {       // shared options for all line series     }   },   series: [{     // specific options for this series instance     type: 'line'   }] });  
*/
@property(nonatomic, readwrite) HISeries *series;
/**
A 3D scatter plot uses x, y and z coordinates to display values for three variables for a set of data. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `scatter3d` series are defined in  `plotOptions.scatter3d`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     scatter3d: {       // shared options for all scatter3d series     }   },   series: [{     // specific options for this series instance     type: 'scatter3d'   }] });  

**Try it**

* [Simple 3D scatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter/)
* [Draggable 3d scatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-scatter-draggable)
*/
@property(nonatomic, readwrite) HIScatter3d *scatter3d;
/**
A bubble series is a three dimensional series type where each point renders an X, Y and Z value. Each points is drawn as a bubble where the position along the X and Y axes mark the X and Y values, and the size of the bubble relates to the Z value. Requires `highcharts-more.js`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bubble` series are defined in  `plotOptions.bubble`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bubble: {       // shared options for all bubble series     }   },   series: [{     // specific options for this series instance     type: 'bubble'   }] });  

**Try it**

* [Bubble chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bubble/)
*/
@property(nonatomic, readwrite) HIBubble *bubble;
/**
A box plot is a convenient way of depicting groups of data through their five-number summaries: the smallest observation (sample minimum), lower quartile (Q1), median (Q2), upper quartile (Q3), and largest observation (sample maximum). Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `boxplot` series are defined in  `plotOptions.boxplot`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     boxplot: {       // shared options for all boxplot series     }   },   series: [{     // specific options for this series instance     type: 'boxplot'   }] });  

**Try it**

* [Box plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/box-plot/)
*/
@property(nonatomic, readwrite) HIBoxplot *boxplot;
/**
A solid gauge is a circular gauge where the value is indicated by a filled arc, and the color of the arc may variate with the value. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `solidgauge` series are defined in  `plotOptions.solidgauge`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     solidgauge: {       // shared options for all solidgauge series     }   },   series: [{     // specific options for this series instance     type: 'solidgauge'   }] });  

**Try it**

* [Solid gauges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-solid/)
*/
@property(nonatomic, readwrite) HISolidgauge *solidgauge;
/**
Funnel charts are a type of chart often used to visualize stages in a sales project, where the top are the initial stages with the most clients. It requires that the modules/funnel.js file is loaded. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `funnel` series are defined in  `plotOptions.funnel`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     funnel: {       // shared options for all funnel series     }   },   series: [{     // specific options for this series instance     type: 'funnel'   }] });  

**Try it**

* [Funnel demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/)
*/
@property(nonatomic, readwrite) HIFunnel *funnel;
/**
Error bars are a graphical representation of the variability of data and are used on graphs to indicate the error, or uncertainty in a reported measurement. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `errorbar` series are defined in  `plotOptions.errorbar`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     errorbar: {       // shared options for all errorbar series     }   },   series: [{     // specific options for this series instance     type: 'errorbar'   }] });  

**Try it**

* [Error bars on a column series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/error-bar/)
* [Error bars on a scatter series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-errorbar/on-scatter/)
*/
@property(nonatomic, readwrite) HIErrorbar *errorbar;
/**
A histogram is a column series which represents the distribution of the data set in the base series. Histogram splits data into bins and shows their frequencies. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `histogram` series are defined in  `plotOptions.histogram`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     histogram: {       // shared options for all histogram series     }   },   series: [{     // specific options for this series instance     type: 'histogram'   }] });  

**Try it**

* [Histogram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/histogram/)
*/
@property(nonatomic, readwrite) HIHistogram *histogram;
/**
A vector plot is a type of cartesian chart where each point has an X and Y position, a length and a direction. Vectors are drawn as arrows. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `vector` series are defined in  `plotOptions.vector`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     vector: {       // shared options for all vector series     }   },   series: [{     // specific options for this series instance     type: 'vector'   }] });  

**Try it**

* [Vector pot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/vector-plot/)
*/
@property(nonatomic, readwrite) HIVector *vector;
/**
A waterfall chart displays sequentially introduced positive or negative values in cumulative columns. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `waterfall` series are defined in  `plotOptions.waterfall`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     waterfall: {       // shared options for all waterfall series     }   },   series: [{     // specific options for this series instance     type: 'waterfall'   }] });  

**Try it**

* [Waterfall chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
* [Horizontal (inverted) waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/waterfall-inverted/)
* [Stacked waterfall chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/waterfall-stacked/)
*/
@property(nonatomic, readwrite) HIWaterfall *waterfall;
/**
A line series displays information as a series of data points connected by straight line segments. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `line` series are defined in  `plotOptions.line`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     line: {       // shared options for all line series     }   },   series: [{     // specific options for this series instance     type: 'line'   }] });  

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/line-basic/)
*/
@property(nonatomic, readwrite) HILine *line;
/**
Wind barbs are a convenient way to represent wind speed and direction in one graphical form. Wind direction is given by the stem direction, and wind speed by the number and shape of barbs. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `windbarb` series are defined in  `plotOptions.windbarb`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     windbarb: {       // shared options for all windbarb series     }   },   series: [{     // specific options for this series instance     type: 'windbarb'   }] });  

**Try it**

* [Wind barb series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/windbarb-series/)
*/
@property(nonatomic, readwrite) HIWindbarb *windbarb;
/**
A bar series is a special type of column series where the columns are horizontal. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bar` series are defined in  `plotOptions.bar`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bar: {       // shared options for all bar series     }   },   series: [{     // specific options for this series instance     type: 'bar'   }] });  

**Try it**

* [Bar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bar-basic/)
*/
@property(nonatomic, readwrite) HIBar *bar;
/**
A variwide chart (related to marimekko chart) is a column chart with a variable width expressing a third dimension. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `variwide` series are defined in  `plotOptions.variwide`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     variwide: {       // shared options for all variwide series     }   },   series: [{     // specific options for this series instance     type: 'variwide'   }] });  

**Try it**

* [Variwide chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variwide/)
* [Inverted variwide chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-variwide/inverted/)
*/
@property(nonatomic, readwrite) HIVariwide *variwide;
/**
A bullet graph is a variation of a bar graph. The bullet graph features a single measure, compares it to a target, and displays it in the context of qualitative ranges of performance that could be set using `plotBands` on `yAxis`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bullet` series are defined in  `plotOptions.bullet`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bullet: {       // shared options for all bullet series     }   },   series: [{     // specific options for this series instance     type: 'bullet'   }] });  

**Try it**

* [Bullet graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bullet-graph/)
*/
@property(nonatomic, readwrite) HIBullet *bullet;
/**
Column series display one column per value along an X axis. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `column` series are defined in  `plotOptions.column`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     column: {       // shared options for all column series     }   },   series: [{     // specific options for this series instance     type: 'column'   }] });  

**Try it**

* [Column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-basic/)
*/
@property(nonatomic, readwrite) HIColumn *column;
/**
A streamgraph is a type of stacked area graph which is displaced around a central axis, resulting in a flowing, organic shape. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `streamgraph` series are defined in  `plotOptions.streamgraph`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     streamgraph: {       // shared options for all streamgraph series     }   },   series: [{     // specific options for this series instance     type: 'streamgraph'   }] });  

**Try it**

* [Streamgraph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph/)
*/
@property(nonatomic, readwrite) HIStreamgraph *streamgraph;
/**
A treemap displays hierarchical data using nested rectangles. The data can be laid out in varying ways depending on options. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `treemap` series are defined in  `plotOptions.treemap`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     treemap: {       // shared options for all treemap series     }   },   series: [{     // specific options for this series instance     type: 'treemap'   }] });  

**Try it**

* [Treemap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-large-dataset/)
*/
@property(nonatomic, readwrite) HITreemap *treemap;
/**
The area spline range is a cartesian series type with higher and lower Y values along an X axis. The area inside the range is colored, and the graph outlining the area is a smoothed spline. Requires `highcharts-more.js`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `areasplinerange` series are defined in  `plotOptions.areasplinerange`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     areasplinerange: {       // shared options for all areasplinerange series     }   },   series: [{     // specific options for this series instance     type: 'areasplinerange'   }] });  
*/
@property(nonatomic, readwrite) HIAreasplinerange *areasplinerange;
/**
A word cloud is a visualization of a set of words, where the size and placement of a word is determined by how it is weighted. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `wordcloud` series are defined in  `plotOptions.wordcloud`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     wordcloud: {       // shared options for all wordcloud series     }   },   series: [{     // specific options for this series instance     type: 'wordcloud'   }] });  

**Try it**

* [Word Cloud chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/wordcloud)
*/
@property(nonatomic, readwrite) HIWordcloud *wordcloud;
/**
A Sunburst displays hierarchical data, where a level in the hierarchy is represented by a circle. The center represents the root node of the tree. The visualization bears a resemblance to both treemap and pie charts. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `sunburst` series are defined in  `plotOptions.sunburst`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     sunburst: {       // shared options for all sunburst series     }   },   series: [{     // specific options for this series instance     type: 'sunburst'   }] });  

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) HISunburst *sunburst;
/**
The area range series is a carteseian series with higher and lower values for each point along an X axis, where the area between the values is shaded. Requires `highcharts-more.js`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `arearange` series are defined in  `plotOptions.arearange`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     arearange: {       // shared options for all arearange series     }   },   series: [{     // specific options for this series instance     type: 'arearange'   }] });  

**Try it**

* [Area range chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange/)
*/
@property(nonatomic, readwrite) HIArearange *arearange;
/**
A variable pie series is a two dimensional series type, where each point renders an Y and Z value. Each point is drawn as a pie slice where the size (arc) of the slice relates to the Y value and the radius of pie slice relates to the Z value. Requires `highcharts-more.js`. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `variablepie` series are defined in  `plotOptions.variablepie`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     variablepie: {       // shared options for all variablepie series     }   },   series: [{     // specific options for this series instance     type: 'variablepie'   }] });  

**Try it**

* [Variable-radius pie chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variable-radius-pie/)
*/
@property(nonatomic, readwrite) HIVariablepie *variablepie;
/**
A scatter plot uses cartesian coordinates to display values for two variables for a set of data. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `scatter` series are defined in  `plotOptions.scatter`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     scatter: {       // shared options for all scatter series     }   },   series: [{     // specific options for this series instance     type: 'scatter'   }] });  

**Try it**

* [Scatter plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/scatter/)
*/
@property(nonatomic, readwrite) HIScatter *scatter;
/**
A sankey diagram is a type of flow diagram, in which the width of the link between two nodes is shown proportionally to the flow quantity. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `sankey` series are defined in  `plotOptions.sankey`. 3. Options for one single series are given in  `the series instance array`.  Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     sankey: {       // shared options for all sankey series     }   },   series: [{     // specific options for this series instance     type: 'sankey'   }] });  

**Try it**

* [Sankey diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sankey-diagram/)
* [Inverted sankey diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-inverted/)
* [Sankey diagram with outgoing links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing)
*/
@property(nonatomic, readwrite) HISankey *sankey;

-(NSDictionary *)getParams;

@end
