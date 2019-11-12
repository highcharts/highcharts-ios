/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HILabels.h"
#import "HIRanges.h"
#import "HIColor.h"


/**
The bubble legend is an additional element in legend which presents the scale of the bubble series. Individual bubble ranges can be defined by user or calculated from series. In the case of automatically calculated ranges, a 1px margin of error is permitted.
*/
@interface HIBubbleLegend: HIChartsJSONSerializable

/**
The color of the ranges borders, can be also defined for an individual range.

**Try it**

* [Similat look to the bubble series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/similartoseries/)
* [Individual bubble border color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/bordercolor/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
The color of the connector, can be also defined for an individual range.
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
/**
Define the visual z index of the bubble legend.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
Whether the bubble legend range value should be represented by the area or the width of the bubble. The default, area, corresponds best to the human perception of the size of each bubble.

**Try it**

* [Size by width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/ranges/)
*/
@property(nonatomic, readwrite) NSString *sizeBy;
/**
The position of the bubble legend in the legend.

**Try it**

* [Bubble legend as last item in legend](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/connectorandlabels/)
*/
@property(nonatomic, readwrite) NSNumber *legendIndex;
/**
The width of the connectors in pixels.

**Try it**

* [Increased connector width](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/connectorandlabels/)
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
The main color of the bubble legend. Applies to ranges, if individual color is not defined.

**Try it**

* [Similat look to the bubble series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/similartoseries/)
* [Individual bubble color](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
Options for the bubble legend labels.
*/
@property(nonatomic, readwrite) HILabels *labels;
/**
Enable or disable the bubble legend.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
When this is true, the absolute value of z determines the size of the bubble. This means that with the default zThreshold of 0, a bubble of value -1 will have the same size as a bubble of value 1, while a bubble of value 0 will have a smaller size according to minSize.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *sizeByAbsoluteValue;
/**
An additional class name to apply to the bubble legend' circle graphical elements. This option does not replace default class names of the graphical element.

**Try it**

* [Styling by CSS](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/bubble-legend/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
Options for specific range. One range consists of bubble, label and connector.

**Try it**

* [Manually defined ranges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/ranges/)
* [Auto calculated ranges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/autoranges/)
*/
@property(nonatomic, readwrite) NSArray <HIRanges *> *ranges;
/**
Miximum bubble legend range size. If values for ranges are not specified, the `minSize` and the `maxSize` are calculated from bubble series.
*/
@property(nonatomic, readwrite) NSNumber *maxSize;
/**
Minimum bubble legend range size. If values for ranges are not specified, the `minSize` and the `maxSize` are calculated from bubble series.
*/
@property(nonatomic, readwrite) NSNumber *minSize;
/**
The width of the ranges borders in pixels, can be also defined for an individual range.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
An additional class name to apply to the bubble legend's connector graphical elements. This option does not replace default class names of the graphical element.

**Try it**

* [Styling by CSS](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/bubble-legend/)
*/
@property(nonatomic, readwrite) NSString *connectorClassName;
/**
Ranges with with lower value than zThreshold, are skipped.
*/
@property(nonatomic, readwrite) NSNumber *zThreshold;
/**
The length of the connectors in pixels. If labels are centered, the distance is reduced to 0.

**Try it**

* [Increased connector length](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/bubble-legend/connectorandlabels/)
*/
@property(nonatomic, readwrite) NSNumber *connectorDistance;

-(NSDictionary *)getParams;

@end
