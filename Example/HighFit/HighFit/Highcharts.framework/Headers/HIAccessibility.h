/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAnnounceNewData.h"
#import "HIKeyboardNavigation.h"
#import "HIChartTypes.h"
#import "HIAccessibilitySeries.h"
#import "HIAxis.h"
#import "HIAccessibilityExporting.h"
#import "HISeriesTypeDescriptions.h"
#import "HIFunction.h"


/**
Options for configuring accessibility for the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](http://www.highcharts.com/docs/chart-concepts/accessibility).
*/
@interface HIAccessibility: HIChartsJSONSerializable

/**
Date format to use to describe range of datetime axes. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) NSString *axisRangeDateFormat;
/**
Date format to use for points on datetime axes when describing them to screen reader users. Defaults to the same format as in tooltip. For an overview of the replacement codes, see `dateFormat`.
*/
@property(nonatomic, readwrite) NSString *pointDateFormat;
/**
Theme to apply to the chart when Windows High Contrast Mode is detected.
*/
@property(nonatomic, readwrite) id highContrastTheme;
/**
A text description of the chart. **Note: Prefer using `caption` instead.** If the Accessibility module is loaded, this option is included by default as a long description of the chart in the hidden screen reader information region. Note: Since Highcharts now supports captions, it is preferred to define the description there, as the caption benefits all users. The caption will be available to screen reader users. If this option is defined instead, the caption is hidden from screen reader users.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Whether or not to add a shortcut button in the screen reader information region to show the data table.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *addTableShortcut;
/**
Amount of landmarks/regions to create for screen reader users. More landmarks can make navigation with screen readers easier, but can be distracting if there are lots of charts on the page. Three modes are available: - `all`: Adds regions for all series, legend, menu, information   region. - `one`: Adds a single landmark per chart. - `disabled`: No landmarks are added.

**Accepted values:** `["all", "one", "disabled"]`.
*/
@property(nonatomic, readwrite) NSString *landmarkVerbosity;
/**
Formatter function to use instead of the default for series descriptions. Receives one argument, `series`, referring to the series to describe. Should return a string with the description of the series for a screen reader user. If `false` is returned, the default formatter will be used for that series.
*/
@property(nonatomic, readwrite) HIFunction *seriesDescriptionFormatter;
/**
When a series contains more points than this, we no longer expose information about individual points to screen readers. Set to `false` to disable.
*/
@property(nonatomic, readwrite) NSNumber *pointDescriptionThreshold;
/**
Formatter function to use instead of the default for point descriptions. Receives one argument, `point`, referring to the point to describe. Should return a string with the description of the point for a screen reader user. If `false` is returned, the default formatter will be used for that point.
*/
@property(nonatomic, readwrite) HIFunction *pointDescriptionFormatter;
/**
Options for announcing new data to screen reader users. Useful for dynamic data applications and drilldown. Keep in mind that frequent announcements will not be useful to users, as they won't have time to explore the new data. For these applications, consider making snapshots of the data accessible, and do the announcements in batches.
*/
@property(nonatomic, readwrite) HIAnnounceNewData *announceNewData;
/**
Whether or not to add series descriptions to charts with a single series.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeSingleSeries;
/**
When a series contains more points than this, we no longer allow keyboard navigation for it. Set to `false` to disable.
*/
@property(nonatomic, readwrite) NSNumber *pointNavigationThreshold;
/**
A hook for adding custom components to the accessibility module. Should be an object mapping component names to instances of classes inheriting from the Highcharts.AccessibilityComponent base class. Remember to add the component to the `keyboardNavigation.order` for the keyboard navigation to be usable.

**Try it**

* [Custom accessibility component](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-component)
*/
@property(nonatomic, readwrite) id customComponents;
/**
A formatter function to create the HTML contents of the hidden screen reader information region. Receives one argument, `chart`, referring to the chart object. Should return a string with the HTML content of the region. By default this returns an automatic description of the chart. The button to view the chart as a data table will be added automatically after the custom HTML content if enabled.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIFunction *screenReaderSectionFormatter;
/**
Suffix to add to the values in the point descriptions. Uses `tooltip.valueSuffix` if not defined.
*/
@property(nonatomic, readwrite) NSString *pointValueSuffix;
/**
Decimals to use for the values in the point descriptions. Uses `tooltip.valueDecimals` if not defined.
*/
@property(nonatomic, readwrite) NSString *pointValueDecimals;
/**
Options for keyboard navigation.
*/
@property(nonatomic, readwrite) HIKeyboardNavigation *keyboardNavigation;
/**
Enable accessibility functionality for the chart.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Prefix to add to the values in the point descriptions. Uses `tooltip.valuePrefix` if not defined.
*/
@property(nonatomic, readwrite) NSString *pointValuePrefix;
/**
A text description of the chart type. If the Accessibility module is loaded, this will be included in the description of the chart in the screen reader information region. Highcharts will by default attempt to guess the chart type, but for more complex charts it is recommended to specify this property for clarity.
*/
@property(nonatomic, readwrite) NSString *typeDescription;
/**
Function to run upon clicking the "View as Data Table" link in the screen reader region. By default Highcharts will insert and set focus to a data table representation of the chart.
*/
@property(nonatomic, readwrite) HIFunction *onTableAnchorClick;
/**
Formatter function to determine the date/time format used with points on datetime axes when describing them to screen reader users. Receives one argument, `point`, referring to the point to describe. Should return a date format string compatible with `dateFormat`.
*/
@property(nonatomic, readwrite) HIFunction *pointDateFormatter;
/**
Expose only the series element to screen readers, not its points.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *exposeAsGroupOnly;
/**
Range description for an axis. Overrides the default range description. Set to empty to disable range description for this axis.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSString *rangeDescription;
@property(nonatomic, readwrite) NSString *legendLabel;
/**
Chart type description strings. This is added to the chart information region. If there is only a single series type used in the chart, we use the format string for the series type, or default if missing. There is one format string for cases where there is only a single series in the chart, and one for multiple series of the same type.
*/
@property(nonatomic, readwrite) HIChartTypes *chartTypes;
@property(nonatomic, readwrite) NSString *rangeSelectorMaxInput;
@property(nonatomic, readwrite) NSString *drillUpButton;
@property(nonatomic, readwrite) NSString *chartContainerLabel;
@property(nonatomic, readwrite) NSString *mapZoomOut;
/**
Lang configuration for different series types. For more dynamic control over the series element descriptions, see `accessibility.seriesDescriptionFormatter`.
*/
@property(nonatomic, readwrite) HIAccessibilitySeries *series;
/**
Axis description format strings.
*/
@property(nonatomic, readwrite) HIAxis *axis;
@property(nonatomic, readwrite) NSString *svgContainerLabel;
@property(nonatomic, readwrite) NSString *rangeSelectorMinInput;
@property(nonatomic, readwrite) NSString *rangeSelectorButton;
/**
Exporting menu format strings for accessibility module.
*/
@property(nonatomic, readwrite) HIAccessibilityExporting *exporting;
@property(nonatomic, readwrite) NSString *credits;
@property(nonatomic, readwrite) NSString *legendItem;
@property(nonatomic, readwrite) NSString *tableSummary;
@property(nonatomic, readwrite) NSString *viewAsDataTable;
@property(nonatomic, readwrite) NSString *defaultChartTitle;
@property(nonatomic, readwrite) NSString *screenReaderRegionLabel;
@property(nonatomic, readwrite) NSString *mapZoomIn;
@property(nonatomic, readwrite) NSString *chartHeading;
@property(nonatomic, readwrite) NSString *resetZoomButton;
/**
Label for the end of the chart. Announced by screen readers.
*/
@property(nonatomic, readwrite) NSString *svgContainerEnd;
/**
Title element text for the chart SVG element. Leave this empty to disable adding the title element. Browsers will display this content when hovering over elements in the chart. Assistive technology may use this element to label the chart.
*/
@property(nonatomic, readwrite) NSString *svgContainerTitle;
/**
Descriptions of lesser known series types. The relevant description is added to the screen reader information region when these series types are used.
*/
@property(nonatomic, readwrite) HISeriesTypeDescriptions *seriesTypeDescriptions;
/**
Thousands separator to use when formatting numbers for screen readers. Note that many screen readers will not handle space as a thousands separator, and will consider "11 700" as two numbers. Set to `null` to use the separator defined in `lang.thousandsSep`.
*/
@property(nonatomic, readwrite) NSString *thousandsSep;

-(NSDictionary *)getParams;

@end
