/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIShapes.h"
#import "HILabels.h"
#import "HILabelOptions.h"
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
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@property(nonatomic, readwrite) NSArray <HIShapes *> *shapes;
/**
An array of labels for the annotation. For options that apply to multiple labels, they can be added to the `labelOptions`.
*/
@property(nonatomic, readwrite) NSArray <HILabels *> *labels;
/**
Options for annotation's labels. Each label inherits options from the labelOptions object. An option from the labelOptions can be overwritten by config for a specific label.
*/
@property(nonatomic, readwrite) HILabelOptions *labelOptions;
/**
The Z index of the annotation.

**Defaults to** `6`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
Whether the annotation is visible.

**Try it**

* [Set annotation visibility](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/visible/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
/**
Options for annotation's shapes. Each shape inherits options from the shapeOptions object. An option from the shapeOptions can be overwritten by config for a specific shape.
*/
@property(nonatomic, readwrite) HIShapeOptions *shapeOptions;

-(NSDictionary *)getParams;

@end
