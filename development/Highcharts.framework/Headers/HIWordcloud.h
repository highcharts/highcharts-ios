/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIRotation.h"
#import "HIColor.h"
#import "HICSSObject.h"


/**
 A `wordcloud` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `wordcloud` series are defined in `plotOptions.wordcloud`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        wordcloud: {
            // shared options for all wordcloud series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'wordcloud'
    }]
 });
 <pre>
 */
@interface HIWordcloud: HISeries

/**
When using automatic point colors pulled from the global `colors` or series-specific `plotOptions.column.colors` collections, this option determines whether the chart should receive one color per series or one color per point. In styled mode, the `colors` or `series.colors` arrays are not supported, and instead this option gives the points individual color class names on the form `highcharts-color-{n}`.

**Defaults to** `false`.

**Try it**

* [False by default](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-false/)
* [True](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-colorbypoint-true/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
/**
CSS styles for the words.

**Defaults to** `{"fontFamily":"sans-serif", "fontWeight": "900"}`.
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
A threshold determining the minimum font size that can be applied to a word.
*/
@property(nonatomic, readwrite) NSNumber *minFontSize;
/**
The word with the largest weight will have a font size equal to this value. The font size of a word is the ratio between its weight and the largest occuring weight, multiplied with the value of maxFontSize.
*/
@property(nonatomic, readwrite) NSNumber *maxFontSize;
/**
If there is no space for a word on the playing field, then this option will allow the playing field to be extended to fit the word. If false then the word will be dropped from the visualization. NB! This option is currently not decided to be published in the API, and is therefore marked as private.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowExtendPlayingField;
/**
Spiral used for placing a word after the initial position experienced a collision with either another word or the borders. It is possible for users to add their own custom spiralling algorithms for use in word cloud. Read more about it in our [documentation](https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-spiralling-algorithm)
*/
@property(nonatomic, readwrite) NSString *spiral;
/**
The width of the border surrounding each column or bar. Defaults to `1` when there is room for a border, but to `0` when the columns are so dense that a border would cover the next column. In styled mode, the stroke width can be set with the `.highcharts-point` rule.

**Defaults to** `undefined`.

**Try it**

* [2px black border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderwidth/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Rotation options for the words in the wordcloud.

**Try it**

* [Word cloud with rotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/wordcloud-rotation)
*/
@property(nonatomic, readwrite) HIRotation *rotation;
/**
This option decides which algorithm is used for placement, and rotation of a word. The choice of algorith is therefore a crucial part of the resulting layout of the wordcloud. It is possible for users to add their own custom placement strategies for use in word cloud. Read more about it in our [documentation](https://www.highcharts.com/docs/chart-and-series-types/word-cloud-series#custom-placement-strategies)
*/
@property(nonatomic, readwrite) NSString *placementStrategy;
/**
The corner radius of the border surrounding each column or bar.

**Try it**

* [Rounded columns](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-borderradius/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
A series specific or series type specific color set to apply instead of the global `colors` when `colorByPoint` is true.
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
The color of the border surrounding each column or bar. In styled mode, the border stroke can be set with the `.highcharts-point` rule.

**Defaults to** `#ffffff`.

**Try it**

* [Dark gray border](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/column-bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
3D columns only. The width of the colored edges.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *edgeWidth;

-(NSDictionary *)getParams;

@end
