/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
 */
@interface HITimelineDataLabelsOptionsObject: HIChartsJSONSerializable

/**
Whether to position data labels alternately. For example, if `distance` is set equal to `100`, then data labels will be positioned alternately (on both sides of the point) at a distance of 100px.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternate;
/**
The color of the line connecting the data label to the point. The default color is the same as the point's color.
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
/**
The width of the line connecting the data label to the point. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
A pixel value defining the distance between the data label and the point. Negative numbers puts the label on top of the point.
*/
@property(nonatomic, readwrite) NSNumber *distance;
@property(nonatomic, readwrite) HIFunction *formatter;
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
