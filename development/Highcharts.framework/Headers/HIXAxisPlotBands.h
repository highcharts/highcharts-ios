/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIXAxisPlotBandsLabel.h"
#import "HIColor.h"


/**
* description: An array of colored bands stretching across the plot area marking an interval on the axis.
In a gauge, a plot band on the Y axis (value axis) will stretch along the perimeter of the gauge.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the plot bands are styled by the .highcharts-plot-band class in addition to the className option.
*/
@interface HIXAxisPlotBands: HIChartsJSONSerializable

/**
* description: The color of the plot band.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Color band
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: An object defining mouse events for the plot band. Supported properties are click, mouseover, mouseout, mousemove.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-events/ : Mouse events demonstrated
*/
@property(nonatomic, readwrite) id events;
/**
* description: The z index of the plot band within the chart, relative to other elements. Using the same z index as another element may give unpredictable results, as the last rendered element will be on top. Values from 0 to 20 make sense.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Behind plot lines by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex/ : above plot lines,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-zindex-above-series/ : above plot lines and series.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: The end position of the plot band in axis units.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Datetime axis,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/ : categorized axis,
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
* description: A custom class name, in addition to the default highcharts-plot-band, to apply to each individual band.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: Border color for the plot band. Also requires borderWidth to be set.
* default: null
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Border width for the plot band.  Also requires borderColor to be set.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: The start position of the plot band in axis units.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-color/ : Datetime axis,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-from/ : categorized axis,
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
* description: An id used for identifying the plot band in Axis.removePlotBand.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-id/ : Remove plot band by id
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: Text labels for the plot bands
*/
@property(nonatomic, readwrite) HIXAxisPlotBandsLabel *label;

-(NSDictionary *)getParams;

@end
