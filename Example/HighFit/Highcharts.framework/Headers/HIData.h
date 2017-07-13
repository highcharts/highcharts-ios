/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: The Data module provides a simplified interface for adding data to a chart from sources like CVS, HTML tables or grid views. See also the http://www.highcharts.com/docs/working-with-data/data-module : tutorial article on the Data module.
It requires the modules/data.js file to be loaded.
Please note that the default way of adding data in Highcharts, without the need of a module, is through the series.data option.
* demo: Data from a http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/ : HTML table, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/csv/ : CSV.
*/
@interface HIData: HIChartsJSONSerializable

/**
* description: The same as the columns input option, but defining rows intead of columns.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/rows/ : Data in rows
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *rows;
/**
* description: A HTML table or the id of such to be parsed as input data. Related options are startRow, endRow, startColumn and endColumn to delimit what part of the table is used.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/ : Parsed table
*/
@property(nonatomic, readwrite) NSString *table;
/**
* description: The key for a Google Spreadsheet to load. See https://developers.google.com/gdata/samples/spreadsheet_sample : general information on GS.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/ : Load a Google Spreadsheet
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetKey;
/**
* description: In tabular input data, the last column (indexed by 0) to use. Defaults to the last column containing data.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
*/
@property(nonatomic, readwrite) NSNumber *endColumn;
/**
* description: A callback function to parse string representations of dates into JavaScript timestamps. Should return an integer timestamp on success.
*/
@property(nonatomic, readwrite) NSString /* Function */ *parseDate;
/**
* description: In tabular input data, the last row (indexed by 0) to use. Defaults to the last row containing data.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
*/
@property(nonatomic, readwrite) NSNumber *endRow;
/**
* description: A comma delimited string to be parsed. Related options are startRow, endRow, startColumn and endColumn to delimit what part of the table is used. The lineDelimiter and itemDelimiter options define the CSV delimiter formats.
The built-in CSV parser doesn't support all flavours of CSV, so in some cases it may be necessary to use an external CSV parser. See http://jsfiddle.net/highcharts/u59176h4/ : this example of parsing CSV through the MIT licensed http://papaparse.com/ : Papa Parse library.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/csv/ : Data from CSV
*/
@property(nonatomic, readwrite) NSString *csv;
/**
* description: In tabular input data, the first row (indexed by 0) to use.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *startRow;
/**
* description: The callback that is evaluated when the data is finished loading, optionally from an external source, and parsed. The first argument passed is a finished chart options object, containing the series. These options can be extended with additional options and passed directly to the chart constructor.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/complete/ : Modify data on complete
*/
@property(nonatomic, readwrite) NSString /* Function */ *complete;
/**
* description: Which of the predefined date formats in Date.prototype.dateFormats to use to parse date values. Defaults to a best guess based on what format gives valid and ordered dates.
Valid options include:

YYYY-mm-dd
dd/mm/YYYY
mm/dd/YYYY
dd/mm/YY
mm/dd/YY


* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/dateformat-auto/ : Best guess date format
* accepted values: [undefined, "YYYY-mm-dd", "dd/mm/YYYY", "mm/dd/YYYY", "dd/mm/YYYY", "dd/mm/YY", "mm/dd/YY"]
*/
@property(nonatomic, readwrite) NSString *dateFormat;
/**
* description: Switch rows and columns of the input data, so that this.columns effectively becomes the rows of the data set, and the rows are interpreted as series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/switchrowsandcolumns/ : Switch rows and columns
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *switchRowsAndColumns;
/**
* description: The decimal point used for parsing numbers in the CSV.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Comma as decimal point
* default: .
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
* description: In tabular input data, the first column (indexed by 0) to use.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *startColumn;
/**
* description: An array containing object with Point property names along with what column id the property should be taken from.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/seriesmapping-label/ : Label from data set
*/
@property(nonatomic, readwrite) NSArray *seriesMapping;
/**
* description: Item or cell delimiter for parsing CSV. Defaults to the tab character \t if a tab character is found in the CSV string, if not it defaults to ,.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Delimiters
*/
@property(nonatomic, readwrite) NSString *itemDelimiter;
/**
* description: Whether to use the first row in the data set as series names. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Don't get series names from the CSV
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *firstRowAsNames;
/**
* description: The Google Spreadsheet worksheet to use in combination with googleSpreadsheetKey. The available id's from your sheet can be read from https://spreadsheets.google.com/feeds/worksheets/{key}/public/basic
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/ : Load a Google Spreadsheet
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetWorksheet;
/**
* description: A callback function to access the parsed columns, the two-dimentional input data array directly, before they are interpreted into series data and categories. Return false to stop completion, or call this.complete() to continue async.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/parsed/ : Modify data after parse
*/
@property(nonatomic, readwrite) NSString /* Function */ *parsed;
/**
* description: A two-dimensional array representing the input data on tabular form. This input can be used when the data is already parsed, for example from a grid view component. Each cell can be a string or number. If not switchRowsAndColumns is set, the columns are interpreted as series.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/columns/ : Columns
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *columns;
/**
* description: Line delimiter for parsing CSV.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Delimiters
* default: \n
*/
@property(nonatomic, readwrite) NSString *lineDelimiter;

-(NSDictionary *)getParams;

@end
