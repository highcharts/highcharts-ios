/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
* description: Set options on specific levels. Takes precedence over series options, but not point options.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/ : Styling dataLabels and borders, http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/demo/treemap-with-levels/ : Different layoutAlgorithm
*/
@interface HIPlotOptionsTreemapLevels: HIChartsJSONSerializable

/**
* description: Decides which level takes effect from the options set in the levels object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/treemap-levels/ : Styling of both levels
*/
@property(nonatomic, readwrite) NSNumber *level;
/**
* description: Set the dash style of the border of all the point which lies on the level.
See plotOptions.scatter.dashStyle for possible options.
*/
@property(nonatomic, readwrite) NSString *borderDashStyle;
/**
* description: Can set the borderWidth on all points which lies on the same level.
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Can set the layoutStartingDirection option on a specific level.
* accepted values: ["vertical", "horizontal"]
*/
@property(nonatomic, readwrite) NSString *layoutStartingDirection;
/**
* description: Can set the layoutAlgorithm option on a specific level. 
* accepted values: ["sliceAndDice", "stripes", "squarified", "strip"]
*/
@property(nonatomic, readwrite) NSString *layoutAlgorithm;
/**
* description: Can set a color on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: Can set the options of dataLabels on each point which lies on the level.
plotOptions.treemap.dataLabels for possible values.
* default: undefined
*/
@property(nonatomic, readwrite) id dataLabels;
/**
* description: Can set a borderColor on all points which lies on the same level.
*/
@property(nonatomic, readwrite) HIColor *borderColor;

-(NSDictionary *)getParams;

@end
