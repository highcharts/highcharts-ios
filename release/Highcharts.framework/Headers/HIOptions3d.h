/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFrame.h"


/**
* description: Options to render charts in 3 dimensions. This feature requires
highcharts-3d.js, found in the download package or online at
http://code.highcharts.com/highcharts-
3d.js : code.highcharts.com/highcharts-3d.js.
*/
@interface HIOptions3d: HIChartsJSONSerializable

/**
* description: One of the two rotation angles for the chart.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *beta;
/**
* description: Set it to "auto" to automatically move the labels to the best
edge.

* accepted values: [null, "auto"]
* default: null
*/
@property(nonatomic, readwrite) NSString *axisLabelPosition;
/**
* description: Whether the 3d box should automatically adjust to the chart plot
area.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *fitToPlot;
/**
* description: The total depth of the chart.
* default: 100
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
* description: Defines the distance the viewer is standing in front of the chart,
this setting is important to calculate the perspective effect
in column and scatter charts. It is not used for 3D pie charts.
* default: 100
*/
@property(nonatomic, readwrite) NSNumber *viewDistance;
/**
* description: Provides the option to draw a frame around the charts by defining
a bottom, front and back panel.
*/
@property(nonatomic, readwrite) HIFrame *frame;
/**
* description: One of the two rotation angles for the chart.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *alpha;
/**
* description: Wether to render the chart using the 3D functionality.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
