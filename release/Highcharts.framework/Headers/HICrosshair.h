/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
Configure a crosshair that follows either the mouse pointer or the hovered point. In styled mode, the crosshairs are styled in the `.highcharts-crosshair`, `.highcharts-crosshair-thin` or `.highcharts-xaxis-category` classes.

**Defaults to** `false`.

**Try it**

* [Crosshair on both axes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-both/)
*/
@interface HICrosshair: HIChartsJSONSerializable

/**
The Z index of the crosshair. Higher Z indices allow drawing the crosshair on top of the series or behind the grid lines.

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The dash style for the crosshair. See `plotOptions.series.dashStyle` for possible values.

**Defaults to** `Solid`.

**Try it**

* [Dotted crosshair](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-dotted/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
The color of the crosshair. Defaults to `#cccccc` for numeric and datetime axes, and `rgba(204,214,235,0.25)` for category axes, where the crosshair by default highlights the whole category.

**Defaults to** `#cccccc`.

**Try it**

* [Customized crosshairs](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-customized/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
A class name for the crosshair, especially as a hook for styling.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The pixel width of the crosshair. Defaults to 1 for numeric or datetime axes, and for one category width for category axes.

**Defaults to** `1`.

**Try it**

* [Customized crosshairs](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-customized/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
Whether the crosshair should snap to the point or follow the pointer independent of points.

**Defaults to** `true`.

**Try it**

* [True by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/crosshair-snap-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *snap;

-(NSDictionary *)getParams;

@end
