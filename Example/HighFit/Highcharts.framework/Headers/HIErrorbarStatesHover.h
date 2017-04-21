/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIErrorbarStatesHoverMarker.h"
#import "HIErrorbarStatesHoverHalo.h"


/**
* description: Options for the hovered series
*/
@interface HIErrorbarStatesHover: HIChartsJSONSerializable

/**
* description: In Highcharts 1.0, the appearance of all markers belonging to the hovered series. For settings on the hover state of the individual point, see marker.states.hover.
*/
@property(nonatomic, readwrite) HIErrorbarStatesHoverMarker *marker;
/**
* description: The additional line width for the graph of a hovered series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/ : 5 pixels wider
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
* description: Options for the halo appearing around the hovered point in line-type series as well as outside the hovered slice in pie charts. By default the halo is filled by the current point or series color with an opacity of 0.25. The halo can be disabled by setting the halo option to false.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the halo is styled with the .highcharts-halo class, with colors inherited from .highcharts-color-{n}.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/halo/ : Halo options
*/
@property(nonatomic, readwrite) HIErrorbarStatesHoverHalo *halo;
/**
* description: Pixel with of the graph line.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidth/ : 5px line on hover
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
* description: Enable separate styles for the hovered series to visualize that the user hovers either the series itself or the legend.			.
* demo: Disable hover on http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled/ : line,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-column/ : column,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-enabled-pie/ : pie
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
