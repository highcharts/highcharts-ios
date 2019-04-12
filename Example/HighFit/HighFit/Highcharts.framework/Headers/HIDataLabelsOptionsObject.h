/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"
#import "HICSSObject.h"


/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names.
*/
@interface HIDataLabelsOptionsObject: HIChartsJSONSerializable

/**
The alignment of the data label compared to the point. If `right`, the right side of the label should be touching the point. For points with an extent, like columns, the alignments also dictates how to align it inside the box, as given with the `inside` option. Can be one of `left`, `center` or `right`.
*/
@property(nonatomic, readwrite) NSString *align;
/**
Whether to allow data labels to overlap. To make the labels less sensitive for overlapping, the `dataLabels.padding` can be set to 0.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
The background color or gradient for the data label.
*/
@property(nonatomic, readwrite) NSString *backgroundColor;
/**
The border color for the data label. Defaults to `undefined`.
*/
@property(nonatomic, readwrite) NSString *borderColor;
/**
The border radius in pixels for the data label.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
The border width in pixels for the data label.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
A class name for the data label. Particularly in styled mode, this can be used to give each series' or point's data label unique styling. In addition to this option, a default color class name is added so that we can give the labels a contrast text shadow.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The text color for the data labels. Defaults to `undefined`. For certain series types, like column or map, the data labels can be drawn inside the points. In this case the data label will be drawn with maximum contrast by default. Additionally, it will be given a `text-outline` style with the opposite color, to further increase the contrast. This can be overridden by setting the `text-outline` style to `none` in the `dataLabels.style` option.
*/
@property(nonatomic, readwrite) NSString *color;
/**
Whether to hide data labels that are outside the plot area. By default, the data label is moved inside the plot area according to the `overflow` option.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
Whether to defer displaying the data labels until the initial series animation has finished.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *defer;
/**
Enable or disable the data labels.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
A declarative filter to control of which data labels to display. The declarative filter is designed for use when callback functions are not available, like when the chart options require a pure JSON structure or for use with graphical editors. For programmatic control, use the `formatter` instead, and return `undefined` to disable a single data label.
*/
@property(nonatomic, readwrite) id filter;
/**
A [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) for the data label. Available variables are the same as for `formatter`.
*/
@property(nonatomic, readwrite) NSString *format;
/**
Callback JavaScript function to format the data label. Note that if a `format` is defined, the format takes precedence and the formatter is ignored.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
/**
For points with an extent, like columns or map areas, whether to align the data label inside the box or to the actual value point. Defaults to `false` in most cases, `true` in stacked columns.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *inside;
/**
Format for points with the value of null. Works analogously to `format`. `nullFormat` can be applied only to series which support displaying null points.
*/
@property(nonatomic, readwrite) id nullFormat;
/**
Callback JavaScript function that defines formatting for points with the value of null. Works analogously to `formatter`. `nullPointFormatter` can be applied only to series which support displaying null points.
*/
@property(nonatomic, readwrite) HIFunction *nullFormatter;
/**
How to handle data labels that flow outside the plot area. The default is `"justify"`, which aligns them inside the plot area. For columns and bars, this means it will be moved inside the bar. To display data labels outside the plot area, set `crop` to `false` and `overflow` to `"allow"`.
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
When either the `borderWidth` or the `backgroundColor` is set, this is the padding within the box.
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
Text rotation in degrees. Note that due to a more complex structure, backgrounds, borders and padding will be lost on a rotated data label.
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
The shadow of the box. Works best with `borderWidth` or `backgroundColor`. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
The name of a symbol to use for the border around the label. Symbols are predefined functions on the Renderer object.
*/
@property(nonatomic, readwrite) NSString *shape;
/**
Styles for the label. The default `color` setting is `"contrast"`, which is a pseudo color that Highcharts picks up and applies the maximum contrast to the underlying point item, for example the bar in a bar chart. The `textOutline` is a pseudo property that applies an outline of the given width with the given color, which by default is the maximum contrast to the text. So a bright text color will result in a black text outline for maximum readability on a mixed background. In some cases, especially with grayscale text, the text outline doesn't work well, in which cases it can be disabled by setting it to `"none"`. When `useHTML` is true, the `textOutline` will not be picked up. In this, case, the same effect can be acheived through the `text-shadow` CSS property. For some series types, where each point has an extent, like for example tree maps, the data label may overflow the point. There are two strategies for handling overflow. By default, the text will wrap to multiple lines. The other strategy is to set `style.textOverflow` to `ellipsis`, which will keep the text on one line plus it will break inside long words.
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
The vertical alignment of a data label. Can be one of `top`, `middle` or `bottom`. The default value depends on the data, for instance in a column chart, the label is above positive values and below negative values.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The x position offset of the label relative to the point in pixels.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The y position offset of the label relative to the point in pixels.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The Z index of the data labels. The default Z index puts it above the series. Use a Z index of 2 to display it behind the series.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
