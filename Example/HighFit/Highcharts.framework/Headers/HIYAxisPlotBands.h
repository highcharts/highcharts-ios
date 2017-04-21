/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIYAxisPlotBandsLabel.h"
#import "HIColor.h"


/**
* description: An array of objects defining plot bands on the Y axis.
*/
@interface HIYAxisPlotBands: HIChartsJSONSerializable

/**
* description: In a gauge chart, this option determines the outer radius of the plot band that stretches along the perimeter. It can be given as a percentage string, like "100%", or as a pixel number, like 100.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge : Gauge plot band
* default: 100%
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ outerRadius;
/**
* description: In a gauge chart, this option determines the inner radius of the plot band that stretches along the perimeter. It can be given as a percentage string, like "100%", or as a pixel number, like 100. By default, the inner radius is controlled by the thickness option.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge : Gauge plot band
* default: null
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ innerRadius;
/**
* description: The start position of the plot band in axis units.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Datetime axis,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/ : categorized axis,
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
* description: Border width for the plot band.  Also requires borderColor to be set.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The z index of the plot band within the chart, relative to other elements. Using the same z index as another element may give unpredictable results, as the last rendered element will be on top. Values from 0 to 20 make sense.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Behind plot lines by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex/ : above plot lines,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex-above-series/ : above plot lines and series.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: A custom class name, in addition to the default highcharts-plot-band, to apply to each individual band.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: In a gauge chart, this option sets the width of the plot band stretching along the perimeter. It can be given as a percentage string, like "10%", or as a pixel number, like 10. The default value 10 is the same as the default tickLength, thus making the plot band act as a background for the tick markers. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-gauge : Gauge plot band
* default: 10
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ thickness;
/**
* description: The color of the plot band.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Color band
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: The end position of the plot band in axis units.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Datetime axis,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/ : categorized axis,
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
* description: An id used for identifying the plot band in Axis.removePlotBand.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-id/ : Remove plot band by id
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: An object defining mouse events for the plot band. Supported properties are click, mouseover, mouseout, mousemove.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-events/ : Mouse events demonstrated
*/
@property(nonatomic, readwrite) id events;
/**
* description: Border color for the plot band. Also requires borderWidth to be set.
* default: null
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Text labels for the plot bands
*/
@property(nonatomic, readwrite) HIYAxisPlotBandsLabel *label;

-(NSDictionary *)getParams;

@end
