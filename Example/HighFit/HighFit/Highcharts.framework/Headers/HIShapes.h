/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPoints.h"
#import "HIPoint.h"
#import "HIColor.h"


/**
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@interface HIShapes: HIChartsJSONSerializable

/**
An array of points for the shape. This option is available for shapes which can use multiple points such as path. A point can be either a point object or a point's id.
*/
@property(nonatomic, readwrite) NSArray <HIPoints *> *points;
/**
Id of the marker which will be drawn at the final vertex of the path. Custom markers can be defined in defs property.

**Try it**

* [Define a custom marker for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/)
*/
@property(nonatomic, readwrite) NSString *markerEnd;
/**
Id of the marker which will be drawn at the first vertex of the path. Custom markers can be defined in defs property.

**Try it**

* [Define a custom marker for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/)
*/
@property(nonatomic, readwrite) NSString *markerStart;
/**
This option defines the point to which the shape will be connected. It can be either the point which exists in the series - it is referenced by the point's id - or a new point with defined x, y properties and optionally axes.
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
The pixel stroke width of the shape.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSNumber *strokeWidth;
/**
The height of the shape.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
The width of the shape.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
The color of the shape's stroke.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) HIColor *stroke;
/**
The radius of the shape.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSNumber *r;
/**
Defines additional snapping area around an annotation making this annotation to focus. Defined in pixels.
*/
@property(nonatomic, readwrite) NSNumber *snap;
/**
The type of the shape, e.g. circle or rectangle.

**Defaults to** `'rect'`.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSString *type;
/**
The color of the shape's fill.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) HIColor *fill;

-(NSDictionary *)getParams;

@end
