/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILegendNavigation.h"
#import "HILegendTitle.h"
#import "HIColor.h"


/**
* description: The legend is a box containing a symbol and name for each series item or point item in the chart. Each series (or points in case of pie charts) is represented by a symbol and its name in the legend.
It is also possible to override the symbol creator function and create http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/studies/legend-custom-symbol/ : custom legend symbols.
*/
@interface HILegend: HIChartsJSONSerializable

/**
* description: The width of the drawn border around the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/borderwidth/ : 2px border width
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Maximum pixel height for the legend. When the maximum height is extended, navigation will show.
*/
@property(nonatomic, readwrite) NSNumber *maxHeight;
/**
* description: The horizontal alignment of the legend box within the chart area. Valid values are left, center and right.
In the case that the legend is aligned in a corner position, the layout option will determine whether to place it above/below or on the side of the plot area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/align/ : Legend at the right of the chart
* accepted values: ["left", "center", "right"]
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html : use HTML to render the legend item texts. Prior to 4.1.7, when using HTML, legend.navigation was disabled.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: When this is true, the legend symbol width will be the same as the symbol height, which in turn defaults to the font size of the legend items.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *squareSymbol;
/**
* description: Callback function to format each of the series' labels. The this keyword refers to the series object, or the point object in case of pie charts. By default the series or point name is printed.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/labelformatter/ : Add text
*/
@property(nonatomic, readwrite) NSString /* Function */ *labelFormatter;
/**
* description: Whether to apply a drop shadow to the legend. A backgroundColor also needs to be applied for this to take effect. Since 2.3 the shadow can be an object configuration containing color, offsetX, offsetY, opacity and width.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/shadow/ : White background and drop shadow
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, Object */ shadow;
/**
* description: Whether to show the symbol on the right side of the text rather than the left side.  This is common in Arabic and Hebraic.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/rtl/ : Symbol to the right
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *rtl;
/**
* description: When the legend is floating, the plot area ignores it and is allowed to be placed below it.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/floating-false/ : False by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/floating-true/ : true.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
* description: If the plot area sized is calculated automatically and the legend is not floating, the legend margin is the  space between the legend and the axis labels or plot area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/margin-default/ : 12 pixels by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/margin-30/ : 30 pixels.
* default: 12
*/
@property(nonatomic, readwrite) NSNumber *margin;
/**
* description: Line height for the legend items. Deprecated as of 2.1. Instead, the line height for each  item can be set using itemStyle.lineHeight, and the padding between items using itemMarginTop and itemMarginBottom.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/lineheight/ : Setting padding.
* default: 16
*/
@property(nonatomic, readwrite) NSNumber *lineHeight;
/**
* description: Options for the paging or navigation appearing when the legend is overflown. Navigation works well on screen, but not in static exported images. One way of working around that is to http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation-enabled-false/ : increase the chart height in export.
*/
@property(nonatomic, readwrite) HILegendNavigation *navigation;
/**
* description: Enable or disable the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/enabled-false/ : Legend disabled
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The pixel bottom margin for each legend item.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/ : 
				Padding and item margins demonstrated
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *itemMarginBottom;
/**
* description: The vertical offset of the legend relative to it's vertical alignment verticalAlign within chart.spacingTop and chart.spacingBottom. Negative y moves it up, positive y moves it down.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/verticalalign/ : Legend 100px from the top of the chart
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The x offset of the legend relative to its horizontal alignment align within chart.spacingLeft and chart.spacingRight. Negative x moves it to the left, positive x moves it to the right. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/width/ : Aligned to the plot area
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: CSS styles for the legend area. In the 1.x versions the position of the legend area was determined by CSS. In 2.x, the position is determined by properties like  align, verticalAlign, x and y, but the styles are still parsed for backwards compatibility.
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: CSS styles for each legend item when the corresponding series or point is hidden. Only a subset of CSS is supported, notably those options related to text. Properties are inherited from style unless overridden here.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/itemhiddenstyle/ : Darker gray color
* default: { "color": "#cccccc" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *itemHiddenStyle;
/**
* description: The width for each legend item. This is useful in a horizontal layout with many items when you want the items to align vertically.  .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/itemwidth-default/ : Null by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/itemwidth-80/ : 80 for aligned legend items
*/
@property(nonatomic, readwrite) NSNumber *itemWidth;
/**
* description: The pixel top margin for each legend item.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/ : 
				Padding and item margins demonstrated
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *itemMarginTop;
/**
* description: The inner padding of the legend box.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/padding-itemmargin/ : 
				Padding and item margins demonstrated
* default: 8
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: A http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting : format string for each legend label. Available variables relates to properties on the series, or the point in case of pies.
* default: {name}
*/
@property(nonatomic, readwrite) NSString *labelFormat;
/**
* description: A title to be added on top of the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/title/ : Legend title
*/
@property(nonatomic, readwrite) HILegendTitle *title;
/**
* description: The pixel height of the symbol for series types that use a rectangle in the legend. Defaults to the font size of legend items.
*/
@property(nonatomic, readwrite) NSNumber *symbolHeight;
/**
* description: The pixel padding between the legend item symbol and the legend item text.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolpadding/ : Greater symbol width and padding
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *symbolPadding;
/**
* description: In a legend with horizontal layout, the itemDistance defines the pixel distance between each item. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-horizontal/ : 50px item distance
* default: 20
*/
@property(nonatomic, readwrite) NSNumber *itemDistance;
/**
* description: CSS styles for each legend item. Only a subset of CSS is supported, notably those options related to text.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/itemstyle/ : Bold black text
* default: { "color": "#333333", "cursor": "pointer", "fontSize": "12px", "fontWeight": "bold" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *itemStyle;
/**
* description: The background color of the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/backgroundcolor/ : Yellowish background
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: CSS styles for each legend item in hover mode. Only a subset of CSS is supported, notably those options related to text. Properties are inherited from style unless overridden here.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/itemhoverstyle/ : Red on hover
* default: { "color": "#000000" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *itemHoverStyle;
/**
* description: The color of the drawn border around the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/bordercolor/ : Brown border
* default: #999999
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The border radius of the symbol for series types that use a rectangle in the legend. Defaults to half the symbolHeight.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolradius/ : Round symbols
*/
@property(nonatomic, readwrite) NSNumber *symbolRadius;
/**
* description: The border corner radius of the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/borderradius-default/ : Square by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/borderradius-round/ : 5px rounded
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: Whether to reverse the order of the legend items compared to the order of the series or points as defined in the configuration object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/reversed/ : Stacked bar with reversed legend
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *reversed;
/**
* description: The width of the legend box.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/width/ : Aligned to the plot area
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: The vertical alignment of the legend box. Can be one of top, middle or  bottom. Vertical position can be further determined by the y option.
In the case that the legend is aligned in a corner position, the layout option will determine whether to place it above/below or on the side of the plot area.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/verticalalign/ : Legend 100px from the top of the chart
* accepted values: ["top", "middle", "bottom"]
* default: bottom
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: The pixel width of the legend item symbol. When the squareSymbol option is set, this defaults to the symbolHeight, otherwise 16.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/symbolwidth/ : Greater symbol width and padding
*/
@property(nonatomic, readwrite) NSNumber *symbolWidth;
/**
* description: The layout of the legend items. Can be one of "horizontal" or "vertical".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-horizontal/ : Horizontal by default,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/layout-vertical/ : vertical
* accepted values: ["horizontal", "vertical"]
* default: horizontal
*/
@property(nonatomic, readwrite) NSString *layout;

-(NSDictionary *)getParams;

@end
