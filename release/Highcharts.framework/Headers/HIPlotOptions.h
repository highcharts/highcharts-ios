/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPolygon.h"
#import "HISolidgauge.h"
#import "HIWordcloud.h"
#import "HIArearange.h"
#import "HIScatter3d.h"
#import "HIHeatmap.h"
#import "HIFunnel.h"
#import "HISpline.h"
#import "HIBullet.h"
#import "HISunburst.h"
#import "HITilemap.h"
#import "HIArea.h"
#import "HITreemap.h"
#import "HIErrorbar.h"
#import "HIVector.h"
#import "HIVariwide.h"
#import "HIAreaspline.h"
#import "HIStreamgraph.h"
#import "HIXrange.h"
#import "HIColumn.h"
#import "HIGauge.h"
#import "HIBubble.h"
#import "HIBar.h"
#import "HIWaterfall.h"
#import "HIAreasplinerange.h"
#import "HIColumnrange.h"
#import "HISankey.h"
#import "HIScatter.h"
#import "HIVariablepie.h"
#import "HIPyramid.h"
#import "HIBellcurve.h"
#import "HIWindbarb.h"
#import "HIBoxplot.h"
#import "HIPie.h"
#import "HIPareto.h"
#import "HILine.h"
#import "HIHistogram.h"
#import "HISeries.h"


/**
* description: The plotOptions is a wrapper object for config objects for each series
type. The config objects for each series can also be overridden for
each series item as given in the series array.
Configuration options for the series are given in three levels. Options
for all series in a chart are given in the plotOptions.series object. Then options for all series of a specific type are
given in the plotOptions of that type, for example plotOptions.line.
Next, options for one single series are given in the series array.
*/
@interface HIPlotOptions: HIChartsJSONSerializable

/**
* description: A polygon series can be used to draw any freeform shape in the cartesian
coordinate system. A fill is applied with the color option, and
stroke is applied through lineWidth and lineColor options. Requires
the highcharts-more.js file.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/polygon/ : Polygon
*/
@property(nonatomic, readwrite) HIPolygon *polygon;
/**
* description: A solid gauge is a circular gauge where the value is indicated by a filled
arc, and the color of the arc may variate with the value.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-solid/ : Solid gauges
*/
@property(nonatomic, readwrite) HISolidgauge *solidgauge;
/**
* description: A word cloud is a visualization of a set of words, where the size and
placement of a word is determined by how it is weighted.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/wordcloud : Word Cloud chart
*/
@property(nonatomic, readwrite) HIWordcloud *wordcloud;
/**
* description: The area range series is a carteseian series with higher and lower values
for each point along an X axis, where the area between the values is shaded.
Requires highcharts-more.js.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/arearange/ : Area range chart
*/
@property(nonatomic, readwrite) HIArearange *arearange;
/**
* description: A 3D scatter plot uses x, y and z coordinates to display values for three
variables for a set of data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter/ : Simple 3D scatter
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-scatter-draggable : Draggable 3d scatter
*/
@property(nonatomic, readwrite) HIScatter3d *scatter3d;
/**
* description: A heatmap is a graphical representation of data where the individual values
contained in a matrix are represented as colors.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap/ : Simple heatmap
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/heatmap-canvas/ : Heavy heatmap
*/
@property(nonatomic, readwrite) HIHeatmap *heatmap;
/**
* description: Funnel charts are a type of chart often used to visualize stages in a sales 
project, where the top are the initial stages with the most clients. 
It requires that the modules/funnel.js file is loaded.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/funnel/ : Funnel demo
*/
@property(nonatomic, readwrite) HIFunnel *funnel;
/**
* description: A spline series is a special type of line series, where the segments between
the data points are smoothed.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/spline-irregular-time/ : Spline chart
*/
@property(nonatomic, readwrite) HISpline *spline;
/**
* description: A bullet graph is a variation of a bar graph. The bullet graph features
a single measure, compares it to a target, and displays it in the context
of qualitative ranges of performance that could be set using
plotBands on yAxis.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bullet-graph/ : Bullet graph
*/
@property(nonatomic, readwrite) HIBullet *bullet;
/**
* description: A Sunburst displays hierarchical data, where a level in the hierarchy is represented by a circle.
The center represents the root node of the tree.
The visualization bears a resemblance to both treemap and pie charts.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst : Sunburst chart
*/
@property(nonatomic, readwrite) HISunburst *sunburst;
/**
* description: A tilemap series is a type of heatmap where the tile shapes are configurable.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/honeycomb-usa/ : Honeycomb tilemap, USA
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-brazil/ : Honeycomb tilemap, Brazil
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-china/ : Honeycomb tilemap, China
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/honeycomb-europe/ : Honeycomb tilemap, Europe
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/circlemap-africa/ : Circlemap tilemap, Africa
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/diamondmap : Diamondmap tilemap
*/
@property(nonatomic, readwrite) HITilemap *tilemap;
/**
* description: The area series type.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/area-basic/ : Area chart
*/
@property(nonatomic, readwrite) HIArea *area;
/**
* description: A treemap displays hierarchical data using nested rectangles. The data can be
laid out in varying ways depending on options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-large-dataset/ : Treemap
*/
@property(nonatomic, readwrite) HITreemap *treemap;
/**
* description: Error bars are a graphical representation of the variability of data and are
used on graphs to indicate the error, or uncertainty in a reported
measurement.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/error-bar/ : Error bars
*/
@property(nonatomic, readwrite) HIErrorbar *errorbar;
/**
* description: A vector plot is a type of cartesian chart where each point has an X and Y
position, a length and a direction. Vectors are drawn as arrows.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/vector-plot/ : Vector pot
*/
@property(nonatomic, readwrite) HIVector *vector;
/**
* description: A variwide chart (related to marimekko chart) is a column chart with a
variable width expressing a third dimension.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variwide/ : Variwide chart
*/
@property(nonatomic, readwrite) HIVariwide *variwide;
/**
* description: The area spline series is an area series where the graph between the points
is smoothed into a spline.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/areaspline/ : Area spline chart
*/
@property(nonatomic, readwrite) HIAreaspline *areaspline;
/**
* description: A streamgraph is a type of stacked area graph which is displaced around a
central axis, resulting in a flowing, organic shape.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph/ : Streamgraph
*/
@property(nonatomic, readwrite) HIStreamgraph *streamgraph;
/**
* description: The X-range series displays ranges on the X axis, typically time intervals
with a start and end date.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range/ : X-range
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/x-range/ : Styled mode X-range
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/chart/inverted-xrange/ : Inverted X-range
*/
@property(nonatomic, readwrite) HIXrange *xrange;
/**
* description: Column series display one column per value along an X axis.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-basic/ : Column chart
*/
@property(nonatomic, readwrite) HIColumn *column;
/**
* description: Gauges are circular plots displaying one or more values with a dial pointing
to values along the perimeter.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/gauge-speedometer/ : Gauge chart
*/
@property(nonatomic, readwrite) HIGauge *gauge;
/**
* description: A bubble series is a three dimensional series type where each point renders
an X, Y and Z value. Each points is drawn as a bubble where the position
along the X and Y axes mark the X and Y values, and the size of the bubble
relates to the Z value. Requires highcharts-more.js.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bubble/ : Bubble chart
*/
@property(nonatomic, readwrite) HIBubble *bubble;
/**
* description: A bar series is a special type of column series where the columns are
horizontal.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bar-basic/ : Bar chart
*/
@property(nonatomic, readwrite) HIBar *bar;
/**
* description: A waterfall chart displays sequentially introduced positive or negative
values in cumulative columns.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/ : Waterfall chart
*/
@property(nonatomic, readwrite) HIWaterfall *waterfall;
/**
* description: The area spline range is a cartesian series type with higher and
lower Y values along an X axis. The area inside the range is colored, and
the graph outlining the area is a smoothed spline. Requires
highcharts-more.js.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/demo/areasplinerange/ : Area spline range
*/
@property(nonatomic, readwrite) HIAreasplinerange *areasplinerange;
/**
* description: The column range is a cartesian series type with higher and lower
Y values along an X axis. Requires highcharts-more.js. To display
horizontal bars, set chart.inverted to true.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/columnrange/ : Inverted column range
*/
@property(nonatomic, readwrite) HIColumnrange *columnrange;
/**
* description: A sankey diagram is a type of flow diagram, in which the width of the 
link between two nodes is shown proportionally to the flow quantity.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sankey-diagram/ : Sankey diagram
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-inverted/ : Inverted sankey diagram
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing : Sankey diagram with outgoing links
*/
@property(nonatomic, readwrite) HISankey *sankey;
/**
* description: A scatter plot uses cartesian coordinates to display values for two variables
for a set of data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/scatter/ : Scatter plot
*/
@property(nonatomic, readwrite) HIScatter *scatter;
/**
* description: A variable pie series is a two dimensional series type, where each point
renders an Y and Z value.  Each point is drawn as a pie slice where the
size (arc) of the slice relates to the Y value and the radius of pie
slice relates to the Z value. Requires highcharts-more.js.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/variable-radius-pie/ : Variable-radius pie chart
*/
@property(nonatomic, readwrite) HIVariablepie *variablepie;
/**
* description: A pyramid series is a special type of funnel, without neck and reversed by
default.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pyramid/ : Pyramid chart
*/
@property(nonatomic, readwrite) HIPyramid *pyramid;
/**
* description: A bell curve is an areaspline series which represents the probability density
function of the normal distribution. It calculates mean and standard
deviation of the base series data and plots the curve according to the
calculated parameters.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/bellcurve/ : Bell curve
*/
@property(nonatomic, readwrite) HIBellcurve *bellcurve;
/**
* description: Wind barbs are a convenient way to represent wind speed and direction in one
graphical form. Wind direction is given by the stem direction, and wind speed
by the number and shape of barbs.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/windbarb-series/ : Wind barb series
*/
@property(nonatomic, readwrite) HIWindbarb *windbarb;
/**
* description: A box plot is a convenient way of depicting groups of data through their
five-number summaries: the smallest observation (sample minimum), lower
quartile (Q1), median (Q2), upper quartile (Q3), and largest observation
(sample maximum).

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/box-plot/ : Box plot
*/
@property(nonatomic, readwrite) HIBoxplot *boxplot;
/**
* description: A pie chart is a circular graphic which is divided into slices to illustrate
numerical proportion.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-basic/ : Pie chart
*/
@property(nonatomic, readwrite) HIPie *pie;
/**
* description: A pareto diagram is a type of chart that contains both bars and a line graph, 
where individual values are represented in descending order by bars, 
and the cumulative total is represented by the line.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pareto/ : Pareto diagram
*/
@property(nonatomic, readwrite) HIPareto *pareto;
/**
* description: A line series displays information as a series of data points connected by
straight line segments.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/line-basic/ : Line chart
*/
@property(nonatomic, readwrite) HILine *line;
/**
* description: A histogram is a column series which represents the distribution of the data
set in the base series. Histogram splits data into bins and shows their frequencies.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/histogram/ : Histogram
*/
@property(nonatomic, readwrite) HIHistogram *histogram;
/**
* description: General options for all series types.
*/
@property(nonatomic, readwrite) HISeries *series;

-(NSDictionary *)getParams;

@end
