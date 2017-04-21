/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A HTML label that can be positioned anywhere in the chart area.
*/
@interface HILabelsItems: HIChartsJSONSerializable

/**
* description: CSS styles for each label. To position the label, use left and top like this:
style: {
	left: '100px',
	top: '100px'
}
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: Inner HTML or text for the label.
*/
@property(nonatomic, readwrite) NSString *html;

-(NSDictionary *)getParams;

@end
