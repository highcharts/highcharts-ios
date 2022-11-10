/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGAttributes.h"


/**
 */
@interface HIHalo: HIChartsJSONSerializable

/**
Opacity for the halo unless a specific fill is overridden using the `attributes` setting. Note that Highcharts is only able to apply opacity to colors of hex or rgb(a) formats.

**Defaults to** `0.25`.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
A collection of SVG attributes to override the appearance of the halo, for example `fill`, `stroke` and `stroke-width`.
*/
@property(nonatomic, readwrite) HISVGAttributes *attributes;
/**
The pixel size of the halo. For point markers this is the radius of the halo. For pie slices it is the width of the halo outside the slice. For bubbles it defaults to 5 and is the width of the halo outside the bubble.

**Defaults to** `10`.
*/
@property(nonatomic, readwrite) NSNumber *size;
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;

-(NSDictionary *)getParams;

@end
