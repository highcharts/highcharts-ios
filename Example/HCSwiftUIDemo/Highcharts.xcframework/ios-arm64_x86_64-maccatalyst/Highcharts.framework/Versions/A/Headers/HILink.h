/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
Link Styling options
*/
@interface HILink: HIChartsJSONSerializable

/**
The color of the links between nodes.

**Defaults to** `#666666`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Type of the link shape.

**Defaults to** `'default'`.

**Try it**

* [Different link types](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/different-link-types)
*/
@property(nonatomic, readwrite) NSString *type;
/**
The line width of the links connecting nodes, in pixels.

**Defaults to** `1`.

**Try it**

* [Square links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-options)
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
Radius for the rounded corners of the links between nodes. Works for `default` link type.

**Defaults to** `10`.

**Try it**

* [Square links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-organization/link-options)
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
Modifier of the shape of the curved link. Works best for values between 0 and 1, where 0 is a straight line, and 1 is a shape close to the default one.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *offset;
/**
Opacity of the link between two nodes.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
A name for the dash style to use for links.
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
Width (px) of the link between two nodes.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *width;
@property(nonatomic, readwrite) NSString *cursor;
/**
Modifier of the shape of the curved link. Works best for values between 0 and 1, where 0 is a straight line, and 1 is a shape close to the default one.

**Defaults to** `0.5`.
*/
@property(nonatomic, readwrite) NSNumber *curveFactor;

-(NSDictionary *)getParams;

@end
