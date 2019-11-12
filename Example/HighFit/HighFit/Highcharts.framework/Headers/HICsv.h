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
Options for exporting data to CSV or ExCel, or displaying the data in a HTML table or a JavaScript structure. This module adds data export options to the export menu and provides functions like `Chart.getCSV`, `Chart.getTable`, `Chart.getDataRows` and `Chart.viewData`. The XLS converter is limited and only creates a HTML string that is passed for download, which works but creates a warning before opening. The workaround for this is to use a third party XLSX converter, as demonstrated in the sample below.

**Try it**

* [Categorized data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/categorized/)
* [Highstock time axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/stock-timeaxis/)
* [Using a third party XLSX converter](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/xlsx/)
*/
@interface HICsv: HIChartsJSONSerializable

/**
Formatter callback for the column headers. Parameters are: - `item` - The series or axis object) - `key` - The point key, for example y or z - `keyLength` - The amount of value keys for this item, for  example a range series has the keys `low` and `high` so the  key length is 2. If `useMultiLevelHeaders` is true, columnHeaderFormatter by default returns an object with columnTitle and topLevelColumnTitle for each key. Columns with the same topLevelColumnTitle have their titles merged into a single cell with colspan for table/Excel export. If `useMultiLevelHeaders` is false, or for CSV export, it returns the series name, followed by the key if there is more than one key. For the axis it returns the axis title or "Category" or "DateTime" by default. Return `false` to use Highcharts' proposed header.

**Try it**

* [Multiple table headers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/multilevel-table)
*/
@property(nonatomic, readwrite) HIFunction *columnHeaderFormatter;
/**
Which decimal point to use for exported CSV. Defaults to the same as the browser locale, typically `.` (English) or `,` (German, French etc).
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
The line delimiter in the exported data, defaults to a newline.
*/
@property(nonatomic, readwrite) NSString *lineDelimiter;
/**
The item delimiter in the exported data. Use `;` for direct exporting to Excel. Defaults to a best guess based on the browser locale. If the locale _decimal point_ is `,`, the `itemDelimiter` defaults to `;`, otherwise the `itemDelimiter` defaults to `,`.
*/
@property(nonatomic, readwrite) NSString *itemDelimiter;
/**
Which date format to use for exported dates on a datetime X axis. See `Highcharts.dateFormat`.
*/
@property(nonatomic, readwrite) NSString *dateFormat;

-(NSDictionary *)getParams;

@end
