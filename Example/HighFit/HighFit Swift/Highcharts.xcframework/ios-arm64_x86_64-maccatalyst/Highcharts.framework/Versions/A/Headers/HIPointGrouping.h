/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Sonification point grouping options for this series.
*/
@interface HIPointGrouping: HIChartsJSONSerializable

/**
The size of each group in milliseconds. Audio events closer than this are grouped together.

**Defaults to** `15`.
*/
@property(nonatomic, readwrite) NSNumber *groupTimespan;
/**
Whether or not to group points

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The grouping algorithm, deciding which points to keep when grouping a set of points together. By default `"minmax"` is used, which keeps both the minimum and maximum points. The other algorithms will either keep the first point in the group (time wise), last point, middle point, or both the first and the last point. The timing of the resulting point(s) is then adjusted to play evenly, regardless of its original position within the group.

**Defaults to** `minmax`.
*/
@property(nonatomic, readwrite) NSString *algorithm;
/**
The data property for each point to compare when deciding which points to keep in the group. By default it is "y", which means that if the `"minmax"` algorithm is used, the two points the group with the lowest and highest `y` value will be kept, and the others not played.

**Defaults to** `y`.
*/
@property(nonatomic, readwrite) NSString *prop;

-(NSDictionary *)getParams;

@end
