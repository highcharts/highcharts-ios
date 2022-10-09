/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIButtonOptions.h"
#import "HIAnnotationsOptions.h"
#import "HIBreadcrumbs.h"
#import "HIBindings.h"
#import "HIEvents.h"
#import "HIPopup.h"
#import "HIColor.h"
#import "HIAnimationOptionsObject.h"
#import "HICSSObject.h"


/**
A collection of options for buttons and menus appearing in the exporting module or in Stock Tools.
*/
@interface HINavigation: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIButtonOptions *buttonOptions;
/**
Additional options to be merged into all annotations.

**Try it**

* [Set red color of all line annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/stock/stocktools/navigation-annotation-options)
*/
@property(nonatomic, readwrite) HIAnnotationsOptions *annotationsOptions;
/**
A CSS class name where all bindings will be attached to. Multiple charts on the same page should have separate class names to prevent duplicating events. Default value of versions < 7.0.4 `highcharts-bindings-wrapper`
*/
@property(nonatomic, readwrite) NSString *bindingsClassName;
/**
Options for breadcrumbs. Breadcrumbs general options are defined in `navigation.breadcrumbs`. Specific options for drilldown are set in `drilldown.breadcrumbs` and for tree-like series traversing, in `plotOptions[series].breadcrumbs`.
*/
@property(nonatomic, readwrite) HIBreadcrumbs *breadcrumbs;
/**
Bindings definitions for custom HTML buttons. Each binding implements simple event-driven interface: - `className`: classname used to bind event to - `init`: initial event, fired on button click - `start`: fired on first click on a chart - `steps`: array of sequential events fired one after another on each  of users clicks - `end`: last event to be called after last step event
*/
@property(nonatomic, readwrite) HIBindings *bindings;
/**
Events to communicate between Stock Tools and custom GUI.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
Path where Highcharts will look for icons. Change this to use icons from a different server.
*/
@property(nonatomic, readwrite) NSString *iconsURL;
/**
Text styles for the legend page navigation.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The color of the inactive up or down arrow in the legend page navigation. .

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *inactiveColor;
/**
Whether to enable the legend navigation. In most cases, disabling the navigation results in an unwanted overflow. See also the [adapt chart to legend](https://www.highcharts.com/products/plugin-registry/single/8/Adapt-Chart-To-Legend) plugin for a solution to extend the chart height to make room for the legend, optionally in exported charts only.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The pixel size of the up and down arrows in the legend paging navigation.

**Defaults to** `12`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) NSNumber *arrowSize;
/**
How to animate the pages when navigating up or down. A value of `true` applies the default navigation given in the `chart.animation` option. Additional options can be given as an object containing values for easing and duration.

**Defaults to** `true`.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
The color for the active up or down arrow in the legend page navigation.

**Try it**

* [Legend page navigation demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/navigation/)
*/
@property(nonatomic, readwrite) HIColor *activeColor;
/**
Translations for all field names used in popup.
*/
@property(nonatomic, readwrite) HIPopup *popup;

-(NSDictionary *)getParams;

@end
