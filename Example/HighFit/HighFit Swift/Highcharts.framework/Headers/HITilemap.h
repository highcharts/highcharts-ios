/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIColor.h"


/**
A `tilemap` series. If the `type` option is not specified, it is inherited from `chart.type`. For options that apply to multiple series, it is recommended to add them to the `plotOptions.series` options structure. To apply to all series of this specific type, apply it to `plotOptions.tilemap`.
*/
@interface HITilemap: HISeries

/**
The padding between points in the tilemap.

**Defaults to** `0`.

**Try it**

* [Point padding on tiles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/tilemap-pointpadding)
*/
@property(nonatomic, readwrite) NSNumber *pointPadding;
/**
The column size - how many X axis units each column in the tilemap should span. Works as in `Heatmaps`.

**Defaults to** `1`.

**Try it**

* [One day](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *colsize;
/**
The row size - how many Y axis units each tilemap row should span. Analogous to `colsize`.

**Defaults to** `1`.

**Try it**

* [1 by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/heatmap/)
*/
@property(nonatomic, readwrite) NSNumber *rowsize;
/**
The shape of the tiles in the tilemap. Possible values are `hexagon`, `circle`, `diamond`, and `square`.

**Try it**

* [Circular tile shapes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/circlemap-africa)
* [Diamond tile shapes](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/maps/demo/diamondmap)
*/
@property(nonatomic, readwrite) NSString *tileShape;
/**
The color applied to null points. In styled mode, a general CSS class is applied instead.
*/
@property(nonatomic, readwrite) HIColor *nullColor;

-(NSDictionary *)getParams;

@end
