/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"


/**
* description: Text labels for the plot bands
*/
@interface HILabel: HIChartsJSONSerializable

/**
* description: Allow labels to be placed distant to the graph if necessary,
and draw a connector line to the graph.
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *connectorAllowed;
/**
* description: An array of boxes to avoid when laying out the labels. Each 
item has a left, right, top and bottom property.
*/
@property(nonatomic, readwrite) NSArray *boxesToAvoid;
/**
* description: Draw the label on the area of an area series. By default it
is drawn on the area. Set it to false to draw it next to
the graph instead.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *onArea;
/**
* description: For area-like series, allow the font size to vary so that
small areas get a smaller font size. The default applies this
effect to area-like series but not line-like series.
*/
@property(nonatomic, readwrite) NSNumber *maxFontSize;
/**
* description: If the label is closer than this to a neighbour graph, draw a
connector.
* default: 24
*/
@property(nonatomic, readwrite) NSNumber *connectorNeighbourDistance;
/**
* description: For area-like series, allow the font size to vary so that
small areas get a smaller font size. The default applies this
effect to area-like series but not line-like series.
*/
@property(nonatomic, readwrite) NSNumber *minFontSize;
/**
* description: Styles for the series label. The color defaults to the series
color, or a contrast color if onArea.
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
* description: Enable the series label per series.
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-
and-string-formatting#html : use HTML to render the labels.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: Horizontal position relative the alignment. Default varies by orientation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-align/ : Aligned 10px from the right edge
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotbands-label/ : Plot band with labels
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: Rotation of the text label in degrees .

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-rotation/ : Vertical text
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: The string text itself. A subset of HTML is supported.
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: Vertical position of the text baseline relative to the alignment.
 Default varies by orientation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-y/ : Label on x axis
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotbands-label/ : Plot band with labels
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Horizontal alignment of the label. Can be one of "left", "center"
or "right".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-align/ : Aligned to the right
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotbands-label/ : Plot band with labels
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: The text alignment for the label. While align determines where
the texts anchor point is placed within the plot band, textAlign
determines how the text is aligned against its anchor point. Possible
values are "left", "center" and "right". Defaults to the same as
the align option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-rotation/ : Vertical text in center position but text-aligned left
*/
@property(nonatomic, readwrite) NSString *textAlign;
/**
* description: Vertical alignment of the label relative to the plot band. Can be
one of "top", "middle" or "bottom".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/xaxis/plotbands-label-verticalalign/ : Vertically centered label
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/stock/xaxis/plotbands-label/ : Plot band with labels
* default: top
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
