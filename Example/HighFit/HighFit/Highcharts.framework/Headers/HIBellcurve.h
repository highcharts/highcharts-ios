/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
 A `bellcurve` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `bellcurve` series are defined in `plotOptions.bellcurve`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        bellcurve: {
            // shared options for all bellcurve series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'bellcurve'
    }]
 });
 <pre>
 */
@interface HIBellcurve: HISeries

/**
An integer identifying the index to use for the base series, or a string representing the id of the series.
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ baseSeries;
/**
This option allows to define the length of the bell curve. A unit of the length of the bell curve is standard deviation.

**Try it**

* [Intervals and points in interval](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bellcurve-intervals-pointsininterval)
*/
@property(nonatomic, readwrite) NSNumber *intervals;
/**
Defines how many points should be plotted within 1 interval. See `plotOptions.bellcurve.intervals`.

**Try it**

* [Intervals and points in interval](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bellcurve-intervals-pointsininterval)
*/
@property(nonatomic, readwrite) NSNumber *pointsInInterval;
/**
A separate color for the negative part of the area. In styled mode, a negative color is set with the `.highcharts-negative` class name.

**Try it**

* [Negative color in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-negative-color/)
*/
@property(nonatomic, readwrite) HIColor *negativeFillColor;
/**
Whether the whole area or just the line should respond to mouseover tooltips and other mouse or touch events.

**Defaults to** `false`.

**Try it**

* [Display the tooltip when the area is hovered](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-trackbyarea/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *trackByArea;
/**
Fill color or gradient for the area. When `null`, the series' `color` is used with the series' `fillOpacity`. In styled mode, the fill color can be set with the `.highcharts-area` class name.

**Try it**

* [Null by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-default/)
* [Gradient](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillcolor-gradient/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
A separate color for the graph line. By default the line takes the `color` of the series, but the lineColor setting allows setting a separate color for the line without altering the `fillColor`. In styled mode, the line stroke can be set with the `.highcharts-graph` class name.

**Try it**

* [Dark gray line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-linecolor/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
Fill opacity for the area. When you set an explicit `fillColor`, the `fillOpacity` is not applied. Instead, you should define the opacity in the `fillColor` with an rgba color definition. The `fillOpacity` setting, also the default setting, overrides the alpha component of the `color` setting. In styled mode, the fill opacity can be set with the `.highcharts-area` class name.

**Defaults to** `0.75`.

**Try it**

* [Automatic fill color and fill opacity of 0.1](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-fillopacity/)
*/
@property(nonatomic, readwrite) NSNumber *fillOpacity;

-(NSDictionary *)getParams;

@end
