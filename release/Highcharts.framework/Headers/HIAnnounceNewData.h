/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
Default announcement for new data in charts. If addPoint or addSeries is used, and only one series/point is added, the `newPointAnnounce` and `newSeriesAnnounce` strings are used. The `...Single` versions will be used if there is only one chart on the page, and the `...Multiple` versions will be used if there are multiple charts on the page. For all other new data events, the `newDataAnnounce` string will be used.
*/
@interface HIAnnounceNewData: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *dataAnnounce;
@property(nonatomic, readwrite) NSString *seriesAnnounceMultiple;
@property(nonatomic, readwrite) NSString *seriesAnnounceSingle;
@property(nonatomic, readwrite) NSString *pointAnnounceMultiple;
@property(nonatomic, readwrite) NSString *pointAnnounceSingle;
/**
Enable announcing new data to screen reader users

**Try it**

* [Dynamic data accessible](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/accessible-dynamic)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Optional formatter callback for the announcement. Receives up to three arguments. The first argument is always an array of all series that received updates. If an announcement is already queued, the series that received updates for that announcement are also included in this array. The second argument is provided if `chart.addSeries` was called, and there is a new series. In that case, this argument is a reference to the new series. The third argument, similarly, is provided if `series.addPoint` was called, and there is a new point. In that case, this argument is a reference to the new point. The function should return a string with the text to announce to the user. Return empty string to not announce anything. Return `false` to use the default announcement format.

**Try it**

* [High priority live alerts](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-dynamic)
*/
@property(nonatomic, readwrite) HIFunction *announcementFormatter;
/**
Choose whether or not the announcements should interrupt the screen reader. If not enabled, the user will be notified once idle. It is recommended not to enable this setting unless there is a specific reason to do so.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *interruptUser;
/**
Minimum interval between announcements in milliseconds. If new data arrives before this amount of time has passed, it is queued for announcement. If another new data event happens while an announcement is queued, the queued announcement is dropped, and the latest announcement is queued instead. Set to 0 to allow all announcements, but be warned that frequent announcements are disturbing to users.
*/
@property(nonatomic, readwrite) NSNumber *minAnnounceInterval;

-(NSDictionary *)getParams;

@end
