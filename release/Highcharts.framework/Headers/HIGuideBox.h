/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDefault.h"


/**
Style options for the guide box. The guide box has one state by default, the `default` state.
*/
@interface HIGuideBox: HIChartsJSONSerializable

/**
Style options for the guide box default state.
*/
@property(nonatomic, readwrite) HIDefault *defaults;

-(NSDictionary *)getParams;

@end
