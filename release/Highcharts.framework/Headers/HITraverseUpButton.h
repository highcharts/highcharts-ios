/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPosition.h"


/**
Options for the button appearing when traversing down in a treemap.
*/
@interface HITraverseUpButton: HIChartsJSONSerializable

/**
The position of the button.
*/
@property(nonatomic, readwrite) HIPosition *position;

-(NSDictionary *)getParams;

@end
