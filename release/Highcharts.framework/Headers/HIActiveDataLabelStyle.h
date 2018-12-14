/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Additional styles to apply to the data label of a point that has drilldown data. By default it is underlined and blue to invite to interaction. In styled mode, active data label styles can be applied with the `.highcharts-drilldown-data-label` class.

**Defaults to** `{ "cursor": "pointer", "color": "#003399", "fontWeight": "bold", "textDecoration": "underline" }`.

**Try it**

* [Label styles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/labels/)
*/
@interface HIActiveDataLabelStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *cursor;
@property(nonatomic, readwrite) NSString *textDecoration;
@property(nonatomic, readwrite) NSString *fontWeight;

-(NSDictionary *)getParams;

@end
