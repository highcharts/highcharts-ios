/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIResonance.h"
#import "HIFrequency.h"


/**
Mapping options for the lowpass filter. A lowpass filter lets low frequencies through, but stops high frequencies, making the sound more dull.
*/
@interface HILowpass: HIChartsJSONSerializable

/**
Map to filter resonance in dB. Can be negative to cause a dip, or positive to cause a bump.
*/
@property(nonatomic, readwrite) HIResonance *resonance;
/**
Map to filter frequency in Hertz from 1 to 20,000Hz.
*/
@property(nonatomic, readwrite) HIFrequency *frequency;

-(NSDictionary *)getParams;

@end
