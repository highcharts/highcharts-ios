/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGAttributes.h"


/**
Pattern options
*/
@interface HIPatternOptionsObject: HIChartsJSONSerializable

/**
For automatically calculated width and height on images, it is possible to set an aspect ratio. The image will be zoomed to fill the bounding box, maintaining the aspect ratio defined.
*/
@property(nonatomic, readwrite) NSNumber *aspectRatio;
/**
Background color for the pattern if a `path` is set (not images).
*/
@property(nonatomic, readwrite) NSString *backgroundColor;
/**
Pattern color, used as default path stroke.
*/
@property(nonatomic, readwrite) NSString *color;
/**
Analogous to pattern.width.
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
ID to assign to the pattern. This is automatically computed if not added, and identical patterns are reused. To refer to an existing pattern for a Highcharts color, use `color: "url(#pattern-id)"`.
*/
@property(nonatomic, readwrite) NSString *id;
/**
URL to an image to use as the pattern.
*/
@property(nonatomic, readwrite) NSString *image;
/**
Opacity of the pattern as a float value from 0 to 1.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
Either an SVG path as string, or an object. As an object, supply the path string in the `path.d` property. Other supported properties are standard SVG attributes like `path.stroke` and `path.fill`. If a path is supplied for the pattern, the `image` property is ignored.
*/
@property(nonatomic, readwrite) HISVGAttributes *path;
/**
Width of the pattern. For images this is automatically set to the width of the element bounding box if not supplied. For non-image patterns the default is 32px. Note that automatic resizing of image patterns to fill a bounding box dynamically is only supported for patterns with an automatically calculated ID.
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
Horizontal offset of the pattern. Defaults to 0.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Vertical offset of the pattern. Defaults to 0.
*/
@property(nonatomic, readwrite) NSNumber *y;

-(NSDictionary *)getParams;

@end
