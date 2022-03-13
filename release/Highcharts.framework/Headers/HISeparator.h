/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HICSSObject.h"


/**
Options object for Breadcrumbs separator.
*/
@interface HISeparator: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *text;
/**
CSS styles for the breadcrumbs separator. In styled mode, the breadcrumbs separators are styled by the `.highcharts-separator` rule with its different states.
*/
@property(nonatomic, readwrite) HICSSObject *style;

-(NSDictionary *)getParams;

@end
