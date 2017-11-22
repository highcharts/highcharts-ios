/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HIDrillUpButton.h"
#import "HILevels.h"
#import "HIColor.h"


/**
* description: A treemap series. If the type option is
not specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
treemap.
*/
@interface HITreemap: HISeries

/**
* description: Used together with the levels and allowDrillToNode options. When
set to false the first level visible when drilling is considered
to be level one. Otherwise the level will be the same as the tree
structure.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *levelIsConstant;
/**
* description: Options for the button appearing when drilling down in a treemap.
*/
@property(nonatomic, readwrite) HIDrillUpButton *drillUpButton;
/**
* description: The color of the border surrounding each tree map item.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/maps/plotoptions/series-border/ : Borders demo
* default: #e6e6e6
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: Defines which direction the layout algorithm will start drawing.
 Possible values are "vertical" and "horizontal".

* accepted values: ["vertical", "horizontal"]
* default: vertical
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;
/**
* description: Set options on specific levels. Takes precedence over series options,
but not point options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/ : Styling dataLabels and borders
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/ : Different layoutAlgorithm
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
* description: Whether to ignore hidden points when the layout algorithm runs.
If false, hidden points will leave open spaces.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *ignoreHiddenPoint;
/**
* description: This option decides if the user can interact with the parent nodes
or just the leaf nodes. When this option is undefined, it will be
true by default. However when allowDrillToNode is true, then it will
be false by default.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-false/ : False
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-interactbyleaf-true-and-allowdrilltonode/ : InteractByLeaf and allowDrillToNode is true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *interactByLeaf;
/**
* description: The opacity of a point in treemap. When a point has children, the
visibility of the children is determined by the opacity.
* default: 0.15
*/
@property(nonatomic, readwrite) NSNumber *opacity;
/**
* description: When enabled the user can click on a point which is a parent and
zoom in on its children.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-allowdrilltonode/ : Enabled
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowDrillToNode;
/**
* description: Enabling this option will make the treemap alternate the drawing
direction between vertical and horizontal. The next levels starting
direction will always be the opposite of the previous.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-alternatestartingdirection-true/ : Enabled
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternateStartingDirection;
/**
* description: This option decides which algorithm is used for setting position
and dimensions of the points. Can be one of sliceAndDice, stripes,
 squarified or strip.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-sliceanddice/ : SliceAndDice by default
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-stripes/ : Stripes
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-squarified/ : Squarified
https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-layoutalgorithm-strip/ : Strip
* accepted values: ["sliceAndDice", "stripes", "squarified", "strip"]
* default: sliceAndDice
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
* description: The sort index of the point inside the treemap level.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-sortindex/ : Sort by years
*/
@property(nonatomic, readwrite) NSNumber *sortIndex;

-(NSDictionary *)getParams;

@end
