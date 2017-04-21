/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A title to be added on top of the legend.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/legend/title/ : Legend title
*/
@interface HILegendTitle: HIChartsJSONSerializable

/**
* description: A text or HTML string for the title. 
* default: null
*/
@property(nonatomic, readwrite) NSString *text;
/**
* description: Generic CSS styles for the legend title.
* default: {"fontWeight":"bold"}
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;

-(NSDictionary *)getParams;

@end
