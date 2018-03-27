/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIContextButton.h"


/**
Options for the export related buttons, print and export. In addition to the default buttons listed here, custom buttons can be added. See `navigation.buttonOptions` for general options.
*/
@interface HIButtons: HIChartsJSONSerializable

/**
Options for the export button. In styled mode, export button styles can be applied with the `.highcharts-contextbutton` class.
*/
@property(nonatomic, readwrite) HIContextButton *contextButton;

-(NSDictionary *)getParams;

@end
