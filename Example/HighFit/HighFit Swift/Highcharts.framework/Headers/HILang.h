/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Language object. The language object is global and it can't be set
on each chart initiation. Instead, use Highcharts.setOptions to
set it before any chart is initialized.
Highcharts.setOptions({
    lang: {
        months: [
            'Janvier', 'Février', 'Mars', 'Avril',
            'Mai', 'Juin', 'Juillet', 'Août',
            'Septembre', 'Octobre', 'Novembre', 'Décembre'
        ],
        weekdays: [
            'Dimanche', 'Lundi', 'Mardi', 'Mercredi',
            'Jeudi', 'Vendredi', 'Samedi'
        ]
    }
});
*/
@interface HILang: HIChartsJSONSerializable

/**
* description: The text for the label appearing when a chart is zoomed.
* default: Reset zoom
*/
@property(nonatomic, readwrite) NSString *resetZoom;
/**
* description: An array containing the months names in abbreviated form. Corresponds
to the %b format in Highcharts.dateFormat().
* default: [ "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" ,
         "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"]
*/
@property(nonatomic, readwrite) NSArray<NSString *> *shortMonths;
/**
* description: The magnitude of numericSymbols replacements.
Use 10000 for Japanese, Korean and various Chinese locales, which
use symbols for 10^4, 10^8 and 10^12.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/numericsymbolmagnitude/ : 10000 magnitude for Japanese
* default: 1000
*/
@property(nonatomic, readwrite) NSNumber *numericSymbolMagnitude;
/**
* description: The text for the button that appears when drilling down, linking
back to the parent series. The parent series' name is inserted for
{series.name}.
* default: Back to {series.name}
*/
@property(nonatomic, readwrite) NSString *drillUpText;
/**
* description: The text to display when the chart contains no data. Requires the
no-data module, see noData.
* default: No data to display
*/
@property(nonatomic, readwrite) NSString *noData;
/**
* description: Exporting module only. The text for the PDF download menu item.
* default: Download PDF document
*/
@property(nonatomic, readwrite) NSString *downloadPDF;
/**
* description: Exporting module menu. The tooltip title for the context menu holding
print and export menu items.
* default: Chart context menu
*/
@property(nonatomic, readwrite) NSString *contextButtonTitle;
/**
* description: Short week days, starting Sunday. If not specified, Highcharts uses
the first three letters of the lang.weekdays option.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/shortweekdays/ : Finnish two-letter abbreviations
*/
@property(nonatomic, readwrite) NSArray<NSString *> *shortWeekdays;
/**
* description: The tooltip title for the label appearing when a chart is zoomed.
* default: Reset zoom level 1:1
*/
@property(nonatomic, readwrite) NSString *resetZoomTitle;
/**
* description: Exporting module only. The text for the menu item to print the chart.
* default: Print chart
*/
@property(nonatomic, readwrite) NSString *printChart;
/**
* description: An array containing the months names. Corresponds to the %B format
in Highcharts.dateFormat().
* default: [ "January" , "February" , "March" , "April" , "May" ,
         "June" , "July" , "August" , "September" , "October" ,
         "November" , "December"]
*/
@property(nonatomic, readwrite) NSArray<NSString *> *months;
/**
* description: Exporting module only. The text for the SVG download menu item.
* default: Download SVG vector image
*/
@property(nonatomic, readwrite) NSString *downloadSVG;
/**
* description: What to show in a date field for invalid dates. Defaults to an empty
string.
*/
@property(nonatomic, readwrite) NSString *invalidDate;
/**
* description: Export-data module only. The text for the menu item.
* default: Download XLS
*/
@property(nonatomic, readwrite) NSString *downloadXLS;
/**
* description: Exporting module only. The text for the JPEG download menu item.
* default: Download JPEG image
*/
@property(nonatomic, readwrite) NSString *downloadJPEG;
/**
* description: Exporting module only. The text for the PNG download menu item.
* default: Download PNG image
*/
@property(nonatomic, readwrite) NSString *downloadPNG;
/**
* description: http://en.wikipedia.org/wiki/Metric_prefix : Metric prefixes used
to shorten high numbers in axis labels. Replacing any of the positions
with null causes the full number to be written. Setting numericSymbols
to null disables shortening altogether.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/lang/numericsymbols/ : Replacing the symbols with text
* default: [ "k" , "M" , "G" , "T" , "P" , "E"]
*/
@property(nonatomic, readwrite) NSArray<NSString *> *numericSymbols;
/**
* description: Export-data module only. The text for the menu item.
* default: Download CSV
*/
@property(nonatomic, readwrite) NSString *downloadCSV;
/**
* description: An array containing the weekday names.
* default: ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
         "Friday", "Saturday"]
*/
@property(nonatomic, readwrite) NSArray<NSString *> *weekdays;
/**
* description: Export-data module only. The text for the menu item.
* default: View data table
*/
@property(nonatomic, readwrite) NSString *viewData;
/**
* description: The loading text that appears when the chart is set into the loading
state following a call to chart.showLoading.
* default: Loading...
*/
@property(nonatomic, readwrite) NSString *loading;
/**
* description: The default decimal point used in the Highcharts.numberFormat
method unless otherwise specified in the function arguments.
* default: .
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
* description: The default thousands separator used in the Highcharts.numberFormat
method unless otherwise specified in the function arguments. Since
Highcharts 4.1 it defaults to a single space character, which is
compatible with ISO and works across Anglo-American and continental
European languages.
The default is a single space.
* default:  
*/
@property(nonatomic, readwrite) NSString *thousandsSep;

-(NSDictionary *)getParams;

@end
