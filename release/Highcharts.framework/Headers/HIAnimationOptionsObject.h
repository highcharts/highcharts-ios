/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
An animation configuration. Animation configurations can also be defined as booleans, where `false` turns off animation and `true` defaults to a duration of 500ms.
*/
@interface HIAnimationOptionsObject: HIChartsJSONSerializable

/**
A callback function to exectute when the animation finishes.
*/
@property(nonatomic, readwrite) HIFunction *complete;
/**
The animation duration in milliseconds.
*/
@property(nonatomic, readwrite) NSNumber *duration;
/**
The name of an easing function as defined on the `Math` object.
*/
@property(nonatomic, readwrite) NSString *easing;
/**
A callback function to execute on each step of each attribute or CSS property that's being animated. The first argument contains information about the animation and progress.
*/
@property(nonatomic, readwrite) HIFunction *step;

-(NSDictionary *)getParams;

@end
