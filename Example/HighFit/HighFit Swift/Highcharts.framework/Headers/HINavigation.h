/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIButtonOptions.h"
#import "HIMenuItemStyle.h"
#import "HIMenuStyle.h"
#import "HIMenuItemHoverStyle.h"
#import "HIColor.h"


/**
* description: A collection of options for buttons and menus appearing in the exporting module.
*/
@interface HINavigation: HIChartsJSONSerializable

/**
* description: Whether to enable the legend navigation. In most cases, disabling
the navigation results in an unwanted overflow.
See also the http://www.highcharts.com/plugin-
registry/single/8/Adapt-Chart-To-Legend : adapt chart to legend plugin for a solution to
extend the chart height to make room for the legend, optionally in
exported charts only.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: How to animate the pages when navigating up or down. A value of true
applies the default navigation given in the chart.animation option.
Additional options can be given as an object containing values for
easing and duration.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : Legend page navigation demonstrated
* default: true
*/
@property(nonatomic, readwrite) id /* Bool, id */ animation;
/**
* description: The color of the inactive up or down arrow in the legend page
navigation. .

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : Legend page navigation demonstrated
* default: #cccccc
*/
@property(nonatomic, readwrite) HIColor *inactiveColor;
/**
* description: The pixel size of the up and down arrows in the legend paging
navigation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : Legend page navigation demonstrated
* default: 12
*/
@property(nonatomic, readwrite) NSNumber *arrowSize;
/**
* description: Text styles for the legend page navigation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : Legend page navigation demonstrated
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: The color for the active up or down arrow in the legend page navigation.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/ : Legend page navigation demonstrated
* default: #003399
*/
@property(nonatomic, readwrite) HIColor *activeColor;
/**
* description: A collection of options for buttons appearing in the exporting module.
In styled mode, the buttons are styled with the .highcharts-contextbutton and .highcharts-button-symbol class.
*/
@property(nonatomic, readwrite) HIButtonOptions *buttonOptions;
/**
* description: CSS styles for the individual items within the popup menu appearing
by default when the export icon is clicked. The menu items are rendered
in HTML.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemstyle/ : Add a grey stripe to the left

* default: { "padding": "0.5em 1em", "color": "#333333", "background": "none" }
*/
@property(nonatomic, readwrite) HIMenuItemStyle *menuItemStyle;
/**
* description: CSS styles for the popup menu appearing by default when the export
icon is clicked. This menu is rendered in HTML.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menustyle/ : Light gray menu background

* default: { "border": "1px solid #999999", "background": "#ffffff", "padding": "5px 0" }
*/
@property(nonatomic, readwrite) HIMenuStyle *menuStyle;
/**
* description: CSS styles for the hover state of the individual items within the
popup menu appearing by default when the export icon is clicked.
 The menu items are rendered in HTML.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/ : Bold text on hover

* default: { "background": "#335cad", "color": "#ffffff" }
*/
@property(nonatomic, readwrite) HIMenuItemHoverStyle *menuItemHoverStyle;

-(NSDictionary *)getParams;

@end
