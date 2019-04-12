/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimation.h"
#import "HIHalo.h"
#import "HIColor.h"


/**
The appearance of the point marker when selected. In order to allow a point to be selected, set the `series.allowPointSelect` option to true.
*/
@interface HISelect: HIChartsJSONSerializable

/**
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2.

**Try it**

* [10px radius for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-radius/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
The width of the point marker's outline.

**Try it**

* [3px line width for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-linewidth/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
Enable or disable visible feedback for selection.

**Defaults to** `true`.

**Try it**

* [Disabled select state](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The fill color of the point marker.

**Try it**

* [Solid red discs for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-fillcolor/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The color of the point marker's outline. When `undefined`, the series' or point's color is used.

**Try it**

* [Red line color for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-linecolor/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
A specific border color for the selected point.

**Defaults to** `#000000`.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
A specific color for the selected point.

**Defaults to** `#cccccc`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Animation setting for hovering the graph in line-type series.
*/
@property(nonatomic, readwrite) HIAnimation *animation;
/**
The additional line width for the graph of a hovered series.

**Try it**

* [5 pixels wider](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-states-hover-linewidthplus/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
Options for the halo appearing around the hovered point in line-type series as well as outside the hovered slice in pie charts. By default the halo is filled by the current point or series color with an opacity of 0.25\. The halo can be disabled by setting the `halo` option to `null`. In styled mode, the halo is styled with the `.highcharts-halo` class, with colors inherited from `.highcharts-color-{n}`.

**Try it**

* [Halo options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/halo/)
*/
@property(nonatomic, readwrite) HIHalo *halo;

-(NSDictionary *)getParams;

@end
