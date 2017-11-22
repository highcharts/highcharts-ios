/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColorVariation.h"
#import "HIColor.h"


/**
* description: Set options on specific levels. Takes precedence over series options,
but not point options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst : Sunburst chart
*/
@interface HILevels: HIChartsJSONSerializable

/**
* description: Can set the borderWidth on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Can set the layoutStartingDirection option on a specific level.

* accepted values: ["vertical", "horizontal"]
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;
/**
* description: Can set a color on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: Can set the options of dataLabels on each point which lies on the
level. plotOptions.treemap.dataLabels
for possible values.
* default: undefined
*/
@property(nonatomic, readwrite) id dataLabels;
/**
* description: Set the dash style of the border of all the point which lies on the
level. See 
plotOptions.scatter.dashStyle for possible options.
*/
@property(nonatomic, readwrite) NSString *borderDashStyle;
/**
* description: A configuration object to define how the color of a child varies from the
parent's color. The variation is distributed among the children of node.
For example when setting brightness, the brightness change will range
from the parent's original brightness on the first child, to the amount
set in the to setting on the last node. This allows a gradient-like
color scheme that sets children out from each other while highlighting
the grouping on treemaps and sectors on sunburst charts.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst/ : Sunburst with color variation
*/
@property(nonatomic, readwrite) HIColorVariation *colorVariation;
/**
* description: Decides which level takes effect from the options set in the levels
object.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/ : Styling of both levels
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
* description: Can set the layoutAlgorithm option on a specific level.

* accepted values: ["sliceAndDice", "stripes", "squarified", "strip"]
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
* description: Can set a borderColor on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Can set a rotationMode on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSString *rotationMode;
/**
* description: Can set a rotation on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *rotation;

-(NSDictionary *)getParams;

@end
