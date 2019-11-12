/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Color stop tuple.
*/
@interface HIGradientColorStopObject: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *zero;
@property(nonatomic, readwrite) NSString *one;

-(NSDictionary *)getParams;

@end
