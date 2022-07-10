/**
* (c) 2009-2021 Highsoft AS
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
*/
@property(nonatomic, readwrite) HIColor *symbolFill;
/**
A collection of strings pointing to config options for the menu items. The config options are defined in the `menuItemDefinitions` option. By default, there is the "View in full screen" and "Print" menu items, plus one menu item for each of the available export types.

**Defaults to** `["viewFullscreen", "printChart", "separator", "downloadPNG", "downloadJPEG", "downloadPDF", "downloadSVG"]`.

**Try it**

* [Menu item definitions](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/menuitemdefinitions/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *menuItems;
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
The symbol for the button. Points to a definition function in the `Highcharts.Renderer.symbols` collection. The default `menu` function is part of the exporting module. Possible values are "circle", "square", "diamond", "triangle", "triangle-down", "menu", "menuball" or custom shape.

**Try it**

* [Use a circle for symbol](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol/)
* [Custom shape as symbol](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-contextbutton-symbol-custom/)
*/
@property(nonatomic, readwrite) NSString *symbol;
/**
The vertical offset of the button's position relative to its `verticalAlign`.

**Defaults to** `0`.

**Try it**

* [Buttons at lower right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
A text string to add to the individual button.

**Defaults to** `null`.

**Try it**

* [Full text button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text/)
* [Combined symbol and text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text-symbol/)
*/
@property(nonatomic, readwrite) NSString *text;
@property(nonatomic, readwrite) HITheme *theme;
/**
Whether to enable buttons.

**Defaults to** `true`.

**Try it**

* [Exporting module loaded but buttons disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
