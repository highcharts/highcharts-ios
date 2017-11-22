/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Additional styles to apply to the data label of a point that has
drilldown data. By default it is underlined and blue to invite to
interaction.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/labels/ : Label styles
* default: { "cursor": "pointer", "color": "#003399", "fontWeight": "bold", "textDecoration": "underline" }
*/
@interface HIActiveDataLabelStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *textDecoration;
@property(nonatomic, readwrite) NSString *cursor;

-(NSDictionary *)getParams;

@end
