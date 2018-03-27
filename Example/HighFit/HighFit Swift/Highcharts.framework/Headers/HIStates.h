/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIHover.h"
#import "HISelect.h"
#import "HINormal.h"


/**
A wrapper object for all the series options in specific states.
*/
@interface HIStates: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIHover *hover;
@property(nonatomic, readwrite) HISelect *select;
/**
The normal state of a single point marker. Currently only used for setting animation when returning to normal state from hover.
*/
@property(nonatomic, readwrite) HINormal *normal;

-(NSDictionary *)getParams;

@end
