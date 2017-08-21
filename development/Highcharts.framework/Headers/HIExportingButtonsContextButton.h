/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Options for the export button.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, export button styles can be applied with the .highcharts-contextbutton class.
*/
@interface HIExportingButtonsContextButton: HIChartsJSONSerializable

/**
* description: The pixel stroke width of the symbol on the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *symbolStrokeWidth;
/**
* description: The y position of the center of the symbol inside the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 10.5
*/
@property(nonatomic, readwrite) NSNumber *symbolY;
/**
* description: Alignment for the buttons.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-align/ : Center aligned
* accepted values: ["left", "center", "right"]
* default: right
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: A text string to add to the individual button. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text/ : Full text button, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text-symbol/ : combined symbol and text 
* default: null
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: The vertical offset of the button's position relative to its verticalAlign.			 .
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/ : Buttons at lower right
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The horizontal position of the button relative to the align
 option.
* demo:  
* default: -10
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: Whether to enable buttons.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-enabled/ : Exporting module loaded but buttons disabled
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The vertical alignment of the buttons. Can be one of "top", "middle" or "bottom".
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/ : Buttons at lower right
* accepted values: ["top", "middle", "bottom"]
* default: top
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: Pixel height of the buttons.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 20
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
* description: The x position of the center of the symbol inside the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 12.5
*/
@property(nonatomic, readwrite) NSNumber *symbolX;
/**
* description: See navigation.buttonOptions => symbolFill.
* default: #666666
*/
@property(nonatomic, readwrite) HIColor *symbolFill;
/**
* description: The symbol for the button. Points to a definition function in the  Highcharts.Renderer.symbols collection. The default exportIcon function is part of the exporting module.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol/ : Use a circle for symbol
* accepted values: ["circle", "square", "diamond", "triangle", "triangle-down", "menu"]
* default: menu
*/
@property(nonatomic, readwrite) NSString *symbol;
/**
* description: The color of the symbol's stroke or line.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolstroke/ : Blue symbol stroke
* default: #666666
*/
@property(nonatomic, readwrite) HIColor *symbolStroke;
/**
* description: The pixel size of the symbol on the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 14
*/
@property(nonatomic, readwrite) NSNumber *symbolSize;
/**
* description: A configuration object for the button theme. The object accepts SVG properties like stroke-width, stroke and fill. Tri-state button styles are supported by the states.hover and states.select objects.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-theme/ : Theming the buttons
*/
@property(nonatomic, readwrite) id theme;
/**
* description: A click handler callback to use on the button directly instead of the popup menu.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-onclick/ : Skip the menu and export the chart directly
*/
@property(nonatomic, readwrite) NSString /* Function */ *onclick;
/**
* description: A collection of config options for the menu items. Each options object consists of a text option which is a string to show in the menu item, as well as an onclick parameter which is a callback function to run on click. By default, there is the "Print" menu item plus one menu item for each of the available export types. Menu items can be customized by defining a new array of items and assigning  null to unwanted positions (see override example below).
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-onclick/ : Skip the menu and export the chart directly,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-menuitems/ : override the menu items
*/
@property(nonatomic, readwrite) NSArray *menuItems;
/**
* description: The pixel width of the button.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons
* default: 24
*/
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
