/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColor.h"
#import "HIAnimationOptionsObject.h"


/**
The hover state for a single point marker.
*/
@interface HIPointStatesHoverOptionsObject: HIChartsJSONSerializable

/**
Animation when hovering over the point marker.
*/
@property(nonatomic, readwrite) HIAnimationOptionsObject *animation;
/**
Enable or disable the point marker.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The fill color of the marker in hover state. When `undefined`, the series' or point's fillColor for normal state is used.
*/
@property(nonatomic, readwrite) HIColor *fillColor;
/**
The color of the point marker's outline. When `undefined`, the series' or point's lineColor for normal state is used.
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
The width of the point marker's outline. When `undefined`, the series' or point's lineWidth for normal state is used.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The additional line width for a hovered point.
*/
@property(nonatomic, readwrite) NSNumber *lineWidthPlus;
/**
The radius of the point marker. In hover state, it defaults to the normal state's radius + 2 as per the radiusPlus option.
*/
@property(nonatomic, readwrite) NSNumber *radius;
/**
The number of pixels to increase the radius of the hovered point.
*/
@property(nonatomic, readwrite) NSNumber *radiusPlus;

-(NSDictionary *)getParams;

@end
