/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPosition.h"
#import "HIStyle.h"


/**
* description: Highchart by default puts a credits label in the lower right corner
of the chart. This can be changed using these options.
*/
@interface HICredits: HIChartsJSONSerializable

/**
* description: Whether to show the credits text.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/enabled-false/ : Credits disabled
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The URL for the credits label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/href/ : Custom URL and text
* default: http://www.highcharts.com
*/
@property(nonatomic, readwrite) NSString *href;
/**
* description: Position configuration for the credits label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/position-left/ : Left aligned

*/
@property(nonatomic, readwrite) HIPosition *position;
/**
* description: CSS styles for the credits label.
* default: { "cursor": "pointer", "color": "#999999", "fontSize": "10px" }
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
* description: The text for the credits label.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/href/ : Custom URL and text
* default: Highcharts.com
*/
@property(nonatomic, readwrite) NSString *text;

-(NSDictionary *)getParams;

@end
