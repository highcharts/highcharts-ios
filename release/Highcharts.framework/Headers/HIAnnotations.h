/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabels.h"
#import "HILabelOptions.h"
#import "HIShapes.h"
#import "HIShapeOptions.h"


/**
Options for configuring annotations, for example labels, arrows or shapes. Annotations can be tied to points, axis coordinates or chart pixel coordinates.

**Try it**

* [Basic annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/basic/)
* [Advanced annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/annotations/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations)
*/
@interface HIAnnotations: HIChartsJSONSerializable

/**
The Z index of the annotation.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
Whether the annotation is visible.

**Try it**

* [Set annotation visibility](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/visible/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
An array of labels for the annotation. For options that apply to multiple labels, they can be added to the `labelOptions`.
*/
@property(nonatomic, readwrite) NSArray <HILabels *> *labels;
/**
Options for annotation's labels. Each label inherits options from the labelOptions object. An option from the labelOptions can be overwritten by config for a specific label.
*/
@property(nonatomic, readwrite) HILabelOptions *labelOptions;
/**
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@property(nonatomic, readwrite) NSArray <HIShapes *> *shapes;
/**
Options for annotation's shapes. Each shape inherits options from the shapeOptions object. An option from the shapeOptions can be overwritten by config for a specific shape.
*/
@property(nonatomic, readwrite) HIShapeOptions *shapeOptions;
/**
Sets an ID for an annotation. Can be user later when removing an annotation in `Chart#removeAnnotation(id)` method.
*/
@property(nonatomic, readwrite) NSString *id;

-(NSDictionary *)getParams;

@end
