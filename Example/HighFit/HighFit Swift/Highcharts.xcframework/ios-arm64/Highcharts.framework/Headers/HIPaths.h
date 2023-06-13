/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The paths include options describing the point image.

**Try it**

* [Pictorial chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pictorial/)
*/
@interface HIPaths: HIChartsJSONSerializable

/**
The definition defines a path to be drawn. It corresponds `d` SVG attribute.

**Try it**

* [Pictorial chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pictorial/)
*/
@property(nonatomic, readwrite) NSString *definition;
/**
The max option determines height of the image. It is the ratio of `yAxis.max` to the `paths.max`.

**Defaults to** `yAxis.max`.

**Try it**

* [Pictorial max option](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-pictorial/paths-max)
*/
@property(nonatomic, readwrite) NSNumber *max;

-(NSDictionary *)getParams;

@end
