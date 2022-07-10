/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeparator.h"
#import "HIEvents.h"
#import "HISVGAttributes.h"
#import "HIFunction.h"
#import "HIBreadcrumbsAlignOptions.h"


/**
Options for the breadcrumbs, the navigation at the top leading the way up through the traversed levels.
*/
@interface HIBreadcrumbs: HIChartsJSONSerializable

/**
The z index of the breadcrumbs group.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
CSS styles for all breadcrumbs. In styled mode, the breadcrumbs buttons are styled by the `.highcharts-breadcrumbs-buttons .highcharts-button` rule with its different states.
*/
@property(nonatomic, readwrite) HISVGAttributes *style;
/**
A format string for the breadcrumbs button. Variables are enclosed by curly brackets. Available values are passed in the declared point options.

**Defaults to** `undefined`.

**Try it**

* [Display custom values in breadcrumb button.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/format)
*/
@property(nonatomic, readwrite) NSString *format;
/**
Whether to reverse the order of buttons. This is common in Arabic and Hebrew.

**Try it**

* [Breadcrumbs in RTL](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/rtl)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *rtl;
/**
Whether to use HTML to render the breadcrumbs items texts.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
A collection of attributes for the buttons. The object takes SVG attributes like `fill`, `stroke`, `stroke-width`, as well as `style`, a collection of CSS properties for the text. The object can also be extended with states, so you can set presentational options for `hover`, `select` or `disabled` button states.

**Try it**

* [Themed, single button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@property(nonatomic, readwrite) HISVGAttributes *buttonTheme;
/**
What box to align the button to. Can be either `plotBox` or `spacingBox`.

**Defaults to** `plotBox`.
*/
@property(nonatomic, readwrite) NSString *relativeTo;
/**
The default padding for each button and separator in each direction.
*/
@property(nonatomic, readwrite) NSNumber *buttonSpacing;
/**
Options object for Breadcrumbs separator.
*/
@property(nonatomic, readwrite) HISeparator *separator;
/**
Show full path or only a single button.

**Try it**

* [Single, styled button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showFullPath;
/**
Positioning for the button row. The breadcrumbs buttons will be aligned properly for the default chart layout (title, subtitle, legend, range selector) for the custom chart layout set the position properties.

**Try it**

* [Single, right aligned button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@property(nonatomic, readwrite) HIBreadcrumbsAlignOptions *position;
/**
When the breadcrumbs are floating, the plot area will not move to make space for it. By default, the chart will not make space for the buttons. This property won't work when positioned in the middle.

**Try it**

* [Floating button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/breadcrumbs/single-button)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *floating;
/**
Callback function to format the breadcrumb text from scratch.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIFunction *formatter;
@property(nonatomic, readwrite) HIEvents *events;

-(NSDictionary *)getParams;

@end
