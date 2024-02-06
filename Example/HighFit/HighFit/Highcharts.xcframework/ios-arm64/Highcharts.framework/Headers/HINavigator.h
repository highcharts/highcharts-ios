/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Navigator language options for accessibility.
*/
@interface HINavigator: HIChartsJSONSerializable

/**
Label for the navigator region. Receives `chart` as context.

**Defaults to** `Axis zoom`.
*/
@property(nonatomic, readwrite) NSString *groupLabel;
/**
Label for the navigator handles. Receives `handleIx` and `chart` as context. `handleIx` refers to the index of the navigator handle.

**Defaults to** `{#eq handleIx 0}Start, percent{else}End, percent{/eq}`.
*/
@property(nonatomic, readwrite) NSString *handleLabel;
/**
Announcement for assistive technology when navigator values are changed. Receives `axisRangeDescription` and `chart` as context. `axisRangeDescription` corresponds to the range description defined in `lang.accessibility.axis`

**Defaults to** `{axisRangeDescription}`.
*/
@property(nonatomic, readwrite) NSString *changeAnnouncement;

-(NSDictionary *)getParams;

@end
