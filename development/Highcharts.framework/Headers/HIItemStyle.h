/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: CSS styles for each legend item. Only a subset of CSS is supported,
notably those options related to text. The default textOverflow
property makes long texts truncate. Set it to null to wrap text
instead. A width property can be added to control the text width.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/legend/itemstyle/ : Bold black text
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/legend/itemstyle/ : Item text styles
* default: { "color": "#333333", "cursor": "pointer", "fontSize": "12px", "fontWeight": "bold", "textOverflow": "ellipsis" }
*/
@interface HIItemStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *textOverflow;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *color;

-(NSDictionary *)getParams;

@end
