/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Animation for the marker as it moves between values. Set to `false` to disable animation. Defaults to `{ duration: 50 }`.
*/
@interface HIAnimation: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *duration;

-(NSDictionary *)getParams;

@end
