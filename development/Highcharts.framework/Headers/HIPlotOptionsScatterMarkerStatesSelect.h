/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: The appearance of the point marker when selected. In order to allow a point to be 
		selected, set the series.allowPointSelect option to true.
*/
@interface HIPlotOptionsScatterMarkerStatesSelect: HIChartsJSONSerializable

/**
* description: The width of the point marker's outline.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-linewidth/ : 3px line width for selected points
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Enable or disable visible feedback for selection.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-enabled/ : Disabled select state
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The radius of the point marker. In hover state, it defaults
		to the normal state's radius + 2.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-radius/ : 10px radius for selected points
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
* description: The color of the point marker's outline. When null, the series' or point's color is used.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-linecolor/ : Red line color for selected points
* default: #000000
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
* description: The fill color of the point marker.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-fillcolor/ : Solid red discs for selected points
*/
@property(nonatomic, readwrite) HIColor *fillColor;

-(NSDictionary *)getParams;

@end
