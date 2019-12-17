/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIFilter.h"
#import "HITextPath.h"
#import "HIParentNodeTextPath.h"
#import "HILinkTextPath.h"
#import "HISVGAttributes.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HIShadowOptionsObject.h"


/**
Can set `dataLabels` on all points which lies on the same level.
*/
@interface HIDataLabels: HIChartsJSONSerializable

/**
Whether to allow data labels to overlap. To make the labels less sensitive for overlapping, the `dataLabels.padding` can be set to 0.

**Defaults to** `false`.

**Try it**

* [Don't allow overlap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-allowoverlap-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
Whether to defer displaying the data labels until the initial series animation has finished.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *defer;
/**
Styles for the label. The default `color` setting is `"contrast"`, which is a pseudo color that Highcharts picks up and applies the maximum contrast to the underlying point item, for example the bar in a bar chart. The `textOutline` is a pseudo property that applies an outline of the given width with the given color, which by default is the maximum contrast to the text. So a bright text color will result in a black text outline for maximum readability on a mixed background. In some cases, especially with grayscale text, the text outline doesn't work well, in which cases it can be disabled by setting it to `"none"`. When `useHTML` is true, the `textOutline` will not be picked up. In this, case, the same effect can be acheived through the `text-shadow` CSS property. For some series types, where each point has an extent, like for example tree maps, the data label may overflow the point. There are two strategies for handling overflow. By default, the text will wrap to multiple lines. The other strategy is to set `style.textOverflow` to `ellipsis`, which will keep the text on one line plus it will break inside long words.

**Try it**

* [Bold labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-style/)
* [Long labels truncated with an ellipsis in a pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotOptions/pie-datalabels-overflow/)
* [Long labels are wrapped in a pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotOptions/pie-datalabels-overflow-wrap/)
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
Decides how the data label will be rotated relative to the perimeter of the sunburst. Valid values are `auto`, `parallel` and `perpendicular`. When `auto`, the best fit will be computed for the point. The `series.rotation` option takes precedence over `rotationMode`.

**Accepted values:** `["auto", "perpendicular", "parallel"]`.
*/
@property(nonatomic, readwrite) NSString *rotationMode;
@property(nonatomic, readwrite) NSNumber *y;
@property(nonatomic, readwrite) NSString *align;
@property(nonatomic, readwrite) NSString *verticalAlign;
@property(nonatomic, readwrite) NSNumber /* Bool */ *inside;
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
@property(nonatomic, readwrite) NSString *format;
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
Callback to format data labels for _nodes_ in the sankey diagram. The `nodeFormat` option takes precedence over the `nodeFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *nodeFormatter;
@property(nonatomic, readwrite) NSString *backgroundColor;
@property(nonatomic, readwrite) HIFunction *formatter;
/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _nodes_ in the sankey diagram. By default the `nodeFormatter` returns `{point.name}`.

**Try it**

* [Node and link data labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-link-datalabels/)
*/
@property(nonatomic, readwrite) NSString *nodeFormat;
/**
Callback JavaScript function that defines formatting for points with the value of null. Works analogously to `formatter`. `nullPointFormatter` can be applied only to series which support displaying null points.

**Try it**

* [Format data label and tooltip for null point.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-format/)
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
How to handle data labels that flow outside the plot area. The default is `"justify"`, which aligns them inside the plot area. For columns and bars, this means it will be moved inside the bar. To display data labels outside the plot area, set `crop` to `false` and `overflow` to `"allow"`.

**Defaults to** `justify`.
*/
@property(nonatomic, readwrite) NSString *overflow;
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
The border color for the data label. Defaults to `undefined`.

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
The text color for the data labels. Defaults to `undefined`. For certain series types, like column or map, the data labels can be drawn inside the points. In this case the data label will be drawn with maximum contrast by default. Additionally, it will be given a `text-outline` style with the opposite color, to further increase the contrast. This can be overridden by setting the `text-outline` style to `none` in the `dataLabels.style` option.

**Try it**

* [Red data labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Format for points with the value of null. Works analogously to `format`. `nullFormat` can be applied only to series which support displaying null points.

**Try it**

* [Format data label and tooltip for null point.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-format/)
*/
@property(nonatomic, readwrite) id /* Bool, NSString */ nullFormat;
/**
When either the `borderWidth` or the `backgroundColor` is set, this is the padding within the box.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
The x position offset of the label relative to the point in pixels.

**Try it**

* [Vertical and positioned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/)
* [Data labels inside the bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bar-datalabels-align-inside-bar/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The shadow of the box. Works best with `borderWidth` or `backgroundColor`. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIShadowOptionsObject *shadow;
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
Aligns data labels relative to points. If `center` alignment is not possible, it defaults to `right`.

**Defaults to** `center`.
*/
@property(nonatomic, readwrite) NSString *position;
/**
The Z index of the data labels. The default Z index puts it above the series. Use a Z index of 2 to display it behind the series.

**Defaults to** `6`.
*/
@property(nonatomic, readwrite) NSNumber *z;
/**
Options for a label text which should follow marker's shape. Border and background are disabled for a label that follows a path. **Note:** Only SVG-based renderer supports this option. Setting `useHTML` to true will disable this option.
*/
@property(nonatomic, readwrite) HITextPath *textPath;
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
Callback to format data labels for _parentNodes_. The `parentNodeFormat` option takes precedence over the `parentNodeFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *parentNodeFormatter;
/**
Options for a _parentNode_ label text. **Note:** Only SVG-based renderer supports this option.

**Try it**

* [Dashboard with dataLabels on parentNodes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-packedbubble/packed-dashboard)
*/
@property(nonatomic, readwrite) HIParentNodeTextPath *parentNodeTextPath;
/**
The width of the line connecting the data label to the point. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.

**Try it**

* [Custom connector width and color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/connector-styles)
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
Whether to position data labels alternately. For example, if `distance` is set equal to `100`, then data labels will be positioned alternately (on both sides of the point) at a distance of 100px.

**Try it**

* [Alternate disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/alternate-disabled)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternate;
/**
The color of the line connecting the data label to the point. The default color is the same as the point's color. In styled mode, the connector stroke is given in the `.highcharts-data-label-connector` class.

**Try it**

* [Custom connector width and color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/connector-styles)
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
@property(nonatomic, readwrite) NSNumber *width;
/**
A pixel value defining the distance between the data label and the point. Negative numbers puts the label on top of the point.
*/
@property(nonatomic, readwrite) NSNumber *distance;
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _links_ in the networkgraph. (Default: `undefined`)
*/
@property(nonatomic, readwrite) NSString *linkFormat;
/**
Callback to format data labels for _links_ in the sankey diagram. The `linkFormat` option takes precedence over the `linkFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *linkFormatter;
/**
Options for a _link_ label text which should follow link connection. Border and background are disabled for a label that follows a path. **Note:** Only SVG-based renderer supports this option. Setting `useHTML` to true will disable this option.
*/
@property(nonatomic, readwrite) HILinkTextPath *linkTextPath;
/**
Alignment method for data labels. Possible values are: - `toPlotEdges`: Each label touches the nearest vertical edge of  the plot area. - `connectors`: Connectors have the same x position and the  widest label of each half (left & right) touches the nearest  vertical edge of the plot area.

**Try it**

* [alignTo: connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-connectors/)
* [alignTo: plotEdges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-plotedges/)
*/
@property(nonatomic, readwrite) NSString *alignTo;
/**
Whether to render the connector as a soft arc or a line with sharp break. Works only if `connectorShape` equals to `fixedOffset`.

**Try it**

* [Soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-true/)
* [Non soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softConnector;
/**
The distance from the data label to the connector. Note that data labels also have a default `padding`, so in order for the connector to touch the text, the `padding` must also be 0.

**Try it**

* [No padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorpadding/)
*/
@property(nonatomic, readwrite) NSNumber *connectorPadding;
/**
Specifies the method that is used to generate the connector path. Highcharts provides 3 built-in connector shapes: `'fixedOffset'` (default), `'straight'` and `'crookedLine'`. Using `'crookedLine'` has the most sense (in most of the cases) when `'alignTo'` is set. Users can provide their own method by passing a function instead of a String. 3 arguments are passed to the callback: - Object that holds the information about the coordinates of the  label (`x` & `y` properties) and how the label is located in  relation to the pie (`alignment` property). `alignment` can by  one of the following:  `'left'` (pie on the left side of the data label),  `'right'` (pie on the right side of the data label) or  `'center'` (data label overlaps the pie). - Object that holds the information about the position of the  connector. Its `touchingSliceAt` porperty tells the position  of the place where the connector touches the slice. - Data label options The function has to return an SVG path definition in array form (see the example).

**Try it**

* [connectorShape is a String](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-string/)
* [connectorShape is a function](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-function/)
*/
@property(nonatomic, readwrite) NSString *connectorShape;
/**
Works only if `connectorShape` is `'crookedLine'`. It defines how far from the vertical plot edge the coonnector path should be crooked.

**Try it**

* [crookDistance set to 90%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-crookdistance/)
*/
@property(nonatomic, readwrite) NSString *crookDistance;
/**
Presentation attributes for the text path.
*/
@property(nonatomic, readwrite) HISVGAttributes *attributes;
@property(nonatomic, readwrite) NSString *parentNodeFormat;

-(NSDictionary *)getParams;

@end
