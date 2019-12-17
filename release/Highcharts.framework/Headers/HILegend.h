/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAccessibility.h"
#import "HITitle.h"
#import "HIBubbleLegend.h"
#import "HINavigation.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HICSSObject.h"
#import "HISeries.h"


/**
The legend is a box containing a symbol and name for each series item or point item in the chart. Each series (or points in case of pie charts) is represented by a symbol and its name in the legend. It is possible to override the symbol creator function and create [custom legend symbols](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/studies/legend-custom-symbol/).
*/
@interface HILegend: HIChartsJSONSerializable

/**
The border radius of the symbol for series types that use a rectangle in the legend. Defaults to half the `symbolHeight`.

**Try it**

* [Round symbols](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolradius/)
*/
@property(nonatomic, readwrite) NSNumber *symbolRadius;
/**
The border corner radius of the legend.

**Try it**

* [Square by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/borderradius-default/)
* [5px rounded](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/borderradius-round/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Whether to show the symbol on the right side of the text rather than the left side. This is common in Arabic and Hebraic.

**Defaults to** `false`.

**Try it**

* [Symbol to the right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/rtl/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *rtl;
/**
Accessibility options for the legend. Requires the Accessibility module.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
/**
When this is true, the legend symbol width will be the same as the symbol height, which in turn defaults to the font size of the legend items.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *squareSymbol;
/**
The width for each legend item. By default the items are laid out successively. In a `horizontal layout`, if the items are laid out across two rows or more, they will be vertically aligned depending on the `legend.alignColumns` option.

**Try it**

* [Undefined by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemwidth-default/)
* [80 for aligned legend items](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemwidth-80/)
*/
@property(nonatomic, readwrite) NSNumber *itemWidth;
/**
The pixel padding between the legend item symbol and the legend item text.

**Try it**

* [Greater symbol width and padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolpadding/)
*/
@property(nonatomic, readwrite) NSNumber *symbolPadding;
/**
When the legend is floating, the plot area ignores it and is allowed to be placed below it.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/floating-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/floating-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
The pixel width of the legend item symbol. When the `squareSymbol` option is set, this defaults to the `symbolHeight`, otherwise 16.

**Try it**

* [Greater symbol width and padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolwidth/)
*/
@property(nonatomic, readwrite) NSNumber *symbolWidth;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the legend item texts. Prior to 4.1.7, when using HTML, `legend.navigation` was disabled.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
The color of the drawn border around the legend.

**Try it**

* [Brown border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The layout of the legend items. Can be one of `horizontal` or `vertical` or `proximate`. When `proximate`, the legend items will be placed as close as possible to the graphs they're representing, except in inverted charts or when the legend position doesn't allow it.

**Accepted values:** `["horizontal", "vertical", "proximate"]`.

**Try it**

* [Horizontal by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-horizontal/)
* [Vertical](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-vertical/)
* [Labels proximate to the data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-proximate)
*/
@property(nonatomic, readwrite) NSString *layout;
/**
A title to be added on top of the legend.

**Try it**

* [Legend title](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/title/)
*/
@property(nonatomic, readwrite) HITitle *title;
/**
The width of the legend box. If a number is set, it translates to pixels. Since v7.0.2 it allows setting a percent string of the full chart width, for example `40%`. Defaults to the full chart width from legends below or above the chart, half the chart width for legends to the left and right.

**Try it**

* [Aligned to the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/width/)
* [A percent of the chart width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/width-percent/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ width;
/**
The pixel bottom margin for each legend item.

**Defaults to** `0`.

**Try it**

* [Padding and item margins demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/)
*/
@property(nonatomic, readwrite) NSNumber *itemMarginBottom;
/**
The background color of the legend.

**Try it**

* [Yellowish background](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/backgroundcolor/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
The pixel top margin for each legend item.

**Defaults to** `0`.

**Try it**

* [Padding and item margins demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/)
*/
@property(nonatomic, readwrite) NSNumber *itemMarginTop;
/**
The bubble legend is an additional element in legend which presents the scale of the bubble series. Individual bubble ranges can be defined by user or calculated from series. In the case of automatically calculated ranges, a 1px margin of error is permitted.
*/
@property(nonatomic, readwrite) HIBubbleLegend *bubbleLegend;
/**
A [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) for each legend label. Available variables relates to properties on the series, or the point in case of pies.

**Defaults to** `{name}`.
*/
@property(nonatomic, readwrite) NSString *labelFormat;
/**
CSS styles for each legend item. Only a subset of CSS is supported, notably those options related to text. The default `textOverflow` property makes long texts truncate. Set it to `undefined` to wrap text instead. A `width` property can be added to control the text width.

**Defaults to** `{"color": "#333333", "cursor": "pointer", "fontSize": "12px", "fontWeight": "bold", "textOverflow": "ellipsis"}`.

**Try it**

* [Bold black text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *itemStyle;
/**
Whether to reverse the order of the legend items compared to the order of the series or points as defined in the configuration object.

**Defaults to** `false`.

**Try it**

* [Stacked bar with reversed legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/reversed/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
Default styling for the checkbox next to a legend item when `showCheckbox` is true.

**Defaults to** `{"width": "13px", "height": "13px", "position":"absolute"}`.
*/
@property(nonatomic, readwrite) HICSSObject *itemCheckboxStyle;
/**
The inner padding of the legend box.

**Defaults to** `8`.

**Try it**

* [Padding and item margins demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/)
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
The vertical alignment of the legend box. Can be one of `top`, `middle` or `bottom`. Vertical position can be further determined by the `y` option. In the case that the legend is aligned in a corner position, the `layout` option will determine whether to place it above/below or on the side of the plot area. When the `layout` option is `proximate`, the `verticalAlign` option doesn't apply.

**Try it**

* [Legend 100px from the top of the chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/verticalalign/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
Whether to apply a drop shadow to the legend. A `backgroundColor` also needs to be applied for this to take effect. The shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Try it**

* [White background and drop shadow](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/shadow/)
*/
@property(nonatomic, readwrite) HICSSObject *shadow;
/**
CSS styles for each legend item in hover mode. Only a subset of CSS is supported, notably those options related to text. Properties are inherited from `style` unless overridden here.

**Defaults to** `{"color": "#000000"}`.

**Try it**

* [Red on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemhoverstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *itemHoverStyle;
/**
In a legend with horizontal layout, the itemDistance defines the pixel distance between each item.

**Defaults to** `20`.

**Try it**

* [50px item distance](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-horizontal/)
*/
@property(nonatomic, readwrite) NSNumber *itemDistance;
/**
Options for the paging or navigation appearing when the legend is overflown. Navigation works well on screen, but not in static exported images. One way of working around that is to [increase the chart height in export](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation-enabled-false/).
*/
@property(nonatomic, readwrite) HINavigation *navigation;
/**
The horizontal alignment of the legend box within the chart area. Valid values are `left`, `center` and `right`. In the case that the legend is aligned in a corner position, the `layout` option will determine whether to place it above/below or on the side of the plot area.

**Try it**

* [Legend at the right of the chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/align/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
Enable or disable the legend. There is also a series-specific option, `showInLegend`, that can hide the series from the legend. In some series types this is `false` by default, so it must set to `true` in order to show the legend for the series.

**Try it**

* [Legend disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/enabled-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Maximum pixel height for the legend. When the maximum height is extended, navigation will show.
*/
@property(nonatomic, readwrite) NSNumber *maxHeight;
/**
CSS styles for each legend item when the corresponding series or point is hidden. Only a subset of CSS is supported, notably those options related to text. Properties are inherited from `style` unless overridden here.

**Defaults to** `{"color": "#cccccc"}`.

**Try it**

* [Darker gray color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemhiddenstyle/)
*/
@property(nonatomic, readwrite) HICSSObject *itemHiddenStyle;
/**
If the `layout` is `horizontal` and the legend items span over two lines or more, whether to align the items into vertical columns. Setting this to `false` makes room for more items, but will look more messy.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alignColumns;
/**
The pixel height of the symbol for series types that use a rectangle in the legend. Defaults to the font size of legend items.
*/
@property(nonatomic, readwrite) NSNumber *symbolHeight;
/**
The width of the drawn border around the legend.

**Defaults to** `0`.

**Try it**

* [2px border width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Callback function to format each of the series' labels. The `this` keyword refers to the series object, or the point object in case of pie charts. By default the series or point name is printed.

**Try it**

* [Add text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/labelformatter/)
*/
@property(nonatomic, readwrite) HIFunction *labelFormatter;
/**
The vertical offset of the legend relative to it's vertical alignment `verticalAlign` within chart.spacingTop and chart.spacingBottom. Negative y moves it up, positive y moves it down.

**Try it**

* [Legend 100px from the top of the chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/verticalalign/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The x offset of the legend relative to its horizontal alignment `align` within chart.spacingLeft and chart.spacingRight. Negative x moves it to the left, positive x moves it to the right.

**Try it**

* [Aligned to the plot area](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/width/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
If the plot area sized is calculated automatically and the legend is not floating, the legend margin is the space between the legend and the axis labels or plot area.

**Defaults to** `12`.

**Try it**

* [12 pixels by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/margin-default/)
* [30 pixels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/margin-30/)
*/
@property(nonatomic, readwrite) NSNumber *margin;
@property(nonatomic, readwrite) NSString *legendLabel;
@property(nonatomic, readwrite) NSString *legendItem;

-(NSDictionary *)getParams;

/**
 Set the legend item text.
 @param item The item for which to update the text in the legend.
 */
-(void)setPointText:(HIPoint *)item;

/**
 Set the legend item text.
 @param item The item for which to update the text in the legend.
 */
-(void)setSeriesText:(HISeries *)item;

/**
 Update the legend with new options. Equivalent to running `chart.update` with a legend configuration option.
 
 **Fires:**
 
 * Highcharts.Legends#event:afterUpdate
 
 **Try it**
 
 * [Legend update](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/legend-update/)
 
 @param options Legend options.
 */
-(void)update:(HILegend *)options;

/**
 Update the legend with new options. Equivalent to running `chart.update` with a legend configuration option.
 
 **Fires:**
 
 * Highcharts.Legends#event:afterUpdate
 
 **Try it**
 
 * [Legend update](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/legend-update/)
 
 @param options Legend options.
 @param redraw Whether to redraw the chart after the axis is altered. If doing more operations on the chart, it is a good idea to set redraw to false and call [Highcharts.Chart#redraw](https://api.highcharts.com/class-reference/Highcharts.Chart.html#redraw) after. Whether to redraw the chart.
 */
-(void)update:(HILegend *)options redraw:(NSNumber /* Bool */ *)redraw;

@end
