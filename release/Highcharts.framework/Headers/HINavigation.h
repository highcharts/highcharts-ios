/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HINavigationButtonOptions.h"


/**
* description: A collection of options for buttons and menus appearing in the exporting module.
*/
@interface HINavigation: HIChartsJSONSerializable

/**
* description: CSS styles for the hover state of the individual items within the popup menu appearing by  default when the export icon is clicked. The menu items are rendered in HTML.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemhoverstyle/ : Bold text on hover
* default: { "background": "#335cad", "color": "#ffffff" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *menuItemHoverStyle;
/**
* description: CSS styles for the popup menu appearing by default when the export icon is clicked. This menu is rendered in HTML.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/menustyle/ : Light gray menu background
* default: { "border": "1px solid #999999", "background": "#ffffff", "padding": "5px 0" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *menuStyle;
/**
* description: A collection of options for buttons appearing in the exporting module.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the buttons are styled with the .highcharts-contextbutton and .highcharts-button-symbol class.
*/
@property(nonatomic, readwrite) HINavigationButtonOptions *buttonOptions;
/**
* description: CSS styles for the individual items within the popup menu appearing by  default when the export icon is clicked. The menu items are rendered in HTML.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/navigation/menuitemstyle/ : Add a grey stripe to the left
* default: { "padding": "0.5em 1em", "color": "#333333", "background": "none" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *menuItemStyle;

-(NSDictionary *)getParams;

@end
