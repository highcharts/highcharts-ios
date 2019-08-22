/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"
#import "HIFunction.h"
#import "HICSSObject.h"


/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names ([see example](https://www.highcharts.com/samples/highcharts/css/series-datalabels)).

**Try it**

* [Data labels enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-enabled)
* [Multiple data labels on a bar series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-multiple)
*/
@interface HIDataLabels: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber *y;
@property(nonatomic, readwrite) NSString *align;
@property(nonatomic, readwrite) NSString *verticalAlign;
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
@property(nonatomic, readwrite) NSString *borderColor;
@property(nonatomic, readwrite) HIStyle *style;
/**
The width of the line connecting the data label to the point. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.

**Try it**

* [Custom connector width and color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/connector-styles)
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
Whether to position data labels alternately. For example, if `distance` is set equal to `100`, then data labels will be positioned alternately (on both sides of the point) at a distance of 100px.

**Try it**

* [Alternate disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/series-timeline/alternate-disabled)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *alternate;
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
@property(nonatomic, readwrite) NSString *color;
/**
The color of the line connecting the data label to the point. The default color is the same as the point's color. In styled mode, the connector stroke is given in the `.highcharts-data-label-connector` class.
*/
@property(nonatomic, readwrite) NSString *connectorColor;
@property(nonatomic, readwrite) NSNumber *borderWidth;
@property(nonatomic, readwrite) NSString *backgroundColor;
/**
Shadow options for the data label.
*/
@property(nonatomic, readwrite) HICSSObject *shadow;
@property(nonatomic, readwrite) HIFunction *formatter;
/**
A pixel value defining the distance between the data label and the point. Negative numbers puts the label on top of the point.
*/
@property(nonatomic, readwrite) NSNumber *distance;
@property(nonatomic, readwrite) NSNumber *padding;
@property(nonatomic, readwrite) NSNumber *x;

-(NSDictionary *)getParams;

@end
