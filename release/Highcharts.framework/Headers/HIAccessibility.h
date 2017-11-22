/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIKeyboardNavigation.h"
#import "HIFunction.h"


/**
* description: Options for configuring accessibility for the chart. Requires the
//code.highcharts.com/modules/accessibility.
js : accessibility module to be loaded. For a description of the module and information
on its features, see http://www.highcharts.
com/docs/chart-concepts/accessibility : Highcharts Accessibility.
*/
@interface HIAccessibility: HIChartsJSONSerializable

/**
* description: A formatter function to create the HTML contents of the hidden screen
reader information region. Receives one argument, chart, referring
to the chart object. Should return a String with the HTML content
of the region.
The link to view the chart as a data table will be added
automatically after the custom HTML content.
* default: undefined
*/
@property(nonatomic, readwrite) HIFunction *screenReaderSectionFormatter;
/**
* description: When a series contains more points than this, we no longer expose
information about individual points to screen readers.
Set to false to disable.
* default: 30
*/
@property(nonatomic, readwrite) NSNumber *pointDescriptionThreshold;
/**
* description: Date format to use for points on datetime axes when describing them
to screen reader users.
Defaults to the same format as in tooltip.
For an overview of the replacement codes, see
dateFormat.
*/
@property(nonatomic, readwrite) NSString *pointDateFormat;
/**
* description: Options for keyboard navigation.
*/
@property(nonatomic, readwrite) HIKeyboardNavigation *keyboardNavigation;
/**
* description: Formatter function to determine the date/time format used with
points on datetime axes when describing them to screen reader users.
Receives one argument, point, referring to the point to describe.
Should return a date format string compatible with
dateFormat.
*/
@property(nonatomic, readwrite) HIFunction *pointDateFormatter;
/**
* description: Formatter function to use instead of the default for point
descriptions.
Receives one argument, point, referring to the point to describe.
Should return a String with the description of the point for a screen
reader user.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
* description: Enable accessibility features for the chart.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: Formatter function to use instead of the default for series
descriptions. Receives one argument, series, referring to the
series to describe. Should return a String with the description of
the series for a screen reader user.
*/
@property(nonatomic, readwrite) HIFunction *seriesDescriptionFormatter;
/**
* description: Whether or not to add series descriptions to charts with a single
series.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeSingleSeries;
/**
* description: Function to run upon clicking the "View as Data Table" link in the
screen reader region.
By default Highcharts will insert and set focus to a data table
representation of the chart.
*/
@property(nonatomic, readwrite) HIFunction *onTableAnchorClick;

-(NSDictionary *)getParams;

@end
