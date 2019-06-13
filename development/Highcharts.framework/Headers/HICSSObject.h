/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
A style object with camel case property names to define visual appearance of a SVG element or HTML element. The properties can be whatever styles are supported on the given SVG or HTML element.
*/
@interface HICSSObject: HIChartsJSONSerializable

/**
Background style for the element.
*/
@property(nonatomic, readwrite) NSString *background;
/**
Background color of the element.
*/
@property(nonatomic, readwrite) NSString *backgroundColor;
/**
Border style for the element.
*/
@property(nonatomic, readwrite) NSString *border;
/**
Radius of the element border.
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Color used in the element. The 'contrast' option is a Highcharts custom property that results in black or white, depending on the background of the element.
*/
@property(nonatomic, readwrite) NSString *color;
/**
Style of the mouse cursor when resting over the element.
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
Font family of the element text. Multiple values have to be in decreasing preference order and separated by comma.
*/
@property(nonatomic, readwrite) NSString *fontFamily;
/**
Font size of the element text.
*/
@property(nonatomic, readwrite) NSString *fontSize;
/**
Font weight of the element text.
*/
@property(nonatomic, readwrite) NSString *fontWeight;
/**
Height of the element.
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
Width of the element border.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
Opacity of the element.
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
Space around the element content.
*/
@property(nonatomic, readwrite) NSString *padding;
/**
Behaviour of the element when the mouse cursor rests over it.
*/
@property(nonatomic, readwrite) NSString *pointerEvents;
/**
Positioning of the element.
*/
@property(nonatomic, readwrite) NSString *position;
/**
Alignment of the element text.
*/
@property(nonatomic, readwrite) NSString *textAlign;
/**
Additional decoration of the element text.
*/
@property(nonatomic, readwrite) NSString *textDecoration;
/**
Outline style of the element text.
*/
@property(nonatomic, readwrite) NSString *textOutline;
/**
Line break style of the element text. Highcharts SVG elements support `ellipsis` when a `width` is set.
*/
@property(nonatomic, readwrite) NSString *textOverflow;
/**
Top spacing of the element relative to the parent element.
*/
@property(nonatomic, readwrite) NSString *top;
/**
Animated transition of selected element properties.
*/
@property(nonatomic, readwrite) NSString *transition;
/**
Line break style of the element text.
*/
@property(nonatomic, readwrite) NSString *whiteSpace;
/**
Width of the element.
*/
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
