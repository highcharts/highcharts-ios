/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


@interface HIPlotOptionsBubbleMarkerStatesHover: HIChartsJSONSerializable

/**
* description: Enable or disable the point marker.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-enabled/ : Disabled hover state
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The width of the point marker's outline.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-linewidth/ : 3px line width
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: The radius of the point marker. In hover state, it defaults to the normal state's radius + 2 as per the radiusPlus option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-radius/ : 10px radius
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
* description: The fill color of the marker in hover state.
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
* description: The number of pixels to increase the radius of the hovered point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/ : 5 pixels greater radius on hover
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *radiusPlus;
/**
* description: The additional line width for a hovered point.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/ : 2 pixels wider on hover
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
* description: The color of the point marker's outline. When null, the series' or point's color is used.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-hover-linecolor/ : White fill color, black line color
* default: #ffffff
*/
@property(nonatomic, readwrite) HIColor *lineColor;

-(NSDictionary *)getParams;

@end
