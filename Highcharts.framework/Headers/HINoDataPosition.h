/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The position of the no-data label, relative to the plot area. 
* default: { "x": 0, "y": 0, "align": "center", "verticalAlign": "middle" }
*/
@interface HINoDataPosition: HIChartsJSONSerializable

/**
* description: Vertical offset of the label, in pixels.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: Horizontal offset of the label, in pixels.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: Horizontal alignment of the label.
* accepted values: ["left", "center", "right"]
* default: center
*/
@property(nonatomic, readwrite) NSString *align;
/**
* description: Vertical alignment of the label.
* accepted values: ["top", "middle", "bottom"]
* default: middle
*/
@property(nonatomic, readwrite) NSString *verticalAlign;

-(NSDictionary *)getParams;

@end
