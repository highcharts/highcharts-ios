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
* description: Options for displaying a message like "No data to display". 
This feature requires the file no-data-to-display.js to be loaded in the page. 
The actual text to display is set in the lang.noData option.
*/
@interface HINoData: HIChartsJSONSerializable

/**
* description: Whether to insert the label as HTML, or as pseudo-HTML rendered with
SVG.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: The position of the no-data label, relative to the plot area.
* default: { "x": 0, "y": 0, "align": "center", "verticalAlign": "middle" }
*/
@property(nonatomic, readwrite) HIPosition *position;
/**
* description: An object of additional SVG attributes for the no-data label.
*/
@property(nonatomic, readwrite) id attr;
/**
* description: CSS styles for the no-data label.
*/
@property(nonatomic, readwrite) HIStyle *style;

-(NSDictionary *)getParams;

@end
