/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
* description: A heatmap series. If the type option is
not specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
heatmap.
*/
@interface HIHeatmap: HISeries

/**
* description: Padding between the points in the heatmap.
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
* description: The row size - how many Y axis units each heatmap row should span.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/ : 1 by default
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *rowsize;
/**
* description: The color applied to null points. In styled mode, a general CSS class is
applied instead.
* default: #f7f7f7
*/
@property(nonatomic, readwrite) HIColor *nullColor;
/**
* description: The column size - how many X axis units each column in the heatmap
should span.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/ : One day
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *colsize;

-(NSDictionary *)getParams;

@end
