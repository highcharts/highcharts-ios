/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPoint.h"
#import "HIColor.h"


/**
* description: An array of shapes for the annotation. For options that apply to multiple
shapes, then can be added to the annotations.shapeOptions.html : shapeOptions.
*/
@interface HIShapes: HIChartsJSONSerializable

/**
* description: The color of the shape's stroke.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
* default: rgba(0, 0, 0, 0.75)
*/
@property(nonatomic, readwrite) HIColor *stroke;
/**
* description: The height of the shape.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
* description: The pixel stroke width of the shape.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *strokeWidth;
/**
* description: The color of the shape's fill.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
* default: rgba(0, 0, 0, 0.75)
*/
@property(nonatomic, readwrite) HIColor *fill;
/**
* description: This option defines the point to which the shape will be connected.
It can be either the point which exists in the series - it is referenced
by the point's id - or a new point with defined x, y properties
and optionally axes.
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
* description: The width of the shape.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
* description: The type of the shape, e.g. circle or rectangle.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
* default: 'rect'
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: Id of the marker which will be drawn at the final vertex of the path.
Custom markers can be defined in defs property.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/ : Define a custom marker for annotations
*/
@property(nonatomic, readwrite) NSString *markerEnd;
/**
* description: An array of points for the shape. This option is available for shapes
which can use multiple points such as path. A point can be either 
a point object or a point's id.
*/
@property(nonatomic, readwrite) NSArray *points;
/**
* description: Id of the marker which will be drawn at the first vertex of the path.
Custom markers can be defined in defs property.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/ : Define a custom marker for annotations
*/
@property(nonatomic, readwrite) NSString *markerStart;
/**
* description: The radius of the shape.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/shape/ : Basic shape annotation
*/
@property(nonatomic, readwrite) NSNumber *r;

-(NSDictionary *)getParams;

@end
