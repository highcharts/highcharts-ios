/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Detailed options for border radius.
*/
@interface HIBorderRadiusOptionsObject: HIChartsJSONSerializable

/**
The border radius. A number signifies pixels. A percentage string, like for example `50%`, signifies a relative size. For columns this is relative to the column width, for pies it is relative to the radius and the inner radius.
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ radius;
/**
The scope of the rounding for column charts. In a stacked column chart, the value `point` means each single point will get rounded corners. The value `stack` means the rounding will apply to the full stack, so that only points close to the top or bottom will receive rounding.

**Accepted values:** `["point", "stack"]`.
*/
@property(nonatomic, readwrite) NSString *scope;
/**
For column charts, where in the point or stack to apply rounding. The `end` value means only those corners at the point value will be rounded, leaving the corners at the base or threshold unrounded. This is the most intuitive behaviour. The `all` value means also the base will be rounded.

**Accepted values:** `["all", "end"]`.
*/
@property(nonatomic, readwrite) NSString *where;

-(NSDictionary *)getParams;

@end
