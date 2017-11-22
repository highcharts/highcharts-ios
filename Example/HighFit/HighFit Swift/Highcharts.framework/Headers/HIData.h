/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIMarker.h"
#import "HIEvents.h"
#import "HITargetOptions.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
* description: An array of data points for the series. For the bullet series type,
points can be given in the following ways:

An array of arrays with 3 or 2 values. In this case, the values
correspond to x,y,target. If the first value is a string,
it is applied as the name of the point, and the x value is inferred.
The x value can also be omitted, in which case the inner arrays
should be of length 2. Then the x value is automatically calculated,
either starting at 0 and incremented by 1, or from pointStart
and pointInterval given in the series options.
data: [
    [0, 40, 75],
    [1, 50, 50],
    [2, 60, 40]
]


An array of objects with named values. The objects are point
configuration objects as seen below. If the total number of data
points exceeds the series' turboThreshold,
this option is not available.
data: [{
    x: 0,
    y: 40,
    target: 75,
    name: "Point1",
    color: "#00FF00"
}, {
    x: 1,
    y: 60,
    target: 40,
    name: "Point2",
    color: "#FF00FF"
}]



*/
@interface HIData: HIChartsJSONSerializable

/**
* description: The wind speed in meters per second.
*/
@property(nonatomic, readwrite) NSNumber *value;
/**
* description: The name of the point as shown in the legend, tooltip, dataLabel
etc.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series/data-array-of-objects/ : Point names
*/
@property(nonatomic, readwrite) NSString *name;
/**
* description: The rank for this point's data label in case of collision. If two
data labels are about to overlap, only the one with the highest labelrank
will be drawn.
*/
@property(nonatomic, readwrite) NSNumber *labelrank;
/**
* description: Styled mode only. A specific color index to use for the point, so its
graphic representations are given the class name highcharts-color-
{n}.
*/
@property(nonatomic, readwrite) NSNumber *colorIndex;
/**
* description: The wind direction in degrees, where 0 is north (pointing towards south).
*/
@property(nonatomic, readwrite) NSNumber *direction;
/**
* description: An additional, individual class name for the data point's graphic
representation.
*/
@property(nonatomic, readwrite) NSString *className;
@property(nonatomic, readwrite) HIMarker *marker;
/**
* description: An id for the point. This can be used after render time to get a
pointer to the point object through chart.get().

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/id/ : Remove an id'd point
* default: null
*/
@property(nonatomic, readwrite) NSString *id;
/**
* description: The y value of the point.
* default: null
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The x value of the point. For datetime axes, the X value is the timestamp
in milliseconds since 1970.
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: A description of the point to add to the screen reader information
about the point. Requires the Accessibility module.
* default: undefined
*/
@property(nonatomic, readwrite) NSString *definition;
/**
* description: The id of a series in the drilldown.series
array to use for a drilldown for this point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/basic/ : Basic drilldown
*/
@property(nonatomic, readwrite) NSString *drilldown;
/**
* description: Individual color for the point. By default the color is pulled from
the global colors array.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/color/ : Mark the highest point
* default: undefined
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: Individual data label for each point. The options are the same as
the ones for plotOptions.series.dataLabels

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/datalabels/ : Show a label for the last value
*/
@property(nonatomic, readwrite) id dataLabels;
/**
* description: Whether the data point is selected initially.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *selected;
/**
* description: Individual point events
*/
@property(nonatomic, readwrite) HIEvents *events;
/**
* description: The size value for each bubble. The bubbles' diameters are computed
based on the z, and controlled by series options like minSize,
 maxSize, sizeBy, zMin and zMax.
*/
@property(nonatomic, readwrite) NSNumber *z;
/**
* description: An array containing object with Point property names along with what
column id the property should be taken from.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/seriesmapping-label/ : Label from data set
*/
@property(nonatomic, readwrite) NSArray *seriesMapping;
/**
* description: In tabular input data, the last row (indexed by 0) to use. Defaults
to the last row containing data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
*/
@property(nonatomic, readwrite) NSNumber *endRow;
/**
* description: A comma delimited string to be parsed. Related options are startRow, endRow, startColumn
and endColumn to delimit what part of the table
is used. The lineDelimiter and itemDelimiter options define the CSV delimiter formats.
The built-in CSV parser doesn't support all flavours of CSV, so in
some cases it may be necessary to use an external CSV parser. See
http://jsfiddle.net/highcharts/u59176h4/ : this example of parsing
CSV through the MIT licensed http://papaparse.com/ : Papa Parse
library.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/csv/ : Data from CSV
*/
@property(nonatomic, readwrite) NSString *csv;
/**
* description: In tabular input data, the first row (indexed by 0) to use.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *startRow;
/**
* description: Whether to use the first row in the data set as series names.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Don't get series names from the CSV
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *firstRowAsNames;
/**
* description: The same as the columns input option, but defining rows intead of
columns.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/rows/ : Data in rows
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *rows;
/**
* description: In tabular input data, the last column (indexed by 0) to use. Defaults
to the last column containing data.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
*/
@property(nonatomic, readwrite) NSNumber *endColumn;
/**
* description: A two-dimensional array representing the input data on tabular form.
This input can be used when the data is already parsed, for example
from a grid view component. Each cell can be a string or number.
If not switchRowsAndColumns is set, the columns are interpreted as
series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/columns/ : Columns
*/
@property(nonatomic, readwrite) NSArray<NSArray *> *columns;
/**
* description: The decimal point used for parsing numbers in the CSV.
If both this and data.delimiter is set to false, the parser will
attempt to deduce the decimal point automatically.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Comma as decimal point
* default: .
*/
@property(nonatomic, readwrite) NSString *decimalPoint;
/**
* description: A callback function to access the parsed columns, the two-dimentional
input data array directly, before they are interpreted into series
data and categories. Return false to stop completion, or call this.
complete() to continue async.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/parsed/ : Modify data after parse
*/
@property(nonatomic, readwrite) HIFunction *parsed;
/**
* description: The Google Spreadsheet worksheet to use in combination with googleSpreadsheetKey. The available id's from your sheet can be
read from https://spreadsheets.google.com/feeds/worksheets/{key}/public/basic

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/ : Load a Google Spreadsheet
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetWorksheet;
/**
* description: A HTML table or the id of such to be parsed as input data. Related
options are startRow, endRow, startColumn and endColumn to
delimit what part of the table is used.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/column-parsed/ : Parsed table
*/
@property(nonatomic, readwrite) id table;
/**
* description: Line delimiter for parsing CSV.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Delimiters
* default: \n
*/
@property(nonatomic, readwrite) NSString *lineDelimiter;
/**
* description: Which of the predefined date formats in Date.prototype.dateFormats
to use to parse date values. Defaults to a best guess based on what
format gives valid and ordered dates.
Valid options include:

YYYY-mm-dd
dd/mm/YYYY
mm/dd/YYYY
dd/mm/YY
mm/dd/YY


* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/dateformat-auto/ : Best guess date format
* accepted values: [undefined, "YYYY-mm-dd", "dd/mm/YYYY", "mm/dd/YYYY", "dd/mm/YYYY", "dd/mm/YY", "mm/dd/YY"]
*/
@property(nonatomic, readwrite) NSString *dateFormat;
/**
* description: The key for a Google Spreadsheet to load. See https://developers.google.com/gdata/samples/spreadsheet_sample : general information
on GS.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/google-spreadsheet/ : Load a Google Spreadsheet
*/
@property(nonatomic, readwrite) NSString *googleSpreadsheetKey;
/**
* description: The callback that is evaluated when the data is finished loading,
optionally from an external source, and parsed. The first argument
passed is a finished chart options object, containing the series.
These options can be extended with additional options and passed
directly to the chart constructor.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/complete/ : Modify data on complete
*/
@property(nonatomic, readwrite) HIFunction *complete;
/**
* description: A callback function to parse string representations of dates into
JavaScript timestamps. Should return an integer timestamp on success.
*/
@property(nonatomic, readwrite) HIFunction *parseDate;
/**
* description: Switch rows and columns of the input data, so that this.columns
effectively becomes the rows of the data set, and the rows are interpreted
as series.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/switchrowsandcolumns/ : Switch rows and columns
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *switchRowsAndColumns;
/**
* description: Item or cell delimiter for parsing CSV. Defaults to the tab character
\t if a tab character is found in the CSV string, if not it defaults
to ,.
If this is set to false or undefined, the parser will attempt to deduce
the delimiter automatically.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/delimiters/ : Delimiters
*/
@property(nonatomic, readwrite) NSString *itemDelimiter;
/**
* description: In tabular input data, the first column (indexed by 0) to use.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/data/start-end/ : Limited data
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *startColumn;
/**
* description: The node that the link runs from.
*/
@property(nonatomic, readwrite) NSString *from;
/**
* description: The node that the link runs to.
*/
@property(nonatomic, readwrite) NSString *to;
/**
* description: The weight of the link.
*/
@property(nonatomic, readwrite) NSNumber *weight;
/**
* description: Whether the link goes out of the system.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/sankey-outgoing : Sankey chart with outgoing links
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *outgoing;
/**
* description: Serves a purpose only if a colorAxis object is defined in the chart
options. This value will decide which color the point gets from the
scale of the colorAxis.
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber *colorValue;
/**
* description: Point padding for a single point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/tilemap-pointpadding : Point padding on tiles
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
* description: Only for treemap. Use this option to build a tree structure. The
value should be the id of the point which is the parent. If no points
has a matching id, or this option is undefined, then the parent will
be set to the root.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/parent/ : Point parent
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/ : Example where parent id is not matching
* default: undefined
*/
@property(nonatomic, readwrite) NSString *parent;
/**
* description: When this property is true, the point display the total sum across
the entire series. The y value is ignored.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/ : Waterfall
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isSum;
/**
* description: When this property is true, the points acts as a summary column for
the values added or substracted since the last intermediate sum,
or since the start of the series. The y value is ignored.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/waterfall/ : Waterfall
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *isIntermediateSum;
/**
* description: The median for each data point. This is drawn as a line through the
middle area of the box.
*/
@property(nonatomic, readwrite) NSNumber *median;
/**
* description: The low value for each data point, signifying the lowest value
in the sample set. The bottom whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *low;
/**
* description: The high value for each data point, signifying the highest value
in the sample set. The top whisker is drawn here.
*/
@property(nonatomic, readwrite) NSNumber *high;
/**
* description: The lower quartile for each data point. This is the bottom of the
box.
*/
@property(nonatomic, readwrite) NSNumber *q1;
/**
* description: The higher quartile for each data point. This is the top of the box.
*/
@property(nonatomic, readwrite) NSNumber *q3;
/**
* description: The sequential index of the data point in the legend.
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
* description: Whether to display a slice offset from the center.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/point/sliced/ : One sliced point
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sliced;
/**
* description: The length of the vector. The rendered length will relate to the
vectorLength setting.
*/
@property(nonatomic, readwrite) NSNumber *length;
/**
* description: The outer radius of an individual point in a solid gauge. Can be
given as a number (pixels) or percentage string.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/ : Individual radius and innerRadius
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ radius;
/**
* description: The inner radius of an individual point in a solid gauge. Can be
given as a number (pixels) or percentage string.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/solidgauge-radius/ : Individual radius and innerRadius
*/
@property(nonatomic, readwrite) id /* NSNumber, NSString */ innerRadius;
/**
* description: Individual target options for each point.
*/
@property(nonatomic, readwrite) HITargetOptions *targetOptions;
/**
* description: The target value of a point.
*/
@property(nonatomic, readwrite) NSNumber *target;

-(NSDictionary *)getParams;

@end
