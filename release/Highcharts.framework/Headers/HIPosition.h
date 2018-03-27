/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The position of the button.
*/
@interface HIPosition: HIChartsJSONSerializable

/**
Vertical offset of the button.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
Horizontal offset of the button.

**Defaults to** `-10`.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Horizontal alignment of the button.

**Accepted values:** `["left", "center", "right"]`.
*/
@property(nonatomic, readwrite) NSString *align;
/**
Vertical alignment of the button.

**Accepted values:** `["top", "middle", "bottom"]`.

**Defaults to** `top`.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
