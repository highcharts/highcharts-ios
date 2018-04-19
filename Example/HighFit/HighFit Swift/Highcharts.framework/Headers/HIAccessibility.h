/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIKeyboardNavigation.h"
#import "HIChartTypes.h"
#import "HIAxis.h"
#import "HISeries.h"
#import "HIExporting.h"
#import "HISeriesTypeDescriptions.h"
#import "HIFunction.h"


/**
Options for configuring accessibility for the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](http://www.highcharts.com/docs/chart-concepts/accessibility).
*/
@interface HIAccessibility: HIChartsJSONSerializable

/**
A formatter function to create the HTML contents of the hidden screen reader information region. Receives one argument, `chart`, referring to the chart object. Should return a String with the HTML content of the region. The link to view the chart as a data table will be added automatically after the custom HTML content.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIFunction *screenReaderSectionFormatter;
/**
Whether or not to add series descriptions to charts with a single series.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeSingleSeries;
/**
Options for keyboard navigation.
*/
@property(nonatomic, readwrite) HIKeyboardNavigation *keyboardNavigation;
/**
Enable accessibility features for the chart.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
When a series contains more points than this, we no longer expose information about individual points to screen readers. Set to `false` to disable.
*/
@property(nonatomic, readwrite) NSNumber *pointDescriptionThreshold;
/**
Formatter function to use instead of the default for point descriptions. Receives one argument, `point`, referring to the point to describe. Should return a String with the description of the point for a screen reader user.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
Date format to use for points on datetime axes when describing them to screen reader users. Defaults to the same format as in tooltip. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) NSString *pointDateFormat;
/**
Formatter function to use instead of the default for series descriptions. Receives one argument, `series`, referring to the series to describe. Should return a String with the description of the series for a screen reader user.
*/
@property(nonatomic, readwrite) HIFunction *seriesDescriptionFormatter;
/**
Function to run upon clicking the "View as Data Table" link in the screen reader region. By default Highcharts will insert and set focus to a data table representation of the chart.
*/
@property(nonatomic, readwrite) HIFunction *onTableAnchorClick;
/**
Formatter function to determine the date/time format used with points on datetime axes when describing them to screen reader users. Receives one argument, `point`, referring to the point to describe. Should return a date format string compatible with `dateFormat`.
*/
@property(nonatomic, readwrite) HIFunction *pointDateFormatter;
/**
Chart type description strings. This is added to the chart information region. If there is only a single series type used in the chart, we use the format string for the series type, or default if missing. There is one format string for cases where there is only a single series in the chart, and one for multiple series of the same type.
*/
@property(nonatomic, readwrite) HIChartTypes *chartTypes;
@property(nonatomic, readwrite) NSString *longDescriptionHeading;
@property(nonatomic, readwrite) NSString *rangeSelectorMaxInput;
@property(nonatomic, readwrite) NSString *structureHeading;
@property(nonatomic, readwrite) NSString *chartContainerLabel;
/**
Axis description format strings.
*/
@property(nonatomic, readwrite) HIAxis *axis;
/**
Lang configuration for different series types. For more dynamic control over the series element descriptions, see `accessibility.seriesDescriptionFormatter`.
*/
@property(nonatomic, readwrite) HISeries *series;
/**
Exporting menu format strings for accessibility module.
*/
@property(nonatomic, readwrite) HIExporting *exporting;
@property(nonatomic, readwrite) NSString *mapZoomOut;
@property(nonatomic, readwrite) NSString *rangeSelectorMinInput;
@property(nonatomic, readwrite) NSString *rangeSelectorButton;
@property(nonatomic, readwrite) NSString *legendItem;
@property(nonatomic, readwrite) NSString *tableSummary;
@property(nonatomic, readwrite) NSString *noDescription;
@property(nonatomic, readwrite) NSString *viewAsDataTable;
@property(nonatomic, readwrite) NSString *defaultChartTitle;
@property(nonatomic, readwrite) NSString *screenReaderRegionLabel;
@property(nonatomic, readwrite) NSString *mapZoomIn;
@property(nonatomic, readwrite) NSString *chartHeading;
/**
Title element text for the chart SVG element. Leave this empty to disable adding the title element. Browsers will display this content when hovering over elements in the chart. Assistive technology may use this element to label the chart.
*/
@property(nonatomic, readwrite) NSString *svgContainerTitle;
@property(nonatomic, readwrite) NSString *navigationHint;
/**
Descriptions of lesser known series types. The relevant description is added to the screen reader information region when these series types are used.
*/
@property(nonatomic, readwrite) HISeriesTypeDescriptions *seriesTypeDescriptions;

-(NSDictionary *)getParams;

@end
