/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: CSS styles for the tooltip. The tooltip can also be styled through
the CSS class .highcharts-tooltip.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/tooltip/style/ : Greater padding, bold text
* default: { "color": "#333333", "cursor": "default", "fontSize": "12px", "pointerEvents": "none", "whiteSpace": "nowrap" }
*/
@interface HIStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *textOutline;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSString *backgroundColor;
@property(nonatomic, readwrite) NSString *textAlign;
@property(nonatomic, readwrite) NSNumber *opacity;
@property(nonatomic, readwrite) NSString *position;
@property(nonatomic, readwrite) NSString *textOverflow;
/**
* description: The font family to use for the word cloud.
* default: Impact, sans-serif
*/
@property(nonatomic, readwrite) NSString *fontFamily;
@property(nonatomic, readwrite) NSString *pointerEvents;
@property(nonatomic, readwrite) NSString *whiteSpace;

-(NSDictionary *)getParams;

@end
