/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIControlPointOptions.h"
#import "HIShapes.h"
#import "HIShapeOptions.h"
#import "HILabels.h"
#import "HILabelOptions.h"
#import "HIEvents.h"


/**
A basic type of an annotation. It allows to add custom labels or shapes. The items can be tied to points, axis coordinates or chart pixel coordinates.

**Try it**

* [Basic annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/basic/)
* [Advanced annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/annotations/)
* [Styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations)
* [Controllable items](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations-advanced/controllable)
*/
@interface HIAnnotations: HIChartsJSONSerializable

/**
Options for annotation's control points. Each control point inherits options from controlPointOptions object. Options from the controlPointOptions can be overwritten by options in a specific control point.
*/
@property(nonatomic, readwrite) HIControlPointOptions *controlPointOptions;
/**
An array of shapes for the annotation. For options that apply to multiple shapes, then can be added to the `shapeOptions`.
*/
@property(nonatomic, readwrite) NSArray <HIShapes *> *shapes;
/**
Options for annotation's shapes. Each shape inherits options from the shapeOptions object. An option from the shapeOptions can be overwritten by config for a specific shape.
*/
@property(nonatomic, readwrite) HIShapeOptions *shapeOptions;
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
Sets an ID for an annotation. Can be user later when removing an annotation in `Chart#removeAnnotation(id)` method.
*/
@property(nonatomic, readwrite) NSString *id;
/**
Allow an annotation to be draggable by a user. Possible values are `"x"`, `"xy"`, `"y"` and `""` (disabled).

**Accepted values:** `["x", "xy", "y", ""]`.

**Try it**

* [Annotations draggable: 'xy'](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/draggable/)
*/
@property(nonatomic, readwrite) NSString *draggable;
/**
Events available in annotations.
*/
@property(nonatomic, readwrite) HIEvents *events;

-(NSDictionary *)getParams;

/**
 Hide or show annotaiton attached to points.
 */
-(void)adjustLabelVisibility:(HILabels *)item;

/**
 Hide or show annotaiton attached to points.
 */
-(void)adjustShapeVisibility:(HIShapes *)item;

/**
Destroy the annotation. This function does not touch the chart that the annotation belongs to (all annotations are kept in the chart.annotations array) - it is recommended to use [Highcharts.Chart#removeAnnotation](https://api.highcharts.com/class-reference/Highcharts.Chart.html#removeAnnotation) instead.
 */
-(void)destroy;

/**
 Destroy a single item.
 */
-(void)destroyLabelItem:(HILabels *)item;

/**
 Destroy a single item.
 */
-(void)destroyShapeItem:(HIShapes *)item;

/**
 Initialisation of a single label
 */
-(void)initLabel:(HILabels *)labelOptions;

/**
 Initialisation of a single shape
 @param shapeOptions a confg object for a single shape
 */
-(void)initShape:(HIShapes *)shapeOptions;

/**
 Redraw a single item.
 */
-(void)redrawLabelItem:(HILabels *)item;

/**
 Redraw a single item.
 */
-(void)redrawLabelItem:(HILabels *)item animation:(NSNumber /* Bool */ *)animation;

/**
 Redraw a single item.
 */
-(void)redrawShapeItem:(HIShapes *)item;

/**
 Redraw a single item.
 */
-(void)redrawShapeItem:(HIShapes *)item animation:(NSNumber /* Bool */ *)animation;

-(void)redrawLabelItems:(NSArray <HILabels *> *)items;

-(void)redrawLabelItems:(NSArray <HILabels *> *)items animation:(NSNumber /* Bool */ *)animation;

-(void)redrawShapeItems:(NSArray <HIShapes *> *)items;

-(void)redrawShapeItems:(NSArray <HIShapes *> *)items animation:(NSNumber /* Bool */ *)animation;

/**
 See Highcharts.Annotation#destroy.
 */
-(void)remove;

/**
 Set an annotation options.
 */
-(void)setOptions;

/**
 Set the annotation's visibility.
 */
-(void)setVisibility;

/**
 Set the annotation's visibility.
 @param visible Whether to show or hide an annotation. If the param is omitted, the annotation's visibility is toggled.
 */
-(void)setVisibility:(NSNumber /* Bool */ *)visible;

@end
