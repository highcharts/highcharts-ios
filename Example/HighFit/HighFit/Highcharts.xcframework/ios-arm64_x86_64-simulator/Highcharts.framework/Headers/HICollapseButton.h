/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"


/**
Options applied to collapse Button. The collape button is the small button which indicates, that the node is collapsable.
*/
@interface HICollapseButton: HIChartsJSONSerializable

/**
CSS styles for the collapse button. In styled mode, the collapse button style is given in the `.highcharts-collapse-button` class.
*/
@property(nonatomic, readwrite) HIStyle *style;
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

**Defaults to** `18`.
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
Width of the button.

**Defaults to** `18`.
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
/**
The line width of the button in pixels

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;

-(NSDictionary *)getParams;

@end
