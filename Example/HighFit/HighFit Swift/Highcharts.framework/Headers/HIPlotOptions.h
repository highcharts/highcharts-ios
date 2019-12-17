/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIGauge.h"
#import "HIVariablepie.h"
#import "HIDumbbell.h"
#import "HIStreamgraph.h"
#import "HINetworkgraph.h"
#import "HIBar.h"
#import "HIVariwide.h"
#import "HIAreasplinerange.h"
#import "HIItem.h"
#import "HIVector.h"
#import "HIColumnpyramid.h"
#import "HIArearange.h"
#import "HIBellcurve.h"
#import "HISeries.h"
#import "HIPyramid3d.h"
#import "HIPareto.h"
#import "HIDependencywheel.h"
#import "HIHeatmap.h"
#import "HISolidgauge.h"
#import "HITimeline.h"
#import "HIFunnel3d.h"
#import "HILollipop.h"
#import "HIColumn.h"
#import "HITreemap.h"
#import "HIWaterfall.h"
#import "HIColumnrange.h"
#import "HIPackedBubble.h"
#import "HIVenn.h"
#import "HISpline.h"
#import "HIArea.h"
#import "HIXrange.h"
#import "HIBubble.h"
#import "HIFunnel.h"
#import "HIHistogram.h"
#import "HILine.h"
#import "HISunburst.h"
#import "HIWordcloud.h"
#import "HIScatter.h"
#import "HISankey.h"
#import "HICylinder.h"
#import "HIPyramid.h"
#import "HITilemap.h"
#import "HIPie.h"
#import "HIAreaspline.h"
#import "HIPolygon.h"
#import "HIPackedBubble.h"
#import "HIScatter3d.h"
#import "HIBoxplot.h"
#import "HIErrorbar.h"
#import "HIWindbarb.h"
#import "HIBullet.h"
#import "HIOrganization.h"


/**
The plotOptions is a wrapper object for config objects for each series type. The config objects for each series can also be overridden for each series item as given in the series array. Configuration options for the series are given in three levels. Options for all series in a chart are given in the `plotOptions.series` object. Then options for all series of a specific type are given in the plotOptions of that type, for example `plotOptions.line`. Next, options for one single series are given in `the series array`.
*/
@interface HIPlotOptions: HIChartsJSONSerializable

/**
Gauges are circular plots displaying one or more values with a dial pointing to values along the perimeter. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `gauge` series are defined in  `plotOptions.gauge`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     gauge: {       // shared options for all gauge series     }   },   series: [{     // specific options for this series instance     type: 'gauge'   }] }); ```       

**Try it**

* [Gauge chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/)
*/
@property(nonatomic, readwrite) HIGauge *gauge;
/**
A variable pie series is a two dimensional series type, where each point renders an Y and Z value. Each point is drawn as a pie slice where the size (arc) of the slice relates to the Y value and the radius of pie slice relates to the Z value. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `variablepie` series are defined in  `plotOptions.variablepie`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     variablepie: {       // shared options for all variablepie series     }   },   series: [{     // specific options for this series instance     type: 'variablepie'   }] }); ```       

**Try it**

* [Variable-radius pie chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variable-radius-pie/)
*/
@property(nonatomic, readwrite) HIVariablepie *variablepie;
/**
The dumbbell series is a cartesian series with higher and lower values for each point along an X axis, connected with a line between the values. Requires `highcharts-more.js` and `modules/dumbbell.js`. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `dumbbell` series are defined in  `plotOptions.dumbbell`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     dumbbell: {       // shared options for all dumbbell series     }   },   series: [{     // specific options for this series instance     type: 'dumbbell'   }] }); ```       

**Try it**

* [Dumbbell chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/dumbbell/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-dumbbell/styled-mode-dumbbell/)
*/
@property(nonatomic, readwrite) HIDumbbell *dumbbell;
/**
A streamgraph is a type of stacked area graph which is displaced around a central axis, resulting in a flowing, organic shape. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `streamgraph` series are defined in  `plotOptions.streamgraph`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     streamgraph: {       // shared options for all streamgraph series     }   },   series: [{     // specific options for this series instance     type: 'streamgraph'   }] }); ```       

**Try it**

* [Streamgraph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph/)
*/
@property(nonatomic, readwrite) HIStreamgraph *streamgraph;
/**
A networkgraph is a type of relationship chart, where connnections (links) attracts nodes (points) and other nodes repulse each other. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `networkgraph` series are defined in  `plotOptions.networkgraph`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     networkgraph: {       // shared options for all networkgraph series     }   },   series: [{     // specific options for this series instance     type: 'networkgraph'   }] }); ```       

**Try it**

* [Networkgraph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/network-graph/)
*/
@property(nonatomic, readwrite) HINetworkgraph *networkgraph;
/**
A bar series is a special type of column series where the columns are horizontal. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bar` series are defined in  `plotOptions.bar`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bar: {       // shared options for all bar series     }   },   series: [{     // specific options for this series instance     type: 'bar'   }] }); ```       

**Try it**

* [Bar chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bar-basic/)
*/
@property(nonatomic, readwrite) HIBar *bar;
/**
A variwide chart (related to marimekko chart) is a column chart with a variable width expressing a third dimension. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `variwide` series are defined in  `plotOptions.variwide`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     variwide: {       // shared options for all variwide series     }   },   series: [{     // specific options for this series instance     type: 'variwide'   }] }); ```       

**Try it**

* [Variwide chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variwide/)
* [Inverted variwide chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-variwide/inverted/)
* [Variwide columns on a datetime axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-variwide/datetime/)
*/
@property(nonatomic, readwrite) HIVariwide *variwide;
/**
The area spline range is a cartesian series type with higher and lower Y values along an X axis. The area inside the range is colored, and the graph outlining the area is a smoothed spline. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `areasplinerange` series are defined in  `plotOptions.areasplinerange`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     areasplinerange: {       // shared options for all areasplinerange series     }   },   series: [{     // specific options for this series instance     type: 'areasplinerange'   }] }); ```       
*/
@property(nonatomic, readwrite) HIAreasplinerange *areasplinerange;
/**
An item chart is an infographic chart where a number of items are laid out in either a rectangular or circular pattern. It can be used to visualize counts within a group, or for the circular pattern, typically a parliament. The circular layout has much in common with a pie chart. Many of the item series options, like `center`, `size` and data label positioning, are inherited from the pie series and don't apply for rectangular layouts. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `item` series are defined in  `plotOptions.item`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     item: {       // shared options for all item series     }   },   series: [{     // specific options for this series instance     type: 'item'   }] }); ```       

**Try it**

* [Parliament chart (circular item chart)](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/parliament-chart)
* [Rectangular item chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-item/rectangular)
* [Infographic with symbols](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-item/symbols)
*/
@property(nonatomic, readwrite) HIItem *item;
/**
A vector plot is a type of cartesian chart where each point has an X and Y position, a length and a direction. Vectors are drawn as arrows. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `vector` series are defined in  `plotOptions.vector`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     vector: {       // shared options for all vector series     }   },   series: [{     // specific options for this series instance     type: 'vector'   }] }); ```       

**Try it**

* [Vector pot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/vector-plot/)
*/
@property(nonatomic, readwrite) HIVector *vector;
/**
Column pyramid series display one pyramid per value along an X axis. To display horizontal pyramids, set `chart.inverted` to `true`. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `columnpyramid` series are defined in  `plotOptions.columnpyramid`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     columnpyramid: {       // shared options for all columnpyramid series     }   },   series: [{     // specific options for this series instance     type: 'columnpyramid'   }] }); ```       

**Try it**

* [Column pyramid](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-pyramid/)
* [Column pyramid stacked](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/columnpyramid-stacked/)
* [Column pyramid inverted](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/columnpyramid-inverted/)
*/
@property(nonatomic, readwrite) HIColumnpyramid *columnpyramid;
/**
The area range series is a carteseian series with higher and lower values for each point along an X axis, where the area between the values is shaded. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `arearange` series are defined in  `plotOptions.arearange`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     arearange: {       // shared options for all arearange series     }   },   series: [{     // specific options for this series instance     type: 'arearange'   }] }); ```       

**Try it**

* [Area range chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange/)
*/
@property(nonatomic, readwrite) HIArearange *arearange;
/**
A bell curve is an areaspline series which represents the probability density function of the normal distribution. It calculates mean and standard deviation of the base series data and plots the curve according to the calculated parameters. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bellcurve` series are defined in  `plotOptions.bellcurve`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bellcurve: {       // shared options for all bellcurve series     }   },   series: [{     // specific options for this series instance     type: 'bellcurve'   }] }); ```       

**Try it**

* [Bell curve](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bellcurve/)
*/
@property(nonatomic, readwrite) HIBellcurve *bellcurve;
/**
General options for all series types. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `line` series are defined in  `plotOptions.line`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     line: {       // shared options for all line series     }   },   series: [{     // specific options for this series instance     type: 'line'   }] }); ```       
*/
@property(nonatomic, readwrite) HISeries *series;
/**
A pyramid3d is a 3d version of pyramid series type. Pyramid charts are a type of chart often used to visualize stages in a sales project, where the top are the initial stages with the most clients. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pyramid3d` series are defined in  `plotOptions.pyramid3d`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pyramid3d: {       // shared options for all pyramid3d series     }   },   series: [{     // specific options for this series instance     type: 'pyramid3d'   }] }); ```       

**Try it**

* [Pyramid3d](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pyramid3d/)
*/
@property(nonatomic, readwrite) HIPyramid3d *pyramid3d;
/**
A pareto diagram is a type of chart that contains both bars and a line graph, where individual values are represented in descending order by bars, and the cumulative total is represented by the line. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pareto` series are defined in  `plotOptions.pareto`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pareto: {       // shared options for all pareto series     }   },   series: [{     // specific options for this series instance     type: 'pareto'   }] }); ```       

**Try it**

* [Pareto diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pareto/)
*/
@property(nonatomic, readwrite) HIPareto *pareto;
/**
A dependency wheel chart is a type of flow diagram, where all nodes are laid out in a circle, and the flow between the are drawn as link bands. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `dependencywheel` series are defined in  `plotOptions.dependencywheel`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     dependencywheel: {       // shared options for all dependencywheel series     }   },   series: [{     // specific options for this series instance     type: 'dependencywheel'   }] }); ```       

**Try it**

* [Dependency wheel](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/dependency-wheel/)
*/
@property(nonatomic, readwrite) HIDependencywheel *dependencywheel;
/**
A heatmap is a graphical representation of data where the individual values contained in a matrix are represented as colors. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `heatmap` series are defined in  `plotOptions.heatmap`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     heatmap: {       // shared options for all heatmap series     }   },   series: [{     // specific options for this series instance     type: 'heatmap'   }] }); ```       

**Try it**

* [Simple heatmap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap/)
* [Heavy heatmap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap-canvas/)
*/
@property(nonatomic, readwrite) HIHeatmap *heatmap;
/**
A solid gauge is a circular gauge where the value is indicated by a filled arc, and the color of the arc may variate with the value. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `solidgauge` series are defined in  `plotOptions.solidgauge`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     solidgauge: {       // shared options for all solidgauge series     }   },   series: [{     // specific options for this series instance     type: 'solidgauge'   }] }); ```       

**Try it**

* [Solid gauges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-solid/)
*/
@property(nonatomic, readwrite) HISolidgauge *solidgauge;
/**
The timeline series presents given events along a drawn line. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `timeline` series are defined in  `plotOptions.timeline`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     timeline: {       // shared options for all timeline series     }   },   series: [{     // specific options for this series instance     type: 'timeline'   }] }); ```       

**Try it**

* [Timeline series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/alternate-labels)
* [Inverted timeline](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/inverted)
* [With true datetime axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/datetime-axis)
*/
@property(nonatomic, readwrite) HITimeline *timeline;
/**
A funnel3d is a 3d version of funnel series type. Funnel charts are a type of chart often used to visualize stages in a sales project, where the top are the initial stages with the most clients. It requires that the `highcharts-3d.js`, `cylinder.js` and `funnel3d.js` module are loaded. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `funnel3d` series are defined in  `plotOptions.funnel3d`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     funnel3d: {       // shared options for all funnel3d series     }   },   series: [{     // specific options for this series instance     type: 'funnel3d'   }] }); ```       

**Try it**

* [Funnel3d](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel3d/)
*/
@property(nonatomic, readwrite) HIFunnel3d *funnel3d;
/**
The lollipop series is a carteseian series with a line anchored from the x axis and a dot at the end to mark the value. Requires `highcharts-more.js`, `modules/dumbbell.js` and `modules/lollipop.js`. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `lollipop` series are defined in  `plotOptions.lollipop`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     lollipop: {       // shared options for all lollipop series     }   },   series: [{     // specific options for this series instance     type: 'lollipop'   }] }); ```       

**Try it**

* [Lollipop chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/lollipop/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-dumbbell/styled-mode-dumbbell/)
*/
@property(nonatomic, readwrite) HILollipop *lollipop;
/**
Column series display one column per value along an X axis. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `column` series are defined in  `plotOptions.column`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     column: {       // shared options for all column series     }   },   series: [{     // specific options for this series instance     type: 'column'   }] }); ```       

**Try it**

* [Column chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-basic/)
*/
@property(nonatomic, readwrite) HIColumn *column;
/**
A treemap displays hierarchical data using nested rectangles. The data can be laid out in varying ways depending on options. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `treemap` series are defined in  `plotOptions.treemap`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     treemap: {       // shared options for all treemap series     }   },   series: [{     // specific options for this series instance     type: 'treemap'   }] }); ```       

**Try it**

* [Treemap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-large-dataset/)
*/
@property(nonatomic, readwrite) HITreemap *treemap;
/**
A waterfall chart displays sequentially introduced positive or negative values in cumulative columns. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `waterfall` series are defined in  `plotOptions.waterfall`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     waterfall: {       // shared options for all waterfall series     }   },   series: [{     // specific options for this series instance     type: 'waterfall'   }] }); ```       

**Try it**

* [Waterfall chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
* [Horizontal (inverted) waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/waterfall-inverted/)
* [Stacked waterfall chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/waterfall-stacked/)
*/
@property(nonatomic, readwrite) HIWaterfall *waterfall;
/**
The column range is a cartesian series type with higher and lower Y values along an X axis. To display horizontal bars, set `chart.inverted` to `true`. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `columnrange` series are defined in  `plotOptions.columnrange`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     columnrange: {       // shared options for all columnrange series     }   },   series: [{     // specific options for this series instance     type: 'columnrange'   }] }); ```       

**Try it**

* [Inverted column range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/columnrange/)
*/
@property(nonatomic, readwrite) HIColumnrange *columnrange;
@property(nonatomic, readwrite) HIPackedbubble *packedBubble;
/**
A Venn diagram displays all possible logical relations between a collection of different sets. The sets are represented by circles, and the relation between the sets are displayed by the overlap or lack of overlap between them. The venn diagram is a special case of Euler diagrams, which can also be displayed by this series type. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `venn` series are defined in  `plotOptions.venn`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     venn: {       // shared options for all venn series     }   },   series: [{     // specific options for this series instance     type: 'venn'   }] }); ```       

**Try it**

* [Venn diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/venn-diagram/)
* [Euler diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/euler-diagram/)
*/
@property(nonatomic, readwrite) HIVenn *venn;
/**
A spline series is a special type of line series, where the segments between the data points are smoothed. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `spline` series are defined in  `plotOptions.spline`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     spline: {       // shared options for all spline series     }   },   series: [{     // specific options for this series instance     type: 'spline'   }] }); ```       

**Try it**

* [Spline chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/spline-irregular-time/)
*/
@property(nonatomic, readwrite) HISpline *spline;
/**
The area series type. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `area` series are defined in  `plotOptions.area`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     area: {       // shared options for all area series     }   },   series: [{     // specific options for this series instance     type: 'area'   }] }); ```       

**Try it**

* [Area chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/area-basic/)
*/
@property(nonatomic, readwrite) HIArea *area;
/**
The X-range series displays ranges on the X axis, typically time intervals with a start and end date. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `xrange` series are defined in  `plotOptions.xrange`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     xrange: {       // shared options for all xrange series     }   },   series: [{     // specific options for this series instance     type: 'xrange'   }] }); ```       

**Try it**

* [X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range/)
* [Styled mode X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/x-range/)
* [Inverted X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/inverted-xrange/)
*/
@property(nonatomic, readwrite) HIXrange *xrange;
/**
A bubble series is a three dimensional series type where each point renders an X, Y and Z value. Each points is drawn as a bubble where the position along the X and Y axes mark the X and Y values, and the size of the bubble relates to the Z value. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bubble` series are defined in  `plotOptions.bubble`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bubble: {       // shared options for all bubble series     }   },   series: [{     // specific options for this series instance     type: 'bubble'   }] }); ```       

**Try it**

* [Bubble chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bubble/)
*/
@property(nonatomic, readwrite) HIBubble *bubble;
/**
Funnel charts are a type of chart often used to visualize stages in a sales project, where the top are the initial stages with the most clients. It requires that the modules/funnel.js file is loaded. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `funnel` series are defined in  `plotOptions.funnel`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     funnel: {       // shared options for all funnel series     }   },   series: [{     // specific options for this series instance     type: 'funnel'   }] }); ```       

**Try it**

* [Funnel demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/)
*/
@property(nonatomic, readwrite) HIFunnel *funnel;
/**
A histogram is a column series which represents the distribution of the data set in the base series. Histogram splits data into bins and shows their frequencies. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `histogram` series are defined in  `plotOptions.histogram`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     histogram: {       // shared options for all histogram series     }   },   series: [{     // specific options for this series instance     type: 'histogram'   }] }); ```       

**Try it**

* [Histogram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/histogram/)
*/
@property(nonatomic, readwrite) HIHistogram *histogram;
/**
A line series displays information as a series of data points connected by straight line segments. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `line` series are defined in  `plotOptions.line`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     line: {       // shared options for all line series     }   },   series: [{     // specific options for this series instance     type: 'line'   }] }); ```       

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/line-basic/)
*/
@property(nonatomic, readwrite) HILine *line;
/**
A Sunburst displays hierarchical data, where a level in the hierarchy is represented by a circle. The center represents the root node of the tree. The visualization bears a resemblance to both treemap and pie charts. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `sunburst` series are defined in  `plotOptions.sunburst`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     sunburst: {       // shared options for all sunburst series     }   },   series: [{     // specific options for this series instance     type: 'sunburst'   }] }); ```       

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@property(nonatomic, readwrite) HISunburst *sunburst;
/**
A word cloud is a visualization of a set of words, where the size and placement of a word is determined by how it is weighted. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `wordcloud` series are defined in  `plotOptions.wordcloud`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     wordcloud: {       // shared options for all wordcloud series     }   },   series: [{     // specific options for this series instance     type: 'wordcloud'   }] }); ```       

**Try it**

* [Word Cloud chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/wordcloud)
*/
@property(nonatomic, readwrite) HIWordcloud *wordcloud;
/**
A scatter plot uses cartesian coordinates to display values for two variables for a set of data. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `scatter` series are defined in  `plotOptions.scatter`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     scatter: {       // shared options for all scatter series     }   },   series: [{     // specific options for this series instance     type: 'scatter'   }] }); ```       

**Try it**

* [Scatter plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/scatter/)
*/
@property(nonatomic, readwrite) HIScatter *scatter;
/**
A sankey diagram is a type of flow diagram, in which the width of the link between two nodes is shown proportionally to the flow quantity. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `sankey` series are defined in  `plotOptions.sankey`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     sankey: {       // shared options for all sankey series     }   },   series: [{     // specific options for this series instance     type: 'sankey'   }] }); ```       

**Try it**

* [Sankey diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sankey-diagram/)
* [Inverted sankey diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-inverted/)
* [Sankey diagram with outgoing links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing)
*/
@property(nonatomic, readwrite) HISankey *sankey;
/**
A cylinder graph is a variation of a 3d column graph. The cylinder graph features cylindrical points. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `cylinder` series are defined in  `plotOptions.cylinder`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     cylinder: {       // shared options for all cylinder series     }   },   series: [{     // specific options for this series instance     type: 'cylinder'   }] }); ```       

**Try it**

* [Cylinder graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/cylinder/)
*/
@property(nonatomic, readwrite) HICylinder *cylinder;
/**
A pyramid series is a special type of funnel, without neck and reversed by default. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pyramid` series are defined in  `plotOptions.pyramid`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pyramid: {       // shared options for all pyramid series     }   },   series: [{     // specific options for this series instance     type: 'pyramid'   }] }); ```       

**Try it**

* [Pyramid chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pyramid/)
*/
@property(nonatomic, readwrite) HIPyramid *pyramid;
/**
A tilemap series is a type of heatmap where the tile shapes are configurable. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `tilemap` series are defined in  `plotOptions.tilemap`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     tilemap: {       // shared options for all tilemap series     }   },   series: [{     // specific options for this series instance     type: 'tilemap'   }] }); ```       

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
A pie chart is a circular graphic which is divided into slices to illustrate numerical proportion. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `pie` series are defined in  `plotOptions.pie`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     pie: {       // shared options for all pie series     }   },   series: [{     // specific options for this series instance     type: 'pie'   }] }); ```       

**Try it**

* [Pie chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-basic/)
*/
@property(nonatomic, readwrite) HIPie *pie;
/**
The area spline series is an area series where the graph between the points is smoothed into a spline. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `areaspline` series are defined in  `plotOptions.areaspline`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     areaspline: {       // shared options for all areaspline series     }   },   series: [{     // specific options for this series instance     type: 'areaspline'   }] }); ```       

**Try it**

* [Area spline chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/areaspline/)
*/
@property(nonatomic, readwrite) HIAreaspline *areaspline;
/**
A polygon series can be used to draw any freeform shape in the cartesian coordinate system. A fill is applied with the `color` option, and stroke is applied through `lineWidth` and `lineColor` options. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `polygon` series are defined in  `plotOptions.polygon`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     polygon: {       // shared options for all polygon series     }   },   series: [{     // specific options for this series instance     type: 'polygon'   }] }); ```       

**Try it**

* [Polygon](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polygon/)
*/
@property(nonatomic, readwrite) HIPolygon *polygon;
/**
A packed bubble series is a two dimensional series type, where each point renders a value in X, Y position. Each point is drawn as a bubble where the bubbles don't overlap with each other and the radius of the bubble relates to the value. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `packedbubble` series are defined in  `plotOptions.packedbubble`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     packedbubble: {       // shared options for all packedbubble series     }   },   series: [{     // specific options for this series instance     type: 'packedbubble'   }] }); ```       

**Try it**

* [Packed bubble chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/packed-bubble/)
* [Split packed bubble chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/packed-bubble-split/)
*/
@property(nonatomic, readwrite) HIPackedbubble *packedbubble;
/**
A 3D scatter plot uses x, y and z coordinates to display values for three variables for a set of data. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `scatter3d` series are defined in  `plotOptions.scatter3d`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     scatter3d: {       // shared options for all scatter3d series     }   },   series: [{     // specific options for this series instance     type: 'scatter3d'   }] }); ```       

**Try it**

* [Simple 3D scatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter/)
* [Draggable 3d scatter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-scatter-draggable)
*/
@property(nonatomic, readwrite) HIScatter3d *scatter3d;
/**
A box plot is a convenient way of depicting groups of data through their five-number summaries: the smallest observation (sample minimum), lower quartile (Q1), median (Q2), upper quartile (Q3), and largest observation (sample maximum). In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `boxplot` series are defined in  `plotOptions.boxplot`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     boxplot: {       // shared options for all boxplot series     }   },   series: [{     // specific options for this series instance     type: 'boxplot'   }] }); ```       

**Try it**

* [Box plot](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/box-plot/)
*/
@property(nonatomic, readwrite) HIBoxplot *boxplot;
/**
Error bars are a graphical representation of the variability of data and are used on graphs to indicate the error, or uncertainty in a reported measurement. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `errorbar` series are defined in  `plotOptions.errorbar`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     errorbar: {       // shared options for all errorbar series     }   },   series: [{     // specific options for this series instance     type: 'errorbar'   }] }); ```       

**Try it**

* [Error bars on a column series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/error-bar/)
* [Error bars on a scatter series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-errorbar/on-scatter/)
*/
@property(nonatomic, readwrite) HIErrorbar *errorbar;
/**
Wind barbs are a convenient way to represent wind speed and direction in one graphical form. Wind direction is given by the stem direction, and wind speed by the number and shape of barbs. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `windbarb` series are defined in  `plotOptions.windbarb`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     windbarb: {       // shared options for all windbarb series     }   },   series: [{     // specific options for this series instance     type: 'windbarb'   }] }); ```       

**Try it**

* [Wind barb series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/windbarb-series/)
*/
@property(nonatomic, readwrite) HIWindbarb *windbarb;
/**
A bullet graph is a variation of a bar graph. The bullet graph features a single measure, compares it to a target, and displays it in the context of qualitative ranges of performance that could be set using `plotBands` on `yAxis`. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `bullet` series are defined in  `plotOptions.bullet`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     bullet: {       // shared options for all bullet series     }   },   series: [{     // specific options for this series instance     type: 'bullet'   }] }); ```       

**Try it**

* [Bullet graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bullet-graph/)
*/
@property(nonatomic, readwrite) HIBullet *bullet;
/**
An organization chart is a diagram that shows the structure of an organization and the relationships and relative ranks of its parts and positions. In TypeScript the `type` option must always be set. Configuration options for the series are given in three levels: 1. Options for all series in a chart are defined in the  `plotOptions.series` object. 2. Options for all `organization` series are defined in  `plotOptions.organization`. 3. Options for one single series are given in  `the series instance array`. ``` Highcharts.chart('container', {   plotOptions: {     series: {       // general options for all series     },     organization: {       // shared options for all organization series     }   },   series: [{     // specific options for this series instance     type: 'organization'   }] }); ```       

**Try it**

* [Organization chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/organization-chart/)
* [Horizontal organization chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/horizontal/)
* [Borderless design](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/borderless)
* [Centered layout](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/center-layout)
*/
@property(nonatomic, readwrite) HIOrganization *organization;

-(NSDictionary *)getParams;

@end
