/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColor.h"
#import "HIAnnotationMockPointOptionsObject.h"


/**
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@interface HIShapes: HIChartsJSONSerializable

/**
The URL for an image to use as the annotation shape. Note, type has to be set to `'image'`.

**Try it**

* [Define a marker image url for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape-src/)
*/
@property(nonatomic, readwrite) NSString *src;
/**
An array of points for the shape or a callback function that returns that shape point. This option is available for shapes which can use multiple points such as path. A point can be either a point object or a point's id.
*/
@property(nonatomic, readwrite) NSArray<HIAnnotationMockPointOptionsObject *> *points;
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

**Try it**

* [Attach annotation to a mock point with different ways](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/mock-points/)
*/
@property(nonatomic, readwrite) HIAnnotationMockPointOptionsObject *point;
/**
Name of the dash style to use for the shape's stroke.

**Try it**

* [Possible values demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-dashstyle-all/)
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
The pixel stroke width of the shape.

**Defaults to** `1`.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) NSNumber *strokeWidth;
/**
The yAxis index to which the points should be attached. Used for the ellipse.
*/
@property(nonatomic, readwrite) NSNumber *yAxis;
/**
The radius of the shape in y direction. Used for the ellipse.

**Try it**

* [Ellipse annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/ellipse/)
*/
@property(nonatomic, readwrite) NSNumber *ry;
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

**Defaults to** `rgba(0, 0, 0, 0.75)`.

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
The xAxis index to which the points should be attached. Used for the ellipse.
*/
@property(nonatomic, readwrite) NSNumber *xAxis;
/**
Defines additional snapping area around an annotation making this annotation to focus. Defined in pixels.

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *snap;
/**
The type of the shape. Available options are circle, rect and ellipse.

**Defaults to** `rect`.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
* [Ellipse annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/ellipse/)
*/
@property(nonatomic, readwrite) NSString *type;
/**
The color of the shape's fill.

**Defaults to** `rgba(0, 0, 0, 0.75)`.

**Try it**

* [Basic shape annotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/)
*/
@property(nonatomic, readwrite) HIColor *fill;

-(NSDictionary *)getParams;

@end
