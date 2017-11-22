/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: A HTML label that can be positioned anywhere in the chart area.
*/
@interface HIItems: HIChartsJSONSerializable

/**
* description: CSS styles for each label. To position the label, use left and top
like this:
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
