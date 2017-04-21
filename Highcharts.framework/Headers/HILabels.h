/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabelsItems.h"


/**
* description: HTML labels that can be positioned anywhere in the chart area.
*/
@interface HILabels: HIChartsJSONSerializable

/**
* description: A HTML label that can be positioned anywhere in the chart area.
*/
@property(nonatomic, readwrite) NSArray <HILabelsItems *> *items;
/**
* description: Shared CSS styles for all labels.
* default: { "color": "#333333" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;

-(NSDictionary *)getParams;

@end
