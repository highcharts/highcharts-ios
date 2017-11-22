/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HITheme.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: Options for the export button.
In styled mode, export button styles can be applied with the
.highcharts-contextbutton class.
*/
@interface HIContextButton: HIChartsJSONSerializable

/**
* description: The pixel stroke width of the symbol on the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 1
*/
@property(nonatomic, readwrite) NSNumber *symbolStrokeWidth;
/**
* description: The vertical alignment of the buttons. Can be one of "top", "middle"
or "bottom".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/ : Buttons at lower right

* accepted values: ["top", "middle", "bottom"]
* default: top
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: Alignment for the buttons.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-align/ : Center aligned

* accepted values: ["left", "center", "right"]
* default: right
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: The pixel size of the symbol on the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 14
*/
@property(nonatomic, readwrite) NSNumber *symbolSize;
/**
* description: The pixel width of the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 24
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: The pixel spacing between buttons.
* default: 3
*/
@property(nonatomic, readwrite) NSNumber *buttonSpacing;
/**
* description: The class name of the context button.
* default: highcharts-contextbutton
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The vertical offset of the button's position relative to its
verticalAlign.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/ : Buttons at lower right

* default: 0
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The horizontal position of the button relative to the align
option.
* default: -10
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The symbol for the button. Points to a definition function in
the Highcharts.Renderer.symbols collection. The default exportIcon
function is part of the exporting module.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol/ : Use a circle for symbol

* accepted values: ["circle", "square", "diamond", "triangle", "triangle-down", "menu"]
* default: menu
*/
@property(nonatomic, readwrite) NSString *symbol;
/**
* description: Whether to enable buttons.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-enabled/ : Exporting module loaded but buttons disabled

* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: A click handler callback to use on the button directly instead of
the popup menu.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-onclick/ : Skip the menu and export the chart directly

*/
@property(nonatomic, readwrite) HIFunction *onclick;
/**
* description: See navigation.buttonOptions.symbolFill.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolfill/ : Blue symbol stroke for one of the buttons

* default: #666666
*/
@property(nonatomic, readwrite) HIColor *symbolFill;
/**
* description: The y position of the center of the symbol inside the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 10.5
*/
@property(nonatomic, readwrite) NSNumber *symbolY;
/**
* description: The color of the symbol's stroke or line.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolstroke/ : Blue symbol stroke

* default: #666666
*/
@property(nonatomic, readwrite) HIColor *symbolStroke;
/**
* description: Pixel height of the buttons.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 22
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
* description: A text string to add to the individual button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text/ : Full text button
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text-symbol/ : Combined symbol and text


* default: null
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: The class name of the menu appearing from the button.
* default: highcharts-contextmenu
*/
@property(nonatomic, readwrite) NSString *menuClassName;
/**
* description: The key to a lang option setting that is used for the
buttons title tooltip. When the key iscontextButtonTitle`, it
refers to lang.contextButtonTitle
that defaults to "Chart context menu".
* default: contextButtonTitle
*/
@property(nonatomic, readwrite) NSString *_titleKey;
/**
* description: The x position of the center of the symbol inside the button.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/ : Bigger buttons

* default: 12.5
*/
@property(nonatomic, readwrite) NSNumber *symbolX;
/**
* description: A configuration object for the button theme. The object accepts
SVG properties like stroke-width, stroke and fill. Tri-state
button styles are supported by the states.hover and states.select
objects.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-theme/ : Theming the buttons

*/
@property(nonatomic, readwrite) HITheme *theme;
/**
* description: A collection of strings pointing to config options for the menu
items. The config options are defined in the
menuItemDefinitions option.
By default, there is the "Print" menu item plus one menu item
for each of the available export types. 
Defaults to 

[
    'printChart',
    'separator',
    'downloadPNG',
    'downloadJPEG',
    'downloadPDF',
    'downloadSVG'
]

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/menuitemdefinitions/ : Menu item definitions

*/
@property(nonatomic, readwrite) NSArray *menuItems;

-(NSDictionary *)getParams;

@end
