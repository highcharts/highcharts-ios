/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"
#import "HILevels.h"
#import "HIColor.h"


/**
* description: A sunburst series. If the type option is
not specified, it is inherited from chart.type.
For options that apply to multiple series, it is recommended to add
them to the plotOptions.series options structure.
To apply to all series of this specific type, apply it to plotOptions.
sunburst.
*/
@interface HISunburst: HISeries

/**
* description: The color of the border surrounding each slice. When null, the
border takes the same color as the slice fill. This can be used
together with a borderWidth to fill drawing gaps created by antialiazing
artefacts in borderless pies.
In styled mode, the border stroke is given in the .highcharts-point class.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-bordercolor-black/ : Black border
* default: #ffffff
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The diameter of the pie relative to the plot area. Can be a percentage
or pixel value. Pixel values are given as integers. The default
behaviour (as of 3.0) is to scale to the plot area and give room
for data labels within the plot area. As a consequence, the size
of the pie may vary when points are updated and data labels more
around. In that case it is best to set a fixed value, for example
"75%".

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-size/ : Smaller pie
*/
@property(nonatomic, readwrite) id /* NSString, NSNumber */ size;
/**
* description: Which point to use as a root in the visualization.
* default: undefined
*/
@property(nonatomic, readwrite) NSString *rootId;
/**
* description: The start angle of the pie slices in degrees where 0 is top and 90
right.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-startangle-90/ : Start from right
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *startAngle;
/**
* description: Set options on specific levels. Takes precedence over series options,
but not point options.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst : Sunburst chart
*/
@property(nonatomic, readwrite) NSArray <HILevels *> *levels;
/**
* description: Used together with the levels and allowDrillToNode options. When
set to false the first level visible when drilling is considered
to be level one. Otherwise the level will be the same as the tree
structure.
* default: True
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *levelIsConstant;
/**
* description: A series specific or series type specific color set to use instead
of the global colors.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome/ : Set default colors for all pies
*/
@property(nonatomic, readwrite) NSArray<HIColor *> *colors;
/**
* description: When enabled the user can click on a point which is a parent and
zoom in on its children.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/sunburst : Allow drill to node
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowDrillToNode;

-(NSDictionary *)getParams;

@end
