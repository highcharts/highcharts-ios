/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIDepth.h"
#import "HISpeed.h"


/**
Mapping options for tremolo effects. Tremolo is repeated changes of volume over time.
*/
@interface HITremolo: HIChartsJSONSerializable

/**
Map to tremolo depth, from 0 to 1. This determines the intensity of the tremolo effect, how much the volume changes.
*/
@property(nonatomic, readwrite) HIDepth *depth;
/**
Map to tremolo speed, from 0 to 1. This determines the speed of the tremolo effect, how fast the volume changes.
*/
@property(nonatomic, readwrite) HISpeed *speed;

-(NSDictionary *)getParams;

@end
