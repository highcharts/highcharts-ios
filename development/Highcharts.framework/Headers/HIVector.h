/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"


/**
* description: A vector series. If the type option is not
specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
vector.
*/
@interface HIVector: HISeries

/**
* description: Maximum length of the arrows in the vector plot. The individual arrow
length is computed between 0 and this value.
* default: 20
*/
@property(nonatomic, readwrite) NSNumber *vectorLength;
/**
* description: What part of the vector it should be rotated around. Can be one of
start, center and end. When start, the vectors will start from
the given [x, y] position, and when end the vectors will end in the
[x, y] position.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/vector-rotationorigin-start/ : Rotate from start
* accepted values: ["start", "center", "end"]
* default: center
*/
@property(nonatomic, readwrite) NSString *rotationOrigin;

-(NSDictionary *)getParams;

@end
