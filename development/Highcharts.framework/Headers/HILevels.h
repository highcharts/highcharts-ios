/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColorVariation.h"
#import "HIColor.h"


/**
Set options on specific levels. Takes precedence over series options, but not point options.

**Try it**

* [Sunburst chart](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst)
*/
@interface HILevels: HIChartsJSONSerializable

/**
Can set a `borderColor` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
Can set a `colorVariation` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColorVariation *colorVariation;
/**
Can set a `levelSize` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) id levelSize;
/**
Can set a `borderDashStyle` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSString *borderDashStyle;
/**
Can set a `color` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Can set a `dataLabels` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) id dataLabels;
/**
Can set a `rotationMode` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSString *rotationMode;
/**
Can set a `borderWidth` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Can set a `rotation` on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
Decides which level takes effect from the options set in the levels object.

**Try it**

* [Styling of both levels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/)
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
Can set the layoutAlgorithm option on a specific level.

**Accepted values:** `["sliceAndDice", "stripes", "squarified", "strip"]`.
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
Can set the layoutStartingDirection option on a specific level.

**Accepted values:** `["vertical", "horizontal"]`.
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;

-(NSDictionary *)getParams;

@end
