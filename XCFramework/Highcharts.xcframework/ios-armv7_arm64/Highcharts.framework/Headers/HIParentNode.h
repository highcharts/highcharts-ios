/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Series options for parent nodes.
*/
@interface HIParentNode: HIChartsJSONSerializable

/**
Allow this series' parent nodes to be selected by clicking on the graph.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowPointSelect;

-(NSDictionary *)getParams;

@end
