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
 A `dumbbell` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `dumbbell` series are defined in `plotOptions.dumbbell`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        dumbbell: {
            // shared options for all dumbbell series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'dumbbell'
    }]
 });
 <pre>
 */
@interface HIDumbbell: HISeries

/**
Color of the line that connects the dumbbell point's values. By default it is the series' color.
*/
@property(nonatomic, readwrite) NSString *connectorColor;
/**
Pixel width of the line that connects the dumbbell point's values.
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
@property(nonatomic, readwrite) NSNumber *pointPadding;
@property(nonatomic, readwrite) NSNumber *groupPadding;
/**
Color of the start markers in a dumbbell graph.
*/
@property(nonatomic, readwrite) HIColor *lowColor;
/**
A separate color for the negative part of the area. In styled mode, a negative color is set with the `.highcharts-negative` class name.

**Try it**

* [Negative color in styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-negative-color/)
*/
@property(nonatomic, readwrite) HIColor *negativeFillColor;
/**
A separate color for the graph line. By default the line takes the `color` of the series, but the lineColor setting allows setting a separate color for the line without altering the `fillColor`. In styled mode, the line stroke can be set with the `.highcharts-graph` class name.

**Try it**

* [Dark gray line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/area-linecolor/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;

-(NSDictionary *)getParams;

@end
