/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options applied to collapse Button. The collape button is the small button which indicates, that the node is collapsable.
*/
@interface HICollapseButton: HIChartsJSONSerializable

/**
Whether the button should be visible.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The symbol of the collapse button.

**Defaults to** `circle`.
*/
@property(nonatomic, readwrite) NSString *shape;
/**
Height of the button.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
Width of the button.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
Whether the button should be visible only when the node is hovered. When set to true, the button is hidden for nodes, which are not collapsed, and shown for the collapsed ones.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *onlyOnHover;
/**
Offset of the button in the y direction.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
Offset of the button in the x direction.
*/
@property(nonatomic, readwrite) NSNumber *x;

-(NSDictionary *)getParams;

@end
