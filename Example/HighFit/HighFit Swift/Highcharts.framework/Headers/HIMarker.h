/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimation.h"
#import "HIStates.h"
#import "HIColor.h"


/**
The triangular marker on a scalar color axis that points to the value of the hovered area. To disable the marker, set `marker: null`.
*/
@interface HIMarker: HIChartsJSONSerializable

/**
The color of the marker.

**Defaults to** `#999999`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Animation for the marker as it moves between values. Set to `false` to disable animation. Defaults to `{ duration: 50 }`.
*/
@property(nonatomic, readwrite) HIAnimation *animation;
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
A predefined shape or symbol for the marker. When undefined, the symbol is pulled from options.symbols. Other possible values are "circle", "square", "diamond", "triangle" and "triangle-down". Additionally, the URL to a graphic can be given on this form: "url(graphic.png)". Note that for the image to be applied to exported charts, its URL needs to be accessible by the export server. Custom callbacks for symbol path generation can also be added to `Highcharts.SVGRenderer.prototype.symbols`. The callback is then used by its method name, as shown in the demo.

**Try it**

* [Predefined, graphic and custom markers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-symbol/)
*/
@property(nonatomic, readwrite) NSString *symbol;
/**
States for a single point marker.
*/
@property(nonatomic, readwrite) HIStates *states;
/**
The fill color of the point marker. When `undefined`, the series' or point's color is used.

**Try it**

* [White fill](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-fillcolor/)
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The color of the point marker's outline. When `undefined`, the series' or point's color is used.

**Try it**

* [Inherit from series color (undefined)](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-fillcolor/)
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
The width of the point marker's outline.

**Defaults to** `0`.

**Try it**

* [2px blue marker](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-fillcolor/)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The fill opacity of the bubble markers.
*/
@property(nonatomic, readwrite) NSNumber *fillOpacity;
/**
Image markers only. Set the image width explicitly. When using this option, a `width` must also be set.

**Try it**

* [Fixed width and height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-width-height/)
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
Image markers only. Set the image width explicitly. When using this option, a `height` must also be set.

**Try it**

* [Fixed width and height](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-width-height/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
The radius of the point marker.

**Defaults to** `4`.

**Try it**

* [Bigger markers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-radius/)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
The threshold for how dense the point markers should be before they are hidden, given that `enabled` is not defined. The number indicates the horizontal distance between the two closest points in the series, as multiples of the `marker.radius`. In other words, the default value of 2 means points are hidden if overlapping horizontally.

**Defaults to** `2`.

**Try it**

* [A higher threshold](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-marker-enabledthreshold)
*/
@property(nonatomic, readwrite) NSNumber *enabledThreshold;

-(NSDictionary *)getParams;

@end
