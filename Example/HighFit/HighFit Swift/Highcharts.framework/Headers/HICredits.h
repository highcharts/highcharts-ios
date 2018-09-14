/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIPosition.h"


/**
Highchart by default puts a credits label in the lower right corner of the chart. This can be changed using these options.
*/
@interface HICredits: HIChartsJSONSerializable

/**
CSS styles for the credits label.

**Defaults to** `{"cursor": "pointer", "color": "#999999", "fontSize": "10px"}`.
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
The text for the credits label.

**Defaults to** `Highcharts.com`.

**Try it**

* [Custom URL and text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/href/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
Whether to show the credits text.

**Try it**

* [Credits disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/enabled-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The URL for the credits label.

**Try it**

* [Custom URL and text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/href/)
*/
@property(nonatomic, readwrite) NSString *href;
/**
Position configuration for the credits label.

**Try it**

* [Left aligned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/position-left/)
* [Left aligned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/position-left/)
*/
@property(nonatomic, readwrite) HIPosition *position;

-(NSDictionary *)getParams;

@end
