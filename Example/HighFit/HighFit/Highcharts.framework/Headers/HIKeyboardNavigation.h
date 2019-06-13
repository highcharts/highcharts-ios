/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFocusBorder.h"


/**
Options for keyboard navigation.
*/
@interface HIKeyboardNavigation: HIChartsJSONSerializable

/**
Skip null points when navigating through points with the keyboard.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipNullPoints;
/**
Enable keyboard navigation for the chart.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Whether or not to wrap around when reaching the end of arrow-key navigation for an element in the chart.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *wrapAround;
/**
Options for the focus border drawn around elements while navigating through them.

**Try it**

* [Custom focus ring](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-focus)
*/
@property(nonatomic, readwrite) HIFocusBorder *focusBorder;
/**
Order of tab navigation in the chart. Determines which elements are tabbed to first. Available elements are: `series`, `zoom`, `rangeSelector`, `chartMenu`, `legend`. In addition, any custom components can be added here.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *order;
/**
Set the keyboard navigation mode for the chart. Can be "normal" or "serialize". In normal mode, left/right arrow keys move between points in a series, while up/down arrow keys move between series. Up/down navigation acts intelligently to figure out which series makes sense to move to from any given point. In "serialize" mode, points are instead navigated as a single list. Left/right behaves as in "normal" mode. Up/down arrow keys will behave like left/right. This can be useful for unifying navigation behavior with/without screen readers enabled.

**Accepted values:** `["normal", "serialize"]`.

**Defaults to** `normal`.
*/
@property(nonatomic, readwrite) NSString *mode;

-(NSDictionary *)getParams;

@end
