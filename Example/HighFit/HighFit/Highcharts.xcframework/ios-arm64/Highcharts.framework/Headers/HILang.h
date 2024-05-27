/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAccessibility.h"
#import "HIExportData.h"
#import "HINavigation.h"


/**
Language object. The language object is global and it can't be set on each chart initialization. Instead, use `Highcharts.setOptions` to set it before any chart is initialized. ```js Highcharts.setOptions({   lang: {     months: [       'Janvier', 'Février', 'Mars', 'Avril',       'Mai', 'Juin', 'Juillet', 'Août',       'Septembre', 'Octobre', 'Novembre', 'Décembre'     ],     weekdays: [       'Dimanche', 'Lundi', 'Mardi', 'Mercredi',       'Jeudi', 'Vendredi', 'Samedi'     ]   } }); ```
*/
@interface HILang: HIChartsJSONSerializable

/**
The text for the menu item.

**Defaults to** `Download CSV`.

**Defaults to** `Share CSV`.
*/
@property(nonatomic, readwrite) NSString *downloadCSV;
/**
The text for the menu item.

**Defaults to** `Download XLS`.
*/
@property(nonatomic, readwrite) NSString *downloadXLS;
/**
Text to show when export is in progress.

**Defaults to** `Exporting...`.
*/
@property(nonatomic, readwrite) NSString *exportInProgress;
/**
Configure the accessibility strings in the chart. Requires the [accessibility module](https://code.highcharts.com/modules/accessibility.js) to be loaded. For a description of the module and information on its features, see [Highcharts Accessibility](https://www.highcharts.com/docs/chart-concepts/accessibility). The lang options use [Format Strings](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#format-strings) with variables that are replaced at run time. These variables should be used when available, to avoid duplicating text that is defined elsewhere. For more dynamic control over the accessibility functionality, see `accessibility.point.descriptionFormatter`, `accessibility.series.descriptionFormatter`, and `accessibility.screenReaderSection.beforeChartFormatter`.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
/**
The text for the menu item.

**Defaults to** `Hide data table`.
*/
@property(nonatomic, readwrite) NSString *hideData;
/**
Short week days, starting Sunday. If not specified, Highcharts uses the first three letters of the `lang.weekdays` option.

**Try it**

* [Finnish two-letter abbreviations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/shortweekdays/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *shortWeekdays;
/**
The text for exported table.
*/
@property(nonatomic, readwrite) HIExportData *exportData;
/**
Exporting module only. The text for the menu item to view the chart in full screen.

**Defaults to** `View in full screen`.
*/
@property(nonatomic, readwrite) NSString *viewFullscreen;
/**
The text to display when the chart contains no data.

**Defaults to** `No data to display`.

**Try it**

* [No-data text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/no-data-to-display/no-data-line)
*/
@property(nonatomic, readwrite) NSString *noData;
@property(nonatomic, readwrite) NSString *mainBreadcrumb;
/**
The loading text that appears when the chart is set into the loading state following a call to `chart.showLoading`.

**Defaults to** `Loading...`.
*/
@property(nonatomic, readwrite) NSString *loading;
/**
Exporting module only. The text for the PNG download menu item.

**Defaults to** `Share image`.
*/
@property(nonatomic, readwrite) NSString *downloadPNG;
/**
[Metric prefixes](https://en.wikipedia.org/wiki/Metric_prefix) used to shorten high numbers in axis labels. Replacing any of the positions with `null` causes the full number to be written. Setting `numericSymbols` to `undefined` disables shortening altogether.

**Defaults to** `["k", "M", "G", "T", "P", "E"]`.

**Try it**

* [Replacing the symbols with text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/numericsymbols/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *numericSymbols;
/**
Exporting module only. The text for the menu item to print the chart.

**Defaults to** `Print chart`.
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

**Defaults to** `Download SVG vector image`.
*/
@property(nonatomic, readwrite) NSString *downloadSVG;
/**
The text for the menu item.

**Defaults to** `View data table`.
*/
@property(nonatomic, readwrite) NSString *viewData;
/**
Exporting module menu. The tooltip title for the context menu holding print and export menu items.

**Defaults to** `Chart context menu`.
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
The text for the Play as sound menu item in the export menu.

**Defaults to** `Play as sound`.
*/
@property(nonatomic, readwrite) NSString *playAsSound;
/**
Exporting module only. The text for the menu item to exit the chart from full screen.

**Defaults to** `Exit from full screen`.
*/
@property(nonatomic, readwrite) NSString *exitFullscreen;
/**
The text for the label appearing when a chart is zoomed.

**Defaults to** `Reset zoom`.
*/
@property(nonatomic, readwrite) NSString *resetZoom;
/**
Exporting module only. The text for the PDF download menu item.

**Defaults to** `Share PDF`.
*/
@property(nonatomic, readwrite) NSString *downloadPDF;
/**
The tooltip title for the label appearing when a chart is zoomed.

**Defaults to** `Reset zoom level 1:1`.
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

**Defaults to** `Share image`.
*/
@property(nonatomic, readwrite) NSString *downloadJPEG;
/**
The default decimal point used in the `Highcharts.numberFormat` method unless otherwise specified in the function arguments.

**Defaults to** `.`.
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
The default thousands separator used in the `Highcharts.numberFormat` method unless otherwise specified in the function arguments. Defaults to a single space character, which is recommended in [ISO 31-0](https://en.wikipedia.org/wiki/ISO_31-0#Numbers) and works across Anglo-American and continental European languages.

**Defaults to** `\u0020`.
*/
@property(nonatomic, readwrite) NSString *thousandsSep;
/**
Configure the Popup strings in the chart. Requires the `annotations.js` or `annotations-advanced.src.js` module to be loaded.
*/
@property(nonatomic, readwrite) HINavigation *navigation;
/**
The text for the MIDI download menu item in the export menu.

**Defaults to** `Download MIDI`.
*/
@property(nonatomic, readwrite) NSString *downloadMIDI;

-(NSDictionary *)getParams;

@end
