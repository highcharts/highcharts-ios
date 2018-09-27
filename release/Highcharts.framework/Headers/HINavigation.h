/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMenuStyle.h"
#import "HIMenuItemStyle.h"
#import "HIButtonOptions.h"
#import "HIMenuItemHoverStyle.h"
#import "HIColor.h"


/**
A collection of options for buttons and menus appearing in the exporting module.
*/
@interface HINavigation: HIChartsJSONSerializable

/**
CSS styles for the popup menu appearing by default when the export icon is clicked. This menu is rendered in HTML.

**Defaults to** `{ "border": "1px solid #999999", "background": "#ffffff", "padding": "5px 0" }`.

**Try it**

* [Light gray menu background](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menustyle/)
*/
@property(nonatomic, readwrite) HIMenuStyle *menuStyle;
/**
CSS styles for the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML.

**Defaults to** `{ "padding": "0.5em 1em", "color": "#333333", "background": "none" }`.

**Try it**

* [Add a grey stripe to the left](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemstyle/)
*/
@property(nonatomic, readwrite) HIMenuItemStyle *menuItemStyle;
/**
A collection of options for buttons appearing in the exporting module. In styled mode, the buttons are styled with the `.highcharts-contextbutton` and `.highcharts-button-symbol` classes.
*/
@property(nonatomic, readwrite) HIButtonOptions *buttonOptions;
/**
CSS styles for the hover state of the individual items within the popup menu appearing by default when the export icon is clicked. The menu items are rendered in HTML.

**Defaults to** `{ "background": "#335cad", "color": "#ffffff" }`.

**Try it**

* [Bold text on hover](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/)
*/
@property(nonatomic, readwrite) HIMenuItemHoverStyle *menuItemHoverStyle;
/**
Text styles for the legend page navigation.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
The pixel size of the up and down arrows in the legend paging navigation.

**Defaults to** `12`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) NSNumber *arrowSize;
/**
Whether to enable the legend navigation. In most cases, disabling the navigation results in an unwanted overflow. See also the `adapt chart to legend` plugin for a solution to extend the chart height to make room for the legend, optionally in exported charts only.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The color of the inactive up or down arrow in the legend page navigation. .

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *inactiveColor;
/**
How to animate the pages when navigating up or down. A value of `true` applies the default navigation given in the `chart.animation` option. Additional options can be given as an object containing values for easing and duration.

**Defaults to** `true`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) id animation;
/**
The color for the active up or down arrow in the legend page navigation.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *activeColor;

-(NSDictionary *)getParams;

@end
