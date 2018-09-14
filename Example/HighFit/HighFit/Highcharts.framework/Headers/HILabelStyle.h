/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
CSS styles for the loading label `span`.

**Defaults to** `{"fontWeight": "bold", "position": "relative", "top": "45%"}`.

**Try it**

* [Vertically centered](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/loading/labelstyle/)
*/
@interface HILabelStyle: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *fontWeight;
@property(nonatomic, readwrite) NSString *top;
@property(nonatomic, readwrite) NSString *position;

-(NSDictionary *)getParams;

@end
