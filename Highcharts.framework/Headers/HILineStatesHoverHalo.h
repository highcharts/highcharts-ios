/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Options for the halo appearing around the hovered point in line-type series as well as outside the hovered slice in pie charts. By default the halo is filled by the current point or series color with an opacity of 0.25. The halo can be disabled by setting the halo option to false.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the halo is styled with the .highcharts-halo class, with colors inherited from .highcharts-color-{n}.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/halo/ : Halo options
*/
@interface HILineStatesHoverHalo: HIChartsJSONSerializable

/**
* description: A collection of SVG attributes to override the appearance of the halo, for example fill, stroke and stroke-width.
*/
@property(nonatomic, readwrite) id attributes;
/**
* description: Opacity for the halo unless a specific fill is overridden using the attributes setting. Note that Highcharts is only able to apply opacity to colors of hex or rgb(a) formats.
* default: 0.25
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
* description: The pixel size of the halo. For point markers this is the radius of the halo. For pie slices it is the width of the halo outside the slice. For bubbles it defaults to 5 and is the width of the halo outside the bubble.
* default: 10
*/
@property(nonatomic, readwrite) NSNumber *size;

-(NSDictionary *)getParams;

@end
