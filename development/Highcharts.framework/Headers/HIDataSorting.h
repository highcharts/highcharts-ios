/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for the series data sorting.
*/
@interface HIDataSorting: HIChartsJSONSerializable

/**
Whether to allow matching points by name in an update. If this option is disabled, points will be matched by order.

**Try it**

* [Enabled match by name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/match-by-name/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *matchByName;
/**
Enable or disable data sorting for the series. Use `xAxis.reversed` to change the sorting order.

**Try it**

* [Data sorting in scatter-3d](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/animation/)
* [Axis labels animation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/labels-animation/)
* [Dependent series sorting](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/dependent-sorting/)
* [Independent series sorting](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/independent-sorting/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Determines what data value should be used to sort by.

**Defaults to** `y`.

**Try it**

* [Sort key as `z` value](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/datasorting/sort-key/)
*/
@property(nonatomic, readwrite) NSString *sortKey;

-(NSDictionary *)getParams;

@end
