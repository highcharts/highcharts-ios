/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFunction.h"
#import "HILabelIntersectBoxObject.h"
#import "HICSSObject.h"


/**
Series labels are placed as close to the series as possible in a natural way, seeking to avoid other series. The goal of this feature is to make the chart more easily readable, like if a human designer placed the labels in the optimal position. The series labels currently work with series types having a `graph` or an `area`.

**Try it**

* [Line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/line-chart)
* [Stream graph](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/streamgraph)
* [Stock chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-label/stock-chart)
*/
@interface HILabel: HIChartsJSONSerializable

/**
Styles for the series label. The color defaults to the series color, or a contrast color if `onArea`.
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
For area-like series, allow the font size to vary so that small areas get a smaller font size. The default applies this effect to area-like series but not line-like series.
*/
@property(nonatomic, readwrite) NSNumber *minFontSize;
/**
A format string for the label, with support for a subset of HTML. Variables are enclosed by curly brackets. Available variables are `name`, `options.xxx`, `color` and other members from the `series` object. Use this option also to set a static text for the label.
*/
@property(nonatomic, readwrite) NSString *format;
/**
For area-like series, allow the font size to vary so that small areas get a smaller font size. The default applies this effect to area-like series but not line-like series.
*/
@property(nonatomic, readwrite) NSNumber *maxFontSize;
/**
Enable the series label per series.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
If the label is closer than this to a neighbour graph, draw a connector.
*/
@property(nonatomic, readwrite) NSNumber *connectorNeighbourDistance;
/**
Draw the label on the area of an area series. By default it is drawn on the area. Set it to `false` to draw it next to the graph instead.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *onArea;
/**
An array of boxes to avoid when laying out the labels. Each item has a `left`, `right`, `top` and `bottom` property.
*/
@property(nonatomic, readwrite) NSArray<HILabelIntersectBoxObject *> *boxesToAvoid;
/**
Callback function to format each of the series' labels. The `this` keyword refers to the series object. By default the `formatter` is undefined and the `series.name` is rendered.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
Allow labels to be placed distant to the graph if necessary, and draw a connector line to the graph. Setting this option to true may decrease the performance significantly, since the algorithm with systematically search for open spaces in the whole plot area. Visually, it may also result in a more cluttered chart, though more of the series will be labeled.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectorAllowed;
/**
Vertical alignment of the label relative to the plot line. Can be one of "top", "middle" or "bottom".

**Defaults to** `top`.

**Try it**

* [Vertically centered label](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-verticalalign-middle/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The text itself. A subset of HTML is supported.
*/
@property(nonatomic, readwrite) NSString *text;
/**
Horizontal alignment of the label. Can be one of "left", "center" or "right".

**Defaults to** `left`.

**Try it**

* [Aligned to the right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-align-right/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
Vertical position of the text baseline relative to the alignment. Default varies by orientation.

**Try it**

* [Label below the plot line](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-y/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
Horizontal position relative the alignment. Default varies by orientation.

**Try it**

* [Aligned 10px from the right edge](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-align-right/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Rotation of the text label in degrees. Defaults to 0 for horizontal plot lines and 90 for vertical lines.

**Try it**

* [Slanted text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-verticalalign-middle/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
The text alignment for the label. While `align` determines where the texts anchor point is placed within the plot band, `textAlign` determines how the text is aligned against its anchor point. Possible values are "left", "center" and "right". Defaults to the same as the `align` option.

**Try it**

* [Text label in bottom position](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotlines-label-textalign/)
*/
@property(nonatomic, readwrite) NSString *textAlign;

-(NSDictionary *)getParams;

@end
