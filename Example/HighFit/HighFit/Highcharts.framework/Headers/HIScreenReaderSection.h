/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
Accessibility options for the screen reader information sections added before and after the chart.
*/
@interface HIScreenReaderSection: HIChartsJSONSerializable

/**
A formatter function to create the HTML contents of the hidden screen reader information region before the chart. Receives one argument, `chart`, referring to the chart object. Should return a string with the HTML content of the region. By default this returns an automatic description of the chart based on `beforeChartFormat`.
*/
@property(nonatomic, readwrite) HIFunction *beforeChartFormatter;
/**
Function to run upon clicking the "View as Data Table" link in the screen reader region. By default Highcharts will insert and set focus to a data table representation of the chart.
*/
@property(nonatomic, readwrite) HIFunction *onViewDataTableClick;
/**
Format for the screen reader information region after the chart. Analogous to `beforeChartFormat`.
*/
@property(nonatomic, readwrite) NSString *afterChartFormat;
/**
Date format to use to describe range of datetime axes. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) NSString *axisRangeDateFormat;
/**
Format for the screen reader information region before the chart. Supported HTML tags are `<h1-7>`, `<p>`, `<div>`, `<a>`, and `<button>`. Attributes are not supported, except for id on `<div>`, `<a>`, and `<button>`. Id is required on `<a>` and `<button>` in the format `<tag id="abcd">`. Numbers, lower- and uppercase letters, "-" and "#" are valid characters in IDs.
*/
@property(nonatomic, readwrite) NSString *beforeChartFormat;
/**
A formatter function to create the HTML contents of the hidden screen reader information region after the chart. Analogous to `beforeChartFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *afterChartFormatter;
@property(nonatomic, readwrite) NSString *beforeRegionLabel;
@property(nonatomic, readwrite) NSString *afterRegionLabel;
/**
Label for the end of the chart. Announced by screen readers.
*/
@property(nonatomic, readwrite) NSString *endOfChartMarker;

-(NSDictionary *)getParams;

@end
