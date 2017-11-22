/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Options for keyboard navigation.
*/
@interface HIKeyboardNavigation: HIChartsJSONSerializable

/**
* description: Enable keyboard navigation for the chart.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Skip null points when navigating through points with the
keyboard.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *skipNullPoints;

-(NSDictionary *)getParams;

@end
