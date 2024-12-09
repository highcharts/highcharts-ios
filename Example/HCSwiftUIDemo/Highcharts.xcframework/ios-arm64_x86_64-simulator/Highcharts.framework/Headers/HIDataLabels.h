/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIFilter.h"
#import "HITextPath.h"
#import "HILinkTextPath.h"
#import "HIParentNodeTextPath.h"
#import "HIColor.h"
#import "HISVGAttributes.h"
#import "HIFunction.h"
#import "HIAnimationOptionsObject.h"
#import "HIShadowOptionsObject.h"
#import "HIAnimationOptionsObject.h"


/**
Can set `dataLabels` on all points which lies on the same level.
*/
@interface HIDataLabels: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
@property(nonatomic, readwrite) NSNumber /* Bool */ *defer;
@property(nonatomic, readwrite) HIStyle *style;
/**
Decides how the data label will be rotated relative to the perimeter of the sunburst. Valid values are `circular`, `auto`, `parallel` and `perpendicular`. When `circular`, the best fit will be computed for the point, so that the label is curved around the center when there is room for it, otherwise perpendicular. The legacy `auto` option works similar to `circular`, but instead of curving the labels they are tangent to the perimeter. The `rotation` option takes precedence over `rotationMode`.

**Defaults to** `circular`.

**Try it**

* [Circular rotation mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sunburst-datalabels-rotationmode-circular/)
*/
@property(nonatomic, readwrite) NSString *rotationMode;
/**
The color of the line connecting the data label to the pie slice. The default color is the same as the point's color. In styled mode, the connector stroke is given in the `.highcharts-data-label-connector` class.

**Try it**

* [Blue connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorcolor/)
* [Styled connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/)
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
/**
Works only if `connectorShape` is `'crookedLine'`. It defines how far from the vertical plot edge the coonnector path should be crooked. With the default, `undefined`, the crook is placed so that the horizontal line from the label intersects with the radial line extending through the center of the pie slice.

**Defaults to** `undefined`.

**Try it**

* [crookDistance set to 90%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-crookdistance/)
*/
@property(nonatomic, readwrite) NSString *crookDistance;
/**
Alignment method for data labels. Possible values are: - `plotEdges`: Each label touches the nearest vertical edge of  the plot area. - `connectors`: Connectors have the same x position and the  widest label of each half (left & right) touches the nearest  vertical edge of the plot area.

**Try it**

* [alignTo: connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-connectors/)
* [alignTo: plotEdges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-plotedges/)
*/
@property(nonatomic, readwrite) NSString *alignTo;
/**
The width of the line connecting the data label to the pie slice. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.

**Defaults to** `1`.

**Try it**

* [Disable the connector](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorwidth-disabled/)
* [Styled connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/)
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
Whether to render the connector as a soft arc or a line with a sharp break. Works only if `connectorShape` equals to `fixedOffset`.

**Defaults to** `True`.

**Try it**

* [Soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-true/)
* [Non soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softConnector;
/**
A [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) for the data label. Available variables are the same as for `formatter`.

**Defaults to** `undefined`.

**Try it**

* [Add a unit](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-format/)
*/
@property(nonatomic, readwrite) NSString *format;
/**
Enable or disable the data labels.

**Defaults to** `True`.

**Try it**

* [Data labels enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The distance from the data label to the connector. Note that data labels also have a default `padding`, so in order for the connector to touch the text, the `padding` must also be 0.

**Defaults to** `5`.

**Try it**

* [No padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorpadding/)
*/
@property(nonatomic, readwrite) NSNumber *connectorPadding;
/**
Specifies the method that is used to generate the connector path. Highcharts provides 3 built-in connector shapes: `'crookedLine'` (default since v11), `'fixedOffset'` and `'straight'`. Users can provide their own method by passing a function instead of a string. Three arguments are passed to the callback: - An object that holds the information about the coordinates of the  label (`x` & `y` properties) and how the label is located in  relation to the pie (`alignment` property). `alignment` can by one  of the following: `'left'` (pie on the left side of the data  label), `'right'` (pie on the right side of the data label) or  `'center'` (data label overlaps the pie). - An object that holds the information about the position of the  connector. Its `touchingSliceAt` porperty tells the position of  the place where the connector touches the slice. - Data label options The function has to return an SVG path definition in array form (see the example).

**Defaults to** `crookedLine`.

**Try it**

* [connectorShape is a String](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-string/)
* [connectorShape is a function](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-function/)
*/
@property(nonatomic, readwrite) NSString *connectorShape;
/**
Callback JavaScript function to format the data label. Note that if a `format` is defined, the format takes precedence and the formatter is ignored.

**Defaults to** `function () { return this.point.isNull ? void 0 : this.point.name; }`.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
The distance of the data label from the pie's edge. Negative numbers put the data label on top of the pie slices. Can also be defined as a percentage of pie's radius. Connectors are only shown for data labels outside the pie.

**Defaults to** `30`.

**Try it**

* [Data labels on top of the pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-distance/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ distance;
/**
Callback JavaScript function that defines formatting for points with the value of null. Works analogously to `formatter`. `nullFormatter` can be applied only to series which support displaying null points i.e `heatmap` or `tilemap`. Does not work with series that don't display null points, like `line`, `column`, `bar` or `pie`.

**Try it**

* [Format data label for null points in heat map](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-nullformat/)
*/
@property(nonatomic, readwrite) HIFunction *nullFormatter;
/**
The border radius in pixels for the data label.

**Defaults to** `0`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Whether to hide data labels that are outside the plot area. By default, the data label is moved inside the plot area according to the `overflow` option.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
The name of a symbol to use for the border around the label. Symbols are predefined functions on the Renderer object.

**Defaults to** `square`.

**Try it**

* [A callout for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-shape/)
*/
@property(nonatomic, readwrite) NSString *shape;
/**
Text rotation in degrees. Note that due to a more complex structure, backgrounds, borders and padding will be lost on a rotated data label.

**Defaults to** `0`.

**Try it**

* [Vertical labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
The border color for the data label. Setting it to `auto` will use the point's color. Defaults to `undefined`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
A declarative filter to control of which data labels to display. The declarative filter is designed for use when callback functions are not available, like when the chart options require a pure JSON structure or for use with graphical editors. For programmatic control, use the `formatter` instead, and return `undefined` to disable a single data label.

**Try it**

* [Data labels filtered by percentage](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome)
*/
@property(nonatomic, readwrite) HIFilter *filter;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
Enable or disable the initial animation when a series is displayed for the `dataLabels`. The animation can also be set as a configuration object. Please note that this option only applies to the initial animation. For other animations, see `chart.animation` and the animation parameter under the API methods. The following properties are supported: - `defer`: The animation delay time in milliseconds.

**Try it**

* [Animation defer settings](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/animation-defer/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
The background color or gradient for the data label. Setting it to `auto` will use the point's color.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
Format for points with the value of null. Works analogously to `format`. `nullFormat` can be applied only to series which support displaying null points i.e `heatmap` or `tilemap`. Does not work with series that don't display null points, like `line`, `column`, `bar` or `pie`.

**Try it**

* [Format data label for null points in heat map](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-nullformat/)
*/
@property(nonatomic, readwrite) id /* Bool, NSString */ nullFormat;
/**
When either the `borderWidth` or the `backgroundColor` is set, this is the padding within the box.

**Defaults to** `5`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
The shadow of the box. Works best with `borderWidth` or `backgroundColor`. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;
/**
The x position offset of the label relative to the point in pixels.

**Try it**

* [Vertical and positioned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/)
* [Data labels inside the bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bar-datalabels-align-inside-bar/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
How to handle data labels that flow outside the plot area. The default is `"justify"`, which aligns them inside the plot area. For columns and bars, this means it will be moved inside the bar. To display data labels outside the plot area, set `crop` to `false` and `overflow` to `"allow"`.

**Defaults to** `justify`.
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
The z index of the data labels. Use a `zIndex` of 6 to display it above the series, or use a `zIndex` of 2 to display it behind the series.

**Defaults to** `6`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The vertical alignment of a data label. Can be one of `top`, `middle` or `bottom`. The default value depends on the data, for instance in a column chart, the label is above positive values and below negative values.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
A class name for the data label. Particularly in styled mode, this can be used to give each series' or point's data label unique styling. In addition to this option, a default color class name is added so that we can give the labels a contrast text shadow.

**Try it**

* [Contrast text shadow](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/data-label-contrast/)
* [Styling by CSS](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
The border width in pixels for the data label.

**Defaults to** `0`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
The y position offset of the label relative to the point in pixels.

**Try it**

* [Vertical and positioned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
Aligns data labels relative to points. If `center` alignment is not possible, it defaults to `right`.

**Defaults to** `center`.
*/
@property(nonatomic, readwrite) NSString *position;
/**
Options for a label text which should follow marker's shape. Border and background are disabled for a label that follows a path. **Note:** Only SVG-based renderer supports this option. Setting `useHTML` to true will disable this option.
*/
@property(nonatomic, readwrite) HITextPath *textPath;
@property(nonatomic, readwrite) NSString *align;
@property(nonatomic, readwrite) NSNumber /* Bool */ *inside;
/**
The format string specifying what to show for *links* in the organization chart. Best to use with ``linkTextPath`` enabled.

**Try it**

* [Organization chart with link labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-labels)
*/
@property(nonatomic, readwrite) NSString *linkFormat;
/**
Options for a _link_ label text which should follow link connection.

**Try it**

* [Organization chart with link labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-labels)
*/
@property(nonatomic, readwrite) HILinkTextPath *linkTextPath;
/**
Callback to format data labels for _links_ in the organization chart. The `linkFormat` option takes precedence over the `linkFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *linkFormatter;
/**
Y offset of the higher data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *yHigh;
/**
X offset of the higher data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *xHigh;
/**
X offset of the lower data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *xLow;
/**
Y offset of the lower data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *yLow;
/**
Callback to format data labels for _nodes_ in the sankey diagram. The `nodeFormat` option takes precedence over the `nodeFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *nodeFormatter;
/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _nodes_ in the sankey diagram. By default the `nodeFormatter` returns `{point.name}`.

**Defaults to** `undefined`.

**Try it**

* [Node and link data labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-link-datalabels/)
*/
@property(nonatomic, readwrite) NSString *nodeFormat;
@property(nonatomic, readwrite) NSString *parentNodeFormat;
@property(nonatomic, readwrite) HIParentNodeTextPath *parentNodeTextPath;
@property(nonatomic, readwrite) id parentNodeFormatter;
/**
Presentation attributes for the text path.
*/
@property(nonatomic, readwrite) HISVGAttributes *attributes;
/**
Whether to position data labels alternately. For example, if `distance` is set equal to `100`, then data labels will be positioned alternately (on both sides of the point) at a distance of 100px.

**Defaults to** `True`.

**Try it**

* [Alternate disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/alternate-disabled)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternate;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
