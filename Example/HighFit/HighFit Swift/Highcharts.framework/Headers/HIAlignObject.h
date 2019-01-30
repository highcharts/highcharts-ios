/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options to align the element relative to the chart or another box.
*/
@interface HIAlignObject: HIChartsJSONSerializable

/**
Horizontal alignment. Can be one of `left`, `center` and `right`.
*/
@property(nonatomic, readwrite) NSString *align;
/**
Use the `transform` attribute with translateX and translateY custom attributes to align this elements rather than `x` and `y` attributes.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alignByTranslate;
/**
Vertical alignment. Can be one of `top`, `middle` and `bottom`.
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
Horizontal pixel offset from alignment.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Vertical pixel offset from alignment.
*/
@property(nonatomic, readwrite) NSNumber *y;

-(NSDictionary *)getParams;

@end
