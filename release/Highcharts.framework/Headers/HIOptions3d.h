/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFrame.h"


/**
Options to render charts in 3 dimensions. This feature requires `highcharts-3d.js`, found in the download package or online at [https://code.highcharts.com/highcharts-3d.js](http://code.highcharts.com/highcharts-3d.js).
*/
@interface HIOptions3d: HIChartsJSONSerializable

/**
Defines the distance the viewer is standing in front of the chart, this setting is important to calculate the perspective effect in column and scatter charts. It is not used for 3D pie charts.

**Defaults to** `100`.
*/
@property(nonatomic, readwrite) NSNumber *viewDistance;
/**
Provides the option to draw a frame around the charts by defining a bottom, front and back panel.
*/
@property(nonatomic, readwrite) HIFrame *frame;
/**
Set it to `"auto"` to automatically move the labels to the best edge.

**Accepted values:** `[null, "auto"]`.
*/
@property(nonatomic, readwrite) NSString *axisLabelPosition;
/**
Wether to render the chart using the 3D functionality.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
One of the two rotation angles for the chart.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *beta;
/**
The total depth of the chart.

**Defaults to** `100`.
*/
@property(nonatomic, readwrite) NSNumber *depth;
/**
Whether the 3d box should automatically adjust to the chart plot area.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *fitToPlot;
/**
One of the two rotation angles for the chart.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *alpha;

-(NSDictionary *)getParams;

@end
