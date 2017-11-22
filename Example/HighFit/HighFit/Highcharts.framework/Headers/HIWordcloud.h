/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIStyle.h"
#import "HIRotation.h"
#import "HIColor.h"


/**
* description: A wordcloud series. If the type option is
not specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
wordcloud.
*/
@interface HIWordcloud: HISeries

/**
* description: The color of the border surrounding each column or bar.
In styled mode, the border stroke can be set with the .highcharts-point
rule.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/ : Dark gray border
* default: #ffffff
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: When using automatic point colors pulled from the options.colors
collection, this option determines whether the chart should receive
one color per series or one color per point.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/ : False by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/ : True
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
* description: CSS styles for the words.
* default: {"fontFamily":"Impact, sans-serif"}
*/
@property(nonatomic, readwrite) HIStyle *style;
/**
* description: This option decides which algorithm is used for placement, and rotation
of a word. The choice of algorith is therefore a crucial part of the
resulting layout of the wordcloud.
It is possible for users to add their own custom placement strategies
for use in word cloud. Read more about it in our
https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-placement-strategies : documentation
* default: random
*/
@property(nonatomic, readwrite) NSString *placementStrategy;
/**
* description: Rotation options for the words in the wordcloud.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/wordcloud-rotation : Word cloud with rotation
*/
@property(nonatomic, readwrite) HIRotation *rotation;
/**
* description: A series specific or series type specific color set to apply instead
of the global colors when colorByPoint is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
* description: The corner radius of the border surrounding each column or bar.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderradius/ : Rounded columns
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: 3D columns only. The width of the colored edges.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *edgeWidth;
/**
* description: Spiral used for placing a word after the inital position experienced a
collision with either another word or the borders.
It is possible for users to add their own custom spiralling algorithms
for use in word cloud. Read more about it in our
https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-spiralling-algorithm : documentation
* default: archimedean
*/
@property(nonatomic, readwrite) NSString *spiral;

-(NSDictionary *)getParams;

@end
