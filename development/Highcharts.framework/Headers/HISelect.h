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
The appearance of the point marker when selected. In order to allow a point to be selected, set the `series.allowPointSelect` option to true.
*/
@interface HISelect: HIChartsJSONSerializable

/**
Enable or disable visible feedback for selection.

**Defaults to** `true`.

**Try it**

* [Disabled select state](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The width of the point marker's outline.

**Try it**

* [3px line width for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-linewidth/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2.

**Try it**

* [10px radius for selected points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-states-select-radius/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
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
A specific color for the selected point.

**Defaults to** `#cccccc`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
A specific border color for the selected point.

**Defaults to** `#000000`.
*/
@property(nonatomic, readwrite) HIColor *borderColor;

-(NSDictionary *)getParams;

@end
