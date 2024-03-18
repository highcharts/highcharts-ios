/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPoint.h"
#import "HIAccessibilitySeries.h"
#import "HIKeyboardNavigation.h"
#import "HIScreenReaderSection.h"
#import "HIAnnounceNewData.h"
#import "HITable.h"
#import "HIAccessibilityExporting.h"
#import "HIAccessibilityLegend.h"
#import "HINavigator.h"
#import "HIAxis.h"
#import "HISonification.h"
#import "HIChartTypes.h"
#import "HIRangeSelector.h"
#import "HIZoom.h"
#import "HISeriesTypeDescriptions.h"


/**
Options for configuring accessibility for the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](https://www.highcharts.com/docs/accessibility/accessibility-module).
*/
@interface HIAccessibility: HIChartsJSONSerializable

/**
Options for descriptions of individual data points.
*/
@property(nonatomic, readwrite) HIPoint *point;
/**
Amount of landmarks/regions to create for screen reader users. More landmarks can make navigation with screen readers easier, but can be distracting if there are lots of charts on the page. Three modes are available: - `all`: Adds regions for all series, legend, information   region. - `one`: Adds a single landmark per chart. - `disabled`: No landmarks are added.

**Accepted values:** `["all", "one", "disabled"]`.

**Defaults to** `all`.
*/
@property(nonatomic, readwrite) NSString *landmarkVerbosity;
/**
A hook for adding custom components to the accessibility module. Should be an object mapping component names to instances of classes inheriting from the Highcharts.AccessibilityComponent base class. Remember to add the component to the `keyboardNavigation.order` for the keyboard navigation to be usable.

**Try it**

* [Custom accessibility component](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/custom-component)
*/
@property(nonatomic, readwrite) id customComponents;
/**
Link the chart to an HTML element describing the contents of the chart. It is always recommended to describe charts using visible text, to improve SEO as well as accessibility for users with disabilities. This option lets an HTML element with a description be linked to the chart, so that screen reader users can connect the two. By setting this option to a string, Highcharts runs the string as an HTML selector query on the entire document. If there is only a single match, this element is linked to the chart. The content of the linked element will be included in the chart description for screen reader users. By default, the chart looks for an adjacent sibling element with the `highcharts-description` class. The feature can be disabled by setting the option to an empty string, or overridden by providing the `accessibility.description` option. Alternatively, the HTML element to link can be passed in directly as an HTML node. If you need the description to be part of the exported image, consider using the `caption` feature. If you need the description to be hidden visually, use the `accessibility.description` option.

**Defaults to** `*[data-highcharts-chart="{index}"] + .highcharts-description`.

**Try it**

* [Accessible line chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/accessibility/accessible-line)
*/
@property(nonatomic, readwrite) NSString *linkedDescription;
/**
Controls how `highContrastTheme` is applied. The default option is `auto`, which applies the high contrast theme the user's system has a high contrast theme active.

**Defaults to** `auto`.
*/
@property(nonatomic, readwrite) NSString *highContrastMode;
/**
Accessibility options global to all data series. Individual series can also have specific `accessibility options` set.
*/
@property(nonatomic, readwrite) HIAccessibilitySeries *series;
/**
Options for keyboard navigation.
*/
@property(nonatomic, readwrite) HIKeyboardNavigation *keyboardNavigation;
/**
Enable accessibility functionality for the chart. For more information on how to include these features, and why this is recommended, see [Highcharts Accessibility](https://www.highcharts.com/docs/accessibility/accessibility-module). Highcharts will by default emit a warning to the console if the [accessibility module](https://code.highcharts.com/modules/accessibility.js) is not loaded. Setting this option to `false` will override and silence the warning. Once the module is loaded, setting this option to `false` will disable the module for this chart.

**Defaults to** `True`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Accessibility options for the screen reader information sections added before and after the chart.
*/
@property(nonatomic, readwrite) HIScreenReaderSection *screenReaderSection;
/**
Options for announcing new data to screen reader users. Useful for dynamic data applications and drilldown. Keep in mind that frequent announcements will not be useful to users, as they won't have time to explore the new data. For these applications, consider making snapshots of the data accessible, and do the announcements in batches.
*/
@property(nonatomic, readwrite) HIAnnounceNewData *announceNewData;
/**
A text description of the chart type. If the Accessibility module is loaded, this will be included in the description of the chart in the screen reader information region. Highcharts will by default attempt to guess the chart type, but for more complex charts it is recommended to specify this property for clarity.
*/
@property(nonatomic, readwrite) NSString *typeDescription;
/**
Theme to apply to the chart when Windows High Contrast Mode is detected. By default, a high contrast theme matching the high contrast system colors is used.
*/
@property(nonatomic, readwrite) id highContrastTheme;
/**
A text description of the chart. **Note: Prefer using `linkedDescription` or `caption` instead.** If the Accessibility module is loaded, this option is included by default as a long description of the chart in the hidden screen reader information region. Note: Since Highcharts now supports captions and linked descriptions, it is preferred to define the description using those methods, as a visible caption/description benefits all users. If the `accessibility.description` option is defined, the linked description is ignored, and the caption is hidden from screen reader users.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Expose only the series element to screen readers, not its points.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *exposeAsGroupOnly;
/**
Format to use for describing the data series group to assistive technology - including screen readers.
*/
@property(nonatomic, readwrite) NSString *descriptionFormat;
/**
Range description for an axis. Overrides the default range description. Set to empty to disable range description for this axis.
*/
@property(nonatomic, readwrite) NSString *rangeDescription;
/**
Accessible label for the drill-up button. `{buttonText}` refers to the visual text on the button.

**Defaults to** `{buttonText}`.
*/
@property(nonatomic, readwrite) NSString *drillUpButton;
/**
Accessibility language options for the data table.
*/
@property(nonatomic, readwrite) HITable *table;
/**
Navigator language options for accessibility.
*/
@property(nonatomic, readwrite) HINavigator *navigator;
/**
Set a label on the container wrapping the SVG.
*/
@property(nonatomic, readwrite) NSString *graphicContainerLabel;
/**
Accessible label for the chart container HTML element. `{title}` refers to the chart title.

**Defaults to** `{title}. Highcharts interactive chart.`.
*/
@property(nonatomic, readwrite) NSString *chartContainerLabel;
/**
Axis description format strings.
*/
@property(nonatomic, readwrite) HIAxis *axis;
/**
Language options for sonification.
*/
@property(nonatomic, readwrite) HISonification *sonification;
/**
Chart type description strings. This is added to the chart information region. If there is only a single series type used in the chart, we use the format string for the series type, or default if missing. There is one format string for cases where there is only a single series in the chart, and one for multiple series of the same type.
*/
@property(nonatomic, readwrite) HIChartTypes *chartTypes;
/**
Accessible label for the chart SVG element. `{chartTitle}` refers to the chart title.

**Defaults to** `Interactive chart`.
*/
@property(nonatomic, readwrite) NSString *svgContainerLabel;
/**
Exporting menu format strings for accessibility module.
*/
@property(nonatomic, readwrite) HIAccessibilityExporting *exporting;
/**
Accessible label for the chart credits. `{creditsStr}` refers to the visual text in the credits.

**Defaults to** `Chart credits: {creditsStr}`.
*/
@property(nonatomic, readwrite) NSString *credits;
/**
Range selector language options for accessibility.
*/
@property(nonatomic, readwrite) HIRangeSelector *rangeSelector;
/**
Language options for accessibility of the legend.
*/
@property(nonatomic, readwrite) HIAccessibilityLegend *legend;
/**
Default title of the chart for assistive technology, for charts without a chart title.

**Defaults to** `Chart`.
*/
@property(nonatomic, readwrite) NSString *defaultChartTitle;
/**
Chart and map zoom accessibility language options.
*/
@property(nonatomic, readwrite) HIZoom *zoom;
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

**Defaults to** `,`.
*/
@property(nonatomic, readwrite) NSString *thousandsSep;

-(NSDictionary *)getParams;

@end
