/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Chart type description strings. This is added to the chart information region. If there is only a single series type used in the chart, we use the format string for the series type, or default if missing. There is one format string for cases where there is only a single series in the chart, and one for multiple series of the same type.
*/
@interface HIChartTypes: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *scatterMultiple;
@property(nonatomic, readwrite) NSString *boxplotSingle;
@property(nonatomic, readwrite) NSString *defaultMultiple;
@property(nonatomic, readwrite) NSString *mapTypeDescription;
@property(nonatomic, readwrite) NSString *lineMultiple;
@property(nonatomic, readwrite) NSString *defaultSingle;
@property(nonatomic, readwrite) NSString *emptyChart;
@property(nonatomic, readwrite) NSString *pieMultiple;
@property(nonatomic, readwrite) NSString *columnSingle;
@property(nonatomic, readwrite) NSString *splineMultiple;
@property(nonatomic, readwrite) NSString *unknownMap;
@property(nonatomic, readwrite) NSString *combinationChart;
@property(nonatomic, readwrite) NSString *columnMultiple;
@property(nonatomic, readwrite) NSString *scatterSingle;
@property(nonatomic, readwrite) NSString *bubbleMultiple;
@property(nonatomic, readwrite) NSString *boxplotMultiple;
@property(nonatomic, readwrite) NSString *barSingle;
@property(nonatomic, readwrite) NSString *barMultiple;
@property(nonatomic, readwrite) NSString *lineSingle;
@property(nonatomic, readwrite) NSString *splineSingle;
@property(nonatomic, readwrite) NSString *bubbleSingle;
@property(nonatomic, readwrite) NSString *pieSingle;

-(NSDictionary *)getParams;

@end
