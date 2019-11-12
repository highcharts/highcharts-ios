/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIHover.h"
#import "HIInactive.h"
#import "HISelect.h"
#import "HINormal.h"


/**
States for a single point marker.
*/
@interface HIStates: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIHover *hover;
/**
The opposite state of a hover for a single point node/link.
*/
@property(nonatomic, readwrite) HIInactive *inactive;
@property(nonatomic, readwrite) HISelect *select;
/**
The normal state of a series, or for point items in column, pie and similar series. Currently only used for setting animation when returning to normal state from hover.
*/
@property(nonatomic, readwrite) HINormal *normal;

-(NSDictionary *)getParams;

@end
