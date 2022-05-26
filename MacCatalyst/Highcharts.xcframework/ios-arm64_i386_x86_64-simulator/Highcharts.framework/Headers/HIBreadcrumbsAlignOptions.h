/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for aligning breadcrumbs group.
*/
@interface HIBreadcrumbsAlignOptions: HIChartsJSONSerializable

/**
Align of a Breadcrumb group.
*/
@property(nonatomic, readwrite) NSString *align;
/**
Vertical align of a Breadcrumb group.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
X offset of a Breadcrumbs group.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Y offset of a Breadcrumbs group.
*/
@property(nonatomic, readwrite) NSNumber *y;

-(NSDictionary *)getParams;

@end
