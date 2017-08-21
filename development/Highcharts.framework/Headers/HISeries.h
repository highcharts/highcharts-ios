/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The actual series to append to the chart. In addition to 
	the members listed below, any member of the plotOptions for that specific
	type of plot can be added to a series individually. For example, even though a general
	lineWidth is specified in plotOptions.series, an individual
	lineWidth can be specified for each series.
*/
@interface HISeries: HIChartsJSONSerializable

/**
* description: An array of data points for the series. The points can be given in three ways:
 
An array of numerical values. In this case, the numerical values will 
 	be interpreted as y values, and x values will be automatically calculated,
 	either starting at 0 and incrementing by 1, or from pointStart 
 	and pointInterval given in the plotOptions. If the axis is
 	has categories, these will be used. This option is not available for range series. Example:
data: [0, 5, 3, 5]

An array of arrays with two values. In this case, the first value is the
 	x value and the second is the y value. If the first value is a string, it is
 	applied as the name of the point, and the x value is incremented following
 	the above rules.
For range series, the arrays will be interpreted as [x, low, high]. In this cases, the X value can be skipped altogether to make use of pointStart and pointRange.

 Example:
data: [[5, 2], [6, 3], [8, 2]]
An array of objects with named values. In this case the objects are
 	point configuration objects as seen below.
Range series values are given by low and high.

Example:
data: [{
	name: 'Point 1',
	color: '#00FF00',
	y: 0
}, {
	name: 'Point 2',
	color: '#FF00FF',
	y: 5
}]

Note that line series and derived types like spline and area, require data to be sorted by X because it interpolates mouse coordinates for the tooltip. Column and scatter series, where each point has its own mouse event, does not require sorting.
* demo: 
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : 1) Numerical values
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays/ : 2a) arrays of numeric x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays-datetime/ : 2b) arrays of datetime x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-name-value/ : 2c) arrays of point.name and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/ : 3) config objects
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/3d-column-null-values/ : 4) 3D column with null values

*/
@property(nonatomic, readwrite) NSArray /* <Data, NSNumber, NSArray> */ *data;
/**
* description: An id for the series. This can be used after render time to get a pointer to the series object through chart.get().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-id/ : Get series by id
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: The name of the series as shown in the legend, tooltip etc.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/name/ : Series name
*/
@property(nonatomic, readwrite) NSString *name;
/**
* description: When using dual or multiple y axes, this number defines which yAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the yAxis array, with 0 being the first.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/yaxis/ : Apply the column series to the secondary Y axis
* default: 0
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ yAxis;
/**
* description: The sequential index of the series in the legend.  Try it:  	http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/legendindex/ : Legend in opposite order .
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
* description: Define the visual z index of the series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex-default/ : With no z index, the series defined last are on top,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-zindex/ : with a z index, the series with the highest z index is on top.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: This option allows grouping series in a stacked chart. The stack option can be a string  or a number or anything else, as long as the grouped series' stack options match each other.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/stack/ : Stacked and grouped columns
*/
@property(nonatomic, readwrite) NSString *stack;
/**
* description: When using dual or multiple x axes, this number defines which xAxis the particular series is connected to. It refers to either the axis id or the index of the axis in the xAxis array, with 0 being the first.
* default: 0
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ xAxis;
/**
* description: The type of series. Can be one of area, areaspline, bar, column, line, pie, scatter or spline. From version 2.3, arearange, areasplinerange and columnrange are supported with the highcharts-more.js component.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/type/ : Line and column in the same chart
* accepted values: [null, "line", "spline", "column", "area", "areaspline", "pie", "arearange", "areasplinerange", "boxplot", "bubble", "columnrange", "errorbar", "funnel", "gauge", "scatter", "waterfall"]
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: This method is deprecated as of version 2.0. Instead, load the data using jQuery.ajax and use options preprocessing as described in http://docs.highcharts.com/#preprocessing : the docs.
*/
@property(nonatomic, readwrite) NSString *dataURL;
/**
* description: The index of the series in the chart, affecting the internal index in the chart.series array, the visible Z index as well as the order in the legend.
*/
@property(nonatomic, readwrite) NSNumber *index;
/**
* description: This method is deprecated as of version 2.0. Instead, use options preprocessing as described in http://docs.highcharts.com/#preprocessing : the docs.
*/
@property(nonatomic, readwrite) NSString /* Function */ *dataParser;

-(NSDictionary *)getParams;

@end
