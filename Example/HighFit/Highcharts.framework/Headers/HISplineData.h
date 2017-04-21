/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HISplineDataMarker.h"
#import "HISplineDataEvents.h"
#import "HIColor.h"


/**
* description: An array of data points for the series. For the spline series type, points can be given in the following ways:
 
An array of numerical values. In this case, the numerical values will 
 	be interpreted as y options. The x values will be automatically calculated,
 	either starting at 0 and incremented by 1, or from pointStart 
 	and pointInterval given in the series options. If the axis
 	has categories, these will be used.  Example:
data: [0, 5, 3, 5]

An array of arrays with 2 values. In this case, the values correspond to x,y. If the first value is a string, it is
 	applied as the name of the point, and the x value is inferred. data: [
    [0, 9], 
    [1, 2], 
    [2, 8]
]
An array of objects with named values. The objects are
 	point configuration objects as seen below. If the total number of data points exceeds the series' turboThreshold, this option is not available.
data: [{
    x: 1,
    y: 9,
    name: "Point2",
    color: "#00FF00"
}, {
    x: 1,
    y: 0,
    name: "Point1",
    color: "#FF00FF"
}]

* demo: The demos use a line series, but the principle is the same for all types.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/chart/reflow-true/ : Numerical values
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays/ : Arrays of numeric x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-arrays-datetime/ : Arrays of datetime x and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-name-value/ : Arrays of point.name and y
http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/ :  Config objects

*/
@interface HISplineData: HIChartsJSONSerializable

/**
* description: The id of a series in the drilldown.series array to use for a drilldown for this point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/drilldown/basic/ : Basic drilldown
*/
@property(nonatomic, readwrite) NSString *drilldown;
/**
* description: Requires Accessibility module
A description of the point to add to the screen reader information about the point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/maps/accessibility/accessible-map/ : Accessible map
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: Individual color for the point. By default the color is pulled from the global colors array.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/point/color/ : Mark the highest point
* default: undefined
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: The y value of the point.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The x value of the point. For datetime axes, the X value is the timestamp in milliseconds since 1970.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: Individual data label for each point. The options are the same as the ones for  plotOptions.series.dataLabels
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/point/datalabels/ : Show a label for the last value
*/
@property(nonatomic, readwrite) id dataLabels;
@property(nonatomic, readwrite) HISplineDataMarker *marker;
/**
* description: Whether the data point is selected initially.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
* description: An id for the point. This can be used after render time to get a pointer to the point object through chart.get().
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/point/id/ : Remove an id'd point
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: An additional, individual class name for the data point's graphic representation.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The name of the point as shown in the legend, tooltip, dataLabel etc.
If the xAxis.type is set to category, and no categories option exists, the category will be pulled from the point.name of the last series defined. For multiple series, best practice however is to define xAxis.categories.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/ : Point names
*/
@property(nonatomic, readwrite) NSString *name;
/**
* description: Individual point events
*/
@property(nonatomic, readwrite) HISplineDataEvents *events;
/**
* description: The rank for this point's data label in case of collision. If two data labels are about to overlap, only the one with the highest labelrank will be drawn.
*/
@property(nonatomic, readwrite) NSNumber *labelrank;
/**
* description: http://www.highcharts.com/docs/chart-design-and-style/style-by-css : Styled mode only. A specific color index to use for the point, so its graphic representations are given the class name highcharts-color-{n}.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;

-(NSDictionary *)getParams;

@end
