/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
The left side of the frame around a 3D chart.
*/
@interface HILeft: HIChartsJSONSerializable

/**
The color of the panel.

**Defaults to** `transparent`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Whether to display the frame. Possible values are `true`, `false`, `"auto"` to display only the frames behind the data, and `"default"` to display faces behind the data based on the axis layout, ignoring the point of view.

**Defaults to** `default`.

**Try it**

* [Auto frames](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/3d/scatter-frame/)
*/
@property(nonatomic, readwrite) id /* Bool, NSString */ visible;
/**
The thickness of the panel.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *size;

-(NSDictionary *)getParams;

@end
