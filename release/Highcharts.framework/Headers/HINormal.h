/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnimationOptionsObject.h"


/**
The normal state of a single point marker. Currently only used for setting animation when returning to normal state from hover.
*/
@interface HINormal: HIChartsJSONSerializable

/**
Animation when returning to normal state after hovering.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;

-(NSDictionary *)getParams;

@end
