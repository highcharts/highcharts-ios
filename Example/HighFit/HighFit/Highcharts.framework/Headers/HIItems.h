/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
An HTML label that can be positioned anywhere in the chart area.
*/
@interface HIItems: HIChartsJSONSerializable

/**
CSS styles for each label. To position the label, use left and top like this: style: {   left: '100px',   top: '100px' }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
Inner HTML or text for the label.
*/
@property(nonatomic, readwrite) NSString *html;

-(NSDictionary *)getParams;

@end
