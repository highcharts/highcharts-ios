/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAccessibility.h"
#import "HINavigation.h"


/**
Language object. The language object is global and it can't be set on each chart initialization. Instead, use `Highcharts.setOptions` to set it before any chart is initialized. ```js Highcharts.setOptions({   lang: {     months: [       'Janvier', 'FĂŠvrier', 'Mars', 'Avril',       'Mai', 'Juin', 'Juillet', 'AoĂťt',       'Septembre', 'Octobre', 'Novembre', 'DĂŠcembre'     ],     weekdays: [       'Dimanche', 'Lundi', 'Mardi', 'Mercredi',       'Jeudi', 'Vendredi', 'Samedi'     ]   } }); ```
*/
@interface HILang: HIChartsJSONSerializable

/**
The text for the menu item.

**Defaults to** `Share CSV`.
*/
@property(nonatomic, readwrite) NSString *downloadCSV;
/**
The text for the menu item.
*/
@property(nonatomic, readwrite) NSString *downloadXLS;
/**
Exporting module only. The text for the PNG download menu item.
*/
@property(nonatomic, readwrite) NSString *downloadPNG;
/**
Configure the accessibility strings in the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](https://www.highcharts.com/docs/chart-concepts/accessibility). For more dynamic control over the accessibility functionality, see `accessibility.pointDescriptionFormatter`, `accessibility.seriesDescriptionFormatter`, and `accessibility.screenReaderSectionFormatter`.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
/**
Short week days, starting Sunday. If not specified, Highcharts uses the first three letters of the `lang.weekdays` option.

**Try it**

* [Finnish two-letter abbreviations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/shortweekdays/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *shortWeekdays;
/**
Exporting module only. View the chart in full screen.
*/
@property(nonatomic, readwrite) NSString *viewFullscreen;
/**
The text to display when the chart contains no data.

**Try it**

* [No-data text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
*/
@property(nonatomic, readwrite) NSString *noData;
/**
The loading text that appears when the chart is set into the loading state following a call to `chart.showLoading`.
*/
@property(nonatomic, readwrite) NSString *loading;
/**
[Metric prefixes](http://en.wikipedia.org/wiki/Metric_prefix) used to shorten high numbers in axis labels. Replacing any of the positions with `null` causes the full number to be written. Setting `numericSymbols` to `null` disables shortening altogether.

**Defaults to** `["k", "M", "G", "T", "P", "E"]`.

**Try it**

* [Replacing the symbols with text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/numericsymbols/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *numericSymbols;
/**
Exporting module only. The text for the menu item to print the chart.
*/
@property(nonatomic, readwrite) NSString *printChart;
/**
The magnitude of `numericSymbols` replacements. Use 10000 for Japanese, Korean and various Chinese locales, which use symbols for 10^4, 10^8 and 10^12.

**Defaults to** `1000`.

**Try it**

* [10000 magnitude for Japanese](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/numericsymbolmagnitude/)
*/
@property(nonatomic, readwrite) NSNumber *numericSymbolMagnitude;
/**
An array containing the weekday names.

**Defaults to** `["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
         "Friday", "Saturday"]`.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *weekdays;
/**
Exporting module only. The text for the SVG download menu item.
*/
@property(nonatomic, readwrite) NSString *downloadSVG;
/**
The text for the button that appears when drilling down, linking back to the parent series. The parent series' name is inserted for `{series.name}`.
*/
@property(nonatomic, readwrite) NSString *drillUpText;
/**
The text for the menu item.
*/
@property(nonatomic, readwrite) NSString *viewData;
/**
Exporting module menu. The tooltip title for the context menu holding print and export menu items.
*/
@property(nonatomic, readwrite) NSString *contextButtonTitle;
/**
Exporting module only. The text for the disabling menu button.

**Defaults to** `Cancel`.
*/
@property(nonatomic, readwrite) NSString *cancelButtonTitle;
/**
What to show in a date field for invalid dates. Defaults to an empty string.
*/
@property(nonatomic, readwrite) NSString *invalidDate;
/**
The text for the label appearing when a chart is zoomed.
*/
@property(nonatomic, readwrite) NSString *resetZoom;
/**
Exporting module only. The text for the PDF download menu item.
*/
@property(nonatomic, readwrite) NSString *downloadPDF;
/**
The text for the menu item.
*/
@property(nonatomic, readwrite) NSString *openInCloud;
/**
The tooltip title for the label appearing when a chart is zoomed.
*/
@property(nonatomic, readwrite) NSString *resetZoomTitle;
/**
An array containing the months names. Corresponds to the `%B` format in `Highcharts.dateFormat()`.

**Defaults to** `["January", "February", "March", "April", "May", "June",
         "July", "August", "September", "October", "November",
         "December"]`.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *months;
/**
An array containing the months names in abbreviated form. Corresponds to the `%b` format in `Highcharts.dateFormat()`.

**Defaults to** `["Jan", "Feb", "Mar", "Apr", "May", "Jun",
         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]`.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *shortMonths;
/**
Exporting module only. The text for the JPEG download menu item.
*/
@property(nonatomic, readwrite) NSString *downloadJPEG;
/**
The default decimal point used in the `Highcharts.numberFormat` method unless otherwise specified in the function arguments.
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
Configure the Popup strings in the chart. Requires the `annotations.js` or `annotations-advanced.src.js` module to be loaded.
*/
@property(nonatomic, readwrite) HINavigation *navigation;
/**
The default thousands separator used in the `Highcharts.numberFormat` method unless otherwise specified in the function arguments. Defaults to a single space character, which is recommended in [ISO 31-0](https://en.wikipedia.org/wiki/ISO_31-0#Numbers) and works across Anglo-American and continental European languages.

**Defaults to** `\u0020`.
*/
@property(nonatomic, readwrite) NSString *thousandsSep;

-(NSDictionary *)getParams;

@end
