/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for the keyboard navigation of data points and series.
*/
@interface HISeriesNavigation: HIChartsJSONSerializable

/**
Skip null points when navigating through points with the keyboard.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipNullPoints;
/**
Set the keyboard navigation mode for the chart. Can be "normal" or "serialize". In normal mode, left/right arrow keys move between points in a series, while up/down arrow keys move between series. Up/down navigation acts intelligently to figure out which series makes sense to move to from any given point. In "serialize" mode, points are instead navigated as a single list. Left/right behaves as in "normal" mode. Up/down arrow keys will behave like left/right. This can be useful for unifying navigation behavior with/without screen readers enabled.

**Accepted values:** `["normal", "serialize"]`.

**Defaults to** `normal`.
*/
@property(nonatomic, readwrite) NSString *mode;
/**
When a series contains more points than this, we no longer allow keyboard navigation for it. Set to `false` to disable.
*/
@property(nonatomic, readwrite) NSNumber *pointNavigationEnabledThreshold;

-(NSDictionary *)getParams;

@end
