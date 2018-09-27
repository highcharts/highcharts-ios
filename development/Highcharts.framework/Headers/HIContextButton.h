/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HITheme.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
Options for the export button. In styled mode, export button styles can be applied with the `.highcharts-contextbutton` class.
*/
@interface HIContextButton: HIChartsJSONSerializable

/**
See `navigation.buttonOptions.symbolFill`.

**Defaults to** `#666666`.

**Try it**

* [Blue symbol stroke for one of the buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolfill/)
*/
@property(nonatomic, readwrite) HIColor *symbolFill;
/**
The symbol for the button. Points to a definition function in the `Highcharts.Renderer.symbols` collection. The default `exportIcon` function is part of the exporting module.

**Accepted values:** `["exportIcon", "circle", "square", "diamond", "triangle", "triangle-down", "menu"]`.

**Defaults to** `menu`.

**Try it**

* [Use a circle for symbol](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol/)
* [Custom shape as symbol](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol-custom/)
*/
@property(nonatomic, readwrite) NSString *symbol;
/**
The class name of the context button.
*/
@property(nonatomic, readwrite) NSString *className;
/**
A click handler callback to use on the button directly instead of the popup menu.

**Try it**

* [Skip the menu and export the chart directly](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-onclick/)
*/
@property(nonatomic, readwrite) HIFunction *onclick;
/**
The key to a `lang` option setting that is used for the button's title tooltip. When the key is `contextButtonTitle`, it refers to `lang.contextButtonTitle` that defaults to "Chart context menu".
*/
@property(nonatomic, readwrite) NSString *titleKey;
/**
The horizontal position of the button relative to the `align` option.

**Defaults to** `-10`.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The class name of the menu appearing from the button.
*/
@property(nonatomic, readwrite) NSString *menuClassName;
/**
A collection of strings pointing to config options for the menu items. The config options are defined in the `menuItemDefinitions` option. By default, there is the "Print" menu item plus one menu item for each of the available export types. Defaults to  [  'printChart',  'separator',  'downloadPNG',  'downloadJPEG',  'downloadPDF',  'downloadSVG' ] 

**Try it**

* [Menu item definitions](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/menuitemdefinitions/)
*/
@property(nonatomic, readwrite) NSArray *menuItems;
/**
The vertical alignment of the buttons. Can be one of "top", "middle" or "bottom".

**Accepted values:** `["top", "middle", "bottom"]`.

**Defaults to** `top`.

**Try it**

* [Buttons at lower right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
A text string to add to the individual button.

**Defaults to** `null`.

**Try it**

* [Full text button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text/)
* [Combined symbol and text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text-symbol/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
Alignment for the buttons.

**Accepted values:** `["left", "center", "right"]`.

**Defaults to** `right`.

**Try it**

* [Center aligned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-align/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
Whether to enable buttons.

**Defaults to** `true`.

**Try it**

* [Exporting module loaded but buttons disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
A configuration object for the button theme. The object accepts SVG properties like `stroke-width`, `stroke` and `fill`. Tri-state button styles are supported by the `states.hover` and `states.select` objects.

**Try it**

* [Theming the buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-theme/)
*/
@property(nonatomic, readwrite) HITheme *theme;
/**
Pixel height of the buttons.

**Defaults to** `22`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
The pixel width of the button.

**Defaults to** `24`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
The pixel spacing between buttons.

**Defaults to** `3`.
*/
@property(nonatomic, readwrite) NSNumber *buttonSpacing;
/**
The pixel size of the symbol on the button.

**Defaults to** `14`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolSize;
/**
The vertical offset of the button's position relative to its `verticalAlign`.

**Defaults to** `0`.

**Try it**

* [Buttons at lower right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The color of the symbol's stroke or line.

**Defaults to** `#666666`.

**Try it**

* [Blue symbol stroke](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolstroke/)
*/
@property(nonatomic, readwrite) HIColor *symbolStroke;
/**
The y position of the center of the symbol inside the button.

**Defaults to** `10.5`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolY;
/**
The x position of the center of the symbol inside the button.

**Defaults to** `12.5`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolX;
/**
The pixel stroke width of the symbol on the button.

**Defaults to** `1`.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolStrokeWidth;

-(NSDictionary *)getParams;

@end
