/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAccessibility.h"
#import "HIDataLabels.h"
#import "HIDragDrop.h"
#import "HIEvents.h"
#import "HIMarker.h"
#import "HITargetOptions.h"
#import "HIPartialFill.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
The Data module provides a simplified interface for adding data to a chart from sources like CVS, HTML tables or grid views. See also the [tutorial article on the Data module](https://www.highcharts.com/docs/working-with-data/data-module). It requires the `modules/data.js` file to be loaded. Please note that the default way of adding data in Highcharts, without the need of a module, is through the `series._type_.data` option.

**Try it**

* [HTML table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/)
* [CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/)
*/
@interface HIData: HIChartsJSONSerializable

/**
Enables automatic refetching of remote datasets every _n_ seconds (defined by setting `data.dataRefreshRate`). Only works when either `data.csvURL`, `data.rowsURL`, `data.columnsURL`, or `data.googleSpreadsheetKey`.

**Defaults to** `false`.

**Try it**

* [Live data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/live-data)
* [Categorized bar chart with CSV and live polling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/livedata-columns)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enablePolling;
/**
In tabular input data, the first column (indexed by 0) to use.

**Defaults to** `0`.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *startColumn;
/**
Line delimiter for parsing CSV.

**Defaults to** `\n`.

**Try it**

* [Delimiters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *lineDelimiter;
/**
An HTML table or the id of such to be parsed as input data. Related options are `startRow`, `endRow`, `startColumn` and `endColumn` to delimit what part of the table is used.

**Try it**

* [Parsed table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/)
*/
@property(nonatomic, readwrite) NSString *table;
/**
A URL to a remote JSON dataset, structured as a row array. Will be fetched when the chart is created using Ajax.

**Try it**

* [Rows with live polling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/livedata-rows)
*/
@property(nonatomic, readwrite) NSString *rowsURL;
/**
A callback function to parse string representations of dates into JavaScript timestamps. Should return an integer timestamp on success.
*/
@property(nonatomic, readwrite) HIFunction *parseDate;
/**
An array containing dictionaries for each series. A dictionary exists of Point property names as the key and the CSV column index as the value.

**Try it**

* [Label from data set](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/seriesmapping-label/)
*/
@property(nonatomic, readwrite) NSArray *seriesMapping;
/**
The same as the columns input option, but defining rows intead of columns.

**Try it**

* [Data in rows](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/rows/)
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *rows;
/**
An URL to a remote CSV dataset. Will be fetched when the chart is created using Ajax.

**Try it**

* [Categorized bar chart with CSV and live polling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/livedata-columns)
* [Time based line chart with CSV and live polling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/livedata-csv)
*/
@property(nonatomic, readwrite) NSString *csvURL;
/**
Which of the predefined date formats in Date.prototype.dateFormats to use to parse date values. Defaults to a best guess based on what format gives valid and ordered dates. Valid options include: `YYYY/mm/dd`, `dd/mm/YYYY`, `mm/dd/YYYY`, `dd/mm/YY`, `mm/dd/YY`.

**Accepted values:** `["YYYY/mm/dd", "dd/mm/YYYY", "mm/dd/YYYY", "dd/mm/YYYY",
            "dd/mm/YY", "mm/dd/YY"]`.

**Try it**

* [Best guess date format](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/dateformat-auto/)
*/
@property(nonatomic, readwrite) NSString *dateFormat;
/**
The Google Spreadsheet worksheet to use in combination with `googleSpreadsheetKey`. The available id's from your sheet can be read from `https://spreadsheets.google.com/feeds/worksheets/{key}/public/basic`.

**Try it**

* [Load a Google Spreadsheet](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/)
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetWorksheet;
/**
Sets the refresh rate for data polling when importing remote dataset by setting `data.csvURL`, `data.rowsURL`, `data.columnsURL`, or `data.googleSpreadsheetKey`. Note that polling must be enabled by setting `data.enablePolling` to true. The value is the number of seconds between pollings. It cannot be set to less than 1 second.

**Defaults to** `1`.

**Try it**

* [Live data with user set refresh rate](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/live-data)
*/
@property(nonatomic, readwrite) NSNumber *dataRefreshRate;
/**
A callback function to access the parsed columns, the two-dimentional input data array directly, before they are interpreted into series data and categories. Return `false` to stop completion, or call `this.complete()` to continue async.

**Try it**

* [Modify data after parse](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/parsed/)
*/
@property(nonatomic, readwrite) HIFunction *parsed;
/**
In tabular input data, the first row (indexed by 0) to use.

**Defaults to** `0`.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *startRow;
/**
A comma delimited string to be parsed. Related options are `startRow`, `endRow`, `startColumn` and `endColumn` to delimit what part of the table is used. The `lineDelimiter` and `itemDelimiter` options define the CSV delimiter formats. The built-in CSV parser doesn't support all flavours of CSV, so in some cases it may be necessary to use an external CSV parser. See [this example](https://jsfiddle.net/highcharts/u59176h4/) of parsing CSV through the MIT licensed [Papa Parse](http://papaparse.com/) library.

**Try it**

* [Data from CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/)
*/
@property(nonatomic, readwrite) NSString *csv;
/**
A two-dimensional array representing the input data on tabular form. This input can be used when the data is already parsed, for example from a grid view component. Each cell can be a string or number. If not switchRowsAndColumns is set, the columns are interpreted as series.

**Try it**

* [Columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/columns/)
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *columns;
/**
In tabular input data, the last row (indexed by 0) to use. Defaults to the last row containing data.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *endRow;
/**
Item or cell delimiter for parsing CSV. Defaults to the tab character `\t` if a tab character is found in the CSV string, if not it defaults to `,`. If this is set to false or undefined, the parser will attempt to deduce the delimiter automatically.

**Try it**

* [Delimiters](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *itemDelimiter;
/**
The callback that is evaluated when the data is finished loading, optionally from an external source, and parsed. The first argument passed is a finished chart options object, containing the series. These options can be extended with additional options and passed directly to the chart constructor.

**Try it**

* [Modify data on complete](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/complete/)
*/
@property(nonatomic, readwrite) HIFunction *complete;
/**
A callback function to modify the CSV before parsing it. Return the modified string.

**Try it**

* [Modify CSV before parse](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/line-ajax/)
*/
@property(nonatomic, readwrite) HIFunction *beforeParse;
/**
In tabular input data, the last column (indexed by 0) to use. Defaults to the last column containing data.

**Try it**

* [Limited data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber *endColumn;
/**
Whether to use the first row in the data set as series names.

**Defaults to** `true`.

**Try it**

* [Don't get series names from the CSV](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *firstRowAsNames;
/**
The key for a Google Spreadsheet to load. See [general information on GS](https://developers.google.com/gdata/samples/spreadsheet_sample).

**Try it**

* [Load a Google Spreadsheet](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/)
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetKey;
/**
Switch rows and columns of the input data, so that `this.columns` effectively becomes the rows of the data set, and the rows are interpreted as series.

**Defaults to** `false`.

**Try it**

* [Switch rows and columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/switchrowsandcolumns/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *switchRowsAndColumns;
/**
The decimal point used for parsing numbers in the CSV. If both this and data.delimiter is set to `undefined`, the parser will attempt to deduce the decimal point automatically.

**Defaults to** `.`.

**Try it**

* [Comma as decimal point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/)
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
A URL to a remote JSON dataset, structured as a column array. Will be fetched when the chart is created using Ajax.

**Try it**

* [Columns with live polling](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/livedata-columns)
*/
@property(nonatomic, readwrite) NSString *columnsURL;
/**
The `high` value for each data point, signifying the highest value in the sample set. The top whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *high;
/**
The lower quartile for each data point. This is the bottom of the box.
*/
@property(nonatomic, readwrite) NSNumber *q1;
/**
The higher quartile for each data point. This is the top of the box.
*/
@property(nonatomic, readwrite) NSNumber *q3;
/**
The median for each data point. This is drawn as a line through the middle area of the box.
*/
@property(nonatomic, readwrite) NSNumber *median;
/**
The `low` value for each data point, signifying the lowest value in the sample set. The bottom whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *low;
/**
The rank for this point's data label in case of collision. If two data labels are about to overlap, only the one with the highest `labelrank` will be drawn.
*/
@property(nonatomic, readwrite) NSNumber *labelrank;
/**
The y value of the point.
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
A description of the point to add to the screen reader information about the point.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
The name of the point as shown in the legend, tooltip, dataLabels, etc.

**Try it**

* [Point names](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/)
*/
@property(nonatomic, readwrite) NSString *name;
/**
Individual color for the point. By default the color is pulled from the global `colors` array. In styled mode, the `color` option doesn't take effect. Instead, use `colorIndex`.

**Try it**

* [Mark the highest point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Whether the data point is selected initially.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
Accessibility options for a data point.
*/
@property(nonatomic, readwrite) HIAccessibility *accessibility;
/**
Individual data label for each point. The options are the same as the ones for `plotOptions.series.dataLabels`.

**Try it**

* [Show a label for the last value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/datalabels/)
*/
@property(nonatomic, readwrite) HIDataLabels *dataLabels;
/**
An additional, individual class name for the data point's graphic representation.
*/
@property(nonatomic, readwrite) NSString *className;
/**
Point specific options for the draggable-points module. Overrides options on `series.dragDrop`.
*/
@property(nonatomic, readwrite) HIDragDrop *dragDrop;
/**
An id for the point. This can be used after render time to get a pointer to the point object through `chart.get()`.

**Try it**

* [Remove an id'd point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/id/)
*/
@property(nonatomic, readwrite) NSString *id;
/**
The x value of the point. For datetime axes, the X value is the timestamp in milliseconds since 1970.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
The `id` of a series in the `drilldown.series` array to use for a drilldown for this point.

**Try it**

* [Basic drilldown](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/basic/)
*/
@property(nonatomic, readwrite) NSString *drilldown;
/**
The individual point events.
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
A specific color index to use for the point, so its graphic representations are given the class name `highcharts-color-{n}`. In styled mode this will change the color of the graphic. In non-styled mode, the color by is set by the `fill` attribute, so the change in class name won't have a visual effect by default.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
The sequential index of the data point in the legend.
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
Options for the point markers of line-like series.
*/
@property(nonatomic, readwrite) HIMarker *marker;
/**
The label of event.
*/
@property(nonatomic, readwrite) NSString *label;
/**
The vector direction in degrees, where 0 is north (pointing towards south).
*/
@property(nonatomic, readwrite) NSNumber *direction;
/**
The length of the vector. The rendered length will relate to the `vectorLength` setting.
*/
@property(nonatomic, readwrite) NSNumber *length;
/**
The target value of a point.
*/
@property(nonatomic, readwrite) NSNumber *target;
/**
Individual target options for each point.
*/
@property(nonatomic, readwrite) HITargetOptions *targetOptions;
/**
The color of the border surrounding the column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
A name for the dash style to use for the column or bar. Overrides dashStyle on the series. In styled mode, the stroke dash-array can be set with the same classes as listed under `data.color`.
*/
@property(nonatomic, readwrite) NSString *dashStyle;
/**
A pixel value specifying a fixed width for the column or bar. Overrides pointWidth on the series.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) NSNumber *pointWidth;
/**
The width of the border surrounding the column or bar. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Whether to display a slice offset from the center.

**Try it**

* [One sliced point](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/sliced/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sliced;
/**
Point padding for a single point.

**Try it**

* [Point padding on tiles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/tilemap-pointpadding)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The value of the point, resulting in a color controled by options as set in the `colorAxis` configuration.
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
When this property is true, the points acts as a summary column for the values added or substracted since the last intermediate sum, or since the start of the series. The `y` value is ignored.

**Defaults to** `false`.

**Try it**

* [Waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isIntermediateSum;
/**
When this property is true, the point display the total sum across the entire series. The `y` value is ignored.

**Defaults to** `false`.

**Try it**

* [Waterfall](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isSum;
/**
The node that the link runs to.
*/
@property(nonatomic, readwrite) NSString *to;
/**
The node that the link runs from.
*/
@property(nonatomic, readwrite) NSString *from;
/**
By deafult sides fill is set to a gradient through this option being set to `true`. Set to `false` to get solid color for the sides.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *gradientForSides;
/**
The weight of the link.
*/
@property(nonatomic, readwrite) NSNumber *weight;
/**
The inner radius of an individual point in a solid gauge. Can be given as a number (pixels) or percentage string.

**Try it**

* [Individual radius and innerRadius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;
/**
The outer radius of an individual point in a solid gauge. Can be given as a number (pixels) or percentage string.

**Try it**

* [Individual radius and innerRadius](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/)
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ radius;
/**
Whether the link goes out of the system.

**Defaults to** `false`.

**Try it**

* [Sankey chart with outgoing links](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *outgoing;
/**
The size value for each bubble. The bubbles' diameters are computed based on the `z`, and controlled by series options like `minSize`, `maxSize`, `sizeBy`, `zMin` and `zMax`.
*/
@property(nonatomic, readwrite) NSNumber *z;
/**
The ending X value of the range point.

**Try it**

* [X-range](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range)
*/
@property(nonatomic, readwrite) NSNumber *x2;
/**
A partial fill for each point, typically used to visualize how much of a task is performed. The partial fill object can be set either on series or point level.

**Try it**

* [X-range with partial fill](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/x-range)
*/
@property(nonatomic, readwrite) HIPartialFill *partialFill;
/**
Only for treemap. Use this option to build a tree structure. The value should be the id of the point which is the parent. If no points has a matching id, or this option is undefined, then the parent will be set to the root.

**Try it**

* [Point parent](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/parent/)
* [Example where parent id is not matching](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/)
*/
@property(nonatomic, readwrite) NSString *parent;
/**
Serves a purpose only if a `colorAxis` object is defined in the chart options. This value will decide which color the point gets from the scale of the colorAxis.
*/
@property(nonatomic, readwrite) NSNumber *colorValue;
/**
The set or sets the options will be applied to. If a single entry is defined, then it will create a new set. If more than one entry is defined, then it will define the overlap between the sets in the array.

**Try it**

* [Venn diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/venn-diagram/)
* [Euler diagram](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/euler-diagram/)
*/
@property(nonatomic, readwrite) NSArray<NSString *> *sets;

-(NSDictionary *)getParams;

@end
