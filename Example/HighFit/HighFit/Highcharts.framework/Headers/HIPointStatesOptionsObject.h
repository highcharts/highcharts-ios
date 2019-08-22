/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPointStatesHoverOptionsObject.h"
#import "HIPointStatesInactiveOptionsObject.h"
#import "HIPointStatesSelectOptionsObject.h"
#import "HIPointStatesNormalOptionsObject.h"


/**
States for a single point marker.
*/
@interface HIPointStatesOptionsObject: HIChartsJSONSerializable

/**
The hover state for a single point marker.
*/
@property(nonatomic, readwrite) HIPointStatesHoverOptionsObject *hover;
/**
The hover state for a single point marker.
*/
@property(nonatomic, readwrite) HIPointStatesInactiveOptionsObject *inactive;
/**
The hover state for a single point marker.
*/
@property(nonatomic, readwrite) HIPointStatesNormalOptionsObject *normal;
/**
The hover state for a single point marker.
*/
@property(nonatomic, readwrite) HIPointStatesSelectOptionsObject *select;

-(NSDictionary *)getParams;

@end
